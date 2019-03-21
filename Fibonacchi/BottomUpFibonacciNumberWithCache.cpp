// C++ Program : fibonacci number - Top down approach

#include <iostream>

using namespace std;

int fib (int num)
{
    if( num == 0 ) return 0;
    if( num == 1 ) return 1;
    
    int cache[num];
    
    cache[0] = 0;
    cache[1] = 1;
    
    for( int i = 2; i <= num; i++)
    {
        cache[i] = cache[i - 1] + cache[i - 2];
    }
    
    return cache[num];
}

int main()
{
    int num = 4;
    
    cout << fib(num);
    return 0;
}
