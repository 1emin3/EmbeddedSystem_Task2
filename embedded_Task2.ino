int xPin = A0;
int yPin = A1;
int buttonPin = 2;

int xVal;
int yVal;
int buttonState;

int upLed = 10;
int downLed = 9;
int leftLed = 11;
int rightLed = 6;
int upBrightness;
int downBrightness;
int leftBrightness;
int rightBrightness;


void setup() {
  Serial.begin(9600);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(upLed, OUTPUT);
  pinMode(downLed, OUTPUT);
  pinMode(leftLed, OUTPUT);
  pinMode(rightLed, OUTPUT);
}

void loop() {
  xVal = analogRead(xPin);
  yVal = analogRead(yPin);
  buttonState = digitalRead(buttonPin);

  upBrightness = map(yVal, 480, 0, 0, 255);
  downBrightness = map(yVal, 498, 1023, 0, 255);
  leftBrightness = map(xVal, 500, 0, 0, 255);
  rightBrightness = map(xVal, 520, 1023, 0, 255);

  if (yVal <= 480) {
    analogWrite(upLed, upBrightness);  
  }

  if (yVal >= 498) {
    analogWrite(downLed, downBrightness);
  }

  if (xVal <= 500) {
    analogWrite(leftLed, leftBrightness);
  }

  if (xVal >= 520) {
    analogWrite(rightLed, rightBrightness);
  }

  if (yVal > 480 && yVal < 498 && xVal > 500 && xVal < 520) {
    analogWrite(upLed, 0);
    analogWrite(downLed, 0);
    analogWrite(leftLed, 0);
    analogWrite(rightLed, 0);
  }

  if(buttonState == LOW) {
    digitalWrite( upLed, HIGH);
    digitalWrite( downLed, HIGH);
    digitalWrite( leftLed, HIGH);
    digitalWrite( rightLed, HIGH);
  }
  // target = map(source, sourceLow, sourceHigh, targerLow, targetHigh)
}
