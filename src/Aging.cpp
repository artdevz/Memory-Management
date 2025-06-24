#include "Aging.hpp"
#include <algorithm>

Aging::Aging(size_t frames) :
    frames(frames) {}

int Aging::Simulate(const std::vector<int>& references) {
    memory.clear();
    int pageFaults = 0;
    int agingInterval = 10;

    for (size_t i = 0; i < references.size(); i++) {
        int reference = references[i];
        bool found = false;

        for (auto& page : memory) {
            if (page.number == reference) {
                page.referenced = true;
                found = true;
                break;
            } 
        }

        if (!found) {
            pageFaults++;

            if (memory.size() < frames) {
                memory.push_back({reference, 0b10000000, true});
            }
            else {
                auto victim = std::min_element(memory.begin(), memory.end(),
                    [](const Page& a, const Page& b) { return a.counter < b.counter; }
                );

                *victim = {reference, 0b10000000, true};
            }
        }

        if ((i + 1) % agingInterval == 0) GrowOld();
    }

    return pageFaults;
}

void Aging::GrowOld() {
    for (auto& page : memory) {
        page.counter >>= 1;
        if (page.referenced) page.counter |= 0b10000000;
        page.referenced = false;
    }
}