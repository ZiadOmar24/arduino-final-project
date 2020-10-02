 #include <Servo.h>
  Servo servo;
  int motor =10;
  int button=2;
  int led=7;
  int ldr1=A0;
  int ldr2=A1;
  int value1=0;
  int value2=0;
  int counter=0;
  int buttonvalue=0;

  void setup()
  {
    Serial.begin(9600);
    servo.attach(10);
    pinMode(led,OUTPUT);
    pinMode(button,INPUT);

  }

  void loop()
  {
    buttonvalue=digitalRead(button);
   
    digitalWrite(led ,LOW);
    value1= analogRead(A0);
    value2= analogRead(A1);
    //Serial.println(value1);
    //Serial.println(value2);
    if (buttonvalue== HIGH)
   {
      Serial.println("NUMBER");
     
     
    if (value1<250 || value2<250)     //elrkm da b2a bn7ddo 3la 7sb 2da2t elmkaan 7tb2a 3mla 2zaay
    {
          if (value2<value1)         //5areg
    {
      counter--;
          for (int i=0;i<181;i++)
      {
        servo.write(i);
        delay(15);
      }
      Serial.println(counter);
    }


          if (counter > 5)
    {
            digitalWrite(led, HIGH);
            delay(2000);
            digitalWrite(led ,LOW);
            counter--;
  
    }
     else if (value1<value2)           //da5el
    {
  
      counter++;
      for (int i=0;i<181;i++)
      {
        servo.write(i);
        delay(15);
      }
      Serial.println(counter);
    }

    } 
    }
    //else
   // {
    //  Serial.println("closed");
   // }

  }
 
 
