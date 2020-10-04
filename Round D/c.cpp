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
ll n,height;
ll **table;
void TreeAncestor(ll n, ll parent[]) 
{
    height = (ll)ceil(log2(n));

    table = new ll *[n + 1];
    for (ll i = 0; i < n + 1; i++) 
    { 
        table[i] = new ll[height + 1]; 
    } 
    for(ll i=0;i<=n;i++)
    {
        for(ll j=0;j<=height;j++)
        {
            table[i][j] = -1;
        }
    }
    for(ll i=0;i<n;i++)
    {
        table[i][0] = parent[i];
    }
//    cout<<"here"<<endl;
    for (ll h = 1; h <= height; h++) 
    { 
        for(ll i=0;i<n;i++)
        {
  //          cout<<i<<" "<<h<<" "<<table[i][h-1]<<endl;
            if(table[i][h-1]!=-1)
                table[i][h] = table[table[i][h - 1]][h - 1]; 

        }
    } 
    return ;
}

ll getKthAncestor(ll node, ll k) {
    for (ll i = 0; i <= height; i++) 
    { 
        if (k & (1 << i)) 
        { 
            node = table[node][i]; 
            if (node == -1) 
                break; 
        } 
    } 
return node; 
}
vector<ll>tree[500000];
void dfsupdate(ll cur,ll p,ll times[],ll a)
{
    for(ll i=0;i<tree[cur].size();i++)
    {
        ll u = tree[cur][i];
        if(u==p)
            continue;
        dfsupdate(u,cur,times,a); 
    }
    ll anc = getKthAncestor(cur, a);
    if(anc!=-1)
    {
        times[anc] += times[cur];
    }
}
int main()
{
    fast
    ll T;
    cin>>T;
    for(ll t=0;t<T;t++)
    {
        ll a,b;
        cin>>n>>a>>b;
        ll parent[n];
        parent[0] = -1;
        for(ll i=0;i<500000;i++)
            tree[i].clear();
        for(ll i=1;i<n;i++)
        {
            cin>>parent[i];
            parent[i]--;
            tree[i].pb(parent[i]);
            tree[parent[i]].pb(i);
        }
        ll timesA[n],timesB[n],timesC[n];
        memset(timesA,0,sizeof(timesA));
        memset(timesB,0,sizeof(timesB));
//         memset(timesC,0,sizeof(timesC));
        for(ll i=0;i<n;i++)
        {
        	timesA[i]=1;
        	timesB[i]=1;
        	timesC[i]=1;
        }
        TreeAncestor(n,parent) ;
        dfsupdate(0,-1,timesA,a);
        dfsupdate(0,-1,timesB,b);
//         dfsupdate(0,-1,timesC,lcm(a,b));
        ll sum=0;
        for(ll i=0;i<n;i++)
            sum+=n*timesA[i]+n*timesB[i]-timesA[i]*timesB[i];
        long double ans = (long double)sum/(long double)(n*n);
        cout<<setprecision(10)<<"Case #"<<t+1<<": "<<ans<<endl;
        
//         cout<<sum<<endl;
         
       
    }
}