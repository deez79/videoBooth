/*
  Video Booth 
  
  
 
    Parts Based on Button Sketch
     by DojoDave <http://www.0j0.org>
     modified 30 Aug 2011
     by Tom Igoe
     http://www.arduino.cc/en/Tutorial/Button
 */

// constants won't change. They're used here to 
// set pin numbers:
  const int buttonPin = 2;     // the number of the pushbutton pin
  const int ledPin =  13;      // the number of the LED pin 
  const int clickPin = 14;     // the number of the makeymakey space pin

// variables will change:
  int buttonState = 0;         // variable for reading the pushbutton status 0 default is not clicked

void setup() {
  // initialize the LED pin and Makey as an output:
  pinMode(ledPin, OUTPUT);  
  pinMode(clickPin, OUTPUT);  
  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  
}
  
void loop(){
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH
  if (buttonState == HIGH) {  //button IS clicked
      digitalWrite(ledPin, HIGH);     // turn LED ON
      makeyClick();
      delay(5 * 1000);
      flash(5);
      makeyClick();
  } 
  else {  //button NOT clicked
    OffApp();
  }

}  //end Loop()              

void OffApp(){
    digitalWrite(ledPin, LOW);      // turn LED OFF
    digitalWrite(clickPin, HIGH);    // Don't activate Makey
}    // end OffApp

void flash(int count){
  for(int p=0; p<count; p++){
    digitalWrite(ledPin, LOW);
    delay(500);
    digitalWrite(ledPin, HIGH);
    delay(500);
  }      //end for
}        //end Flash

void makeyClick(){
    digitalWrite(clickPin, LOW);    // click activate Makey, Makey needs to be grounded to activate: If LED is connected, LED turns off
    delay(500);
    digitalWrite(clickPin, HIGH);
}  //end makeyClick
