#include "../../src/system.h"
#include "../../src/flow.h"
#include "../../src/model.h"
#include "funcional_tests.h"
#include <cmath>
#include <assert.h>
#define PMAX 70

class ExponentialFlow : public Flow{
    public:
        ExponentialFlow() : Flow(nullptr, nullptr) {}
        ExponentialFlow(System *source, System *target) : Flow(source, target) {}
        double executeEquation() override{
            return 0.01 * this->getSource()->getValue();
        }
};

class LogisticFlow : public Flow{
    public:
        LogisticFlow() : Flow(nullptr, nullptr) {}
        LogisticFlow(System *source, System *target) : Flow(source, target) {}
        double executeEquation() override{
            double value = this->getTarget()->getValue();
            return 0.01 * value * (1 - value / PMAX);
        }
};

void exponentialFuncionalTest(){
    Model *model = new Model();
    System *pop1 = new System(100); 
    System *pop2 = new System();
    ExponentialFlow *exponencial = new ExponentialFlow();

    exponencial->setSource(pop1);
    exponencial->setTarget(pop2);

    model->add(pop1);
    model->add(pop2);
    model->add(exponencial);

    model->run(100);

    double tolerance = 1e-4;
    assert(fabs(pop1->getValue() - 36.6032) < tolerance);
    assert(fabs(pop2->getValue() - 63.3968) < tolerance);

    std::cout << "Exponential Test Passed" << std::endl;
}

void logisticalFuncionalTest(){
    Model *model = new Model();
    System *p1 = new System(100); 
    System *p2 = new System(10);
    LogisticFlow *logistic = new LogisticFlow();

    logistic->setSource(p1);
    logistic->setTarget(p2);

    model->add(p1);
    model->add(p2);
    model->add(logistic);

    model->run(100);

    double tolerance = 1e-4;
    assert(fabs(p1->getValue() - 88.2167) < tolerance);
    assert(fabs(p2->getValue() - 21.7833) < tolerance);

    std::cout << "Logistic Test Passed" << std::endl;
}

void complexFuncionalTest(){
    Model *model = new Model();

    System *Q1 = new System(100); 
    System *Q2 = new System();
    System *Q3 = new System(100);
    System *Q4 = new System();
    System *Q5 = new System();

    ExponentialFlow *v = new ExponentialFlow(Q4, Q1);
    ExponentialFlow *u = new ExponentialFlow(Q3, Q4);
    ExponentialFlow *f = new ExponentialFlow(Q1, Q2);
    ExponentialFlow *g = new ExponentialFlow(Q1, Q3);
    ExponentialFlow *t = new ExponentialFlow(Q2, Q3);
    ExponentialFlow *r = new ExponentialFlow(Q2, Q5);

    model->add(Q1);
    model->add(Q2);
    model->add(Q3);
    model->add(Q4);
    model->add(Q5);

    model->add(v);
    model->add(u);
    model->add(f);
    model->add(g);
    model->add(t);
    model->add(r);

    model->run(100);

    double tolerance = 1e-4;
    assert(fabs(Q1->getValue() - 31.8513) < tolerance);
    assert(fabs(Q2->getValue() - 18.4003) < tolerance);
    assert(fabs(Q3->getValue() - 77.1143) < tolerance);
    assert(fabs(Q4->getValue() - 56.1728) < tolerance);
    assert(fabs(Q5->getValue() - 16.4612) < tolerance);

    std::cout << "Complex Test Passed" << std::endl;
}