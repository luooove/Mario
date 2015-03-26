int sensorPin = A0;
int ledOut = 13; 
int sensorValue;
volatile int state = LOW; 
void setup() {
  // put youri
  pinMode(ledOut, OUTPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  Serial.begin(9600);
attachInterrupt(1, jump,RISING);//当int.下降沿触发 改变时,触发中断函数blink //IO is 2     low
attachInterrupt(0, jump2,RISING);//当int.下降沿触发 改变时,触发中断函数blink //IO is 3    high
attachInterrupt(4, jump3,RISING);//当int.下降沿触发 改变时,触发中断函数blink //IO is 7    highest
}

void loop() {
  // put your main code here, to run repeatedly:
//Keyboard.press('d');
if(digitalRead(8) == 0)
  Keyboard.releaseAll();
else
{
    Keyboard.press('d');
delay(100);  
}


if(digitalRead(9) == 0)
  Keyboard.releaseAll();
else
{
  Keyboard.press('a');
delay(100);  
}


}

void jump()
{
    Keyboard.press('k');
    delay(2000);
  Keyboard.releaseAll();
}
void jump2()
{
    Keyboard.press('k');
    delay(5000);
  Keyboard.releaseAll();
}
void jump3()
{
    Keyboard.press('k');
    delay(8000);
  Keyboard.releaseAll();
}
void stateChange()
{
  state = !state;
  digitalWrite(ledOut, state);  
 // Serial.println("a");
}
