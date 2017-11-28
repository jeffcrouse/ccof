#include <ClickEncoder.h>
#include <TimerOne.h>

ClickEncoder *encoder;
int16_t last, value;

void timerIsr() {
  encoder->service();
}

void setup() {
  Serial.begin(9600);
  encoder = new ClickEncoder(A1, A0, A2);
  encoder->setAccelerationEnabled(true);
  Timer1.initialize(1000);
  Timer1.attachInterrupt(timerIsr);
  last = -1;
}



void loop() {
  int value = encoder->getValue();
  if (value != 0) {
    Serial.print(value);
    Serial.print("\n");
  }

  //  if (value != last) {
  //    last = value;
  //    Serial.print(value);
  //    Serial.print("\n");
  //  }

  ClickEncoder::Button b = encoder->getButton();
  if (b != ClickEncoder::Open) {
    switch (b) {
      //case ClickEncoder::Pressed:       Serial.println("Pressed");        break;
      //case ClickEncoder::Held:          Serial.println("Held");           break;
      //case ClickEncoder::Released:      Serial.println("Released");       break;
      case ClickEncoder::Clicked:       Serial.print("Clicked\n");        break;
      case ClickEncoder::DoubleClicked: Serial.print("DoubleClicked\n");  break;
    }
  }
}

