#pragma once
#include <vector>
#include <unordered_map>
#include <bitset>

struct Page {
    int number;
    u_int8_t counter = 0;
    bool referenced = false;
};

class Aging {

public:
    explicit Aging(size_t frames);
    int Simulate(const std::vector<int>& references);

private:
    size_t frames;    
    std::vector<Page> memory;

    void GrowOld();

};