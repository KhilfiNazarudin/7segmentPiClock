
#include <TM1637Display.h>
#define CLK 2
#define DIO 3

TM1637Display display = TM1637Display(CLK, DIO);

// Create array that turns all segments on:
const uint8_t data[] = {0xff, 0xff, 0xff, 0xff};

// Create array that turns all segments off:
const uint8_t blank[] = {0x00, 0x00, 0x00, 0x00};



// 7 SEGMENT DISPLAY CLOCK WITHOUT RTC

int counter = 1;
int switchPin = 13; //Change mode
int buttonPin = 8;
int btnState;

int hrs_btn;
int min_btn;

int Time;
int Hrs = 20;
int Min = 59;
double Sec = 0;
const unsigned long period = 1000; //one second
double startMillis = millis();
double currentMillis;

double i = 0;
double a = millis();
double c ;

int timer;

double start = millis();
double current;





void setup()
{
  pinMode(switchPin, INPUT);
  digitalWrite(switchPin, HIGH);
  pinMode(5,OUTPUT); //RED
  pinMode(6,OUTPUT); //GREEN

  Serial.begin(9600);
 
  pinMode(8, INPUT); //start reset //hrs 
  digitalWrite(8, HIGH);
  pinMode(9, INPUT); //stop        //mins
  digitalWrite(9, HIGH);

  
  
  Serial.println(counter);
  display.clear();
      // Set the brightness:
  display.setBrightness(7);
  // All segments on:
  display.setSegments(data);

  delay(1000);
  display.clear();
  delay(1000);

  
  
}

void loop() 
{



  
  //theClock();
  //Handle input
  //PULL DOWN BUTTON. BUTTON ALWAYS ON. CONNECT IT TO GROUND TO ACTIVATE
  currentMillis = millis();
  if (currentMillis - startMillis >= period)
    {
      Sec = Sec + 1;
      startMillis = currentMillis;
    }
  if (Sec == 60)
    {
      Sec = 0;
      Min = Min + 1;
    }
  if (Min == 60)
    {
      Min = 0;
      Hrs = Hrs + 1;
    }  
  if (Hrs == 24)
    {
      Hrs = 0;
    }
  Time = Hrs * 100 + Min;
  
  int btnState = digitalRead(switchPin);
  if(btnState == LOW)
    {
      delay(1000);  
      counter = counter + 1;
      //Reset count if over max mode number
      if(counter > 3)
        {
          counter = 1;
          Serial.println("----");
        }
    }

  else
    //Change mode
    switch (counter) 
    {
      case 1:
        digitalWrite(6,HIGH);
        digitalWrite(5,HIGH);
        display.showNumberDecEx(Time, 0b11100000, true);
        //display.showNumberDec(Time, true);
        Serial.println(Time);
        
        hrs_btn = digitalRead(8);
        min_btn = digitalRead(9);
  
          if(hrs_btn == 0)
            {
              delay(500);
              Hrs = Hrs + 1;
            }
          if(min_btn == 0)
            {
              delay(500);
              Min = Min + 1;
            }
          
        
        break;
      case 2:
      digitalWrite(6,HIGH);
      digitalWrite(5,LOW);
      delay(100);   
      if(digitalRead(8) == LOW)
        {
          a = millis();
          while(digitalRead(9) == HIGH)
            {      
              c = millis();
              i = (c - a) / 1000;
              Serial.println(i);
              Serial.println("......");
              display.showNumberDecEx(i, 0b11100000, true);
              digitalWrite(6,HIGH);
              delay(500);
              digitalWrite(6,LOW);
              delay(500);
            }
          if(digitalRead(9) == LOW)
            {
              while(digitalRead(8) == HIGH)//start reset
                {
                  delay(100);
                }
              if(digitalRead(8) == LOW) //stop
                {
                  Serial.println("0");
                  display.showNumberDecEx(0000, 0b11100000, true);
                  delay(500); 
                }                  
             }                     
        }  
          delay(500);
        break;
        case 3:
            digitalWrite(6,LOW);
            digitalWrite(5,HIGH);
            delay(100);
          while (digitalRead(buttonPin) == LOW )
            { 
              //Slow down increment
              digitalWrite(5,HIGH);
              delay(50);
              digitalWrite(5,LOW);
              delay(50); 
              timer = timer + 100; 
              Serial.print("ms = ");
              Serial.println(timer);
              display.showNumberDecEx(timer/100, 0b11100000, true);
            }
          if(digitalRead(buttonPin) == HIGH)
          {
            while(timer > 0)
            {
              current = millis();
              if (current - start >= period)
                {
                  timer = timer - 100;
                  startMillis = current;
                }
              Serial.print(timer/100);
              Serial.println("s");
              
              display.showNumberDecEx(timer/100, 0b11100000, true);
              digitalWrite(5,HIGH);
              delay(500);
              digitalWrite(5,LOW);
              delay(500);

              
            }
          }
  
          timer = 0; 
         break;
      }
}

void theClock(){


  // Set the brightness:
  //display.setBrightness(0.5);
  
  //hrs_btn = digitalRead(13);
  //min_btn = digitalRead(8);


//  if(hrs_btn == 1)
//  {
//    Hrs = Hrs + 1;
//  }
//  if(min_btn == 1)
//  {
//    Min = Min + 1;
//  }
  
  currentMillis = millis();
  if (currentMillis - startMillis >= period)
  {
    Sec = Sec + 1;
    startMillis = currentMillis;
  }
  if (Sec == 60)
  {
    Sec = 0;
    Min = Min + 1;
  }
  if (Min == 60)
  {
    Min = 0;
    Hrs = Hrs + 1;
  }  
  if (Hrs == 24)
  {
    Hrs = 0;
  }
  Time = Hrs * 100 + Min;

  //Serial.println(Sec);

  //Serial.println(Time);

 // display.showNumberDecEx(Time, 0b11100000, true);
 // display.showNumberDec(Time, true);

  
}
