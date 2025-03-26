#include <Keypad.h>
#include <LiquidCrystal.h>

// Define the keypad rows and columns
const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns

// Define the keymap
char keys[ROWS][COLS] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', '*'},
  {'C', '0', '=', '/'}
};

// Define row and column pins on the Arduino
byte rowPins[ROWS] = {4, 5, 6, 7};
byte colPins[COLS] = {0, 1, 2, 3};

// Initialize the Keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Define the LCD pins (DB4-DB7 -> 11, 10, 9, 8)
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

String input = "";
char operatorSymbol;
float num1 = 0, num2 = 0;
bool operatorSelected = false;

void setup() {
  lcd.begin(16, 2); // Initialize the LCD (16x2 display)
  lcd.print("Calculator Ready");
  delay(1000);
  lcd.clear();
}

void loop() {
  char key = keypad.getKey();
  
  if (key) {
    if (key >= '0' && key <= '9') {
      input += key;
      lcd.print(key);
    } else if (key == '+' || key == '-' || key == '*' || key == '/') {
      if (!operatorSelected && input.length() > 0) {
        num1 = input.toFloat();
        operatorSymbol = key;
        operatorSelected = true;
        input = "";
        lcd.print(key);
      }
    } else if (key == '=') {
      if (operatorSelected && input.length() > 0) {
        num2 = input.toFloat();
        float result = 0;
        switch (operatorSymbol) {
          case '+': result = num1 + num2; break;
          case '-': result = num1 - num2; break;
          case '*': result = num1 * num2; break;
          case '/': result = (num2 != 0) ? num1 / num2 : 0; break;
        }
        lcd.clear();
        lcd.print("Result: ");
        lcd.setCursor(0, 1);
        lcd.print(result);
        delay(2000);
        resetCalculator();
      }
    } else if (key == 'C') {
      resetCalculator();
    }
  }
}

void resetCalculator() {
  input = "";
  num1 = num2 = 0;
  operatorSelected = false;
  lcd.clear();
}
