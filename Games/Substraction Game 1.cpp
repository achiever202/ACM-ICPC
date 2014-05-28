#include <iostream>
 
		using namespace std;
 
		int gcd(int a, int b)
		{
			int temp;
 
			if(a<b)
			{
				temp = a;
				a = b;
				b = temp;
			}
			while(a%b!=0)
			{
				temp = a;
				a = b;
				b = temp%b;
			}
			return b;
		}
 
		int main()
		{
			int t, n, i, g, sum;
			cin>>t;
			while(t--)
			{
				cin>>n;
				int num[n];
				sum = 0;
				for(i=0; i<n; i++)
				{
					cin>>num[i];
					//sum += num[i];
				}
 
				g = gcd(num[0], num[1]);
 
				for(i=2; i<n; i++)
					g = gcd(num[i], g);
 
				cout<<g<<endl;
			}
			return 0;
		}
