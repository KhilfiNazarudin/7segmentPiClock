// Include the library:
#include <TM1637Display.h>

// Define the connections pins:
#define CLK 2
#define DIO 3

// Create display object of type TM1637Display:
TM1637Display display = TM1637Display(CLK, DIO);

const unsigned long period = 1000; //one second
double startMillis = millis();
double currentMillis;

int hrs_btn = 0;
int min_btn = 0;

int Hrs = 20;
int Min = 59;
double Sec = 0;

int Time;


void setup() {
  // Clear the display:
  display.clear();
  delay(1000);
  pinMode(13, INPUT);
  pinMode(8, INPUT);

  Serial.begin(9600);
  theClock();

}

void loop() {

  
  stopwatch();

}

void stopwatch(){
    
  display.setBrightness(0.5);
  hrs_btn = digitalRead(13);
  min_btn = digitalRead(8);
  
  currentMillis = millis();
  Sec = (currentMillis - startMillis) / 1000;
  
}



void theClock(){

while(true){
  // Set the brightness:
  display.setBrightness(0.5);
  
  hrs_btn = digitalRead(13);
  min_btn = digitalRead(8);


  if(hrs_btn == 1)
  {
    Hrs = Hrs + 1;
  }
  if(min_btn == 1)
  {
    Min = Min + 1;
  }
  
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

  Serial.println(Time);

 // display.showNumberDecEx(Time, 0b11100000, true);
 // display.showNumberDec(Time, true);
}
  
}
