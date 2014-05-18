#include <iostream>
#include <math.h>
#include <stack>

using namespace std;

long long int num[100004];

class his
{
	public:
		long long int pos;
		long long int height;

		his(long long int i, long long int j)
		{
			pos = i;
			height = j;
		}
};

stack <his> histogram;

int main()
{
	long long int n;
	cin>>n;
	while(n)
	{
		for(long long int i=0; i<n; i++)
			cin>>num[i];

		long long int hi, low, poslow = 0, poshi = 0;
		long long int ans = 0;

		histogram.push(his(0, -1));
		for(long long int i=0; i<n; i++)
		{
		//	cout<<"pushing: "<<i+1<<" "<<num[i]<<endl;
			his temp = histogram.top();
		//	cout<<"top: "<<temp.pos<<" "<<temp.height<<endl;

			if(num[i]>temp.height)
				histogram.push(his(i+1, num[i]));
			else if(num[i]<temp.height)
			{
				long long int j = temp.pos;
				his cur = temp;
				histogram.pop();
				temp = histogram.top();
				while(temp.pos!=0 && cur.height>num[i])
				{
					long long area = (i+1-cur.pos)*cur.height;
					j = cur.pos;
					//cout<<"area1: "<<i+1<<" "<<cur.pos<<" "<<cur.height<<" "<<area<<endl;
		//			cout<<"area: "<<i<<" "<<temp.pos<<" "<<temp.height<<" "<<area<<endl;
					if(ans<area)
						ans = area;
					cur = temp;
					histogram.pop();
					temp = histogram.top();
				}

				if(temp.pos==0)
				{
					if(cur.height>num[i])
					{
						
						long long area = (i)*cur.height;
						j = cur.pos;
						//cout<<"area2: "<<i+1<<" "<<cur.pos<<" "<<cur.height<<" "<<area<<endl;
						if(ans<area)
							ans = area;
						histogram.push(his(j, num[i]));
					}
					else
					{
						histogram.push(cur);
						if(cur.height!=num[i])
							histogram.push(his(j, num[i]));
					}
				}
				else
				{
					histogram.push(cur);
					if(cur.height!=num[i])
						histogram.push(his(j, num[i]));
				}
			}
		}

		his temp = histogram.top();
		//cout<<"top: "<<temp.pos<<" "<<temp.height<<endl;
		his cur = temp;
		histogram.pop();
		temp = histogram.top();
		while(temp.pos!=0)
		{
			
			long long int area = (n+1-cur.pos)*cur.height;
			//cout<<"area3: "<<n+1<<" "<<cur.pos<<" "<<cur.height<<" "<<area<<endl;
			//cout<<"area: "<<cur.pos<<" "<<temp.pos<<" "<<cur.height<<" "<<area<<endl;
			if(area>ans)
				ans = area;

			cur = temp;
			histogram.pop();
			temp = histogram.top();
		}

		if(ans<(n)*cur.height)
		{
			ans = n*cur.height;
			//cout<<"area4: "<<n<<" "<<cur.pos<<" "<<cur.height<<" "<<ans<<endl;
		}
		cout<<ans<<endl;
		cin>>n;
	}
	return 0;
}
