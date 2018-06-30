const int buttonPin = 2;
const int ledPin = 13;
const int otherLedPin = 12;
int buttonState;
void setup() {

  pinMode(ledPin, OUTPUT) ;
  pinMode(otherLedPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop ()  {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
  digitalWrite(ledPin, HIGH);
  digitalWrite(otherLedPin, LOW);
  } else {
    digitalWrite(ledPin,LOW);
    digitalWrite(otherLedPin, HIGH);
  }
}
