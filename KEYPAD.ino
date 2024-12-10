#include "Arduino.h"
#include "Keypad.h"
#include "LiquidCrystal_I2C.h"
#define ROW_NUM 4
#define COLUMN_NUM 4
char keys[ROW_NUM][COLUMN_NUM]={
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'},
};
byte pin_rows[ROW_NUM]={14, 27, 26, 25};
byte pin_colomn[COLUMN_NUM] = {33, 32, 18, 19};
Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_colomn, ROW_NUM, COLUMN_NUM);
LiquidCrystal_I2C lcd(0x27,16,2);
int cursorColumn =0;
void setup() {
  lcd.init();
  lcd.backlight();

}

void loop() {
  char key=keypad.getKey();
  if(key)
  {
    lcd.setCursor(cursorColumn, 0);
    lcd.print(key);
    cursorColumn++;
    if(cursorColumn==16)
    {
      lcd.clear();
      cursorColumn=0;
    }
  }

}
