#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#pragma once

#include <exception>
#include <string>

namespace Skeye
{
  namespace rend
  {
    struct Exception : 
      public std::exception
    {
      Exception(const std::string& message);
      virtual ~Exception() throw();
      virtual const char* what() const throw();

    private:
      std::string message;

    };
  }
}

#endif