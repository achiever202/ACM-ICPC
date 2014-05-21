#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

#define mod 1000000007
#define ll long long int
#define maxn 200000

using namespace std;

long long int calc[10][maxn+5];
ll power_10[maxn+5];
string num;

int main()
{
	power_10[0] = 1;
	power_10[1] = 10;
	for(ll i=2; i<=maxn; i++)
		power_10[i] = (power_10[i-1]*10)%mod;

	for(ll i=1; i<=9; i++)
	{
		calc[i][0] = i;
		for(ll j=1; j<=maxn; j++)
			calc[i][j] = (calc[i][j-1] + (i*power_10[j])%mod)%mod;
	}

	cin>>num;
	ll len = num.length();
	ll ans = 0;
	for(ll i=0; i<len; i++)
	{
		//cout<<ans<<" "<<calc[num[i]-'0'][len-1-i]<<endl;
		ans = (ans + ((i+1)*calc[num[i]-'0'][len-1-i])%mod)%mod;
		
		//cout<<ans<<endl;
	}
	cout<<ans;
	return 0;
}
