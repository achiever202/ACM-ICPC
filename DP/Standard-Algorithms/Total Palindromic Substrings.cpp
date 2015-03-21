/*
 * Author: Adarsh Pugalia
 * This program counts the total number of palindromic substrings in a give string.
 *
 * Let us consider a substring s[i...j], that is part of the string between indexes i and j.
 * The given substring is a palindrome iff, s[i]=s[j] and s[i+1...j-1] is a palindrome.
 * Using the above,
 * Let, dp[i][j] denote if the substring s[i..j] is a palindrome, if dp[i][j] = 1, else dp[i][j] = 0.
 * Thus, dp[i][j] = 1, iff, s[i] = s[j] and dp[i+1][j-1] = 1
 *
 * Now to find the total number of substrings, just sum over all i,j.
 *
 * Time: O(n^2)
 * Space: O(n^2)
 */

#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <stack>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

#define max_nodes_size 200005
#define max_size 200005
#define ll long long int
#define mod 1000000007
using namespace std;

ll palin_dp[2005][2005];
string word;

int main()
{
	cin>>word;

	for(ll i=word.length()-1; i>=0; i--)
	{
		for(ll j=word.length()-1; j>=i; j--)
		{
			if(word[i]==word[j])
			{
				if(i+1>j-1)
					palin_dp[i][j] = 1;
				else
					palin_dp[i][j] = palin_dp[i+1][j-1];
			}
			else
				palin_dp[i][j] = 0;
		}
	}

	ll ans = 0;
	for(ll i=0; i<=word.length(); i++)
		for(ll j=i; j<word.length(); j++)
			ans += dp[i][j];
	

	cout<<ans<<endl;
}	
