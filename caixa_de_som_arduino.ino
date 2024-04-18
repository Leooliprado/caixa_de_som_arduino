#include "DFRobotDFPlayerMini.h"

#define pinBot1 7
#define pinBot2 6
#define pinBot3 5
#define pinBot4 2
#define pinLDR 34
#define pinSensor 35

#define volumeMP3 30

DFRobotDFPlayerMini playerMP3;

void setup() {
  Serial.begin(9600);
  Serial2.begin(9600, SERIAL_8N1, 16, 17); // Inicializa a comunicação serial com o DFPlayer Mini (TX pin 17, RX pin 16)

  pinMode(pinBot1, INPUT_PULLUP);
  pinMode(pinBot2, INPUT_PULLUP);
  pinMode(pinBot3, INPUT_PULLUP);
  pinMode(pinBot4, INPUT_PULLUP);

  Serial.println();
  Serial.println(F("Iniciando DFPlayer ... (Espere 3~5 segundos)"));

  if (!playerMP3.begin(Serial2)) {
    Serial.println(F("Falha ao iniciar:"));
    Serial.println(F("1.Confira as conexões!"));
    Serial.println(F("2.Confira o cartão SD!"));
    while (true) {
      delay(0);
    }
  }

  Serial.println(F("DFPlayer ligado!"));

  playerMP3.volume(volumeMP3);

#ifdef DEBUG
  Serial.println("Fim Setup");
#endif
  playerMP3.playFolder(2, 3);
}

void loop() {
  if (digitalRead(pinBot1) == LOW) {
    playerMP3.playFolder(1, 1);
    Serial.println("Tocando pasta 01, musica 001");
    delay(1000);
  }
  if (digitalRead(pinBot2) == LOW) {
    playerMP3.playFolder(1, 2);
    Serial.println("Tocando pasta 01, musica 002");
    delay(1000);
  }
  if (digitalRead(pinBot3) == LOW) {
    playerMP3.playFolder(1, 3);
    Serial.println("Tocando pasta 01, musica 003");
    delay(1000);
  }
  if (digitalRead(pinLDR) == HIGH) {
    playerMP3.playFolder(2, 1);
    Serial.println("Tocando pasta 02, musica 001");
    delay(1000);
  }
  if (digitalRead(pinSensor) == LOW) {
    playerMP3.playFolder(2, 1);
    Serial.println("Tocando pasta 02, musica 001");
    delay(1000);
  }
  if (digitalRead(pinBot4) == LOW) {
    playerMP3.playFolder(2, 2);
    Serial.println("Tocando pasta 02, musica 002");
    delay(1000);
  }
}
