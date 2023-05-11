int water1 = A0;
int water2 = A1;
int datawater1;
int datawater2;
int bombawater = 8;
int led1 = 11;
int led2 = 12;

void setup() {
 Serial.begin(9600);
 pinMode(water1, INPUT);
 pinMode(water2, INPUT);
 pinMode(bombawater, OUTPUT);
 pinMode(led1, OUTPUT);
 pinMode(led2, OUTPUT);
}
void loop() {
 datawater1 = analogRead(water1);
 Serial.print("NIVEL DEL AGUA1: ");
 Serial.println(datawater1);
 delay(1000);

 datawater2 = analogRead(water2);
 Serial.print("NIVEL DE AGUA2: ");
 Serial.println(datawater2);
 delay(1000);

 if (datawater1 <= 550 && datawater2 <= 550) {
  digitalWrite(bombawater, HIGH);
  delay(3000);
 }

 else{
  digitalWrite(bombawater, LOW);
 }

 if (datawater1 >= 550) {
  digitalWrite(led1, HIGH);
 }

 else{
  digitalWrite(led1, LOW);
 }

 if (datawater2 >= 550) {
  digitalWrite(led2, HIGH);
 }

 else{
  digitalWrite(led2, LOW);
 }
}
