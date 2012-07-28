#include <IRremote.h>

int RECV_PIN = 13;

IRrecv irrecv(RECV_PIN);
decode_results results;

#define BT_1 0x20DF8877 //Botao 1
#define BT_2 0x20DF48B7 //Botao 2
#define BT_3 0x20DFC837 //Botao 3
#define BT_4 0x20DF08F7 //Botao 4

#define LED_1 2 //Pino led 1
#define LED_2 3 //Pino led 2
#define LED_3 4 //Pino led 3
#define LED_4 5 //Pino led 4

int led1State = LOW; //Estado atual do led 1
int led2State = LOW; //Led 2
int led3State = LOW; //Led 3
int led4State = LOW; //Led 4

long bt = 0; //Ultimo botao precionado
unsigned long startMilis = 0; //Contado para blink sem delay

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    irrecv.resume(); 
    
    Serial.println(results.value, HEX); //Aqui voce descobre qual o botao do seu controle
    
    //Apenas para filtrar os botoes apertados, no meu caso para filtrar outros controles =)
    if(results.value == BT_1 || results.value == BT_2 || results.value == BT_3 || results.value == BT_4)
    {
      startMilis = millis(); //Apertou um botao, reseta o contador
      bt = results.value; //Salva ultimo botao apertado
    }
  }
  
  //Ativa o modo dos leds de acordo com o botao apertado
  switch(bt)
  {
    case BT_1 : mod(1); break;
    case BT_2 : mod(2); break;
    case BT_3 : mod(3); break;
    default: mod(0); break;
  }
}

void mod(int x)
{
  unsigned long currentMillis = millis();
  
  if(x == 0)
  {
    //Mod 0, tudo apagado
    led1State = LOW;
    led2State = LOW;
    led3State = LOW;
    led4State = LOW;
  }
  else if(x == 1)
  {
    //Mod 1, tudo aceso
    led1State = HIGH;
    led2State = HIGH;
    led3State = HIGH;
    led4State = HIGH;
  }
  else if(x == 2)
  {
    //Mod 2, pisca pisca
    if(startMilis + 1000 > currentMillis)
    {
      return mod(1);
    }
    else if(startMilis + 2000 > currentMillis)
    {
      return mod(0);
    }
    else
    {
      startMilis = currentMillis;
    }
  }
  else if(x == 3)
  {
    //Mod 3, arvore de natal
    mod(0);
    
    if(startMilis + 250 > currentMillis)
    {
      led1State = HIGH;
    }
    else if(startMilis + 500 > currentMillis)
    {
      led2State = HIGH;
    }
    else if(startMilis + 750 > currentMillis)
    {
      led3State = HIGH;
    }
    else if(startMilis + 1000 > currentMillis)
    {
      led4State = HIGH;
    }
    else
    {
      startMilis = currentMillis;
    }
  }
  
  digitalWrite(LED_1, led1State);
  digitalWrite(LED_2, led2State);
  digitalWrite(LED_3, led3State);
  digitalWrite(LED_4, led4State);
}
