#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstring>
#include<iomanip>
#include<stdio.h>
#include<limits>
#include<unordered_map>
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
#define pii pair<int,int>
#define F first
#define S second
#define m_p make_pair
#define all(v) (v.begin(),v.end())
using namespace std;

inline int  b_search(int dp[], int l,int r,int key)
{
    while(r>l+1)
    {
        int m=l+(r-l)/2;
        if(dp[m]>=key){
        	r=m;
		}
        else{
        	l=m;
		}
    }
    return r;
}

int solve(int a[], int  l)
{
    int len=1;
    int dp[10001];
    mst(dp,0);
    dp[0]=a[0];
    for(int i=1;i<l;i++)
    {
        if(a[i]<dp[0])
        	dp[0]=a[i];

        else if(a[i]>dp[len-1])
        	dp[len++]=a[i];
        else
        	dp[b_search(dp,-1,len-1,a[i])]=a[i];
    }
    return len;
}
int main()
{
	int t;
    cin>>t;
    while(t--)
    {
        int n;
    	cin>>n;
    	int a[2*n];
        for(int i=0;i<n;i++){
        	cin>>a[i];
        	a[i+n]=a[i];
        }
        int ans=0;
        for(int i=0;i<n;i++){
        	ans=max(ans,solve(a+i,n));
        }
        cout<<ans<<endl;
    }
    return 0;
}

