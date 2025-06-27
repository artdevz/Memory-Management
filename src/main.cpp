#include <iostream>
#include <vector>
#include "FIFO.hpp"
#include "Aging.hpp"
#include "ReferenceGenerator.hpp"
#include "GnuplotWrapper.hpp"

constexpr int NUM_SIMULATIONS = 10;

int main(int argc, char* argv[]) {
    std::vector<int> framesVec = {1, 2, 3, 5, 10, 15};
    std::vector<float> fifoAvgFaultsVec;
    std::vector<float> agingAvgFaultsVec;
    
    for (int frames : framesVec) {
        int fifoTotal = 0;
        int agingTotal = 0;
        
        for (int i = 0; i < NUM_SIMULATIONS; i++) {
            auto references = ReferenceGenerator::Generate();

            FIFO fifoSimulator(frames);
            fifoTotal += fifoSimulator.Simulate(references);

            Aging agingSimulator(frames);
            agingTotal += agingSimulator.Simulate(references);
        }

        float fifoAvg = (float)fifoTotal / NUM_SIMULATIONS;
        float agingAvg = (float)agingTotal / NUM_SIMULATIONS;

        fifoAvgFaultsVec.push_back(fifoAvg);
        agingAvgFaultsVec.push_back(agingAvg);
        std::cout << "[INFO] Frames: " << frames << " | FIFO: " << fifoAvg << " | Aging: " << agingAvg << "\n";

    }

    GnuplotWrapper plotter;
    plotter.Plot(framesVec, fifoAvgFaultsVec, "FIFO", agingAvgFaultsVec, "Aging", "Comparação FIFO x Aging", "fifo_plot.png");

    return 0;
}