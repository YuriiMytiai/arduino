
//*********** libs:

#include <LiquidCrystal.h>

//********** consts:
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7, lp = 10, led = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

boolean isOn = false;
int ext_relay_pin = 12;

volatile int count_inter = 0, delay_betw_claps = 500;
volatile boolean change_relay_status = false;
volatile long prev_inter_time = 0;
volatile long cur_inter_time = 0;


//********** setup:
void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  analogWrite(lp, 0);
  lcd.noDisplay();
  
  pinMode(ext_relay_pin, OUTPUT);
  digitalWrite(ext_relay_pin, LOW);
  
  
  //Serial.begin(9600);
  //Serial.println("Start");

  attachInterrupt(digitalPinToInterrupt(2), inter_func, RISING);
}


//********** main loop:
void loop() {
if (change_relay_status) {
  manage_relay(); 
  change_relay_status = false; 
}
delay(500);
}

//************ interruption func:
void inter_func() {
  if (change_relay_status){
    Serial.println("I'm here");
    return;
    }
  count_inter++;
  cur_inter_time = millis();
  //Serial.println(prev_inter_time);
  //Serial.println(cur_inter_time);
  if (cur_inter_time - prev_inter_time < delay_betw_claps) {
    //Serial.println("I'm at 1");
    prev_inter_time = cur_inter_time;
    return;
    }
  else if ((cur_inter_time - prev_inter_time > delay_betw_claps) && (cur_inter_time - prev_inter_time < 1000)) {
    //Serial.println("I/m at 2");
   // Serial.println("-------------");
    prev_inter_time = cur_inter_time;
    change_relay_status = true;
  } else {
    //Serial.println("I'm at 3");
    prev_inter_time = cur_inter_time;
    return;
  }
}

void manage_relay(){
  if (isOn) {
        digitalWrite(ext_relay_pin, LOW);
        turned_OFF_message();
        isOn = false;
      } else {
        digitalWrite(ext_relay_pin, HIGH);
        turned_ON_message();
        analogWrite(lp, 0);
        isOn = true;
  }
}


