// Define pins
const int tempSensorPin = A0;  // Temperature sensor connected to A1
const int gasSensorPin = A1;   // Gas sensor connected to A0
const int buzzerPin = 7;       // Buzzer connected to pin 7
const int ledPin = 13;         // LED connected to pin 13

// Threshold values
const int gasThreshold = 300;      // Gas limit
const float tempThreshold = 40.0;  // Temperature limit in °C

void setup() {
    pinMode(buzzerPin, OUTPUT);
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);  // Start Serial Monitor
    delay(5000);  // Allow sensors to stabilize
}

void loop() {
    // Read temperature sensor value
    int tempValue = analogRead(tempSensorPin);
    float temperature = (tempValue / 1023.0) * 5.0 * 100; // Convert to °C

    // Read gas sensor value
    int gasValue = analogRead(gasSensorPin);

    // Print values to Serial Monitor
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");

    Serial.print("Gas Sensor Value: ");
    Serial.println(gasValue);

    // If both sensors are working, apply conditions
    if (gasValue > gasThreshold) {
        digitalWrite(buzzerPin, HIGH);
        digitalWrite(ledPin, HIGH);
        Serial.println("⚠ GAS ALERT! Buzzer & LED ON ⚠");
        delay(500);
        digitalWrite(buzzerPin, LOW);
        delay(500);
    } 
    else if (temperature > tempThreshold) {
        digitalWrite(buzzerPin, HIGH);
        digitalWrite(ledPin, HIGH);
        Serial.println("🔥 HIGH TEMP ALERT! Buzzer & LED ON 🔥");
        delay(1000);
        digitalWrite(buzzerPin, LOW);
    } 
    else {
        digitalWrite(buzzerPin, LOW);
        digitalWrite(ledPin, LOW);
        Serial.println("✅ Safe - Buzzer & LED OFF");
    }

    delay(2000); // Allow simulation to update values properly
}


