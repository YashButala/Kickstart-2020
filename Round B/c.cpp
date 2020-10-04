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
		string s;
		cin>>s;
		stack<ll>muls;
		ll p=1;
		ll dir[4];
		memset(dir,0,sizeof(dir));
		muls.push(1);
		for(ll i=0;i<s.size();i++)
		{
			if(s[i]-'0'<=9 && s[i]-'0'>=0)
			{
				ll tmp=s[i]-'0'; 
				p*=tmp;
				p %=MOD;
				muls.push(p);
			}
			if(s[i]=='(')
			{
				continue;
			}
			if(s[i]==')')
			{
				muls.pop();
				p = muls.top();
				
			}
			p%=MOD;
			if(s[i]=='N')
			{	
				dir[0]+=p;
				dir[0]%=MOD;
			}
			if(s[i]=='E')
			{	
				dir[1]+=p;
				dir[1]%=MOD;
			}
			if(s[i]=='S')
			{	
				dir[2]+=p;
				dir[2]%=MOD;
			}
			if(s[i]=='W')
			{	
				dir[3]+=p;
				dir[3]%=MOD;
			}									
		}
		ll w = 0,h=0;
		w = (dir[1]-dir[3]+MOD)%MOD+1;
		h = (dir[2]-dir[0]+MOD)%MOD+1;	
		cout<<"Case #"<<t+1<<": "<<w<<" "<<h<<endl;
	}
}