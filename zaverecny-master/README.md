Meteostanice

Jak to bude fungovat...

Cílem bude sběr dat z čidel - vlhkost, teplota do mqtt serveru (pokud možno s použitím protokolu mqtt ssl) Použité prvky:esp8266, Použité technologie: homie framework img VB -ide vsCode, platformio ukázat jak funguje komunikace

posílaní přes json -> zapni/vypni topení

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

