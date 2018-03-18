//*********** libs:
#include <LiquidCrystal.h>

//********** consts:
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7, lp = 10, led = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int ext_relay_pin = 12, ext_mic_pin = 1, mic_val, thresh = 90; 
bool isOn = false;

//********** setup:
void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  analogWrite(lp, 0);
  lcd.noDisplay();
  
  pinMode(ext_relay_pin, OUTPUT);
  digitalWrite(ext_relay_pin, LOW);
  
  
  Serial.begin(9600);
  Serial.println("Start");
}



//********** main loop:
void loop() {

  mic_val = analogRead(ext_mic_pin);
  Serial.println(mic_val);
  
  if (mic_val > thresh) {
    delay(30);
    mic_val = analogRead(ext_mic_pin);
    
    Serial.println("second meas:");
    Serial.println(mic_val);
    
    if (mic_val < thresh) {
      if (isOn) {
        digitalWrite(ext_relay_pin, LOW);
        show_info_lcd("Light is off");
        isOn = false;
      } else {
        digitalWrite(ext_relay_pin, HIGH);
        show_info_lcd("Light is on!");
        isOn = true;
      }
    }
  }

  delay(5);

  

/*
  digitalWrite(ext_relay_pin, LOW);
  show_info_lcd();
  

  digitalWrite(ext_relay_pin, HIGH);
  delay(2000);
  
 */ 
  //if (analogRead(A5) > 60) Serial.println (analogRead(A5));
//delay(20);


}

void show_info_lcd(String message) {
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print(message);
  analogWrite(lp, 50);
  lcd.display();      
  delay(5000);
  lcd.noDisplay();
  analogWrite(lp, 0);
}

