#include <iostream>
#include <time.h>
#include<array>
#include<iomanip>
using namespace std;

int main()
{
	srand(time(0));
	int no_of_times = rand() % 500;
	int cards_to_move;
	array<string, 52> deck;
	array<string, 52> shuffled_deck;
	for(int i = 0; i < 52; i++)
	{
		cin >> deck[i];
	}
	cout << endl << endl;
	for(int i = 0; i < no_of_times; i++)
	{
		int k = 0;
		cards_to_move = rand() % 52;
		for(int j = 51; j >= cards_to_move; j--)
		{
			shuffled_deck[k] = deck[j];
			k++;
		}
		for(int p = 0; p < cards_to_move; p++)
		{
			shuffled_deck[k] = deck[p];
			k++;
		}
		copy(begin(shuffled_deck), end(shuffled_deck), begin(deck));
	}
	for(int i = 0; i < 52; i++)
	{
	        if((i+1)%13 == 0)
		{
			cout << deck[i] << endl;
		}
		else
		{
			cout << deck[i] << setw(5);
		}	
	}
	return 0;
}
