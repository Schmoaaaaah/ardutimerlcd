#include <Arduino.h>
#include <LiquidCrystal.h>

int seconds = 0;
int milstart = 0;
int milend = 0;
int runs = 0;
int buttonpin = 10;
int ledgruen = 8;
int ledrot = 9;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  pinMode(buttonpin, INPUT_PULLUP);
  pinMode(ledgruen, OUTPUT);
  pinMode(ledrot, OUTPUT);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Seconds: ");
  lcd.setCursor(1, 0);
  lcd.print("Runs: ");
}

void loop()
{
  seconds = (millis() - milstart) / 1000;
  if (digitalRead(buttonpin) == LOW)
  {
    if (milstart > 0)
    {
      milend = millis();
      seconds = (milend - milstart) / 1000;
      runs = runs + 1;
      digitalWrite(ledgruen, LOW);
      digitalWrite(ledrot, HIGH);
      milstart = 0;
      milend = 0;
    }
    else
    {
      milstart = millis();
      digitalWrite(ledgruen, HIGH);
      digitalWrite(ledrot, LOW);
    }
  }
  lcd.clear();
  lcd.setCursor(0, 9);
  lcd.print(seconds); //9
  lcd.setCursor(6, 1);
  lcd.print(runs); // 6
}