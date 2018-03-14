// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7, lp = 10, led = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
String button;
byte key_num;

//****************************************
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.clear();
  lcd.noDisplay();

  analogWrite(lp, 0);

  pinMode(led, OUTPUT);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Pressed button:");

  key_num = key();
  button = but_name(key_num);
  lcd.setCursor(0,1);
  lcd.print(button);
  
  if (key_num != 7) {
    digitalWrite(led, HIGH); 
    lcd.display(); 
    analogWrite(lp, 100);
    }
  else {
    digitalWrite(led, LOW); 
    lcd.noDisplay(); 
    analogWrite(lp, 0);
    }

  delay(1000);
}

byte key() {
  //sel '0' - 639
  //left '1' - 408
  // up '2' - 98
  // down '3' - 250
  // right '4' - 0
  //default '7' - 1023

  int val = analogRead(0);
  if (val < 20) return  4;
  else if ((val > 200) && (val < 300)) return 3;
  else if ((val > 50) && (val < 150)) return 2;
  else if ((val > 350) && (val < 450)) return  1;
  else if ((val > 550) && (val < 700)) return 0;
  else if (val > 1000) return 7;
}

String but_name(byte key){
  String name;
  switch (key) {
    case 0: name = "select";
                    break;
    case 1: name = "left";
                    break;
    case 2: name = "up";
                    break;
    case 3: name = "down";
                    break;
    case 4: name = "right";
                    break;

    default: name = "waiting...";
  }
  return name;
}

