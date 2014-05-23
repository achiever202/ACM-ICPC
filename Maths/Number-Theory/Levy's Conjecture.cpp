/* Levy's conjecture states that any integer greater than 5 can be expressed as the sum of an odd prime, and an even semiprime.
 * n = p + 2*q, where p and q are primes, n>5
 */

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

int seive[seive_max+1] = {0};
int cnt[maxn+1] = {0};
vector <int> primes;

/* seive[prime] == 0 */
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
}

int main()
{
	int n, t;
	generate_sieve();
	for(int i=0; i<primes.size(); i++)
	{
		for(int j=0; j<primes.size(); j++)
		{
			if(primes[i] + 2*primes[j]<=maxn)
				cnt[primes[i] + 2*primes[j]]++;
		}
	}

	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<cnt[n]<<endl;
	}
	return 0;
}
