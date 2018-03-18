int curs_pos[2];

void show_info_lcd(String message, int curs_pos[]) {
  lcd.setCursor(curs_pos[0], curs_pos[1]);
  lcd.print(message);
  analogWrite(lp, 50);
  lcd.display();    
}

void turned_ON_message() {
  lcd.clear();
  curs_pos[0] = 2; 
  curs_pos[1] = 0; 
  show_info_lcd("The light is", curs_pos);
  curs_pos[0] = 3; 
  curs_pos[1] = 1; 
  show_info_lcd("turned ON", curs_pos);
  delay(5000);
  lcd.noDisplay();
  analogWrite(lp, 0);
}

void turned_OFF_message() {
  lcd.clear();
  curs_pos[0] = 2; 
  curs_pos[1] = 0; 
  show_info_lcd("The light is", curs_pos);
  curs_pos[0] = 3; 
  curs_pos[1] = 1;  
  show_info_lcd("turned OFF", curs_pos);
  delay(5000);
  lcd.noDisplay();
  analogWrite(lp, 0);
}

