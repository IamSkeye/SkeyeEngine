#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#pragma once
namespace SkeyeEngine
{
  class Keyboard {
  private:
    bool getKey(int keyCode);
    bool getKeyDown(int keyCode);
    bool getKeyUp(int keyCode);

  public:
    Keyboard();
    ~Keyboard();
  };
}
#endif