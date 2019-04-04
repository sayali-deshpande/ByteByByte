/* ● Question : Given two integers, write a function to determine whether or not their
 * binary representations differ by a single bit.
*/

#include <iostream>
using namespace std;

int isGrey(int a, int b)
{
    int x = a ^ b;
    return (x & (x - 1) == 0);
}

int main()
{
    int a = 5, b = 3;
    
    if(isGrey(a,b))
        cout << endl << "Yes";
    else
        cout << endl << "No";

    return 0;
}
