#include <iostream>

using namespace std;

int main()
{
	int n,u, c,p,k,o,count=0,num=0;
	cin >> n;

	char* str = new char[n];

	for (int i = 0; i < n; i++)
	{
		cin>>str[i];
	}

	cin >> p;
	char* p_str = new char[p];

	for (int i = 0; i < p; i++)
	{
		cin >> p_str[i];
	}

	cin >> u;
	char* nstr = new char[u];
	for (int i = 0; i < u; i++)
	{
		cin >> nstr[i];
	}
	
	for (int i = 0; i <= n - p; i++)
	{
		k = 0;
		for (int j = 0; j < p; j++)
		{
			if (str[i + j] == p_str[j])
			{
				k++;
			}
		}
		if (k == p)
		{
			count++;
			i += p-1;
		}
	}
	
	o = n + count * (u-p)

	char* ans = new char[o];
	for (int i = 0; i < n; i++)
	{
		k = 0;
		for (int j = 0; j < p; j++)
		{
			if (str[i + j] == p_str[j])
			{
				k++;
			}
		}
		if (k == p)
		{
			count++;
			for (int z = 0; z < u; z++)
			{
				ans[num] = nstr[z];
				num++;
			}
			i += p-1;
		}
		else
		{
			ans[num] = str[i];
			num++;
		}
	}
	for (int i = 0; i < o; i++)
	{
		cout << ans[i];
	}
}
