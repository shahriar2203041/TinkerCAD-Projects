const int potPin = A0;  // Potentiometer wiper connected to analog pin A0

void setup() {
  Serial.begin(9600);  // Initialize Serial Monitor
}

void loop() {
  int potValue = analogRead(potPin);  // Read potentiometer value (0-1023)
  Serial.print("Potentiometer Value: ");
  Serial.println(potValue);  // Print the value
  delay(500);  // Small delay
}
