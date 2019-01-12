Meteostanice

Jak to bude fungovat...

Cílem bude sběr dat z čidel - vlhkost, teplota do mqtt serveru Použité prvky:esp8266 NodeMcu a esp8266 d1, Použité technologie: homie framework PlatformioIDE vsCode.

Jak funguje mqtt

https://docs.platformio.org/en/latest/ide/vscode.html

https://learn.adafruit.com/esp8266-temperature-slash-humidity-webserver/code

https://platformio.org/lib/show/19/DHT%20sensor%20library

pio run -t upload -> upload na esp

pio run -t uploadfs -> upload na mqtt

pio device monitor -> monitoruje ve VS code terminálu

mosquitto_pub -t homie/18fe34d8a419/switch/on/set -m "false" -> vypne ledku (true zapne)

mosquitto_sub -t "#" -v -> vypíše mqtt

sudo apt install mosquitto

sudo apt install mosquitto clients -> sub a pub

Ondřej Mikuš
