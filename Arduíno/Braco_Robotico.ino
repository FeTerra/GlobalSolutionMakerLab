#include <Servo.h>

// Servos
Servo servoBraco;
Servo servoGarra;

// Pinos
const int PINO_SERVO_BRACO = 9;
const int PINO_SERVO_GARRA = 10;
const int PINO_LED_STATUS = 13;

// Ângulos iniciais
int anguloBraco = 90;
int anguloGarra = 90;

void setup() {
  Serial.begin(9600);

  servoBraco.attach(PINO_SERVO_BRACO);
  servoGarra.attach(PINO_SERVO_GARRA);

  pinMode(PINO_LED_STATUS, OUTPUT);

  servoBraco.write(anguloBraco);
  servoGarra.write(anguloGarra);

  digitalWrite(PINO_LED_STATUS, LOW);

  Serial.println("Sistema iniciado - Braco Robotico Docking & Retrieval");
  Serial.println("Comandos:");
  Serial.println("U = Up / subir o braco");
  Serial.println("D = Down / descer o braco");
  Serial.println("O = Open / abrir a garra");
  Serial.println("C = Close / fechar a garra");
}

void loop() {
  if (Serial.available() > 0) {
    char comando = Serial.read();

    if (comando == 'U' || comando == 'u') {
      anguloBraco = 45;
      servoBraco.write(anguloBraco);
      indicarStatus();
      Serial.println("Comando U executado: braco elevado.");
    }

    else if (comando == 'D' || comando == 'd') {
      anguloBraco = 130;
      servoBraco.write(anguloBraco);
      indicarStatus();
      Serial.println("Comando D executado: braco abaixado.");
    }

    else if (comando == 'O' || comando == 'o') {
      anguloGarra = 20;
      servoGarra.write(anguloGarra);
      indicarStatus();
      Serial.println("Comando O executado: garra aberta.");
    }

    else if (comando == 'C' || comando == 'c') {
      anguloGarra = 90;
      servoGarra.write(anguloGarra);
      indicarStatus();
      Serial.println("Comando C executado: garra fechada.");
    }

    else {
      Serial.println("Comando invalido. Use apenas U, D, O ou C.");
    }
  }
}

// LED de status indica que um comando foi recebido
void indicarStatus() {
  digitalWrite(PINO_LED_STATUS, HIGH);
  delay(1000);
  digitalWrite(PINO_LED_STATUS, LOW);
}