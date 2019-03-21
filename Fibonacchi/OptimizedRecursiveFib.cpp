//C++ Program : Optimized recursive fibonacci -  every number is calculated only once

#include <iostream>

using namespace std;

int getFib(int num, int cache[])
{
   if(cache[num] != -1)
    return cache[num];
    
   cache[num] = getFib(num - 1, cache) + getFib(num - 2, cache);
   return cache[num];
}

int fib(int num)
{
    if (num == 0) return 0;
    if (num == 1) return 1;
    
    int cache[num];
    
    for(int i = 0; i <= num; i++)
        cache[i] = -1;
        
    cache[0] = 0;
    cache[1] = 1;
    
    return getFib(num,cache);
}

int main()
{
    int num  = 4;
    cout << fib(num);
    return 0;
}