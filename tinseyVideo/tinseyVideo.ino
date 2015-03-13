//**************************************************************************************
//
//  TITLE:   Video Booth with MacBook running photo booth
//  AUTHOR:  @deez79
//  DATE:    01/11/2015
//
//**************************************************************************************



//**************************************************************************************
// Info
//**************************************************************************************
/*
  This project is for creating a "Video Booth" using a podium and a MacBook.
  The idea is to have the laptop opened, but have the keyboard secured below the surface of the podium.
  Only a large 60mm LED enabled arcade button will be available for users to interact with.
  Upon clicking of arcade button, teensy will send Mouse.click() to laptop activating Apple Photo Booth application 
    and Arcade button will light up (On Air style).
  Arcade button will remain light for "eventTime" then button LED will start to flash for variable number of seconds
    based on argument in flash().
  After last flash Mouse.click() will be sent again to end the Photo Booth application recording.
  
  When loading this onto teensy, don't forget Tools > USB Type: (Serial +) Keyboard + Mouse + Joystick
  
  Sketch was originally written to use MakeyMakey board http://makeymakey.com/ instead of Mouse.click().  
  makeyClick() function was written to utilize this.
  In the end, the MakeyMakey was not used as the hardware was too expensive for this project.

  
  Button interaction based on Button Sketch
     by DojoDave <http://www.0j0.org>
     modified 30 Aug 2011
     by Tom Igoe
     http://www.arduino.cc/en/Tutorial/Button
 */
 
//***************************************************************************************
// Schematic
//***************************************************************************************
/*

Teensy 3.0
____________
|          |
|     21   |--------------------------------------------------------------------------[makey makey]
|          |
|     13   |----------/\/\/\/------------------>|-------------------------+
|          |                                                              |
|          |                                                              |
|     2    |--------------------------------------+------------/\/\/\/----+
|          |                                      |                       |
|          |                                      0                       |
|          |                                     ---|                     |
|          |                                      0                       |
|          |                                      |                       |
|     5v   |--------------------------------------+                       |
|          |                                                              |
|     gnd  |--------------------------------------------------------------+
|          |
|          |
------------

*/

//***************************************************************************************
// Main Sketch
//***************************************************************************************

//*****************************************
// Constants
//*****************************************
  const int buttonPin = 15;				// the number of the pushbutton pin Default 2, currently 15
  const int ledPin =  13;				// the number of the LED pin 
  const int makeyPin = 21;				// the number of the makeymakey space pin

//*****************************************
// Variables
//*****************************************
  int buttonState = 0;					// variable for reading the pushbutton status 0 default is not clicked
  int eventTime = 28;					// Time to wait after button click before clicking again. (add 3 seconds for application delay)  
											// Note each number passed to flash represents 1 second.

//*****************************************
// Functions
//*****************************************
void appOff(){
    digitalWrite(ledPin, LOW);      	// turn LED OFF
    digitalWrite(makeyPin, HIGH);    	// Don't activate Makey
}    // end appOff()

void makeyClick(){
    // click activate Makey, Makey needs to be grounded to activate: If LED is connected, LED turns off
    blink(makeyPin);
}  	//end makeyClick()

void blink(int PIN){
   digitalWrite(PIN, LOW);
   delay(500);
   digitalWrite(PIN, HIGH); 
}	// end blink()

void flash(int count){
  for(int p=0; p<count; p++){
    blink(ledPin);
    delay(500);
  } //end for
}   //end flash()

//*****************************************
// Setup
//*****************************************
void setup() {
  // initialize the LED pin and Makey as an output:
  pinMode(ledPin, OUTPUT);  
  pinMode(makeyPin, OUTPUT);  
  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}
 
//*****************************************
// Loop
//*****************************************
void loop(){  
   buttonState = digitalRead(buttonPin);   // read the state of the pushbutton value:
  
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH
  if (buttonState == HIGH) {  //button IS clicked
      digitalWrite(ledPin, HIGH);     // turn LED ON

      Mouse.click();
      //makeyClick();

      delay(eventTime * 1000);    
      flash(5);

      Mouse.click();
      //makeyClick();
  } 
  else {  //button NOT clicked
    appOff();
  }

}	//end Loop()              
