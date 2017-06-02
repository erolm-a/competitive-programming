#include <fstream>
#include <cinttypes>
#include <cmath>
#include <iostream>

using namespace std;

#define MAX_CACHE 1000000
long long dp[MAX_CACHE];
uint64_t cifre[] = {6, 2, 5, 5, 4, 5, 6 , 3, 7, 6};

void init();
uint64_t trova(uint64_t num);

uint64_t potenza10(int exp) // pow è solo approssimato
{
    uint64_t t = 1;
    while(exp-- > 0)
        t *= 10;

    return t;
}

int main()
{
    ifstream i_f("input.txt");
    ofstream o_f("output.txt");
    ofstream o_f2("output_strano.txt");

    uint64_t num;
    i_f >> num;

    init();
    o_f << trova(num);

    for(int i = 0; i < 150; i++)
        o_f2 << trova(i) << endl;

    return 0;
}


#define calculate(power) \
    for(i = power; i < power*10; i++)\
        dp[i] = i/power*dp[power-1] + dp[i%power] + (i%power + 1)*cifre[i/power] \
            + 10*(dp[i/power - 1] - cifre[0])

void init() {

    dp[0] = 6;
    for(int i = 0; i < 10; i++)
        dp[i] = dp[i-1] + cifre[i%10];

    uint64_t i;

    calculate(10);
    calculate(100);
    calculate(1000);
    calculate(10000);
    calculate(100000);

}

uint64_t trova(uint64_t num) {
    if(num < MAX_CACHE)
        return dp[num];

    // calcola numero di cifre
    uint64_t temp = num; int n = 0;

    while(temp > 0)
        n++, temp /= 10;


    uint64_t mask = potenza10(n-1), first = num / mask;

    return first * trova((int) mask - 1) + trova(num % mask) + ((num % mask) + 1)*cifre[first]
            + 10*(dp[first-1] - cifre[0]);
}
