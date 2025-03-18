# Proyecto Final - Monitor de Movimiento con Wi-Fi y NeoPixel

## Descripción
Este proyecto consiste en un monitor de movimiento que utiliza sensores de movimiento y un LED NeoPixel para indicar el estado de detección de movimiento. Además, el dispositivo se conecta a una red Wi-Fi y proporciona una interfaz web para monitorear el estado de los sensores en tiempo real.

## 🛠️ Tecnologías

[![Arduino](https://img.shields.io/badge/Arduino-1.8.13-blue?style=flat&logo=arduino)](https://www.arduino.cc/)
[![Wi-Fi](https://img.shields.io/badge/Wi--Fi-802.11-blue?style=flat&logo=wi-fi)](https://www.wi-fi.org/)
[![Adafruit NeoPixel](https://img.shields.io/badge/Adafruit%20NeoPixel-1.10.4-blue?style=flat&logo=adafruit)](https://www.adafruit.com/category/168)
[![Motion Sensors](https://img.shields.io/badge/Motion%20Sensors-1.0.0-blue?style=flat&logo=sensor)](https://www.example.com/motion-sensors)

## Tecnologías Utilizadas
- **Arduino**: Plataforma de hardware libre basada en una placa con un microcontrolador y un entorno de desarrollo.
- **Wi-Fi**: Utilizado para conectar el dispositivo a una red inalámbrica y permitir la comunicación a través de un servidor web.
- **Adafruit NeoPixel**: LED RGB direccionable utilizado para indicar visualmente el estado de los sensores de movimiento.
- **Sensores de Movimiento**: Utilizados para detectar la presencia de movimiento en el área monitoreada.

## Componentes
- **Placa Arduino**: Microcontrolador para ejecutar el código.
- **Módulo Wi-Fi**: Para la conectividad inalámbrica.
- **LED NeoPixel**: Para la indicación visual.
- **Sensores de Movimiento**: Para la detección de movimiento.

## Configuración del Proyecto
1. **Conexiones**:
   - Sensor 1 ➔ Pin 4.
   - Sensor 2 ➔ Pin 5.
   - LED NeoPixel ➔ Pin 48.

2. **Wi-Fi**:
   - Modifica `ssid` y `password` en el código con los datos de tu red.

3. **Bibliotecas**:
   - Instala `WiFi.h` (incluida en ESP32) y `Adafruit_NeoPixel` (via Arduino Library Manager).

## Funcionamiento
1. El dispositivo se conecta a la red Wi-Fi configurada.
2. Los sensores de movimiento detectan la presencia de movimiento.
3. El LED NeoPixel cambia de color según el estado de los sensores:
   - Rojo: Conexión Wi-Fi fallida.
   - Verde: Conexión Wi-Fi exitosa.
   - Azul: Movimiento detectado.
   - Apagado: Sin movimiento detectado.
4. Un servidor web en el puerto 80 permite monitorear el estado de los sensores a través de una interfaz web.

## Uso
1. Conectar el dispositivo a la red Wi-Fi.
2. Acceder a la URL proporcionada en el Monitor Serie para ver la interfaz web.
3. Monitorear el estado de los sensores en tiempo real.

## Autor
- **Nombre del Autor**: [Adrián Brihuega Sánchez]

