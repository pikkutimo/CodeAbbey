#include<iostream>
using namespace std;
int main()
{
    int n,a[3],ans[100];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        ans[i]=1000000000;
        cin>>a[0]>>a[1]>>a[2];
        for(int j=1;j<a[2];j++)
        {
            ans[i]=min(ans[i],max(j*a[0],(a[2]-j)*a[1]));
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<endl;
    }
}