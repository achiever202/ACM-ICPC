/* Functions available
 * 1. init_prefix_sum
 * 2. generate_seive
 * 3. check_subsequence
 * 4. mulmod
 * 5. pow
 * 6. miller_rabin
 * 7. gcd
 * 8. lcm
 */

/* This function calculates the prefix sums of an array ar */
int prefix_sum[maxn+1];
void init_prefix_sum(ll n)
{
	prefix_sum[0] = 0;
	for(ll i=1; i<=n; i++)
		prefix_sum[i] = prefix_sum[i-1] + ar[i-1];
}

/* This functions generates the seive of primes. */
int seive[seive_max+1] = {0};
vector <int> primes;
void generate_sieve()
{
	seive[0] = seive[1] = -1;

	for(int i=2; i<=seive_max; i++)
	{
		if(seive[i]==0)
		{
			primes.pb(i);
			for(int j=i+i; j<=seive_max; j=j+i)
				seive[j]++;
		}
	}
}

/*This function checks if string a is a subsequence of string b.*/
bool check_subsequence(string a, string b)
{
	int i=0, j=0;
	while(i<a.length() && j<b.length())
	{
		if(a[i]==b[j])
			i++;
		j++;
	}
	if(i==a.length())
		return true;
	else
		return false;
}

/*This function multiples a and b such that a and b are < 10^18, ans avoid overflow.*/
ll mulmod(ll a, ll b)
{
	ll x = 0, y = a%mod;

	while(b>0)
	{
		if(b%2==1)
			x = (x + y)%mod;

		y = (y*2)%mod;
		b = b/2;
	}

	return x;
}

/*This function calculates power */
ll pow(ll n, ll power)
{
	ll res = 1;
	while(power>0)
	{
		if(power&1)
			res = mulmod(res, n);

		n = mulmod(n, n);
		power = power/2;
	}

	return res;
}

/* Miller Rabin Test */
bool miller_rabin(ll p)
{

	if(p==2)
		return true;

	if(p%2==0)
	{
		///cout<<"here1"<<endl;
		return false;
	}

	ll s = p-1;
	mod = p;

	while(s%2==0)
		s = s/2;

	int iterations = 2;

	while(iterations--)
	{
		ll a = rand()%(p-1) + 1;

		ll temp = s;

		ll ans = pow(a, temp);

		//cout<<"temp: "<<temp<<" a: "<<a<<" ans: "<<ans<<endl;

		while(temp!=p-1 && ans!=1 && ans!=p-1)
		{
			ans = mulmod(ans, ans);
			temp = temp*2;
			//cout<<"ans: "<<ans<<" temp: "<<temp<<endl;
		}

		if(ans!=p-1 && temp%2==0)
		{
			//cout<<"here2\n";
			return false;
		}
	}
	

	for(int i=0; i<10 && primes[i]*primes[i]<=p; i++)
	{
		if(p%primes[i]==0)
		{
			//cout<<"here3\n";
			return false;
		}
	}

	return true;
}

ll gcd(ll a, ll b)
{
	if(a<b)
	{
		ll temp = a;
		a = b;
		b = temp;
	}

	if(b==0)
		return a;

	while(a%b!=0)
	{
		ll temp = a;
		a = b;
		b = temp%b;
	}
	return b;
}

ll lcm(ll a, ll b)
{
	ll g = gcd(a, b);

	ll x = a/g;
	ll y = b/g;

	ll lcm = g*x*y;
	return lcm;
+
