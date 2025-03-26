#include <Keypad.h>

// Define the number of rows and columns in the keypad
const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns

// Define the keymap
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Define row and column pins on the Arduino UNO
byte rowPins[ROWS] = {9, 8, 7, 6};  // Row pins connected to Arduino digital pins 9-6
byte colPins[COLS] = {5, 4, 3, 2};  // Column pins connected to Arduino digital pins 5-2

// Initialize the Keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600); // Start serial communication
  Serial.println("Keypad Ready");
}

void loop() {
  char key = keypad.getKey();
  
  if (key) {
    Serial.print("Key Pressed: ");
    Serial.println(key);
  }
}
