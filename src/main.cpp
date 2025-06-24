#include <iostream>
#include <vector>
#include "FIFO.hpp"
#include "Aging.hpp"
#include "ReferenceGenerator.hpp"
#include "GnuplotWrapper.hpp"

int main(int argc, char* argv[]) {
    auto references = ReferenceGenerator::Generate();

    std::vector<int> framesVec = {1, 2, 3, 5, 10, 15};
    std::vector<int> fifoFaultsVec;
    std::vector<int> agingFaultsVec;

    for (int frames : framesVec) {
        FIFO fifoSimulator(frames);
        int fifoFaults = fifoSimulator.Simulate(references);
        fifoFaultsVec.push_back(fifoFaults);

        Aging agingSimulator(frames);
        int agingFaults = agingSimulator.Simulate(references);
        agingFaultsVec.push_back(agingFaults);

        std::cout << "[INFO] Frames: " << frames << " | FIFO: " << fifoFaults << " | Aging: " << agingFaults << "\n";
    }

    GnuplotWrapper plotter;
    plotter.Plot(framesVec, fifoFaultsVec, "FIFO", agingFaultsVec, "Aging", "Comparação FIFO x Aging", "fifo_plot.png");

    return 0;
}