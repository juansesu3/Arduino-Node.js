int switchState = 0;

void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
  Serial.begin(9600);  // Iniciar la comunicación serial a 9600 bps
}

void loop() {
  int currentSwitchState = digitalRead(2);

  // Si el estado del interruptor cambia, actualiza y envía datos
  if (currentSwitchState != switchState) {
    switchState = currentSwitchState;

    if (switchState == LOW) {
      digitalWrite(3, HIGH);  // LED verde
      digitalWrite(4, LOW);   // LED rojo
      digitalWrite(5, LOW);   // LED rojo
      Serial.println("SwitchState: LOW");  // Enviar estado al puerto serial
    } else {
      digitalWrite(3, LOW);   // LED verde
      digitalWrite(4, LOW);   // LED rojo
      digitalWrite(5, HIGH);  // LED rojo
      delay(250);
      digitalWrite(4, HIGH);  // LED rojo
      digitalWrite(5, LOW);   // LED rojo
      delay(250);
      Serial.println("SwitchState: HIGH"); // Enviar estado al puerto serial
    }
  }
}