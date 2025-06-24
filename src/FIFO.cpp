#include "FIFO.hpp"

FIFO::FIFO(size_t frames) :
    frames(frames) {}

int FIFO::Simulate(const std::vector<int>& references) {
    std::queue<int> queue;
    std::unordered_set<int> pagesInMemory;
    int pageFaults = 0;

    for (int reference : references) {
        if (pagesInMemory.count(reference)) continue;

        pageFaults++;

        if (queue.size() >= frames) {
            int removed = queue.front();
            queue.pop();
            pagesInMemory.erase(removed);
        }

        queue.push(reference);
        pagesInMemory.insert(reference);
    }

    return pageFaults;
}