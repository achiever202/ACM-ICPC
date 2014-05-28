#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define mod 1000000007
#define ll long long int
#define maxn 100004
#define seive_max 10000

using namespace std;

ll mod;

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

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

ll pow(ll n, ll power)
{
	ll res = 1;
	while(power>0)
	{
		if(power&1)
			res = mulmod(res, n);

		n = mulmod(n, n);
		power = power/2;
	}

	return res;
}

bool miller_rabin(ll p)
{

	if(p==2)
		return true;

	if(p%2==0)
	{
		///cout<<"here1"<<endl;
		return false;
	}

	ll s = p-1;
	mod = p;

	while(s%2==0)
		s = s/2;

	int iterations = 2;

	while(iterations--)
	{
		ll a = rand()%(p-1) + 1;

		ll temp = s;

		ll ans = pow(a, temp);

		//cout<<"temp: "<<temp<<" a: "<<a<<" ans: "<<ans<<endl;

		while(temp!=p-1 && ans!=1 && ans!=p-1)
		{
			ans = mulmod(ans, ans);
			temp = temp*2;
			//cout<<"ans: "<<ans<<" temp: "<<temp<<endl;
		}

		if(ans!=p-1 && temp%2==0)
		{
			//cout<<"here2\n";
			return false;
		}
	}
	

	for(int i=0; i<10 && primes[i]*primes[i]<=p; i++)
	{
		if(p%primes[i]==0)
		{
			//cout<<"here3\n";
			return false;
		}
	}

	return true;
}


int main()
{
	srand(time(NULL));
	ll t, n;
	scanf("%lld", &t);
	while(t--)
	{
		scanf("%lld", &n);
		if(miller_rabin(n))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
