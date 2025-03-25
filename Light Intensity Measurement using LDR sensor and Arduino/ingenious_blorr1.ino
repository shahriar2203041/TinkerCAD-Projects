// Define Pins
const int ldrPin = A0;  // LDR connected to Analog Pin A0
const int ledPin = 9;   // LED connected to Digital Pin 9
const int threshold = 600; // Adjust based on simulation

void setup() {
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);  // Start serial communication
}

void loop() {
    int ldrValue = analogRead(ldrPin); // Read LDR sensor value

    // Print LDR value to Serial Monitor
    Serial.print("LDR Value: ");
    Serial.println(ldrValue);

    // Light Condition Check
    if (ldrValue < threshold) {  // Low light detected
        digitalWrite(ledPin, HIGH);
        Serial.println("🌙 DARK - LED ON");
    } else {  // Bright light detected
        digitalWrite(ledPin, LOW);
        Serial.println("☀ BRIGHT - LED OFF");
    }

    delay(1000);  // Wait before next reading
}
