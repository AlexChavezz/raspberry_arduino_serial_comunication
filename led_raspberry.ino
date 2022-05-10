char value;

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
}

void loop() {
  if (Serial.available()){value = Serial.read();}
  if(value == 'A'){
    digitalWrite(2, HIGH);
  }else{
    digitalWrite(5, HIGH);
  }
}
