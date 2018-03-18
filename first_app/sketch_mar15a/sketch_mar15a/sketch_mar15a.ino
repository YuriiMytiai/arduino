//************** libraries:
#include <LiquidCrystal.h>


//************** constatnts:
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7, lp = 10, led = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


String button;
byte key_num;

//----------------------------------------------------------------------------------
void setup() {
  // put your setup code here, to run once:
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.clear();

  analogWrite(lp, 10);
  pinMode(led, OUTPUT);


  Serial.begin(9600);
  Serial.println("Hello Computer");

}

//------------------------------------------------------------------------------------

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Pressed button:");

  key_num = key();
  button = but_name(key_num);
  lcd.setCursor(0,1);
  lcd.print(button);
  Serial.println(button);

  
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
