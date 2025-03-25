#include <Keypad.h>

// Define Keypad
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Password Variables
String password = "1234";  // Set your 4-digit password
String input = "";

// LED & Buzzer Pins
const int redLED = 10;
const int greenLED = 11;
const int buzzer = 12;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  Serial.println("System Ready! Enter 4-digit Password:");
}

void loop() {
  char key = keypad.getKey();

  if (key) {  // If a key is pressed
    Serial.print("Key Pressed: ");
    Serial.println(key);

    if (key == '*') {  // Clear input if '*' is pressed
      input = "";
      Serial.println("Input Cleared ❌");
      return;
    }

    if (key == '#') {  // Check password only when 4 digits are entered
      if (input.length() == 4) {  
        if (input == password) {
          Serial.println("✅ Correct Password! Access Granted.");
          digitalWrite(greenLED, HIGH);
          tone(buzzer, 1000);
          delay(1000);
          noTone(buzzer);
          digitalWrite(greenLED, LOW);
        } else {
          Serial.println("❌ Incorrect Password! Access Denied.");
          
          // **Blink red LED & sound buzzer multiple times**
          for (int i = 0; i < 3; i++) {
            digitalWrite(redLED, HIGH);
            tone(buzzer, 500);
            delay(300);
            digitalWrite(redLED, LOW);
            noTone(buzzer);
            delay(300);
          }
        }
        input = "";  // Reset input after checking
        Serial.println("Enter 4-digit Password Again:");
      } else {
        Serial.println("⚠ Enter full 4-digit password first!");
      }
      return;
    }

    // Append pressed key to input string only if it's a number and length is < 4
    if (isdigit(key) && input.length() < 4) {
      input += key;
      Serial.print("Current Input: ");
      Serial.println(input);
    } else if (!isdigit(key)) {
      Serial.println("⚠ Only digits are allowed!");
    }
  }
}

