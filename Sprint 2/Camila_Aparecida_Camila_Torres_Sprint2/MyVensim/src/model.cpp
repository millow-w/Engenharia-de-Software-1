#include "model.h"

Model::Model() : time(0) {}

Model::~Model(){}

void Model:: add(System *system){
    this->systems.push_back(system);
}

void Model:: add(Flow *flow){
    this->flows.push_back(flow);
}

void Model::run(int time) {
    std::vector<double> v(this->flows.size());
    for (int t = 1; t <= time; t++) {
        size_t i = 0;
        for (auto &flow : this->flows) {
            v[i] = flow->executeEquation();
            i++;
        }
        i = 0;
        for (auto &flow : this->flows) {
            System* source = flow->getSource();
            source->setValue(source->getValue() - v[i]);

            System* target = flow->getTarget();
            target->setValue(target->getValue() + v[i]);
            
            i++;
        }
    }
}

Model::Model(const Model &model){
    this->time = model.time;
    this->flows = model.flows;
    this->systems = model.systems;
}

Model &Model::operator=(const Model &model){
    if (this != &model){

        this->time = model.time;
        
        this->systems.clear();
        this->flows.clear();

        this->systems.insert(this->systems.begin(), model.systems.begin(), model.systems.end());
        this->flows.insert(this->flows.begin(), model.flows.begin(), model.flows.end());
    }

    return *this;
}