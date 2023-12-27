//Bounce2 라이브러리 활용 - 왼/오른쪽 마우스

#include <Bounce2.h>

int L_button = 2;
int R_button = 3;
int oper_led = 13;

Bounce L_debouncer = Bounce();
Bounce R_debouncer = Bounce();

void setup()
{
  pinMode(oper_led, OUTPUT);
  pinMode(L_button, INPUT_PULLUP);
  pinMode(R_button, INPUT_PULLUP);

  L_debouncer.attach(L_button);
  R_debouncer.attach(R_button);

  L_debouncer.interval(5);
  R_debouncer.interval(5);

  Serial.begin(9600);
}

void loop()
{
  R_debouncer.update();
  L_debouncer.update();

  if(R_debouncer.fell())
  {
    Serial.println("R_button_Pressed   :O");
  }
  else if(R_debouncer.rose())
  {
    Serial.println("R_button_Released  :|");
  }

  if(L_debouncer.fell())
  {
    Serial.println("L_button_Pressed   :O");
  }
  else if(L_debouncer.rose())
  {
    Serial.println("L_button_Released  :|");
  }
  else
  {
    digitalWrite(oper_led, HIGH);
  }
}