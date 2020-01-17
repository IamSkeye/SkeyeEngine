#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#pragma once
namespace Skeye
{
  class Keyboard 
  {
  private:
    //std::vector<int> keyCodes;

  public:
    Keyboard();
    ~Keyboard();

    bool getKey(int keyCode);
    bool getKeyDown(int keyCode);
    bool getKeyUp(int keyCode);

  };
}
#endif