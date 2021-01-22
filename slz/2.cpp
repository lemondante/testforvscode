#include "iostream"
using namespace std;
using namespace std;
typedef long long ll;
const int maxn = 250050;
int n,m;
int dp[403][403][403],p[401];
int s[maxn],t[maxn],c[maxn],r[maxn];

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    for(int i=1;i<=m;i++){
        cin>>s[i];
        cin>>t[i];
        cin>>c[i];
        cin>>r[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            dp[i][j][1]=p[j]-p[i];
        }
    }
    for(int k=2;k<=n+1;k++){
        for(int i=1;i<=n;i++){
            int pos=i;
            for(int j=i+1;j<=n;j++){
                while(pos<=j&&dp[i][pos][k-1]<p[j]-p[pos])pos++;
                dp[i][j][k]=min(p[j]-p[pos-1],dp[i][pos][k-1]);
            }
        }
    }
    ll result=0,tmp;
    for(int i=1;i<=m;i++){
        tmp=1ll*c[i]*dp[s[i]][t[i]][r[i]+1];
        result=max(result, tmp);
    }
    cout << result;
    return 0;
}

