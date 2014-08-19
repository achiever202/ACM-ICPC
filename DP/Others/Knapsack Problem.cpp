#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define ll long long int
#define maxn 100002
#define mod 1000000007
#define pb push_back
#define pb_ pop_back

using namespace std;

ll n, sum = 0;
vector <ll>  first, second;

bool comp(ll i, ll j)
{
	return i>j;
}

ll table[300000][5];

int main()
{
	cin>>n;
	for(ll i=0; i<n; i++)
	{
		ll w, c;
		cin>>w>>c;

		sum += w;

		if(w==1)
			first.pb(c);
		else
			second.pb(c);
	}

	sort(first.begin(), first.end(), comp);
	sort(second.begin(), second.end(), comp);

	table[0][0] = 0;
	table[0][1] = 0;
	table[0][2] = 0;

	if(first.size()>0)
	{
		table[1][0] = first[0];
		table[1][1] = 1;
		table[1][2] = 0;
	}
	else
	{
		table[1][0] = 0;
		table[1][1] = 0;
		table[1][2] = 0;
	}

	table[2][0] = 0;

	if(sum>1)
	{
		if(first.size()>1)
		{
			table[2][0] = first[0] + first[1];
			table[2][1] = 2;
			table[2][2] = 0;
		}

		if(second.size()>0 && table[2][0]<second[0])
		{
			table[2][0] = second[0];
			table[2][1] = 0;
			table[2][2] = 1;
		}

		//dp[2][0] = max(dp[1][0], dp[2][0]);
	}

	for(ll i=3; i<=sum; i++)
	{
		table[i][0] = 0;

		if(table[i-1][0]>0 && table[i-1][1]<first.size())
		{
			table[i][0] = table[i-1][0] + first[table[i-1][1]];
			table[i][1] = table[i-1][1] + 1;
			table[i][2] = table[i-1][2];
		}

		if(table[i-2][0]>0 && table[i-2][2]<second.size() && table[i-2][0]+second[table[i-2][2]]>table[i][0])
		{
			table[i][0] = table[i-2][0] + second[table[i-2][2]];
			table[i][1] = table[i-2][1];
			table[i][2] = table[i-2][2] + 1;
		}
	}

	for(ll i=1; i<=sum; i++)
		cout<<max(table[i][0], table[i-1][0])<<" ";

	return 0;

}