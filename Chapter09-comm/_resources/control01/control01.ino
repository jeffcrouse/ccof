#define NUM_PINS 4
#define SERIAL_BUF_SIZE 32

int relay_pins[NUM_PINS] = {7, 6, 5, 4};
char on_command[NUM_PINS] = {'a', 'b', 'c', 'd'};
char off_command[NUM_PINS] = {'e', 'f', 'g', 'h'};


void setup() {
  Serial.begin(9600);
  for (int i = 0; i < NUM_PINS; i++) {
    pinMode(relay_pins[i], OUTPUT);
    digitalWrite(relay_pins[i], LOW);
  }
}

void loop() {
  while (Serial.available() > 0) {
    // get the new byte:
    char data = (char)Serial.read();
    for (int i = 0; i < NUM_PINS; i++) {
      if (data == on_command[i]) {
        digitalWrite(relay_pins[i], HIGH);
      }
      if (data == off_command[i]) {
        digitalWrite(relay_pins[i], LOW);
      }
    }
  }
}


