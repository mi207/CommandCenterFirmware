/****Configuration File For the Controller****/

/*
 * Here you can define what the key mapping should be as explained the in protocol below
 * and you can also set some of the joystick timeing parameters. 
 */

//Protocol based on the following:


const uint8_t MOUSE_MOVE_DELAY = 5;
const uint8_t MOUSE_WHEEL_DELAY = 150;
const uint8_t JOYSTICK_THRESHOLD = 2;    // resting threshold, can be 0-4

//This would disable option 6-9, i.e. joystick would just function as a mouse
//When False, it would disable mouse and treats joystick like a button-pad
const bool JOYSTICK_AS_MOUSE=false;

//The structure is defined by . {x,y},  
//Index location=Event, can be 0-9 and defined by above. e.g. put 0 for buttonUpPressed
//x=Resulting Action Type keyboardPress=0,mousePress=1,mouseWheelDownWithDelay=2
//y=argument into the action, i.e. what key or what mouse button, refer to below

static const uint8_t FUNCTION_MAP[][2]={
                                         {0,'w'},
                                         {0,'s'},
                                         {0,'a'},
                                         {0,'d'},
                                         {0,'k'},
                                         {0,0xDA},
                                         {0,0xD9},
                                         {0,0xD8},
                                         {0,0xD7}
                                       };

/*
**Event Types:** This is the index meaning of FUNCTION_MAP
0=buttonUpPressed
1=buttonDownPressed
2=buttonLeftPressed
3=buttonRightPressed
4=joystickPressed
5=joystickUp 
6=joystickDown
7=joystickLeft
8=joystickRight
*/

/*
**Action Types:**
0=Keyboard Pressed
1=Mouse Pressed
2=Mouse Wheel Down
*/

/*
**Arugments**
Depends on the Action Type
For Keyboard Pressed: Argument is the key ASCII number
For Mouse it's 
#define MOUSE_LEFT 1
#define MOUSE_RIGHT 2
#define MOUSE_MIDDLE 4
#define MOUSE_ALL (MOUSE_LEFT | MOUSE_RIGHT | MOUSE_MIDDLE)

/* KEYBOARD 
#define KEY_LEFT_CTRL   0x80
#define KEY_LEFT_SHIFT    0x81
#define KEY_LEFT_ALT    0x82
#define KEY_LEFT_GUI    0x83
#define KEY_RIGHT_CTRL    0x84
#define KEY_RIGHT_SHIFT   0x85
#define KEY_RIGHT_ALT   0x86
#define KEY_RIGHT_GUI   0x87

#define KEY_UP_ARROW    0xDA
#define KEY_DOWN_ARROW    0xD9
#define KEY_LEFT_ARROW    0xD8
#define KEY_RIGHT_ARROW   0xD7
#define KEY_BACKSPACE   0xB2
#define KEY_TAB       0xB3
#define KEY_RETURN      0xB0
#define KEY_ESC       0xB1
#define KEY_INSERT      0xD1
#define KEY_DELETE      0xD4
#define KEY_PAGE_UP     0xD3
#define KEY_PAGE_DOWN   0xD6
#define KEY_HOME      0xD2
#define KEY_END       0xD5
#define KEY_CAPS_LOCK   0xC1
#define KEY_F1        0xC2
#define KEY_F2        0xC3
#define KEY_F3        0xC4
#define KEY_F4        0xC5
#define KEY_F5        0xC6
#define KEY_F6        0xC7
#define KEY_F7        0xC8
#define KEY_F8        0xC9
#define KEY_F9        0xCA
#define KEY_F10       0xCB
#define KEY_F11       0xCC
#define KEY_F12       0xCD
#define KEY_F13       0xF0
#define KEY_F14       0xF1
#define KEY_F15       0xF2
#define KEY_F16       0xF3
#define KEY_F17       0xF4
#define KEY_F18       0xF5
#define KEY_F19       0xF6
#define KEY_F20       0xF7
#define KEY_F21       0xF8
#define KEY_F22       0xF9
#define KEY_F23       0xFA
#define KEY_F24       0xFB
*/



