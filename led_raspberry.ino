//Variables asociadas a los dos LEDs que se van a controlar
int rel_1 = 2, rel_2 = 3, rel_3 = 4, rel_4 = 5, rel_LucesDelanteras = 8, rel_LucesTraseras = 9;

int valor; //Variable para indicar que llega una orden

void setup() {

  pinMode(rel_1, OUTPUT);
  pinMode(rel_2, OUTPUT);
  pinMode(rel_3, OUTPUT);
  pinMode(rel_4, OUTPUT);
  pinMode(rel_LucesDelanteras, OUTPUT);
  pinMode(rel_LucesTraseras, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  if (Serial.available()) //Si el puerto serie (Bluetooth) está disponible
  {
    valor = Serial.read(); //Lee el dato entrante via Bluetooth
    Serial.println(valor);
    if (valor == 'A') {
      adelante();
    }
    if (valor == 'B') {
      reversa();
      LucesTracerasOn();
      delay(1000);
      LucesTrecerasOff();
    }
    if (valor == 'R') {
      derecha();
    }
    if (valor == 'L') {
      izquierda();
    }
    if (valor == 'W') {
      //LucesON();
    }
    if (valor == 'Q') {
      LucesOFF();
    }
    if (valor == 'S') {
      alto();
    }
    if (valor == 'E') {
      LucesTracerasOn();
    }
    if (valor == 'D') {
      LucesTrecerasOff();
    }
  }
}

void LucesON() {
  digitalWrite(rel_LucesDelanteras, HIGH);
}
void LucesOFF() {
  digitalWrite(rel_LucesDelanteras, LOW);
}
void LucesTracerasOn() {
  digitalWrite(rel_LucesTraseras, HIGH);
}
void LucesTrecerasOff() {
  digitalWrite(rel_LucesTraseras, LOW);
}

void reversa() {
  digitalWrite(rel_1, HIGH);
  digitalWrite(rel_2, LOW);
  digitalWrite(rel_3, LOW);
  digitalWrite(rel_4, HIGH);

}
void adelante() {
  digitalWrite(rel_1, LOW);
  digitalWrite(rel_2, HIGH);
  digitalWrite(rel_3, HIGH);
  digitalWrite(rel_4, LOW);

}
void derecha() {
  digitalWrite(rel_1, HIGH);
  digitalWrite(rel_2, LOW);
  digitalWrite(rel_3, HIGH);
  digitalWrite(rel_4, LOW);
}

void izquierda() {
  digitalWrite(rel_1, LOW);
  digitalWrite(rel_2, HIGH);
  digitalWrite(rel_3, LOW);
  digitalWrite(rel_4, HIGH);
}
void alto() {
  digitalWrite(rel_1, LOW);
  digitalWrite(rel_2, LOW);
  digitalWrite(rel_3, LOW);
  digitalWrite(rel_4, LOW);
}
