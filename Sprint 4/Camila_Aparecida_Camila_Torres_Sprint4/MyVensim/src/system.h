/**
 * @file system.h
 * @brief Declaration of the System class.
 *
 * This file contains the declaration of the System class, which represents
 * a system with a specific value that can be manipulated.
 */

#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
using namespace std;

/**
 * @class System
 * @brief Represents a system with a specific value.
 *
 * The System class holds a value (e.g., for simulation purposes) and provides
 * functions to get and set this value. It also includes functions for copying
 * and displaying the system's value.
 */
class System {
  protected:
      double value; /**< The value associated with the system */

  public: 
      /**
       * @brief Default constructor for System.
       *
       * Initializes the system with a default value of 0.
       */
      System();

      /**
       * @brief Parameterized constructor for System.
       *
       * Initializes the system with the provided value.
       *
       * @param value The initial value of the system.
       */
      System(double value);

      /**
       * @brief Destructor for System.
       *
       * Cleans up resources used by the System object.
       */
      virtual ~System();

      /**
       * @brief Copy constructor for System.
       *
       * Creates a copy of another System object.
       *
       * @param system The System object to copy.
       */
      System(const System &system);

      /**
       * @brief Assignment operator for System.
       *
       * Assigns the values from one System object to another.
       *
       * @param system The System object to be assigned.
       * @return Reference to the assigned System object.
       */
      System &operator=(const System &system);

      /**
       * @brief Sets the value of the system.
       *
       * @param value The value to set for the system.
       */
      void setValue(double value);

      /**
       * @brief Gets the value of the system.
       *
       * @return The current value of the system.
       */
      double getValue();

      /**
       * @brief Displays the current value of the system.
       *
       * Prints the value of the system to the console.
       */
      void show();
};

#endif
