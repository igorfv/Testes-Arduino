int en1 = 12;
int en4 = 8;
int en2 = 13;
int en3 = 9;

void setup()
{
  pinMode(11, OUTPUT);   // sets the pin as output
  pinMode(12, OUTPUT);   // sets the pin as output
  pinMode(13, OUTPUT);   // sets the pin as output
  pinMode(8, OUTPUT);   // sets the pin as output
  pinMode(9, OUTPUT);   // sets the pin as output
  pinMode(10, OUTPUT);   // sets the pin as output
  
  analogWrite(11, 1023);
  analogWrite(10, 1023);
}

void loop()
{
  digitalWrite(en1,HIGH);
  digitalWrite(en4,HIGH);
  digitalWrite(en2,LOW);
  digitalWrite(en3,LOW);
  
  delay(1000);
  
  digitalWrite(en1,HIGH);
  digitalWrite(en4,LOW);
  digitalWrite(en2,LOW);
  digitalWrite(en3,HIGH);
  
  delay(1000);
  
  digitalWrite(en1,LOW);
  digitalWrite(en4,HIGH);
  digitalWrite(en2,HIGH);
  digitalWrite(en3,LOW);
  
  delay(1000);
  
  digitalWrite(en1,LOW);
  digitalWrite(en4,LOW);
  digitalWrite(en2,HIGH);
  digitalWrite(en3,HIGH);
  
  delay(1000);
}
