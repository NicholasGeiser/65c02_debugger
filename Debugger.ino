void setup() {
  pinMode(2,OUTPUT); //clk
  pinMode(3,INPUT); //IO probe

  //address bus:
  for (int i=22;i<=52;i=i+2) {
    pinMode(i,INPUT);
  }//data bus
  for (int i=23;i<=37;i=i+2) {
    pinMode(i,INPUT);
  }

  pinMode(5,INPUT);//EEPROM CS
  pinMode(6,INPUT);//RAM CS
  pinMode(7,INPUT);//IO CS
  pinMode(8,INPUT);//UART CS
 
  Serial.begin(115200);
}

void loop() {
  Serial.println("CLOCK");
  digitalWrite(2,HIGH);
  reading();
  delay(500);
  digitalWrite(2,LOW);
  delay(500);
}

void reading()
{
  uint16_t abus = 0;
  uint8_t datbus = 0;
  uint8_t temp = 0;
  int i;
  //address bus:
  for (i=0;i<=15;i++) {
    temp = digitalRead(i*2+22);
    Serial.print(temp);
    abus |= temp << (15-i);
  }
  Serial.print(" ABUS: ");
  Serial.print(abus,HEX);
  Serial.print(" ");
  //data bus:
  for (i=0;i<=8;i++) {
    temp = digitalRead(i*2+23);
    Serial.print(temp);
    datbus |= temp << (8-i);
  }
  Serial.print(" DATABUS: ");
  Serial.print(datbus,HEX);

  temp = digitalRead(5);
  Serial.print(" ROM CS: ");
  Serial.print(temp);

  temp = digitalRead(6);
  Serial.print(" RAM CS: ");
  Serial.print(temp);

  temp = digitalRead(7);
  Serial.print(" IO CS: ");
  Serial.print(temp);

  temp = digitalRead(8);
  Serial.print(" UART CS: ");
  Serial.print(temp);

  temp = digitalRead(3);
  Serial.print(" 65c22 Output: ");
  Serial.println(temp);
  
}
