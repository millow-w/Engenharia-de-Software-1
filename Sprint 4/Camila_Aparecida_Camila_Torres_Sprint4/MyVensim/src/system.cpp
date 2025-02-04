#include "system.h"

System::System(){
    value = 0;
}

System::System(double value){
    this->value = value;
}

System::~System(){}

System::System(const System &system){
    this->value = system.value;
}

System &System::operator=(const System &system) {
  if (this != &system) {
    this->value = system.value;
  }
  return *this;
}

void System::setValue(double value){
    this->value = value;
}

double System::getValue(){
    return value;
}

void System::show(){
    std::cout<< value <<std::endl;
}