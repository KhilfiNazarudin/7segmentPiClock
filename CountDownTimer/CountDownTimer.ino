


/////////Declare and Initialize Variables////////////////////////////

//We need to track how long the momentary pushbutton is held in order to execute different commands
//This value will be recorded in seconds
float timer = 0;      
int buttonPin = 2;

void setup(){

  // Initialize the pushbutton pin as an input pullup
  // Keep in mind, when pin 2 has ground voltage applied, we know the button is being pressed
  pinMode(buttonPin, INPUT_PULLUP);     

  Serial.begin(9600);                                     

} // close setup


void loop() {

  //Record *roughly* the tenths of seconds the button in being held down
    while (digitalRead(buttonPin) == LOW )
    { 

      delay(100);  //if you want more resolution, lower this number 
      timer = timer + 100;   
  
      //display how long button is has been held
      Serial.print("ms = ");
      Serial.println(timer);

    }



         

   

  


  //every time through the loop, we need to reset the pressLength_Seconds counter
  timer = 0;

} // close void loop
