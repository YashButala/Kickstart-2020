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
 struct sch{
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
ll lcm(ll a,ll b)
{
  return a*b/gcd(a,b);
}
ll power(ll x, ll y, ll p) 
{ 
    ll res = 1; 
    x = x % p;  
    while (y > 0) 
    {
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 
ll modInverse(ll n, ll p) 
{ 
    return power(n, p-2, p); 
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
        ll v[n];
        for(ll i=0;i<n;i++)
            cin>>v[i];
        ll ans=0;
        ll mi =-1;
        for(ll i=0;i<n;i++)
        {
            if(v[i]>mi)
            {
                if(i==n-1)
                {
                    ans++;
                }
                else
                {
                    if(v[i]>v[i+1])
                        ans++;
                }
            }
            mi = max(v[i],mi);
        }
        cout<<"Case #"<<t+1<<": "<<ans<<endl;
    }
}