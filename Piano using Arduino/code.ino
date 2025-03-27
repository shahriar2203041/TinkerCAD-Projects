const int buzzer = 13;  // Buzzer connected to pin 13
const int buttons[8] = {2, 3, 4, 5, 6, 7, 8, 9};  // 8 Buttons from pin 2 to pin 9
const int tones[8] = {262, 294, 330, 349, 392, 440, 494, 523};  // Frequency of tones for each button

void setup() {
    pinMode(buzzer, OUTPUT);  // Set buzzer as output

    // Set each button pin as input with internal pull-up resistor
    for (int i = 0; i < 8; i++) {
        pinMode(buttons[i], INPUT_PULLUP);
    }
}

void loop() {
    bool buttonPressed = false;  // Flag to track button press

    for (int i = 0; i < 8; i++) {
        if (digitalRead(buttons[i]) == LOW) { // If button is pressed
            tone(buzzer, tones[i]);  // Play assigned tone
            buttonPressed = true;  // Mark that a button is pressed
            break;  // Stop checking other buttons (only one sound at a time)
        }
    }

    if (!buttonPressed) {
        noTone(buzzer);  // Stop buzzer when no button is pressed
    }
}
