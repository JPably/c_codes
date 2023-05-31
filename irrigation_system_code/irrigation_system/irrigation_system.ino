#include <LiquidCrystal.h>

int V0 = 3;
int RS = 5;
int E = 6;
int D4 = 9;
int D5 = 10;
int D6 = 11;
int D7 = 12;

//int waterlevel = A0;
//int datawaterlevel;
int soilmoisture = A1;
int datasoilmoisture;
int blueled = 2;
int greenled = 4;
int yellowled = 7;
int waterbomb = 8;

LiquidCrystal lcd(RS, E, D4, D5, D6, D7);

void setup() {
  lcd.begin(16, 2);
  analogWrite(V0, 50);
  Serial.begin(9600);
  //pinMode(waterlevel, INPUT);
  pinMode(soilmoisture, INPUT);
  pinMode(blueled, OUTPUT);
  pinMode(greenled, OUTPUT);
  pinMode(yellowled, OUTPUT);
  pinMode(waterbomb, OUTPUT);

}
void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  //lcd.print("N.agua: ");
  //lcd.print(datawaterlevel);
  //lcd.print("%");
  lcd.print("Proy. grado");
  lcd.setCursor(0, 1);
  lcd.print("H.tierra: ");
  lcd.print(datasoilmoisture);
  lcd.print("%");
  
  //datawaterlevel = analogRead(waterlevel);
  //Serial.print("Nivel del agua: ");
  //Serial.println(datawaterlevel);
  //delay(1500);

  datasoilmoisture = analogRead(soilmoisture);
  Serial.print("Humedad del suelo: ");
  Serial.println(datasoilmoisture);
  delay(1000);

 if (datasoilmoisture >= 750 && datasoilmoisture <= 1023) {
  digitalWrite(yellowled, HIGH);
 }

 else{
  digitalWrite(yellowled, LOW);
 }

 if (datasoilmoisture >= 450 && datasoilmoisture <= 749) {
  digitalWrite(greenled, HIGH);
 }

 else{
  digitalWrite(greenled, LOW);
 }

 if (datasoilmoisture >= 0 && datasoilmoisture <= 449) {
  digitalWrite(blueled, HIGH);
 }

 else{
  digitalWrite(blueled, LOW);
 }

 if(datasoilmoisture >= 850 && datasoilmoisture <= 1023) {
  digitalWrite(waterbomb, HIGH);
  delay(6000);
 }

 else{
  digitalWrite(waterbomb, LOW);
 }
}
