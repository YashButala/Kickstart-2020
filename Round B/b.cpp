#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000000ll
#define pb push_back
#define vl vector<ll>
#define pll pair<ll,ll>
#define mp make_pair
using namespace std; 
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
bool sortinrev(const pair<ll,ll> &a, const pair<ll,ll> &b) 
{ 
       return (a.first > b.first); 
} 
ll a[1010];
bool check(ll start,ll d,ll n)
{
	ll x=start;
	for(ll i=0;i<n;i++)
	{
		if(x%a[i]==0)
		{
			continue;
		}
		else
		{
			ll p = x%a[i];
			x += a[i]-p;
		}
	}
	if(x<=d)	
		return true;
	else
		return false;

}

int main()
{
	fast
	ll T;
	cin>>T;
	for(ll t=0;t<T;t++)
	{
		ll n,d;
		cin>>n>>d;
		for(ll i=0;i<n;i++)
			cin>>a[i];
		ll l = 1;
		ll r = d;
		ll mid;
		while(1)
		{
			mid = (l+r)/2;
			if(!check(mid,d,n))
			{
				r = mid;
			}
			else
			{
				if(mid==d || !check(mid+1,d,n))
				{
					break;
				}
				l = mid+1;
			}
		}
		cout<<"Case #"<<t+1<<": "<<mid<<endl;
	}
}