// Define pins
const int trigPin = 10; // Trigger pin connected to Arduino pin 10
const int echoPin = 9;  // Echo pin connected to Arduino pin 9

void setup() {
    pinMode(trigPin, OUTPUT); // Set trigPin as output
    pinMode(echoPin, INPUT);  // Set echoPin as input
    Serial.begin(9600);       // Start serial communication
}

void loop() {
    // Clear the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    
    // Send a 10-microsecond pulse to trigger the sensor
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    // Read the echoPin, returns the sound wave travel time in microseconds
    long duration = pulseIn(echoPin, HIGH);
    
    // Calculate the distance (speed of sound = 0.034 cm/microsecond)
    float distance = duration * 0.034 / 2;
    
    // Print the distance to the Serial Monitor
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    
    delay(500); // Wait for half a second before the next measurement
}

