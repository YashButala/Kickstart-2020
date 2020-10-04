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
		ll w,h,l,u,r,d;
		cin>>w>>h>>l>>u>>r>>d;
		double grid[h][w];

		grid[0][0]=1.0;
		l--;u--;r--;d--;
		if(l==0 && u==0)
		{
			cout<<"Case #"<<t+1<<": "<<0<<endl;	
			continue;
		}
		for(ll i=1;i<h;i++)
		{
			grid[i][0]=grid[i-1][0]*0.5;
			if(i>=u && l==0)
			{
				grid[i][0]=0;
			}
		}
		for(ll i=1;i<w;i++)
		{
			grid[0][i]=grid[0][i-1]*0.5;
			if(i>=l && u==0)
			{
				grid[0][i]=0;
			}
		}

		
		for(ll i=1;i<h;i++)
		{
			for(ll j=1;j<w;j++)
			{
				if(i>=u && i<=d && j>=l && j<=r)
					grid[i][j]=0.0;
				else if((i==h-1 && j==w-1) )
				{
					grid[i][j]=grid[i-1][j]+grid[i][j-1];	
				}
				else if(i==h-1)
				{
					grid[i][j]=grid[i-1][j]/2+grid[i][j-1];
				}
				else if(j==w-1)
				{
					grid[i][j]=grid[i-1][j]+grid[i][j-1]/2;	
				}
				else
				{
					grid[i][j]=(grid[i-1][j]+grid[i][j-1])/2;

				}
			}
		}
		//double ans=0;
		cout<<"Case #"<<t+1<<": "<<grid[h-1][w-1]<<endl;
	}
}