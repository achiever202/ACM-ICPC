/* Editorial: http://discuss.codechef.com/problems/AMSTRING */

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>

#define mod 1000000007
#define ll long long int
#define maxn 10000
#define seive_max 10000

using namespace std;


int main()
{
	int t, n, k;
	string a,b;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		cin>>a>>b;
		int ans = 0, i;
		for(i=0; i<n; i++)
		{
			int l1 = 0, l2 = i, r1=l1, r2=l2;
			int count = 0;
			if(a[l1]!=b[l2])
				count++;
			while(r1<n && r2<n)
			{
				if(count==k+1)
				{
					ans += r1-l1;
					if(a[l1]!=b[l2])
						count--;
					l1++, l2++;
				}
				else
				{
					r1++, r2++;
					if(r1<n && r2<n && a[r1]!=b[r2])
						count++;
				}
			}
			int len = n-l1;
			if(len>n-l2)
				len = n-l2;

			ans += (len*(len+1))/2;
		}

		for(i=1; i<n; i++)
		{
			int l1 = i, l2 = 0, r1=l1, r2=l2;
			int count = 0;
			if(a[l1]!=b[l2])
				count++;
			while(r1<n && r2<n)
			{
				if(count==k+1)
				{
					ans += r1-l1;
					if(a[l1]!=b[l2])
						count--;
					l1++, l2++;
				}
				else
				{
					r1++, r2++;
					if(r1<n && r2<n && a[r1]!=b[r2])
						count++;
				}
			}
			int len = n-l1;
			if(len>n-l2)
				len = n-l2;

			ans += (len*(len+1))/2;
		}

		cout<<ans<<endl;
	}
	return 0;
}
