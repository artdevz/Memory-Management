#include "ReferenceGenerator.hpp"
#include <random>
#include <fstream>

namespace ReferenceGenerator {

    std::vector<int> Generate(int totalReferences) {
        std::vector<int> references;
        std::random_device rd;
        std::mt19937 gen(rd());
        // std::mt19937 gen(12345);

        int offset = 0;

        while ((int)references.size() < totalReferences) {
            std::uniform_int_distribution<> worksetSizeDist(4, 6);
            int worksetSize = worksetSizeDist(gen);

            std::uniform_int_distribution<> durationDist(300, 700);
            int duration = durationDist(gen);

            std::uniform_int_distribution<> pageDist(offset, offset + worksetSize - 1);

            std::uniform_real_distribution<> outsideAccessDist(0.0, 1.0);

            for (int i = 0; i < duration && (int)references.size() < totalReferences; i++) {
                if (outsideAccessDist(gen) < 0.1) { // 10%
                    std::uniform_int_distribution<> outsideDist(0, offset + worksetSize + 50);
                    int outsidePage = outsideDist(gen);
                    if (outsidePage >= offset && outsidePage < offset + worksetSize) outsidePage = offset + worksetSize + 1 + (outsidePage % 50);
                    references.push_back(outsidePage);
                }
                else references.push_back(pageDist(gen)); // 90%
            }

            offset += worksetSize + 20;
        }

        std::ofstream out("references.txt");
        for (int reference : references) out << reference << "\n";
        out.close();

        return references;
    }

}