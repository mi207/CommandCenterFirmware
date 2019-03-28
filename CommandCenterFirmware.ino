/*  ******************
    **Piper Game Pad**
    ******************
  Controls the mouse and keyboard  from a two joysticks connected to on an 
  Arduino Leonardo, Micro or Due. The two joysticks are potentiometers with
  in built button that will reperesent the left and right mouse button clicks.
  
  Hardware:
  - Right 2-axis joystick connected to pins A0 and A1, built-in buttion on D2- Controls mouse
  - Left  2-axis joystick connected to pins A2 and A3, built-in buttion on D3- Control Keyboard WASD

  The mouse movement is always relative. This sketch reads two analog inputs
  that range from 0 to 1023 (or less on either end) and translates them into
  ranges of -6 to 6. This code assumes that the joystick resting values are 
  around the middle of the range, but that they vary within a threshold.
  
  #WARNING: When you use this code, the controller overlays on your
  mouse and keyboard! 
  
  Mehdi Imani Masoleh
  V1:21-Jun-2018
  V2:06-Mar-2019
  V3:28-Mar-2019

  Inspired by: http://www.arduino.cc/en/Tutorial/JoystickMouseControl
  
*/

#include "ControllerConfig.h"
#include "src/KeyboardMouse/KeyboardMouse.h"

// set pin numbers for switch, joystick axes, and LED:
// Look at https://law.resource.org/pub/us/cfr/ibr/005/sae.j1733.1994.html for axis convention

int range = 8;               // output range of X or Y movement
int center = range / 2;       // resting position value, mapped

// Joystick Raw Center values
int rawCenter = 512;


/******Arduino Micro Setup*********/
// Joystick Movement
const int yawAxis = A1; // horizontal
const int pitchAxis = A0; // vertical

const int CE = 5;

// Click & Button Pins
const int btnLeftPin = 8;
const int btnRightPin = 9;
const int btnUpPin = 6;
const int btnDownPin = 7;
const int joystickPressPin = 13;
/******Arduino Micro Setup*********/

/******ProMicro Setup*********/
/* 
 // Joystick Movement
 const int yawAxis = 9; // horizontal
const int pitchAxis = 8; // vertical
const int joystickPressPin = 7;
const int JOYSTICK_VCC=6;

const int CE = 10;
// Click & Button Pins
//const int btnUpPin = 10;
//const int btnDownPin = 16;
//const int btnLeftPin = 14; 
//const int btnRightPin = 15;
const int btnUpPin = A0;
const int btnDownPin = A1;
const int btnLeftPin = A2;
const int btnRightPin = A3;
*/
/******ProMicro Setup*********/

//This is for making the array of class member function pointers 
typedef  void (KeyboardMouseClass::*KeyboardMouseClassMemFn)(uint8_t x, bool y); 
#define CALL_MEMBER_FN(object,ptrToMember)  ((object).*(ptrToMember))

KeyboardMouseClassMemFn pressEvents[]= {&KeyboardMouse.keyboardPress,
                                        &KeyboardMouse.mousePress,
                                        &KeyboardMouse.mouseWheelDownWithDelay};                                               

void setup() {

  pinMode(yawAxis, INPUT);
  pinMode(pitchAxis, INPUT);
  pinMode(btnLeftPin, INPUT_PULLUP);
  pinMode(btnRightPin, INPUT_PULLUP);
  pinMode(btnUpPin, INPUT_PULLUP);
  pinMode(btnDownPin, INPUT_PULLUP);
  pinMode(joystickPressPin, INPUT_PULLUP);
  pinMode(CE, OUTPUT);                          //initialized the pin's mode.
  /*
  pinMode(JOYSTICK_VCC, OUTPUT);                //For ProMicro, set pin mode for postive rail
  digitalWrite(JOYSTICK_VCC, HIGH);               //Set it high for VCC
  */
  KeyboardMouse.mouseMoveDelay=MOUSE_MOVE_DELAY;
  KeyboardMouse.mouseWheelDelay=MOUSE_WHEEL_DELAY;

  //TAKE OVER MOUSE
  Mouse.begin();
  //Serial.begin(9600);
}

void loop()
{
     checkJoystick();
}

void checkJoystick()
{
  int yawReading = readAxis(yawAxis);
  int pitchReading = readAxis(pitchAxis);

  if (!JOYSTICK_AS_MOUSE)
  {
    CALL_MEMBER_FN(KeyboardMouse,pressEvents[FUNCTION_MAP[5][0]])(FUNCTION_MAP[5][1],pitchReading<0);
    CALL_MEMBER_FN(KeyboardMouse,pressEvents[FUNCTION_MAP[6][0]])(FUNCTION_MAP[6][1],pitchReading>0);
    CALL_MEMBER_FN(KeyboardMouse,pressEvents[FUNCTION_MAP[7][0]])(FUNCTION_MAP[7][1],yawReading<0);
    CALL_MEMBER_FN(KeyboardMouse,pressEvents[FUNCTION_MAP[8][0]])(FUNCTION_MAP[8][1],yawReading>0); 
  }
  
  if (JOYSTICK_AS_MOUSE && (yawReading!=0 || pitchReading!=0))
  {
      KeyboardMouse.mouseMoveWithDelay(yawReading, pitchReading); 
  }

  CALL_MEMBER_FN(KeyboardMouse,pressEvents[FUNCTION_MAP[0][0]])(FUNCTION_MAP[0][1],digitalRead(btnUpPin) == LOW);
  CALL_MEMBER_FN(KeyboardMouse,pressEvents[FUNCTION_MAP[1][0]])(FUNCTION_MAP[1][1],digitalRead(btnDownPin) == LOW);
  CALL_MEMBER_FN(KeyboardMouse,pressEvents[FUNCTION_MAP[2][0]])(FUNCTION_MAP[2][1],digitalRead(btnLeftPin) == LOW);
  CALL_MEMBER_FN(KeyboardMouse,pressEvents[FUNCTION_MAP[3][0]])(FUNCTION_MAP[3][1],digitalRead(btnRightPin) == LOW);
  CALL_MEMBER_FN(KeyboardMouse,pressEvents[FUNCTION_MAP[4][0]])(FUNCTION_MAP[4][1],digitalRead(joystickPressPin) == LOW);

  //Serial.print(lastMouseWheel);
  //Serial.print("\n");
}


/* reads an axis (data pin) and scales the analog input range to a range
  from 0 to <range>
*/
int readAxis(int thisAxis)
{
  // read the analog input:
  int reading = analogRead(thisAxis);
  int distance = 0;

  // map the reading from the analog input range to the output range:
  reading = map(reading, 0, 1023, 0, range);

  // if the output reading is outside from the rest position threshold, use it:
  distance = reading - center;

  if (abs(distance) < JOYSTICK_THRESHOLD) {
    distance = 0;
  }

  // return the distance for this axis:
  return distance;
}


