#ifndef MODEL_H
#define MODEL_H

#include "system.h"
#include "flow.h"
#include "vector"
using namespace std;

class Model {
protected:
    vector<System*> systems;
    vector<Flow*> flows;
    int time;  

public:
    Model();
    virtual ~Model();

    Model(const Model &model); 

    void add(System *system);
    void add(Flow *flow);

    void run(int time);

private: 
    Model &operator=(const Model &model);
};

#endif