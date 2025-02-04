#ifndef FLOW_H
#define FLOW_H 

#include "system.h"
using namespace std;

class Flow {
    protected:
        System *source;
        System *target;

    public: 
        Flow();
        Flow(System *source, System *target);
        virtual ~Flow();

        Flow(const Flow &flow);

        Flow &operator=(const Flow &flow);

        void setSource(System *source);
        System *getSource();

        void setTarget(System *target);
        System *getTarget();

        virtual double executeEquation() = 0;
};

#endif