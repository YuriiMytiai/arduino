double calc_RMS(int len) {
// len max value - 1024
double sqr_sum = 0;
double U_ref = 0.707;
double U_value;
for (int i = 0 ; i < len ; i++) { // save some samples
  while(!(ADCSRA & 0x10)); // wait for adc to be ready
  ADCSRA = 0xf5; // restart adc
  byte low = ADCL; // fetch adc data (low byte)
  byte high = ADCH; // fetch adc data (high byte)
  int value = (high << 8) | low; // combine the two bytes
  U_value = (double) value / 1024 * 5;
  sqr_sum += U_value * U_value;
}

double sqr_mean = sqr_sum / len;

double sqrt_val = sqrt(sqr_mean); 
return 10 * log10(sqrt_val / U_ref); 
}

