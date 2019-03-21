// C++ Program : fibonacci number - Top down approach without cache

#include <iostream>

using namespace std;

int fib (int num)
{
    if( num == 0 ) return 0;
    if( num == 1 ) return 1;
    
    int n0  = 0, n1 = 1, n2;
    
    for(int i = 2; i <= num; i++)
    {
        n2 = n0 + n1;
        n0 = n1;
        n1 = n2;
    }
   
    return n2;
}

int main()
{
    int num = 10;
    
    cout << fib(num);
    return 0;
}
