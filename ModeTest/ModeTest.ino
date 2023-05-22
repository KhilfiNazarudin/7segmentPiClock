int btnState;
String mode = 'clock';

void setup() {
  // put your setup code here, to run once:
  pinMode(13,INPUT);
  Serial.begin(9600);

}

void loop() {
  if(mode == clock)
  {
    print(mode);
    btnState = digitalRead(13);
    
      if(btnState == 1)
      {
        btnState = digitalRead(13);
        mode = 'stopwatch'
        print(mode);

        
      
      }
    
  }
  
 
  
  

}
