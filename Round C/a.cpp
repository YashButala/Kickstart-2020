#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007ll 
#define pb push_back
#define vl vector<ll>
#define pll pair<ll,ll>
#define mp make_pair
using namespace std;
#define pi (long double)3.14159265358979323846 
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 struct sch
{
	ll s,e,t;
};
bool sortinrev(const struct sch &a, const struct sch &b) 
{ 
    return (a.s < b.s); 
}
ll gcd(ll a, ll b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
}
ll power(ll x,ll y,ll f)
{
	if(y==0)
		return 1;
	ll tmp = power(x,y/2,f);
	if(y%2)
	{
		tmp = (tmp*tmp)%f;
		tmp = (tmp*x)%f;
		return tmp;
	}
	else
	{
		tmp = (tmp*tmp)%f;
		return tmp;
	}
}
ll modInverse(ll a, ll m)
{ 
	return power(a, m-2, m);
}
int main()
{
	fast
	ll T;
	cin>>T;
	for(ll t=0;t<T;t++)
	{
		ll n,k;
		cin>>n>>k;
		ll a[n];
		for(ll i=0;i<n;i++)
			cin>>a[i];
		ll res=0,cur = k;
		for(ll i=0;i<n;i++)
		{
			if(a[i]==cur)
			{
				cur--;
			}
			else
			{
				cur = k;
				if(a[i]==k)
					cur--;
			}
			if(cur==0)
			{
				res++;
				cur = k;
			}
		}
		cout<<"Case #"<<t+1<<": "<<res<<endl;
	}

}