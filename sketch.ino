#include <WiFi.h>
#include <PubSubClient.h>

const char* SSID = "Wokwi-GUEST";
const char* PASSWORD = "";
const char* BROKER_MQTT = "46.17.108.113";
int BROKER_PORT = 1883;

WiFiClient espClient;
PubSubClient MQTT(espClient);

const int potPin = 34;  // Porta analógica onde o potenciômetro está conectado
#define TOPICO_PUBLISH_POT "/TEF/lamp120/potenciometro"

void publishPotValue();

void setup() {
    Serial.begin(115200);

    pinMode(potPin, INPUT);

    delay(10);
    Serial.println("------Conexao WI-FI------");
    Serial.print("Conectando-se na rede: ");
    Serial.println(SSID);
    Serial.println("Aguarde");

    WiFi.begin(SSID, PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
        delay(100);
        Serial.print(".");
    }

    Serial.println();
    Serial.print("Conectado com sucesso na rede ");
    Serial.print(SSID);
    Serial.println("IP obtido: ");
    Serial.println(WiFi.localIP());
    
    MQTT.setServer(BROKER_MQTT, BROKER_PORT);
}

void loop() {
    publishPotValue();
    delay(1000);
    MQTT.loop();
}

void publishPotValue() {
    int potValue = analogRead(potPin);
    float potVoltage = potValue / 4095.0 * 255;
    char potValueStr[10];
    dtostrf(potVoltage, 4, 2, potValueStr);
    Serial.println(potVoltage);
    MQTT.publish(TOPICO_PUBLISH_POT, potValueStr);
}
