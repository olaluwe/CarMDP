// main.cpp
#include "../include/CarMDP.h"
#include "../include/Constants.h"

int main() {
  Constants constants;

  std::vector<double> initialStateValues = constants.V_INITIAL;

  // This project only have two states
  if (!initialStateValues.empty()) { // Ensure there are at least two elements
    double initialStateValueCold = initialStateValues.front();        // Get an iterator pointing to the first element
    double initialStateValueWarm = initialStateValues.back(); // Dereference the iterator to get the second element

    int resultThreshold = constants.THRESHOLD;
    int maxIteration = constants.MAX_ITERATIONS;

    CarMDP carMDP(initialStateValueCold, initialStateValueWarm, maxIteration, resultThreshold);

    carMDP.runSimulation();
    carMDP.printResults();
  }

  return 0;
}
