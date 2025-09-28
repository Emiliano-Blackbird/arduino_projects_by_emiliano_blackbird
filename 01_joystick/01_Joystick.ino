// C++ code
int EjeX;       // Variable del potenciómetro horizontal
int EjeY;       // Variable del potenciómetro vertical
bool Pulsador;  // Variable del pulsador (true/false)

void setup() {
  pinMode(2, INPUT_PULLUP);    // Activo resistencia Pull-Up integrada
  Serial.begin(9600);          // Comunicación con monitor serie
}

void loop() {
  // Lectura de valores de potenciómetros X e Y
  EjeX = analogRead(A0);       // mejor usar A0, A1
  EjeY = analogRead(A1);
  Pulsador = digitalRead(2);

  // Valores en monitor serie
  Serial.print("X -> ");
  Serial.print(EjeX);
  Serial.print("\tY -> ");
  Serial.print(EjeY);
  Serial.print("\tPulsador -> ");
  Serial.println(Pulsador);

  delay(100);  // un pequeño delay para no saturar el puerto serie
}
