#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h> // dolaczenie pobranej biblioteki I2C dla LCD
 
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Ustawienie adresu ukladu na 0x27
 
int data = 0;

#define DHTPIN 12
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  lcd.init();   // Inicjalizacja LCD 2x16
  lcd.backlight(); // zalaczenie podwietlenia 
  Serial.begin(9600);
  dht.begin();
}
 
void loop()
{ 
  //Pobranie informacji o wilgotnosci i temperaturze
  int wilgotnosc = dht.readHumidity();
  int temperatura = dht.readTemperature();
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
