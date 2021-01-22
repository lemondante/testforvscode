#include<stdio.h>
#include<algorithm>
using namespace std;
int a[300005];
int main()
{
    int n,m,i;
    scanf("%d%d",&n,&m);
    for(i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }
    int l=0,r=m,ans;
    while(l<=r)
    {
        int mid;
        int flag=0;
        mid=(l+r)/2;
        int pre=0;//前一个数的取值
        for(i=1; i<=n; i++)
        {
            int vis;
            if(a[i]+mid>=m)
            {
                vis=1;//此时a[i]的取值范围是 [a[i],m-1]∪[0,a[i]+mid-m]
            }
            else
            {
                vis=0;//此时a[i]的取值范围 [a[i],a[i]+mid]
            }
            if(vis==0)
            {
                if(a[i]+mid>=pre)
                {
                    pre=max(a[i],pre);
                    if(i==n)
                        flag=1;
                }
                else
                    break;
            }
            if(vis==1)
            {
                if(a[i]+mid-m>=pre)
                    pre=pre;
                else
                {
                    if(a[i]>=pre)
                        pre=a[i];
                    else
                        pre=pre;
                }
                if(i==n)
                    flag=1;
            }
        }
        if(flag==1)
        {
            r=mid-1;
            ans=mid;
        }
        else
            l=mid+1;
    }
    printf("%d\n",ans);
}