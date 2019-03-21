/* Smallest Change - Recursive approach
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
	int minimum_change = 9999, min_coins;
	if (change == 0) return 0;

	if(cache[change] >= 0)
		return cache[change];

	for(int i = 0; i< no_of_coins; i++)
	{
		if( change - coins[i] >= 0)
		{
			min_coins = makechange(change - coins[i], cache, coins, no_of_coins);
			if( min_coins < minimum_change)
				minimum_change = min_coins;
		}
	}
	
	cache[change] = minimum_change + 1;
	return minimum_change + 1;
}

int main()
{
	int change = 120;
	int cache[150];

	int coins[ ] = {1,5,25,10};
	
	int no_of_coins = sizeof(coins)/sizeof(coins[0]);

	for(int i = 0; i <change; i++)
		cache[i] = -1;

	cout << "Minimum coins required for change "<< change <<"  :  "<<makechange(change, cache, coins, no_of_coins) << endl;

	return 0;
}
