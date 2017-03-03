/*
          WRITTEN BY FERIT YIGIT BALABAN    
             SAYISAL KUMBARA - V2.7    

___________________THE CODE____________________________
*/

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int besKrs = 2;
const int onKrs = 4;
const int yirmibesKrs = 7;
const int elliKrs = 8;
const int birLira = 12;

uint8_t heart[8] = {0x0, 0xa, 0x1f, 0x1f, 0xe, 0x4, 0x0};
uint8_t shChar[8] = {0, 14, 16, 14, 1, 30, 4, 0};

float paraDegeri = 0;

void setup()
{
  lcd.begin();
  lcd.backlight();

  lcd.createChar(3, heart);
  lcd.createChar(4, shChar);
  
  lcd.clear();
  lcd.home();
  
  lcd.print("SAYISAL KUMBARA");
  lcd.setCursor(0, 1);
  lcd.print("F. YIGIT BALABAN");
  delay(2500);
  lcd.clear();
  lcd.home();
  lcd.print(" i ");
  lcd.write(3);
  lcd.print(" arduinos!");
  delay(2250);

  lcd.clear();
  lcd.home();

  pinMode(besKrs, INPUT);
  pinMode(onKrs, INPUT);
  pinMode(yirmibesKrs, INPUT);
  pinMode(elliKrs, INPUT);
  pinMode(birLira, INPUT);

  Serial.begin(1200);
}

void loop()
{
  if (digitalRead(besKrs) == 0)
  {
    delay(750);
    paraDegeri += 0.05;
  }
  if (digitalRead(onKrs) == 0)
  {
    delay(750);
    paraDegeri += 0.10;
  }
  if (digitalRead(yirmibesKrs) == 0)
  {
    delay(750);
    paraDegeri += 0.25;
  }
  if (digitalRead(elliKrs) == 0)
  {
    delay(750);
    paraDegeri += 0.50;
  }
  if (digitalRead(birLira) == 0)
  {
    delay(750);
    paraDegeri += 1.00;
  }

  delay(500);
  lcd.home();
  lcd.print("TOPLAM:");
  lcd.setCursor(0, 1);
  lcd.print(paraDegeri);
  lcd.setCursor(5, 1);
  lcd.print("kr");
  lcd.write(4);
  Serial.println(paraDegeri);
}
