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
#define maxn 1000005
#define seive_max 10000

using namespace std;

ll len, gap;

ll sa[maxn], pos[maxn], temp[maxn], lcp[maxn];

bool suf_comp(ll i, ll j)
{
	if(pos[i]!=pos[j])
		return pos[i]<pos[j];

	i += gap;
	j += gap;

	if(i<len && j<len)
		return pos[i]<pos[j];
	else
		return i>j;
}

void build_lcp(string s)
{
	for (int i = 0, k = 0; i < len; ++i) if (pos[i] != len - 1)
	{
		for (int j = sa[pos[i] + 1]; s[i + k] == s[j + k];)
		++k;
		lcp[pos[i]] = k;
		if (k)--k;
	}
}

void build_suffix_array(string s)
{
	len = s.length();

	for(ll i=0; i<len; i++)
	{
		sa[i] = i;
		pos[i] = s[i];
	}

	for(gap=1; ; gap *= 2)
	{
		sort(sa, sa+len, suf_comp);
		temp[0] = 0;
		for(ll i=1; i<len; i++)
			temp[i] = temp[i-1] + suf_comp(sa[i-1], sa[i]);

		for(ll i=0; i<len; i++)
			pos[sa[i]] = temp[i];

		if(temp[len-1]==len-1)
			break;
	}

	build_lcp(s);
}

int main()
{
	
	string s;
	cin>>s;
	build_suffix_array(s);
	return 0;
}
