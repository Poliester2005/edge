# Simulador de Medidor de Glicose no Sangue

## Visão Geral

Este é um projeto de simulador de medidor de glicose no sangue desenvolvido para o microcontrolador ESP32. O código Arduino simula leituras de glicose, utilizando um potenciômetro, e publica esses valores em um broker MQTT. As bibliotecas WiFi e PubSubClient para ESP32 são utilizadas para estabelecer uma conexão com uma rede WiFi específica e um broker MQTT. Os valores do potenciômetro são lidos de um pino analógico e publicados em um tópico MQTT em intervalos regulares.

## Requisitos de Hardware

- Microcontrolador ESP32
- Potenciômetro conectado ao pino analógico 34
- Acesso a uma rede WiFi

## Video de demonstração

- [Video](https://youtu.be/dqxhQ3M2JWg)

## Dependências

- [Biblioteca WiFi](https://github.com/espressif/arduino-esp32/tree/master/libraries/WiFi)
- [Biblioteca PubSubClient](https://github.com/knolleary/pubsubclient)

## Configuração

Antes de carregar o código para o ESP32, certifique-se de ajustar os seguintes parâmetros no código:

- **SSID**: Nome da sua rede WiFi.
- **PASSWORD**: Senha da sua rede WiFi.
- **BROKER_MQTT**: Endereço IP ou domínio do broker MQTT.
- **BROKER_PORT**: Porta do broker MQTT (o padrão é 1883).
- **TOPICO_PUBLISH_POT**: Tópico MQTT para publicar as simulações de leitura de glicose.

## Como Usar

1. Conecte o potenciômetro ao pino analógico 34 no ESP32.
2. Configure as credenciais da WiFi e as informações do broker MQTT no código.
3. Envie o código para o ESP32 usando o Arduino IDE ou outra plataforma compatível.
4. Abra o Serial Monitor para visualizar o status de conexão do ESP32 e as simulações de leitura de glicose.
5. O ESP32 se conectará à rede WiFi especificada e ao broker MQTT.
6. As simulações de leitura de glicose serão realizadas e publicadas no tópico MQTT especificado a cada segundo.

## Saída do Serial Monitor

O Serial Monitor exibirá as seguintes informações:

- Status de conexão com a rede WiFi.
- Endereço IP local do ESP32 após conectar-se com sucesso à rede WiFi.
- Simulações de leitura de glicose sendo publicadas no formato de voltagem no broker MQTT.

## Observação

- Certifique-se de que as bibliotecas necessárias estejam instaladas no seu Arduino IDE.
- Ajuste o pino analógico e outros parâmetros conforme necessário.
- Este projeto assume que o broker MQTT não possui medidas de segurança (nome de usuário/senha). Modifique conforme necessário para conexões seguras.

---

**Feito por:**

- Eduardo Pielich Sanchez RM: 99767
- Renato Izumi Ichikawa RM: 99242
