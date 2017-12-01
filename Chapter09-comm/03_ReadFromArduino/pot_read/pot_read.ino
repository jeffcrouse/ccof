
#define POT_PIN A0

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(POT_PIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(POT_PIN);
  Serial.println( val );
  delay(10);
}
