/*
 * This can be done using suffix arrays. Total number of substrings = sum of the lengths of each suffix.
 * Now, for each pair of adjacent suffixes, in the sorted suffix array, the length of the longest matching prefix reduces the number of distinct
 * substrings by the length of the prefix. For example,
 * for the string ABA, the sorted suffix array would be,
 * 
 * A
 * ABA
 * BA
 * 
 * Thus the total number of substrings would be 1 + 3 + 2 = 6
 * but since, A is common in A and ABA, the distinct subbstrings {A, AB, ABA, B, BA} reduces to 5.
 */

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

#define mod 1000000009
#define ll long long int
#define fact_max 100001

using namespace std;

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		string word;
		cin>>word;
		vector <string> ar;

		for(ll i=0; i<word.length(); i++)
			ar.push_back(word.substr(i, word.length()-i));

		sort(ar.begin(), ar.end());

		ll ans = ar[0].length();

		for(ll i=1; i<ar.size(); i++)
		{
			ll len1 = ar[i-1].length();
			ll len2 = ar[i].length();

			ll pos = 0;
			while(pos<len1 && pos<len2 && ar[i-1][pos]==ar[i][pos])
				pos++;

			ans += len2-pos;
		}

		cout<<ans<<endl;
	}
	return 0;
}
