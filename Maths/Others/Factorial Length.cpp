/* The length of n! i.e. number of digits in n! can be given by the following formula,
 * no. of digits = [(log(2*pi*n)/2 + n*(log(n)-log(e))/log(10)] + 1
 * where, [x] is the integral part of x.
 * Also, n=0 is a corner case, and it should be handled separately!
 */
 
#include <iostream>
#include <math.h>

#define mod 1000000009
#define ll long long int
#define pi 3.14159265358979323
#define e 2.71828182845904523536

using namespace std;

int main()
{
	ll t;
	double n;
	cin>>t;
	while(t--)
	{
		long long int a;
		cin>>n;
		if(n==0)
			a = 1;
		else
		{
			double ans = log(2*pi*n)/2;
			ans += n*(log(n)-log(e));
			ans /= log(10);
			a = ans;
			a++;
		}
		cout<<a<<endl;
	}
	return 0;
}
