#include <LiquidCrystal.h>

// Initialize the LCD with the interface pins (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Voltage divider resistors
float R1 = 90900.0;  // 90.9kΩ
float R2 = 10000.0;  // 10kΩ

void setup() {
    Serial.begin(9600); // Start serial communication
    lcd.begin(16, 2);   // Initialize LCD (16 columns, 2 rows)
    lcd.print("Digital Voltmeter"); // Display title on LCD
    delay(2000);  // Wait 2 seconds
    lcd.clear();  // Clear the display
}

void loop() {
    int analog_value = analogRead(A0); // Read input from A0
    float temp = (analog_value * 5.0) / 1023.0;  // Convert to voltage
    float voltage = temp / (R2 / (R1 + R2)); // Calculate actual voltage

    // Display on LCD
    lcd.setCursor(0, 0);
    lcd.print("Voltage: ");
    lcd.print(voltage);
    lcd.print("V ");

    // Print to Serial Monitor
    Serial.print("Voltage: ");
    Serial.print(voltage);
    Serial.println(" V");

    delay(500); // Wait before next reading
}
