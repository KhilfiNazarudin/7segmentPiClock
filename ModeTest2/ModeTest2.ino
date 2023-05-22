int counter = 1;

int switchPin = 13;
int btnState;

int LEDB = 11;
int LEDG = 10;
int LEDR = 9;


void setup()
{
  pinMode(switchPin, INPUT);
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //Handle input
  int btnState = digitalRead(switchPin);
  if(btnState == HIGH)
  {
    delay(1000);  
    counter = counter + 1;
    //Reset count if over max mode number
    if(counter > 3)
    {
      counter = 1;
    }
  }

  else
    //Change mode
    switch (counter) {
    case 1:
      
      Serial.println(counter);
      delay(500);
      break;
    case 2:
      
      Serial.println(counter);
      delay(500);
      break;
    case 3:
      
      Serial.println(counter);
      delay(500);
      break;
    
    }
}
