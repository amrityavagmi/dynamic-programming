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
int main()
{
    ios::sync_with_stdio(0);
    int n;
    cout<<"enter the number of elements\n";
    cin>>n;
    int a[n];
    cout<<"enter the array\n";
    for(int i=0;i<n;i++)
        cin>>a[i];
    int dp[n][2];//dp[i][0] contains the answer if including
    // ith element and taking it as the number greater than previous.
    //and dp[i][1] if it is smaller than the previous one.
    dp[0][0]=1;
    dp[0][1]=1;
    for(int i=0;i<n;i++)
    {
        dp[i][0]=1;
        for(int j=i-1;j>=0;j--)
        {
            if(a[j]>a[i])
                dp[i][0]=max(dp[i][0],dp[j][1]+1);
        }
        dp[i][1]=1;
        for(int j=i-1;j>=0;j--)
        {
            if(a[j]<a[i])
                dp[i][1]=max(dp[i][1],dp[j][0]+1);
        }
    }
    int maxi=1;
    cout<<"length of the maximum subsequence is ";
    for(int i=0;i<n;i++)
        maxi=max(maxi,max(dp[i][0],dp[i][1]));
    cout<<maxi<<endl;
    return 0;
}


