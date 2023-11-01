#include "scopetimer.hpp"

ScopeTimer::ScopeTimer(const char* name) {
    this->name = name;
    // Indentation for every "outer" timer
    for (size_t i = 0; i < this->nActiveTimers; i++)
    {
        std::cout << "\t";
    }
    std::cout << "Starting Timer " << "\"" << name << "\"\n";
    this->clockStart = std::clock();
    this->nActiveTimers++;

}

ScopeTimer::~ScopeTimer() {
    this->nActiveTimers--;
    std::clock_t clockEnd = std::clock();
    double time_ms = 1000.0 * (clockEnd - this->clockStart) / CLOCKS_PER_SEC;
    // Indentation for every "outer" timer
    for (size_t i = 0; i < this->nActiveTimers; i++)
    {
        std::cout << "\t";
    }
    std::cout << "Timer " << "\"" << name << "\" " << "took " << time_ms << " ms\n";
}