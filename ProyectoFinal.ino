#include <WiFi.h>
#include <Adafruit_NeoPixel.h>

// Configuración Wi-Fi
const char* ssid = "PixelKiko";
const char* password = "ertiokl9";

// Configuración del LED NeoPixel
#define RGB_BUILTIN 48
Adafruit_NeoPixel led = Adafruit_NeoPixel(1, RGB_BUILTIN, NEO_GRB + NEO_KHZ800);

// Pines de los sensores de movimiento
#define SENSOR_1 4
#define SENSOR_2 5

// Crear un servidor web en el puerto 80
WiFiServer server(80);

void setup() {
  Serial.begin(115200);

  // Configuración de los pines de los sensores
  pinMode(SENSOR_1, INPUT);
  pinMode(SENSOR_2, INPUT);


  // Configuración del LED NeoPixel
  led.begin();
  led.show(); // Inicializa todos los píxeles a 'apagado'

  // Conexión a la red Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    // Encender LED rojo si la conexión falla
    led.setPixelColor(0, led.Color(255, 0, 0)); // Rojo
    led.show();
  }

  // Conexión exitosa
  Serial.println("");
  Serial.println("Conectado a la red Wi-Fi");

  // Imprime la URL con formato clicable en el Monitor Serie
  String ipAddress = WiFi.localIP().toString();
  Serial.println("http://" + ipAddress);

  // Apagar LED rojo
  led.setPixelColor(0, led.Color(0, 0, 0)); // Apagado
  led.show();

  // Iniciar el servidor
  server.begin();

  led.setPixelColor(0, led.Color(0, 255, 0)); // Verde
  led.show();
}

void loop() {
  // Verificar si hay movimiento en los sensores
  bool movimientoSensor1 = digitalRead(SENSOR_1);
  bool movimientoSensor2 = digitalRead(SENSOR_2);

  // Encender LED azul si detecta movimiento en cualquier sensor
  if (movimientoSensor1 || movimientoSensor2) {
    led.setPixelColor(0, led.Color(0, 0, 255)); // Azul
    led.show();
  } else {
    led.setPixelColor(0, led.Color(0, 0, 0)); // Apagado
    led.show();
  }

  // Atender clientes en el servidor web
  WiFiClient client = server.available();

  if (client) {
    String request = client.readStringUntil('\r');
    client.flush();

    String pagina = "<html><head>";
    pagina += "<title>Monitor de Movimiento</title>"; // Título de la página
    pagina += "<meta http-equiv='refresh' content='2'>"; // Actualización automática cada 2 segundos
    pagina += "</head><body>";

    // Contenido de la página
    pagina += "<h1>Monitor de Movimiento</h1>";
    if (movimientoSensor1 || movimientoSensor2) {
      pagina += "<p><strong>No hay movimiento detectado en:</strong></p>";
      if (movimientoSensor1) pagina += "<p>Sensor 1</p>";
      if (movimientoSensor2) pagina += "<p>Sensor 2</p>";
    } else {
      pagina += "<p>En todos hay movimiento.</p>";
    }

    pagina += "</body></html>";

    // Enviar respuesta al cliente
    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/html");
    client.println();
    client.println(pagina);
    client.println();

    client.stop();
  }
}
