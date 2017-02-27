#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstring>
#include<iomanip>
#include<stdio.h>
#include<limits>
#include<map>
#include<set>
#include<list>
#include<vector>
#include<stack>
#define gcd __gcd
#define pb(x) push_back(x)
#define ll long long
#define in(x) scanf("%d",&x)
#define mod 1000000007
#define sz(x) x.size()
#define mst(x,a) memset(x,a,sizeof(x))
#define pii pair<ll,ll>
#define F first
#define S second
#define m_p make_pair
#define all(v) (v.begin(),v.end())
using namespace std;
map<pair<pii,pii>,bool>mp;
int main()
{
    ios::sync_with_stdio(0);
    cout<<"enter the height and width\n";
    ll x,y;
    cin>>x>>y;
    cout<<"enter the number of bad node\n";
    ll n;
    cin>>n;
    cout<<"enter the bad paths in a group of four\n";
    ll a,b,c,d;
    for(ll i=0;i<n;i++)
    {
        cin>>a>>b>>c>>d;
        if(a+b==c+d+1)
            mp[m_p(m_p(a,b),m_p(c,d))]=1;
        else
            mp[m_p(m_p(c,d),m_p(a,b))]=1;
    }
    ll dp[x+1][y+1];
    for(ll i=0;i<=x;i++) for(ll j=0;j<=y;j++) dp[i][j]=0;
    dp[0][0]=1;
    for(ll i=0;i<=x;i++)
    {
        for(ll j=0;j<=y;j++)
        {
            pair<pii,pii> ver=m_p(m_p(i,j),m_p(i,j-1));
            if(j>=1&&!mp[ver])
                dp[i][j]+=dp[i][j-1];
            pair<pii,pii> hor=m_p(m_p(i,j),m_p(i-1,j));
            if(i>=1&&!mp[hor])
                dp[i][j]+=dp[i-1][j];
        }
    }
    cout<<"ans\n";
    cout<<dp[x][y]<<endl;

    return 0;
}


