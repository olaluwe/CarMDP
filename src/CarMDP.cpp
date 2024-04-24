// src/CarMDP.cpp
#include "../include/CarMDP.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>

CarMDP::CarMDP(double initVcold, double initVwarm, int iter, double thresh)
    : Vcold_n(initVcold), Vwarm_n(initVwarm), iterations(iter), threshold(thresh) {}

void CarMDP::runSimulation() {
    for (int i = 0; i < iterations; ++i) {
        double Vcold_next = std::max(1 + 0.9 * Vcold_n, 0.5 * (2 + 0.9 * Vcold_n) + 0.5 * (2 + 0.9 * Vwarm_n));
        double Vwarm_next = std::max(0.5 * (1 + 0.9 * Vwarm_n) + 0.5 * (1 + 0.9 * Vcold_n), -10 + 0.9 * Vwarm_n);
        
        std::stringstream cold_ss, warm_ss;
        cold_ss << std::fixed << std::setprecision(4) 
                << "max(1 + 0.9 * " << Vcold_n << ", 0.5 * (2 + 0.9 * " << Vcold_n << ") + 0.5 * (2 + 0.9 * " << Vwarm_n << ")) = " << Vcold_next;
        warm_ss << std::fixed << std::setprecision(4) 
                << "max(0.5 * (1 + 0.9 * " << Vwarm_n << ") + 0.5 * (1 + 0.9 * " << Vcold_n << "), -10 + 0.9 * " << Vwarm_n << ") = " << Vwarm_next;
        
        results.push_back({cold_ss.str(), warm_ss.str()});

        if (std::abs(Vcold_next - Vcold_n) <= threshold && std::abs(Vwarm_next - Vwarm_n) <= threshold) {
            std::cout << "Converged at iteration " << i+1 << std::endl;
            break;
        }

        Vcold_n = Vcold_next;
        Vwarm_n = Vwarm_next;
    }
}

void CarMDP::printResults() const {
    int id = 1;
    for (const auto& [cold, warm] : results) {
        std::cout << "Iteration " << id++ << ":\nCool: " << cold << "\nWarm: " << warm << std::endl;
    }
}