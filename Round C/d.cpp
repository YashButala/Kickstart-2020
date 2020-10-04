#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double 
#define MOD 1000000007ll 
#define pb push_back
#define vl vector<ll>
#define pll pair<ll,ll>
#define mp make_pair
using namespace std;
#define pi (long double)3.14159265358979323846 
#define ll_MAX 1223372036854775807ll
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAXN 100000
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
ll power(ll a,ll p,ll m)
{
    ll re=1;
    re%=m;
    for(;p;p>>=1){
        if(p&1) re=re*a%m;
        a=a*a%m;
    }
    return re;
}
void updateElement(ll n,ll pos,ll val,ll BIT[])
{
    ll index = pos+1;
    while(index<=n)
    {
        BIT[index] += val;
        index = index + (index & (-index));
    }
}   
ll getSum(ll x,ll BIT[])
{
    ll ret = 0,index = x+1;
    while(index>0)
    {
        ret += BIT[index];
        index = index - (index & (-index));
    }
    return ret;
}
int main()
{
    fast
    ll T;
    cin>>T;
    for(ll t=0;t<T;t++)
    {
        ll n,q;
        cin>>n>>q;
        ll a[n],b[n];
        ll bit1[n+1],bit2[n+1];
        memset(bit1,0,sizeof(bit1));
        memset(bit2,0,sizeof(bit2));
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
            if(i%2)
            {
                b[i] = -a[i];
                a[i] = -(i+1)*a[i];
            }
            else
            {
                b[i] = a[i];
                a[i] = (i+1)*a[i];
            }
            updateElement(n,i,a[i],bit1);
            updateElement(n,i,b[i],bit2);
        }
        ll res = 0;
        while(q--)
        {
            char ch;
            cin>>ch;
            if(ch=='Q')
            {
                ll l,r;
                cin>>l>>r;
                l--;r--;
                ll ans = getSum(r,bit1)-getSum(l-1,bit1);
                ans -= (l)*(getSum(r,bit2)-getSum(l-1,bit2));
                if(l%2)
                    ans = -ans;
                res += ans;
            //    cout<<ans<<endl;
            }
            else
            {
                ll x,v;
                cin>>x>>v;
                x--;
                if(x%2)
                    v = -v;
                updateElement(n,x,(x+1)*v-a[x],bit1);
                updateElement(n,x,v-b[x],bit2);
                b[x] = v;
                a[x] = (x+1)*v;
            }

        }
        cout<<"Case #"<<t+1<<": "<<res<<endl;
    }
}