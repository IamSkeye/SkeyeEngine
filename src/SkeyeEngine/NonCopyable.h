#ifndef _NON_COPYABLE_H_
#define _NON_COPYABLE_H_

#pragma once

/*
* Classes inherit this so that they become non copyable
*/

namespace Skeye
{
  class NonCopyable
  {
  protected:
    NonCopyable() {}
    ~NonCopyable() {}
  private:
    NonCopyable(const NonCopyable &);
    NonCopyable& operator=(const NonCopyable &);
  };
}

#endif