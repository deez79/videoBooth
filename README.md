**************************************************************************************
    TITLE:   Video Booth with MacBook running photo booth
    AUTHOR:  @deez79
    DATE:    01/11/2015

**************************************************************************************



**************************************************************************************
    Info
**************************************************************************************

This project is for creating a "Video Booth" using a podium and a MacBook.
The idea is to have the laptop opened, but have the keyboard secured below the surface of the podium.
Only a large 60mm LED enabled arcade button will be available for users to interact with.
Upon clicking of arcade button, teensy will send Mouse.click() to laptop activating Apple Photo Booth application 
and Arcade button will light up (On Air style).
Arcade button will remain light for "eventTime" then button LED will start to flash for variable number of seconds
based on argument in flash().
After last flash Mouse.click() will be sent again to end the Photo Booth application recording.
  
When loading this onto teensy, don't forget Tools > USB Type: (Serial +) Keyboard + Mouse + Joystick
      
Two seperate versions of the code are available. The teensy only code is availble in teensyVideo folder.  The code for 
using the makeymakey with this project is available in makey folder.
      
Sketch was originally written to use MakeyMakey board http://makeymakey.com/ instead of Mouse.click().  
makeyClick() function was written to utilize this.
In the end, the MakeyMakey was not used as the hardware was too expensive for this project.

  
Button interaction based on Button Sketch
      by DojoDave <http://www.0j0.org>
      modified 30 Aug 2011
      by Tom Igoe
      http://www.arduino.cc/en/Tutorial/Button
 
 
***************************************************************************************
    Schematic
***************************************************************************************

<pre>
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
</pre>

