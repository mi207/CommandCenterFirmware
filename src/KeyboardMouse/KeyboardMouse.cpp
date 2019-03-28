#include "KeyboardMouse.h"

KeyboardMouseClass KeyboardMouse;

KeyboardMouseClass::KeyboardMouseClass()
{
    //Nothing to do;
    
}

void KeyboardMouseClass::keyboardPress(uint8_t key, bool prs)
{
  if(prs)
  {
    Keyboard.press(key);
  }
  else
  {
    Keyboard.release(key);
  }
}

void KeyboardMouseClass::mousePress(uint8_t btn, bool prs)
{
  if(prs)
  {
    Mouse.press(btn);
  }
  else
  {
    Mouse.release(btn);
  }
}

void KeyboardMouseClass::mouseWheelDownWithDelay(uint8_t step,bool prs)
{
  if (prs)
  {
    unsigned long currentTime = millis();
    if(currentTime - lastWheelMove >= mouseWheelDelay) // slow it down
    {
      //wheel scroll down action, we could change step if we wanted to down the line
      //but keeping it to -1 for now to make config less error prone
      Mouse.move(0,0,-1); 
      lastWheelMove = currentTime;
    }
  }
}

void KeyboardMouseClass::mouseMoveWithDelay(int yawReading,int pitchReading)
{
  unsigned long currentTime = millis();
  if(currentTime - lastMouseMove >= mouseMoveDelay) // slow it down
  {
    Mouse.move(yawReading, pitchReading, 0);
    lastMouseMove = currentTime;
  }
}

