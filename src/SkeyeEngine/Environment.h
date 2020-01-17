#ifndef _ENVIRONMENT_H_
#define _ENVIRONMENT_H_

#pragma once



namespace Skeye
{
  class Environment
  {
  private:
    float deltaTime;

  public:
    Environment();
    ~Environment();

    float getDeltaTime();

  };
}
#endif