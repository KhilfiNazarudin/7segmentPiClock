//------Electronics-project-hub.com-----//
#include "SevSeg.h"
SevSeg Display;
const unsigned long period = 1000; //one second
const unsigned long led_period = 500; //LED blink millisecond
unsigned long startMillis;
unsigned long led_startMillis;
unsigned long currentMillis;
unsigned long led_currentMillis;
const int hrs_btn = A0;
const int min_btn = A1;
const int ledPin = A2;
int Hrs = 12;
int Min = 0;
int Sec = 0;
int Time;
int ledState = LOW;
void setup()
{
  pinMode(hrs_btn, INPUT_PULLUP);
  pinMode(min_btn, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  byte numDigits = 4;
  byte digitPins[] = {10, 11, 12, 13};
  byte segmentPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
  bool resistorsOnSegments = false;
  bool updateWithDelays = false;
  byte hardwareConfig = COMMON_CATHODE;
  bool leadingZeros = true;
  bool disableDecPoint = true;
  Display.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, updateWithDelays, leadingZeros, disableDecPoint);
  Display.setBrightness(100);
}
void loop()
{
  currentMillis = millis();
  if (currentMillis - startMillis >= period)
  {
    Sec = Sec + 1;
    startMillis = currentMillis;
  }
  led_currentMillis = millis();
  if (led_currentMillis - led_startMillis >= led_period)
  {
    led_startMillis = led_currentMillis;
    if (ledState == LOW)
    {
      ledState = HIGH;
      if (digitalRead(hrs_btn) == LOW)
      {
        Hrs = Hrs + 1;
      }
      if (digitalRead(min_btn) == LOW)
      {
        Min = Min + 1;
        Sec = 0;
      }
    }
    else
    {
      ledState = LOW;
    }
    digitalWrite(ledPin, ledState);
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
  if (Hrs == 13)
  {
    Hrs = 1;
  }
  Time = Hrs * 100 + Min;
  Display.setNumber(Time);
  Display.refreshDisplay();
}
//------Electronics-project-hub.com-----//
