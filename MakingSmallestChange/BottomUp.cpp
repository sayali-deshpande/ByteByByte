/* Smallest Change - Bottom up approach
*  Question : Given an input amount of change x, write a function to determine the
*  minimum number of coins required to make that amount of change.
*  Ex: change(100) = 4;
*  change(1) = 1;
*/
// Complexity C * n (c= change, n = number of coins because that much banches exist for each iteration)

#include <iostream>
using namespace std;

int makechange(int change, int cache[ ], int coins[ ], int no_of_coins)
{
	int min_coins;
	if (change == 0) return 0;

	cache[0] = 0;

	for(int i = 1; i <= change; i++)
	{
		int minimum_change = 9999;
		for(int j = 0; j < no_of_coins ; j++)
		{
			if( i - coins[j] >= 0)
			{
				min_coins = cache[i - coins[j]] + 1;
				if(min_coins < minimum_change)
					minimum_change = min_coins;
			}
		}
		cache[i] = minimum_change;
	}
	return cache[change];
}

int main()
{
	int change = 45;
	int cache[150];

	int coins[ ] = {1,5,25,10};
	
	int no_of_coins = sizeof(coins)/sizeof(coins[0]);

	for(int i = 0; i <change; i++)
		cache[i] = -1;

	cout << "Minimum coins required for change "<< change <<"  :  "<<makechange(change, cache, coins, no_of_coins) << endl;

	return 0;
}
