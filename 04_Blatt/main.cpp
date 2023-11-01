#include "scopetimer.hpp"
#include <cstdlib>

void work01()
{
    ScopeTimer timer = ScopeTimer("work01");
    double numbers[10000];
    ScopeTimer* timer2 = new ScopeTimer("work01_loop01");
    for(int i = 0; i < 10000; ++i)
    {
        numbers[i] = double(std::rand())/double(RAND_MAX);
    }
    delete timer2;
    ScopeTimer* timer3 = new ScopeTimer("work01_loop02");
    for (int n = 10000; n > 1; n = n-1){
        for (int i = 0; i < n-1; i = i+1){
            if (numbers[i] > numbers[i+1]){
                double tmp = numbers[i];
                numbers[i] = numbers[i+1];
                numbers[i+1] = tmp;
            }
        }
    }
    delete timer3;
}

void work02()
{
    ScopeTimer timer = ScopeTimer("work02");
    int* buf[1024];

    for(int i = 2; i < 1024; ++i)
        buf[i] = new int[i];
    for(int i = 2; i < 1024; ++i)
        delete[] buf[i];
}

// counts the number of primes in an interval
int work03( int n0, int n1 )
{
    ScopeTimer timer = ScopeTimer("work03");
    int freq = n1-n0+1;
    for(int i = n0; i <= n1; ++i)
    {
        // Have fun: use the alternative iteration direction and see how fast
        // it gets!
        // for(int j = 2; j < i; ++j)
        for(int j = i-1; j > 1; --j)
        {
            if(i%j == 0)
            {
                --freq;
                break;
            }
       }
    }
    return freq;
}

int main(int, char**)
{
    ScopeTimer timer = ScopeTimer("main");
    work01();
    work02();
    work03(0, 10000);
}