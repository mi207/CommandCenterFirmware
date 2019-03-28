#ifndef KEYBOARDMOUSE_H
#define KEYBOARDMOUSE_H


#include "Mouse.h"
#include "Keyboard.h"

class KeyboardMouseClass
{
    public:
        KeyboardMouseClass();
        void keyboardPress(uint8_t key, bool prs);
        void mousePress(uint8_t btn, bool prs);
        void mouseWheelDownWithDelay(uint8_t btn, bool prs);
        void mouseMoveWithDelay(int yawReading, int pitchReading);
        unsigned long lastMouseMove=0;;
        unsigned long lastWheelMove=0;
        uint8_t mouseMoveDelay = 5;
        uint8_t mouseWheelDelay= 150;
        
};

extern KeyboardMouseClass KeyboardMouse;

#endif

