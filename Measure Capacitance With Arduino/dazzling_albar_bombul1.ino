// Pin Definitions
const int analogPin = A0;  // Analog pin to read capacitor voltage
const int chargePin = 13;  // Charge the capacitor
const int dischargePin = 11;  // Discharge the capacitor
const int resistorValue = 10000;  // 10kΩ resistor

// Timer Variables
unsigned long startTime;
unsigned long elapsedTime;

// Capacitance Variables
float microFarads;
float nanoFarads;

void setup() {
  Serial.begin(9600);
  pinMode(chargePin, OUTPUT);
  digitalWrite(chargePin, LOW);
  pinMode(dischargePin, OUTPUT);
  digitalWrite(dischargePin, LOW);
}

void loop() {
  // Step 1: Fully Discharge the Capacitor
  Serial.println("\nDischarging Capacitor...");
  pinMode(dischargePin, OUTPUT);
  digitalWrite(dischargePin, LOW);
  delay(500); // Wait for complete discharge
  pinMode(dischargePin, INPUT);  // Stop discharging

  // Step 2: Start Charging the Capacitor
  Serial.println("Starting to Charge...");
  digitalWrite(chargePin, HIGH);
  startTime = millis();  // Start timing

  // Step 3: Wait for the capacitor to reach 63.2% of 5V (≈3.16V)
  while (analogRead(analogPin) < 648) { 
    int voltageReading = analogRead(analogPin);
    float voltage = (voltageReading / 1023.0) * 5.0;  // Convert to voltage
    Serial.print("Voltage: "); Serial.print(voltage); Serial.println("V");
    delay(50);
  }

  // Step 4: Calculate Charge Time
  elapsedTime = millis() - startTime;
  digitalWrite(chargePin, LOW);  // Stop charging

  // Step 5: Calculate Capacitance using C = T / R
  microFarads = ((float)elapsedTime / resistorValue) * 1000;

  // Step 6: Print Results
  Serial.print("Charge Time: ");
  Serial.print(elapsedTime);
  Serial.print(" ms | Capacitance: ");

  if (microFarads > 1) {
    Serial.print(microFarads);
    Serial.println(" µF");
  } else {
    nanoFarads = microFarads * 1000;
    Serial.print(nanoFarads);
    Serial.println(" nF");
  }

  // Step 7: Discharge Capacitor Before Next Measurement
  Serial.println("Discharging Capacitor...");
  pinMode(dischargePin, OUTPUT);
  digitalWrite(dischargePin, LOW);
  while (analogRead(analogPin) > 0) {
    // Wait for capacitor to fully discharge
  }
  
  Serial.println("Capacitor Discharged. Ready for next measurement.");
  delay(1000);
}
