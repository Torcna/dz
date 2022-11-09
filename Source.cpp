#include <iostream>
#include <cstdlib>
#include <locale.h>
#include<cstdio>
#include<stdio.h>
using namespace std;

int menya(int n, char* buff, char* p_str, char* nstr, int p, int u)
{
	int o;
	int count = 0;
	int k = 0;
	int num = 0;
	for (int i = 0; i <= n - p; i++)
	{
		k = 0;
		for (int j = 0; j < p; j++)
		{
			if (buff[i + j] == p_str[j])
			{
				k++;
			}
		}
		if (k == p)
		{
			count++;
			i += p - 1;
		}
	}

	o = n + count * (u - p);

	char* ans = new char[o];
	for (int i = 0; i < n; i++)
	{
		k = 0;
		for (int j = 0; j < p; j++)
		{
			if (buff[i + j] == p_str[j])
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
			i += p - 1;
		}
		else
		{
			if (buff[i] != '\n')
			{
				ans[num] = buff[i];
				num++;
			}		
		}
	}
	for (int i = 0; i < o; i++)
	{
		cout << ans[i];
	}
	return count;
}

int main()

{
	int n, u, c, p, k, m ,j = 0;
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
	setlocale(LC_ALL, "Russian");
	char in[] = "war and peace.txt";
	FILE** pRead = new FILE*;
	freopen_s(pRead,in, "r", stdin);
	if (*pRead != 0)
	{
		char buff[5000];
		m = 0;
		while (gets_s(buff, 5000))
		{
			n = 0;
			while (buff[j] != '\n')
			{
				j++;
				n++;
			}
			m += menya(n,buff,p_str, nstr, p, u);
			cout << endl;
			
		}
	}
}
