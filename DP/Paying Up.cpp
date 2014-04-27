#include<iostream>
 
using namespace std;
 
int main()
{
    int t, i, j, n, m, dp[20000], num[20], ctr;
    cin>>t;
    while(t--)
    {
        ctr = 0;
        cin>>n>>m;
        for(i=0; i<n; i++)
            cin>>num[i];
        for(i=0; i<=m; i++)
            dp[i] = -1;
        dp[0] = 0;
 
        for(i=0; i<n; i++)
        {
            for(j=m-1; j>=0; j--)
            {
                if(dp[j]==0 && j+num[i]<=m && dp[j+num[i]]==-1)
                    dp[j+num[i]] = 0;
            }
            if(dp[m]==0)
            {
                ctr = 1;
                break;
            }
        }
        if(ctr==1)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}
 
