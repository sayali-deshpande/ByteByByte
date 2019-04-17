/* Number of Ones in a Binary Number
   ● Question : Given an integer, write a function to compute the number of ones in
     the binary representation of the number.
   ● Eg. Given an integer, write a function to compute the number of ones in the
     binary representation of the number.
	 
	 Time complexity = O(log x)
*/

#include <iostream>
using namespace std;

int number_of_ones(int num)
{
    int sum = 0;
    while(num > 0)
    {
        sum += num & 1;
        num >>= 1;
    }
    return sum;
}

int main()
{
    int num = 10;
    
    cout<<endl<<number_of_ones(num);
    return 0;
}