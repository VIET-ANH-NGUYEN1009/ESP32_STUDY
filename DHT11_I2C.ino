#include "Arduino.h"
#include "DHT.h"
#include "LiquidCrystal_I2C.h"
#define  DHTPIN 23
#define DHTTYPE DHT11
LiquidCrystal_I2C lcd(0x3F, 16, 2);
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  dht.begin();
  lcd.init();
  lcd.backlight();

}

void loop() {
  delay(2000);
  float h=dht.readHumidity(); // do am
  float t=dht.readTemperature(); //nhiet do
  float f=dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f))
  {
      Serial.println(F("Failed to read from DHT sensor!"));
      return;
  }

    // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
    // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
  lcd.clear();

  if(isnan(h) || isnan(t) || isnan(f))
  {
    lcd.setCursor(0, 0);
    lcd.print("FAILED");
  }
  else {
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Humi: ");
  lcd.print(h);
  lcd.print(" %");
  }

 

}
