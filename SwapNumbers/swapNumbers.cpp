/* ● Question : Given two integers, write a function that swaps them without using
 * any temporary variables
 */
 
#include <iostream>

using namespace std;

void swap(int a, int b)
{
    a = a + b;
    b = a - b;
    a = a - b;
    cout<<endl<<"Numbers after swap A = "<<a <<"  B = "<<b;
}

int main()
{
    int a = 10, b = 20;
    
    cout<<endl<<"Numbers before swap A = "<<a <<"  B = "<<b;

    swap(a,b);
    return 0;
}
