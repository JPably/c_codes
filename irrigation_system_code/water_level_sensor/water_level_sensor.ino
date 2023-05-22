int waterlevel = A0;
int datawaterlevel;

void setup() {
  Serial.begin(9600);
  pinMode(waterlevel, INPUT);

}

void loop() {
  datawaterlevel = analogRead(waterlevel);
  Serial.print("Nivel del agua: ");
  Serial.println(datawaterlevel);
  delay(1000);

}
