// James Fehrmann
// Simple Binary Tree Walker
// License: MIT
// Editor: Neovim
// Date: 01/17/24

#include <chrono>
#include <iostream>
using namespace std::chrono;

time_point<high_resolution_clock> now() { return high_resolution_clock::now(); }

float getDeltaTime(time_point<high_resolution_clock> lastTime) {
    return duration_cast<duration<float>>(now() - lastTime).count();
}

time_point<high_resolution_clock> updateLastTime() { return now(); }

// time sink
void sleep(int ms) {
    float z = ms / 1000.f;
    time_point<high_resolution_clock> lastTime = updateLastTime();
    while (getDeltaTime(lastTime) < z) {
        // grab a snickers
    }
}



void printBreak() { std::cout << "-----------------------" << std::endl; }

int main() {
    return 0;
}
