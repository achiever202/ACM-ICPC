#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stack>

#define mod 1000000009
#define ll long long int
#define maxn 5005
#define seive_max 35000

#define pb push_back
#define fact_max 5005

using namespace std;

ll fact[fact_max];
ll inv_fact[fact_max];

ll mulmod(ll a, ll b)
{
	ll x = 0, y = a%mod;

	while(b>0)
	{
		if(b%2==1)
			x = (x + y)%mod;

		y = (y*2)%mod;
		b = b/2;
	}

	return x;
}

ll pow_(ll n, ll power)
{
	ll res = 1;
	while(power>0)
	{
		if(power&1)
		{
			//res = mulmod(res, n);
			res = (res*n)%mod;
		}

		//n = mulmod(n, n);
		n = (n*n)%mod;
		power = power/2;
        
        //cout<<res<<endl;
	}
    
	return res;
}

void init_fact()
{
	fact[0] = 1;
	for(ll i=1; i<fact_max; i++)
		fact[i] = (fact[i-1]*i)%mod;
}

void init_inv_fact()
{
	inv_fact[fact_max-1] = pow_(fact[fact_max-1], mod-2);
    //cout<<fact[fact_max-1]<<" "<<inv_fact[fact_max-1]<<endl;
	for(ll i=fact_max-2; i>=0; i--)
		inv_fact[i] = ((i+1)*inv_fact[i+1])%mod;
}

ll ncr(ll n, ll r)
{
	ll ans = (fact[n]*inv_fact[r])%mod;
	ans = (ans*inv_fact[n-r])%mod;
	return ans;
}

ll dp[maxn] = {0}, total_dp[maxn] = {0};

int main()
{
	init_fact();
	init_inv_fact();
    
	dp[0] = total_dp[0] = 1;
	dp[1] = total_dp[1] = 1;

	for(ll i=2; i<maxn; i++)
	{
		for(ll j=1; j<i; j++)
		{
			total_dp[i] = (total_dp[i] + (ncr(i, j)*dp[j])%mod)%mod;
		}

		for(ll j=1; j<=i; j++)
			dp[i] = (dp[i] + (dp[j-1]*dp[i-j])%mod)%mod;

		total_dp[i] = (total_dp[i]+dp[i])%mod;
	}

	ll t, n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<total_dp[n]<<endl;
	}
	return 0;
}
