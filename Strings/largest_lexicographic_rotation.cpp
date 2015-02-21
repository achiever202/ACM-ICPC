/*
 * Author: Adarsh Pugalia
 * Algorithm: Booth's algorithms for largest lexicographic rotation.
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Source: Wikipedia
 */
 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <math.h>
#include <queue>

#define ll long long int
#define maxn 100000
#define sieve_max 1000000

using namespace std;

ll failure[9*1000000];

/* This function returns the index of the string where largest lexicographic rotation begins. */
ll largest_lexicographic_rotation(string s)
{
	ll n = s.length();

	s += s;

	for(ll i=0; i<=s.length(); i++)
		failure[i] = -1;

	ll k = 0;
	for(ll j=1; j<=2*n; j++)
	{
		ll i = failure[j-k-1];
        while(i != -1 && s[j] != s[k+i+1])
        {
        	if (s[j]>s[k+i+1])
                k = j-i-1;

            i = failure[i];
        }

        if(i == -1 && s[j] != s[k+i+1])
        {
        	if(s[j]>s[k+i+1])
                k = j;
            failure[j-k] = -1;
        }
        else
            failure[j-k] = i+1;
    }
    return k;
}

string s;
int main()
{
	cin>>s;
	ll k = largest_lexicographic_rotation(s);

	k = k%s.length();
	
	for(ll i=k; i<s.length(); i++)
		cout<<s[i];

	for(ll i=0; i<k; i++)
		cout<<s[i];

	return 0;
}
