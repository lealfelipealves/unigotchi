
#include <Ultrasonic.h>
#include <ArduinoJson.h>
#include <SPI.h>
#include <Ethernet.h>

// --------------------------------------------
// Define as portas
// --------------------------------------------

// Buzzer
#define PINO_BUZZER   12  // Porta do Buzzer

// Led Indicadores
#define LED_LIFE      11  // LED AMARELO
#define LED_EAT       10  // LED VERDE
#define LED_FUN       9   // LED AZUL 1
#define LED_SLEEP     5   // LED AZUL 2

// Ultrasom
#define PINO_TRIGGER  6   //Porta ligada ao pino Trigger do sensor
#define PINO_ECHO     7   //Porta ligada ao pino Echo do sensor


// Botões
#define BTN_RESET     3  // BTN FIO ROSA
#define BTN_MENU      2  // BTN FIO AMARELO


// --------------------------------------------
// [Sensor Ultrasonico] - Inicializa 
// --------------------------------------------
Ultrasonic ultrasonic(PINO_TRIGGER, PINO_ECHO);

// --------------------------------------------
// [Ethernet] - Inicializa 
// --------------------------------------------
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; // Definicoes de IP, mascara de rede e gateway

//IPAddress ip(192,168,100,45);           // Define o endereco IP
//IPAddress gateway(192,168,100,1);       // Define o gateway
//IPAddress subnet(255, 255, 255, 0);     // Define a máscara de rede

EthernetServer server(80); // Inicializa o servidor web na porta 80

// --------------------------------------------
// [Variaveis] -  
// --------------------------------------------

int counter = 0;

void setup() {
  // Inicializa Serial Port
  Serial.begin(9600);
  while (!Serial) continue;
  
  // Verifica Inicilização da interface 
  if (!Ethernet.begin(mac)) {
    Serial.println(F("Falha ao inicizalizar biblioteca da interface de rede"));
    return;
  }

  // Inicializa a interface de rede
  server.begin();

  // Definindo o pino BUZZER como de saída.
  pinMode(PINO_BUZZER, OUTPUT);

  // Definindo os pinos de LED como de saída.
  pinMode(LED_LIFE,   OUTPUT);
  pinMode(LED_EAT,    OUTPUT);
  pinMode(LED_FUN,    OUTPUT);
  pinMode(LED_SLEEP,  OUTPUT);

  // Definindo os pinos de btn como de entrada.
  pinMode(BTN_RESET, INPUT);
  pinMode(BTN_MENU, INPUT);
  
  Serial.println(F("Servidor pronto."));
  Serial.print(F("Por gentileza, conecte ao http://"));
  Serial.println(Ethernet.localIP());
}

void loop() {
  float cmMsec;
  int ledLife = 255;
  int ledEat = 255;
  int ledFun = 255;
  int ledSleep = 255;
  
  long microsec = ultrasonic.timing();

  
  // Le e armazena as informacoes do sensor ultrasonico
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);

  if(digitalRead(BTN_RESET) == HIGH) { 
    Serial.println("BTN_RESET");
  }

  if(digitalRead(BTN_MENU) == HIGH) {
    btnMenu();
    delay(200);
  }

  Serial.println(cmMsec);
  Serial.println(counter);

  // Aguarda conexao do browser
  /*EthernetClient client = server.available();

  if (!client) return;
  Serial.println(F("Novo Cliente."));
  client.println();*/

  
/*
  while (client.available()) client.read();
  
  analogWrite(LED_EAT, ledLife);
  
  StaticJsonDocument<200> doc;
  doc["sensor"] = cmMsec;
  serializeJson(doc, Serial);
                       
  // Write response headers
  client.println("HTTP/1.0 200 OK");
  client.println("Content-Type: application/json");
  client.println();
  serializeJsonPretty(doc, client);
  client.stop();*/
}

void btnMenu() {
  selectOption(counter);
  counter++;
  if(counter > 4) {
    counter = 0;
  }
}

void setAllLeds(int value) {
  analogWrite(LED_LIFE, value);
  analogWrite(LED_EAT, value);
  analogWrite(LED_FUN, value);
  analogWrite(LED_SLEEP, value);
}

void selectOption(int value) {
  setAllLeds(0);
  switch(value) {
    case 0:
      analogWrite(LED_LIFE, 255);
      tone(PINO_BUZZER, 262, 200);
      break;
    case 1:
      analogWrite(LED_EAT, 255);
      tone(PINO_BUZZER, 294, 300);
      break;
    case 2:
      analogWrite(LED_FUN, 255);
      tone(PINO_BUZZER, 330, 300);
      break;
    case 3:
      analogWrite(LED_SLEEP, 255);
      tone(PINO_BUZZER, 349, 300);
      break;
    case 4:
      setAllLeds(255);
      tone(PINO_BUZZER, 262, 200);
      delay(200);
      tone(PINO_BUZZER, 294, 300);
      delay(200);
      tone(PINO_BUZZER, 330, 300);
      delay(200);
      tone(PINO_BUZZER, 349, 300);
      delay(300);
      break;
    default:
      setAllLeds(0);
      break;
  }
}
