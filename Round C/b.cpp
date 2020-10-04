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
		ll r,c;
		cin>>r>>c;
		string s[r];
		for(ll i=0;i<r;i++)
			cin>>s[i];
		set<ll> sup[26];
		ll res = 0;
		for(ll i=0;i<26;i++)
		{
			char ch = (char)('A'+i);
			for(ll i1=0;i1<r;i1++)
			{
				for(ll j1=0;j1<c;j1++)
				{
					if(s[i1][j1]==ch)
					{
						if(i1==r-1)
						{
							sup[i].insert(-1);
						}
						else
						{
							sup[i].insert(s[i1+1][j1]-'A');
						}
					}
				}
			}
			if(sup[i].size())
			{
				sup[i].erase(i);
				res++;
			}
		}
		//cout<<endl;
		vl hold;
		int flag = 1;
		vl order;
		for(ll i=0;i<26;i++)
		{
			if(sup[i].size()==1)
			{
				set<ll>::iterator itr = sup[i].begin();
				if(*itr==-1)
				{
					hold.pb(i);
					order.pb(i);
					sup[i].erase(-1);
//					cout<<i<<" ";
				}
			}
		}
		if(hold.size()==0)
		{
			cout<<"Case #"<<t+1<<": "<<-1<<endl;
			continue;
		}
		while(hold.size())
		{
			vl tmp;
			for(ll i=0;i<26;i++)
			{
				sup[i].erase(-1);
				for(ll j=0;j<hold.size();j++)
				{
					if(sup[i].size())
					{
						sup[i].erase(hold[j]);	
						if(sup[i].size()==0)
						{
							tmp.pb(i);
							order.pb(i);
						}						
					}			
					
				}

			}
			hold  = tmp;

		}
		if(res!=order.size())
		{
			cout<<"Case #"<<t+1<<": "<<-1<<endl;
			continue;
		}
		cout<<"Case #"<<t+1<<": ";
		for(ll i=0;i<order.size();i++)
		{
			cout<<(char)(order[i]+'A');
		}
		cout<<endl;
	}

}