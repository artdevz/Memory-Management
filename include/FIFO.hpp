#pragma once
#include <vector>
#include <queue>
#include <unordered_set>

class FIFO {

public:
    explicit FIFO(size_t frames);
    int Simulate(const std::vector<int>& references);

private:
    size_t frames;
    std::queue<int> queue;
    std::unordered_set<int> pagesInMemory;

};