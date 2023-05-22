int counter = 1;

int btn1;
int btn2;
int buttonPin = 13;

int LED1 = 12;
int LED2 = 11;
int LED3 = 10;

int delayTime;

void setup()
{
 pinMode(buttonPin, INPUT);
// pinMode(LED1, OUTPUT);
// pinMode(LED2, OUTPUT);
// pinMode(LED3, OUTPUT);
 Serial.begin(9600);
}

void loop()
{
  //Handle input
  digitalRead(buttonPin);
  if(buttonPin = HIGH)
  {
    counter + 1;
    //Reset count if over max mode number
    if(counter == 3)
    {
      counter = 1;
    }
  }
  
  //Change mode
  if(counter == 1)
  {
    // btn1 change hrs
    //btn2 change sec
    //display the time
    Serial.println("This is clock mode");
    Serial.println(counter);
    delay(500);
  }
  else if(counter == 2)
  {
    //btn1 start/stop
    //btn2 reset
    //display the stopwatch
    Serial.println("This is stopwatch mode");
    Serial.println(counter);
    delay(500);
  }
//  else if(counter == 3)
//  {
//    delayTime = 50;
//  }
  
  //Light show!
  //  digitalWrite(LED1, HIGH);
  //  delay(delayTime);
  //  digitalWrite(LED1, LOW);
  //  digitalWrite(LED2, HIGH);
  //  delay(delayTime);
  //  digitalWrite(LED2, LOW);
  //  digitalWrite(LED3, HIGH);
  //  delay(delayTime);
  //  digitalWrite(LED3, LOW);
  //  delay(delayTime);
}
