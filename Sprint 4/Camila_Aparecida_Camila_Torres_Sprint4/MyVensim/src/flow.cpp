#include "flow.h"

Flow::Flow(){
    source = nullptr;
    target = nullptr;
}

Flow::Flow(System *source, System *target){
    this->source = source;
    this->target = target;
}

Flow::~Flow(){}

Flow::Flow(const Flow &flow){
    this->source = flow.source;
    this->target = flow.target;
}

Flow &Flow::operator=(const Flow &flow){
    if(this != &flow){
        this->source = flow.source;
        this->target = flow.target;
    }
    return *this;
}

void Flow::setSource(System *source){
    this->source = source;
}

System* Flow::getSource(){
    return source;
}

void Flow::setTarget(System *target){
    this->target = target;
}

System* Flow::getTarget(){
    return target;
}