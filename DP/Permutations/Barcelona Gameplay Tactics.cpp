#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>

#define mod 1000000007
#define ll long long int
#define maxn 10000
#define pb push_back
#define seive_max 10000

using namespace std;

int ar[maxn+1];

//int prefix_sum[maxn+1];
//int seive[seive_max+1] = {0};
//vector <int> primes;

/*void init_prefix_sum(ll n)
{
	prefix_sum[0] = 0;
	for(ll i=1; i<=n; i++)
		prefix_sum[i] = prefix_sum[i-1] + ar[i-1];
}*/

/* seive[prime] == 0 
void generate_sieve()
{
	seive[0] = seive[1] = -1;

	for(int i=2; i<=seive_max; i++)
	{
		if(seive[i]==0)
		{
			primes.pb(i);
			for(int j=i+i; j<=seive_max; j=j+i)
				seive[j]++;
		}
	}
}*/

ll dp[1001][2];

int main()
{
	ll t, n, k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		dp[0][0] = 1;
		dp[0][1] = 0;

		for(ll i=1; i<=n; i++)
		{
			dp[i][0] = dp[i-1][1];
			dp[i][1] = ((dp[i-1][0]*k)%mod + (dp[i-1][1]*(k-1))%mod)%mod;
		}
		cout<<dp[n][0]<<endl;
	}
	return 0;
}
