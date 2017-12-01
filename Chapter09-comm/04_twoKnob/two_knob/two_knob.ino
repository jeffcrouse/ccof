
#define PIN_1 A0
#define PIN_2 A1

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PIN_1, INPUT);
  pinMode(PIN_2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.print("x ");
  Serial.print( analogRead(PIN_1) );
  Serial.print("\n"); 
  
  Serial.print("y ");
  Serial.print( analogRead(PIN_2) );
  Serial.print("\n");
  delay(10);

}
