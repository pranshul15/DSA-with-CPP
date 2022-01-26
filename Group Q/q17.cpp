#include<iostream>

using namespace std;

const int MOD = 1000000007;
int main()
{
	int N;
	long ans = 1;
	cout << "Entrez votre numero"<< endl;
	cin >> N;
	bool * primeno{ new bool[N]{}};
	for(int i = 2; i*i <= N; i++)
	{
		if(!primeno[i])
		{
			for(int j = i*i; j <= N; j+=i)
			{
				primeno[j] = true;
			}
		}
	}
	for(int i = 2; i <= N; i++)
	{
		if(!primeno[i])
		{
			ans = ((ans % MOD) * (i)) % MOD;
		}
	}
	cout << "Votre reponse :" << endl;
	cout << ans << endl;
	delete [] primeno;
	return 0;
}
