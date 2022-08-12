#include<iostream>

using namespace std;

int main()
{
	string str;
	cout << "Enter a string :" << endl;
	getline(cin, str);
	int tmp, beg = 0, n = str.length();
	for (int i =0; i <= n; i++)
	{
		if(str[i] == char(32))
		{
			tmp = str[beg];
			str[beg] = str[i-1];
			str[i-1] = tmp;
			beg = i+1;
			continue;
		}
		else if(i == n-1)
		{
			tmp = str[beg];
			str[beg] = str[i];
			str[i] = tmp;
		}
	}
	cout << str << endl;
	return 0;
}
