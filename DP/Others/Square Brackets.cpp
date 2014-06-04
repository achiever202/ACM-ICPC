/*
 * Here, we chose a state dp[i][j] as the number of sequences in which an expression of length i has j '[' brackets.
 * Now, for the ith place,
 *  if we add a '[' bracket, then dp[i][j] = dp[i-1][j-1], i.e. number of sequences having j '[' brackets will be equal to the number of 
 *  sequences having j-1 '[' brackets in i-1 length.
 *  Also, if we add a ']' brackets at ith length, then dp[i][j] = dp[i-1][j], i.e equal to the number of sequences having j ']' brackets in 
 * length i-1.
 */

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stack>

//#define mod 1000000007
#define ll long long int
#define maxn 35000
#define seive_max 35000

#define pb push_back

using namespace std;

int main()
{
	ll n, m, a, b, t, k, i;

	cin>>t;
	while(t--)
	{
		cin>>n>>k;

		bool start[2*n+1];
		for(i=1; i<=2*n; i++)
			start[i] = false;

		while(k--)
		{
			cin>>a;
			start[a] = true;
		}

		ll dp[2*n+1][n+1];

		for(i=0; i<=2*n; i++)
			for(ll j=0; j<=n; j++)
				dp[i][j] = 0;

		dp[1][1] = 1;

		for(i=2; i<=2*n; i++)
		{
			/*cout<<i-1<<":\n";
			for(ll j=1; j<=n; j++)
				cout<<dp[i-1][j]<<" ";
			cout<<endl;*/

			if(start[i]==true)
			{
				//cout<<"here\n";
				if(i==2*n)
					dp[i][n] = 0;
				else
				{
					for(ll j=1; j<=n; j++)
						dp[i][j] = dp[i-1][j-1];
				}
			}
			else
			{
				for(ll j=1; j<=n; j++)
				{
					if(i!=2*n)
						dp[i][j] += dp[i-1][j-1];

					if(i-j<=j)
						dp[i][j] += dp[i-1][j];
				}
			}
		}

		/*cout<<i-1<<":\n";
			for(ll j=1; j<=n; j++)
				cout<<dp[i-1][j]<<" ";
			cout<<endl;*/

		cout<<dp[2*n][n]<<endl;
	}
	return 0;
}
