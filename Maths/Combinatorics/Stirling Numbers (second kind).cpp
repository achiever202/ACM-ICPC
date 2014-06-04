// Wikipedia - http://en.wikipedia.org/wiki/Stirling_numbers_of_the_second_kind

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
	ll t, n, m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;

		printf("%d\n", ((n-m)&(m-1>>1))==0);
	}
	return 0;
}
