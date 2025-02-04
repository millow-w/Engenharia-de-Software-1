/**
 * @file model.h
 * @brief Declaration of the Model class.
 *
 * This file contains the declaration of the Model class, which manages 
 * a collection of systems and flows, and runs simulations over time.
 */

#ifndef MODEL_H
#define MODEL_H

#include "system.h"
#include "flow.h"
#include "vector"
using namespace std;

/**
 * @class Model
 * @brief Manages systems and flows, and runs simulations.
 *
 * The Model class manages a collection of systems and flows, and can execute
 * a simulation over a specified amount of time. The time progression is controlled
 * by the `run` function.
 */
class Model {
protected:
    vector<System*> systems; /**< Vector containing pointers to the systems */
    vector<Flow*> flows;     /**< Vector containing pointers to the flows */
    int time;                /**< The simulation time */

public:
    /**
     * @brief Default constructor for Model.
     *
     * Initializes the Model object with no systems or flows.
     */
    Model();

    /**
     * @brief Destructor for Model.
     *
     * Cleans up the resources used by the Model, including systems and flows.
     */
    virtual ~Model();

    /**
     * @brief Copy constructor for Model.
     *
     * Creates a copy of another Model object.
     *
     * @param model The Model object to copy.
     */
    Model(const Model &model);

    /**
     * @brief Adds a system to the model.
     *
     * @param system Pointer to the System to be added.
     */
    void add(System *system);

    /**
     * @brief Adds a flow to the model.
     *
     * @param flow Pointer to the Flow to be added.
     */
    void add(Flow *flow);

    /**
     * @brief Runs the simulation for a specified amount of time.
     *
     * The simulation is executed by advancing the time and updating
     * the systems and flows at each step.
     *
     * @param time The duration of the simulation.
     */
    void run(int time);

private:
    /**
     * @brief Assignment operator for Model (private).
     *
     * Prevents assignment between Model objects, as it is a private method.
     *
     * @param model The Model object to be assigned.
     * @return Reference to the assigned Model object.
     */
    Model &operator=(const Model &model);
};

#endif
