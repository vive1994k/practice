#include<iostream>
#define N 100
#define M 50
#define INT_MAX 1000000000
#define INT_MIN -1000000000
using namespace std;
int arr[N];
int sum[N];
int dp_max[N][M];
int dp_min[N][M];
int getRangeSum(int i,int j)
{
    int ans=sum[j];
    if(i!=0)
        ans-=sum[i-1];
    return ans;
}
void pre(int n,int m)
{
    sum[0]=arr[0];
    for(int i=1;i<n;i++)
        sum[i]=sum[i-1]+arr[i];
    for(int i=0;i<n;i++)
    {
        dp_max[i][0]=INT_MAX;
        dp_min[i][0]=INT_MIN;
    }
    for(int j=0;j<=m;j++)
    {
        dp_max[n][j]=0;
        dp_min[n][j]=0;
    }
    dp_max[n][0]=INT_MIN;
    dp_min[n][0]=INT_MAX;
}
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        pre(n,m);
        for(int i=n-1;i>=0;i--)
        {
            for(int j=1;j<=n-i;j++)
            {
                int max_cur=INT_MIN;
                int min_cur=INT_MAX;
                int cur_diff=INT_MAX;
                for(int k=i;k<=n-1;k++)
                {
                    int max_till_now=max(getRangeSum(i,k),dp_max[k+1][j-1]);
                    int min_till_now=min(getRangeSum(i,k),dp_min[k+1][j-1]);
                    cout<<i<<" "<<j<<" "<<k<<" "<<max_till_now<<" "<<min_till_now<<" "<<cur_diff<<endl;
                    if(max_till_now-min_till_now<cur_diff)
                    {
                        if(j!=1)
                            cur_diff=max_till_now-min_till_now;
                        max_cur=max_till_now;
                        min_cur=min_till_now;
                    }
                }
                dp_max[i][j]=max_cur;
                dp_min[i][j]=min_cur;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                cout<<dp_max[i][j]<<" "<<dp_min[i][j]<<" ";
            }
            cout<<endl;
        }

        cout<<dp_max[0][m]-dp_min[0][m]<<"\n";
    }
}
