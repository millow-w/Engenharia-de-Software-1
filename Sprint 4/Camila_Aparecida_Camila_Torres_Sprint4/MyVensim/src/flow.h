/**
 * @file flow.h
 * @brief Declaration of the Flow class.
 *
 * This file contains the declaration of the Flow class, which represents
 * a flow between two systems (source and target).
 */

#ifndef FLOW_H
#define FLOW_H 

#include "system.h"
using namespace std;

/**
 * @class Flow
 * @brief Represents a flow between two systems.
 *
 * The Flow class represents a flow between a source system and a target system.
 * The flow can execute a custom equation that needs to be implemented in the derived classes.
 */
class Flow {
    protected:
        System *source; /**< Pointer to the source system */
        System *target; /**< Pointer to the target system */

    public: 
        /**
         * @brief Default constructor for Flow.
         *
         * Initializes the Flow object with no source or target system.
         */
        Flow();

        /**
         * @brief Parameterized constructor for Flow.
         *
         * @param source Pointer to the source system.
         * @param target Pointer to the target system.
         */
        Flow(System *source, System *target);

        /**
         * @brief Destructor for Flow.
         *
         * Cleans up the resources used by the Flow object.
         */
        virtual ~Flow();

        /**
         * @brief Copy constructor for Flow.
         *
         * @param flow The Flow object to be copied.
         */
        Flow(const Flow &flow);

        /**
         * @brief Assignment operator for Flow.
         *
         * Assigns the values from one Flow object to another.
         *
         * @param flow The Flow object to be assigned.
         * @return Reference to the assigned Flow object.
         */
        Flow &operator=(const Flow &flow);

        /**
         * @brief Sets the source system of the flow.
         *
         * @param source Pointer to the source system.
         */
        void setSource(System *source);

        /**
         * @brief Gets the source system of the flow.
         *
         * @return Pointer to the source system.
         */
        System *getSource();

        /**
         * @brief Sets the target system of the flow.
         *
         * @param target Pointer to the target system.
         */
        void setTarget(System *target);

        /**
         * @brief Gets the target system of the flow.
         *
         * @return Pointer to the target system.
         */
        System *getTarget();

        /**
         * @brief Executes the equation of the flow.
         *
         * This is a pure virtual function that must be implemented
         * in derived classes to define the specific behavior of the flow.
         *
         * @return The result of the equation execution.
         */
        virtual double executeEquation() = 0;
};

#endif
