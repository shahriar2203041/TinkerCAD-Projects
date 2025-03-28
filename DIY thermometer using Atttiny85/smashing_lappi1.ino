#define SENSOR_PIN A1  // PB2 (Analog input from TMP36)
#define LED_PIN 0      // PB0 (LED output)

float realDegree = 0.0;

void setup() {
    pinMode(LED_PIN, OUTPUT);
    realDegree = 0.0;
}

void loop() {
    int degree = analogRead(SENSOR_PIN);
    realDegree = (degree / 1024.0) * 5.0;  // Convert to voltage (0-5V)
    float tempC = (realDegree - 0.5) * 100; // Convert voltage to temperature in Celsius
    float tempF = (tempC * 9.0 / 5.0) + 32.0; // Convert Celsius to Fahrenheit

    if (tempC < 20) {
        digitalWrite(LED_PIN, LOW); // LED off for low temperatures
    } else if (tempC >= 20 && tempC < 30) {
        digitalWrite(LED_PIN, HIGH); // LED remains steady for moderate temperatures
    } else if (tempC >= 30 && tempC < 40) {
        digitalWrite(LED_PIN, HIGH);
        delay(500);
        digitalWrite(LED_PIN, LOW);
        delay(500); // Slow blink for warm temperatures
    } else {
        digitalWrite(LED_PIN, HIGH);
        delay(200);
        digitalWrite(LED_PIN, LOW);
        delay(200); // Fast blink for high temperatures
    }
}
