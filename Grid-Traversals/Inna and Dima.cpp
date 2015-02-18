#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <stack>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

#define ss(n) scanf("%s", n)
#define sl(n) scanf("%lld", &n)

#define mp(n, m) make_pair(n, m)
#define pb(n) push_back(n)

#define max_nodes_size 100005
#define max_size 100005
#define ll long long int
#define mod 1000000007
using namespace std;

pair<ll, ll> grid[1005][1005];

char name[] = {'D', 'I', 'M', 'A'};
ll dx[] = {1, -1, 0, 0};
ll dy[] = {0, 0, 1, -1};

char dima[1005][1005];

ll flag = 1;

ll dfs(ll x, ll y, ll step, ll n, ll m)
{
	grid[x][y].first = step;
	ll temp = 0;

	if(dima[x][y]=='A')
	{
		temp++;
	}

	ll temp2 = 0;

	for(ll i=0; i<4; i++)
	{
		for(ll j=0; j<4; j++)
		{
			if(name[j]==dima[x][y])
			{
				if(x+dx[i]>=0 && x+dx[i]<n && y+dy[i]>=0 && y+dy[i]<m && dima[x+dx[i]][y+dy[i]]==name[(j+1)%4])
				{
					if(grid[x+dx[i]][y+dy[i]].first==-1)
						temp2 = max(temp2, dfs(x+dx[i], y+dy[i], step, n, m));
					else
					{
						if(grid[x+dx[i]][y+dy[i]].first==step)
							flag = 0;
						else
						{
							temp2 = max(temp2, grid[x+dx[i]][y+dy[i]].second);
						}
					}
				}
			}
		}
	}

	temp += temp2;
	grid[x][y].second = temp;
	grid[x][y].first = step-1;
	return temp;
}

int main()
{
	ll n, m;
	sl(n); sl(m);
	for(ll i=0; i<n; i++)
		ss(dima[i]);

	for(ll i=0; i<n; i++)
		for(ll j=0; j<m; j++)
			grid[i][j] = mp(-1, 0);

	ll pos = 1;
	for(ll i=0; i<n; i++)
	{
		for(ll j=0; j<m; j++)
		{
			if(dima[i][j]=='D' && grid[i][j].first==-1)
			{
				dfs(i, j, pos, n, m);
			}
		}
	}

	if(!flag)
	{
		cout<<"Poor Inna!";
		return 0;
	}

	ll ans = 0;
	for(ll i=0; i<n; i++)
	{
		for(ll j=0; j<m; j++)
		{
			if(grid[i][j].second>ans)
			{
				ans = grid[i][j].second;
			}
		}
	}


	if(ans==0)
		cout<<"Poor Dima!";
	else
		cout<<ans;

	return 0;
}
