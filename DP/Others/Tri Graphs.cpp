#include <iostream>

#define mod 1000000009
#define ll long long int

using namespace std;

int num[100004][3];
int dp[100004][3];

int main()
{
	ll n, k=0;
	cin>>n;
	while(n)
	{
		k++;

		for(ll i=0; i<n; i++)
		{
			cin>>num[i][0]>>num[i][1]>>num[i][2];
		}

		dp[0][0] = 100000000;
		dp[0][1] = num[0][1];
		dp[0][2] = num[0][2] + num[0][1];

		for(ll i=1; i<n; i++)
		{
			dp[i][0] = num[i][0];

			if(dp[i-1][0]<dp[i-1][1])
				dp[i][0] += dp[i-1][0];
			else
				dp[i][0] += dp[i-1][1];

			dp[i][1] = dp[i-1][0];
			if(dp[i-1][1]<dp[i][1])
				dp[i][1] = dp[i-1][1];
			if(dp[i-1][2]<dp[i][1])
				dp[i][1] = dp[i-1][2];
			if(dp[i][0]<dp[i][1])
				dp[i][1] = dp[i][0];
			dp[i][1] += num[i][1];

			dp[i][2] = dp[i-1][1];
			if(dp[i-1][2]<dp[i][2])
				dp[i][2] = dp[i-1][2];
			if(dp[i][1]<dp[i][2])
				dp[i][2] = dp[i][1];
			dp[i][2] += num[i][2];
		}

		//for(ll i=0; i<n; i++)
		//	cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;

		cout<<k<<". "<<dp[n-1][1]<<endl;
		cin>>n;
	}
	return 0;
}
