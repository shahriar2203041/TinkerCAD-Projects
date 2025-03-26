#include <IRremote.hpp>

#define IR_PIN 12  // IR Receiver connected to pin 12
#define BLUE_LED 2
#define ORANGE_LED 3
#define GREEN_LED 4

void setup() {
    Serial.begin(9600);
    IrReceiver.begin(IR_PIN, ENABLE_LED_FEEDBACK);  // Start the IR receiver

    pinMode(BLUE_LED, OUTPUT);
    pinMode(ORANGE_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);
}

void loop() {
    if (IrReceiver.decode()) {
        int command = IrReceiver.decodedIRData.command; // Get received command
        Serial.print("Received Command: ");
        Serial.println(command); // Print the command for debugging
        
        switch (command) {
            case 10: // Change these values based on Serial Monitor output
                digitalWrite(BLUE_LED, HIGH);
                break;
            case 11:
                digitalWrite(BLUE_LED, LOW);
                break;
            case 12:
                digitalWrite(ORANGE_LED, HIGH);
                break;
            case 13:
                digitalWrite(ORANGE_LED, LOW);
                break;
            case 14:
                digitalWrite(GREEN_LED, HIGH);
                break;
            case 15:
                digitalWrite(GREEN_LED, LOW);
                break;
            default:
                Serial.println("Unknown command");
                break;
        }
        
        IrReceiver.resume(); // Continue receiving next signal
    }
}
