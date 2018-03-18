
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
