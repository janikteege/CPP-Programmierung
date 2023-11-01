#pragma once

#include <ctime>
#include <iostream>

// The ScopeTimer measures the time between construction and
// destruction and writes it formatted with its name to the console.
class ScopeTimer{
public: 
    ScopeTimer(const char* name);
    ~ScopeTimer();
private:    
    inline static size_t nActiveTimers = 0;

    const char* name;
    std::clock_t clockStart;
};