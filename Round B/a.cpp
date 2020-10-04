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
int main()
{
	fast
	ll T;
	cin>>T;
	for(ll t=0;t<T;t++)
	{
		ll n;
		cin>>n;
		ll a[n];
		for(ll i=0;i<n;i++)
			cin>>a[i];
		ll ans=0;
		for(ll i=1;i<n-1;i++)
		{
			if(a[i]>a[i-1] && a[i]>a[i+1])
				ans++;
		}
		cout<<"Case #"<<t+1<<": "<<ans<<endl;
	}
}