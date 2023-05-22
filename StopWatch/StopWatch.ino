double i = 0;
double a = millis();
double c ;
 
void setup()
{

 
Serial.begin(9600);
pinMode(8, INPUT); //start reset
digitalWrite(8, HIGH);
pinMode(9, INPUT); //stop
digitalWrite(9, HIGH);

}

 
void loop()
{
  delay(100);   
  if(digitalRead(8) == LOW)
  {
    a = millis();
    while(digitalRead(9) == HIGH)
      {
        c = millis();
        i = (c - a) / 1000;
        
//        Serial.println(c);
//        Serial.println(a);
        Serial.println(i);
        Serial.println("......");
        delay(100);
      }
   
  if(digitalRead(9) == LOW)
    {
      while(digitalRead(8) == HIGH)
        {
          delay(100);
        }
      if(digitalRead(8) == LOW)
      {
        Serial.println("0");
        delay(500); 
      }
          
     }
        
             
    }
}
