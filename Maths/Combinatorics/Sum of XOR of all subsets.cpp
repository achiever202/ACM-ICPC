#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

#define mod 1000000007

using namespace std;

long long modpow(long long x)
{
	long long res = 1, a = 2;
	while(x>0)
    {
		if(x%2==1)
			res = (res*a)%mod;
		a = (a*a)%mod;
		x = x/2;
	}
	return res;
}


int main()
{
    long long int t, n,a ,ans, b;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>a;
        for(int i=1; i<n; i++)
        {
            cin>>b;
            a = a|b;
        }
        ans = modpow(n-1);
        ans = (ans*a)%mod;
        cout<<ans<<endl;
    }
    return 0;
}
