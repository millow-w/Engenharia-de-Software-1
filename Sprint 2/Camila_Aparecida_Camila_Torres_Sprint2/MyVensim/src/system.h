#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
using namespace std;

class System{
  protected:
      double value;
  public: 
      System();
      System(double value);
      virtual ~System();

      System(const System &system);

      System &operator=(const System &system);

      void setValue(double value);
      double getValue();
      
      void show();
};

#endif