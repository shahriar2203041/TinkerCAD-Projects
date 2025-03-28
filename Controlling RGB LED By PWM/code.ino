int rp = 11;
int bp = 10;
int gp = 9;

void setup() {
    pinMode(rp, OUTPUT);
    pinMode(bp, OUTPUT);
    pinMode(gp, OUTPUT);
}

void loop() {
    color(255, 0, 0);  // Red
    delay(500);
    color(0, 255, 0);  // Green
    delay(500);
    color(0, 0, 255);  // Blue
    delay(500);
    color(255, 255, 255);  // White
    delay(500);
    color(0, 0, 0);  // LED off
    delay(500);
}

void color(unsigned char red, unsigned char green, unsigned char blue) {
    analogWrite(rp, red);
    analogWrite(gp, green);
    analogWrite(bp, blue);
}
