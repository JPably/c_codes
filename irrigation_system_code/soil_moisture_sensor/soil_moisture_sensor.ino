int soilmoisture = A1;
int datasoilmoisture;

void setup() {
  Serial.begin(9600);
  pinMode(soilmoisture, INPUT);

}

void loop() {
  datasoilmoisture = analogRead(soilmoisture);
  Serial.print("Humedad del suelo: ");
  Serial.println(datasoilmoisture);
  delay(1000);

}
