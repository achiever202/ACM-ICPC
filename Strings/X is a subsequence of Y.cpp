#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>

#define mod 1000000007
#define ll long long int
#define maxn 10000
#define seive_max 10000

using namespace std;

bool check_subsequence(string a, string b)
{
	int i=0, j=0;
	while(i<a.length() && j<b.length())
	{
		if(a[i]==b[j])
			i++;
		j++;
	}
	if(i==a.length())
		return true;
	else
		return false;
}

int main()
{
	int t;
	string a, b;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		if(a.length()>b.length())
		{
			string temp = a;
			a = b;
			b = temp;
		}

		if(check_subsequence(a, b))
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}
