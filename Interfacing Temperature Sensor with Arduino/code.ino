// Define LM35 sensor pin
const int sensorPin = A0;  // LM35 output connected to A0

void setup() {
  Serial.begin(9600);  // Start Serial Monitor
}

void loop() {
  // Read the analog voltage from LM35
  int sensorValue = analogRead(sensorPin);
  
  // Convert to Temperature in Celsius
  float voltage = sensorValue * (5.0 / 1023.0);
  float temperatureC = voltage * 100.0;

  // Convert to Fahrenheit
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;

  // Print temperature to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.print("°C  |  ");
  Serial.print(temperatureF);
  Serial.println("°F");

  delay(2000); // Wait before next reading
}
