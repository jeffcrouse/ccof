#include <ClickEncoder.h>
#include <TimerOne.h>

ClickEncoder *encoder;


void timerIsr() {
  encoder->service();
}

void setup() {
  Serial.begin(9600);
  encoder = new ClickEncoder(A1, A0, A2);
  encoder->setAccelerationEnabled(true);

  Timer1.initialize(100);
  Timer1.attachInterrupt(timerIsr);
}


void loop() {
  int value = encoder->getValue();
  if (value != 0) {
    Serial.print("move ");
    Serial.print(value);
    Serial.print("\n");
  }

  
  ClickEncoder::Button b = encoder->getButton();
  if (b == ClickEncoder::Clicked) {
    Serial.print("click 1\n");
  }
  if (b == ClickEncoder::DoubleClicked) {
    Serial.print("click 2\n");
  }
}

