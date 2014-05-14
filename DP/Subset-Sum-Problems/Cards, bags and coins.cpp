#include <iostream>

#define mod 1000000009
#define ll long long int

#define fact_max 100001

using namespace std;

long long int num[100001];
ll mod_num[100];
ll fact_mod_num[100][100];

ll fact[fact_max];
ll inv_fact[fact_max];

ll solved[101];

/* This function calculates the power.
 * n is the num whose some power has to be calculated.
 * power is the power to which n has to be raised.
 */
ll pow(ll n, ll power)
{
	ll res = 1;
	while(power>0)
	{
		if(power%2==1)
			res = (res*n)%mod;

		n = (n*n)%mod;
		power = power/2;
	}
	return res;
}

// This function initialises the factorial till fact_max-1.
void init_fact()
{
	fact[0] = 1;
	for(ll i=1; i<fact_max; i++)
		fact[i] = (fact[i-1]*i)%mod;
}

// Ths function initialises the inverse factorial mod p uptil fact_max-1.
void init_inv_fact()
{
	inv_fact[fact_max-1] = power(fact[fact_max-1], mod-2);
	for(ll i=fact_max-2; i>=0; i--)
	{
		inv_fact[i] = ((i+1)*inv_fact[i+1])%mod;
	}
}

// This function calculates the the value of ncr, using modular inverse.
ll calc_modular_ncr(ll n, ll r)
{
	ll ans = (fact[n]*inv_fact[r])%mod;
	ans = (ans*inv_fact[n-r])%mod;
	return ans;
}

void calc_fact_mod_num(ll n, ll m)
{
	for(ll i=0; i<m; i++)
		for(ll j=0; j<m; j++)
			fact_mod_num[i][j] = 0;

	for(ll i=0; i<m; i++)
	{
		ll cur = 0;
		ll count = 0;
		while(count<=mod_num[i])
		{
			fact_mod_num[i][cur] = (fact_mod_num[i][cur] + calc_modular_ncr(mod_num[i], count))%mod;
			cur = (cur+i)%m;
			count++;
		}
	}
}


void calc_mod_num(ll n, ll m)
{
	for(ll i=0; i<m; i++)
		mod_num[i] = 0;

	for(ll i=0; i<n; i++)
		mod_num[(num[i]%m+m)%m]++;
}


void solve(long long int n)
{
	ll m;
	cin>>m;

	if(solved[m]>-1)
		cout<<solved[m]<<endl;
	else
	{
		calc_mod_num(n, m);
		/*for(ll i=0; i<m; i++)
			cout<<mod_num[i]<<" ";
		cout<<endl;*/

		calc_fact_mod_num(n, m);
		/*for(ll i=0; i<m; i++)
		{
			for(ll j=0; j<m; j++)
				cout<<fact_mod_num[i][j]<<" ";
			cout<<endl;
		}

		cout<<endl;*/

		ll dp[m+1][m];

		for(ll i=0; i<=m; i++)
			for(ll j=0; j<m; j++)
				dp[i][j] = 0;

		dp[0][0] = 1;

		for(ll i=1; i<=m; i++)
		{
			for(ll j=0; j<m; j++)
			{
				for(ll k=0; k<m; k++)
				{
					dp[i][j] = (dp[i][j] + fact_mod_num[i-1][k]*dp[i-1][(j+m-k)%m])%mod;
				}
			}
		}

		/*for(ll i=0; i<=m; i++)
		{
			for(ll j=0; j<m; j++)
				cout<<dp[i][j]<<" ";
			cout<<endl;
		}*/

		solved[m] = dp[m][0];
		cout<<dp[m][0]<<endl;
	}
}

int main()
{
	long long int t, n, q;

	init_fact();
	init_inv_fact();

	cin>>t;
	while(t--)
	{
		cin>>n>>q;

		for(ll i=0; i<n; i++)
			cin>>num[i];

		for(ll i=0; i<=100; i++)
			solved[i] = -1;

		while(q--)
		{
			solve(n);
		}
	}
	return 0;
}
