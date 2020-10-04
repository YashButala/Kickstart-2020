#include<bits/stdc++.h>
using namespace std;
 
#define ll int
#define lf long double
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef pair <ll,ll > ii;
typedef vector <ll> vi;
typedef vector <ii> vii;
typedef vector <bool> vb;
typedef vector <vector <ll> > vv;
typedef vector <vector <vector<ll> > > vvv;
typedef vector <string> vs;
typedef vector <lf> vf;
#define sz(x) (ll)(x).size()
#define tr1(x) cerr << #x << ": " << x << endl
#define tr2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl
#define tr3(x,y,z) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define tr4(x,y,z,w) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<" | "<<#w<<": "<<w<<endl
#define trv(a) cerr<<#a<<": ";for(ll zz=0;zz<sz(a);zz++) cerr<<a[zz]<<" ";cerr<<endl
#define trii(x) cerr<<#x<<": ("<<x.F<<","<<x.S<<")\n";
#define trvii(a) cerr<<#a<<": ";for(ll zz=0;zz<sz(a);zz++) cerr<<"("<<a[zz].F<<","<<a[zz].S<<") ";cerr<<nl
#define trset(s) cerr<<#s<<": ";for(auto &i:s) cerr<<i<<" ";cerr<<"\n"
#define trsetii(s) cerr<<#s<<": ";for(auto &i:s) trii(i);
#define epsilon 0.000000001L
#define mod 1000000007ll
#define inf 9999999999999999ll
#define nl endl
#define all(x) x.begin(), x.end()
#define r_all(x) x.rbegin(), x.rend()
#define fast()  ios_base::sync_with_stdio(false);cin.tie(NULL)
#define modulo 998244353ll



const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};



#include <ext/pb_ds/assoc_container.hpp> // Common file


#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;





int main()
{
//    fast();
    //ll changed
    ll T;
    scanf(" %d",&T);
    for(ll w1=1;w1<=T;w1++)
    {

        ll n;
        scanf(" %d",&n);
        vi a(n);
        for(ll i=0;i<n;i++)
        {
            scanf(" %d",&a[i]);
        }
        ll max_sum=0;
        ll su=0;
        for(ll i=0;i<n;i++)
        {
            su+=a[i];
            if(su<0)
            {
                su=0;
            }
            max_sum=max(max_sum,su);
        }
        ll ma=sqrtl(max_sum+1);
        long long ans=0;
        gp_hash_table<int, int,chash> sum; 
        sum[0]=1;
        su=0;
        for(ll i=0;i<n;i++)
        {
            su+=a[i];
            
            for(ll j=0;j<=ma;j++)
            {
                if(sum.find(su-j*j)!=sum.end())
                {
                    ans+=sum[su-j*j];
                }
            }
            sum[su]++;
        }
        printf("Case #%d: %lld\n",w1,ans);
    }
}

