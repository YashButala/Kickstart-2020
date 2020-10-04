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
        ll a[n];
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
        }
        ll dp[n][4];
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<4;j++)
            {
                dp[i][j] = MOD;
            }
        }
        dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = 0;
        for(ll i=1;i<n;i++)
        {
            if(a[i]>a[i-1])
            {
                dp[i][0] = min(min(dp[i-1][0],dp[i-1][1]),min(dp[i-1][2],dp[i-1][3]))+1;
                dp[i][1] = min(min(dp[i-1][0],dp[i-1][1]),min(dp[i-1][2],dp[i-1][3]))+1;
                dp[i][2] = min(min(dp[i-1][0],dp[i-1][1]),min(dp[i-1][2],dp[i-1][3]))+1;
                dp[i][3] = min(min(dp[i-1][0],dp[i-1][1]),min(dp[i-1][2],dp[i-1][3]))+1;
                dp[i][1] = min(dp[i-1][0],dp[i][1]);
                dp[i][2] = min(min(dp[i-1][0],dp[i-1][1]),dp[i][2]);
                dp[i][3] = min(min(dp[i-1][0],dp[i-1][1]),min(dp[i][3],dp[i-1][2]));
            }
            if(a[i]==a[i-1])
            {
                for(ll j=0;j<4;j++)
                    dp[i][j] = min(dp[i][j],dp[i-1][j]);
            }
            if(a[i]<a[i-1])
            {
                dp[i][0] = min(min(dp[i-1][0],dp[i-1][1]),min(dp[i-1][2],dp[i-1][3]))+1;
                dp[i][1] = min(min(dp[i-1][0],dp[i-1][1]),min(dp[i-1][2],dp[i-1][3]))+1;
                dp[i][2] = min(min(dp[i-1][0],dp[i-1][1]),min(dp[i-1][2],dp[i-1][3]))+1;
                dp[i][3] = min(min(dp[i-1][0],dp[i-1][1]),min(dp[i-1][2],dp[i-1][3]))+1;
                dp[i][2] = min(dp[i-1][3],dp[i][2]);
                dp[i][1] = min(min(dp[i-1][2],dp[i-1][3]),dp[i][1]);
                dp[i][0] = min(min(dp[i-1][1],dp[i-1][2]),min(dp[i][0],dp[i-1][3]));   
            }
        }
        ll ans = min(min(dp[n-1][0],dp[n-1][1]),min(dp[n-1][2],dp[n-1][3]));
        cout<<"Case #"<<t+1<<": "<<ans<<endl;
    }
}