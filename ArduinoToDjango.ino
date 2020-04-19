#include "DHT.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h> // dolaczenie pobranej biblioteki I2C dla LCD
 
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Ustawienie adresu ukladu na 0x27
 
int data = 0;

#define DHT11_PIN 2
DHT dht;

void setup()
{
  lcd.begin(16,2);   // Inicjalizacja LCD 2x16
  lcd.backlight(); // zalaczenie podwietlenia 
  Serial.begin(9600);
  dht.setup(DHT11_PIN);
}
 
void loop()
{ 
  //Pobranie informacji o wilgotnosci i temperaturze
  int wilgotnosc = dht.getHumidity();
  int temperatura = dht.getTemperature();
  unsigned long now = millis();
  
  
  if(wilgotnosc !=0 && temperatura !=0){
    lcd.clear();
    lcd.setCursor(0,0);
    Serial.print(wilgotnosc);
    lcd.print(wilgotnosc);
    Serial.print(" ");
    lcd.print(" ");
    Serial.println(temperatura);
    lcd.print(temperatura);
    delay(2000);
  }
}
