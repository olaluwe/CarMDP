// include/CarMDP.h
#ifndef CAR_MDP_H
#define CAR_MDP_H

#include <vector>
#include <string>

class CarMDP {
private:
    double Vcold_n, Vwarm_n;
    int iterations;
    double threshold;
    std::vector<std::pair<std::string, std::string>> results;

public:
    CarMDP(double initVcold = 0.0, double initVwarm = 0.0, int iter = 100, double thresh = 0.1);
    void runSimulation();
    void printResults() const;
};

#endif // CAR_MDP_H