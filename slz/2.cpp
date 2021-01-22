#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <queue>
#include <cstdio>
#include <map>
#include <set>
#include <utility>
#include <stack>
#include <cstring>
#include <cmath>
#include <vector>
#include <ctime>
#include <bitset>
#include <assert.h>
#include <iomanip>
using namespace std;
#define pb push_back
#define sd(n) scanf("%d",&n)
#define sdd(n,m) scanf("%d%d",&n,&m)
#define sddd(n,m,k) scanf("%d%d%d",&n,&m,&k)
#define sld(n) scanf("%lld",&n)
#define sldd(n,m) scanf("%lld%lld",&n,&m)
#define slddd(n,m,k) scanf("%lld%lld%lld",&n,&m,&k)
#define sf(n) scanf("%lf",&n)
#define sff(n,m) scanf("%lf%lf",&n,&m)
#define sfff(n,m,k) scanf("%lf%lf%lf",&n,&m,&k)
#define ss(str) scanf("%s",str)
#define ansn() printf("%d\n",ans)
#define lansn() printf("%lld\n",ans)
#define r0(i,n) for(int i=0;i<(n);++i)
#define r1(i,e) for(int i=1;i<=e;++i)
#define rn(i,e) for(int i=e;i>=1;--i)
#define mst(abc,bca) memset(abc,bca,sizeof abc)
#define lowbit(a) (a&(-a))
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pll pair<long long,long long>
#define mp(aa,bb) make_pair(aa,bb)
#define lrt rt<<1
#define rrt rt<<1|1
#define X first
#define Y second
#define PI (acos(-1.0))
double pi = acos(-1.0);
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
//const ll mod = 1000000007;
const double eps=1e-12;
const int inf=0x3f3f3f3f;
//const ll infl = 100000000000000000;//1e17
const int maxn=  2e6+20;
const int maxm = 5e3+20;
//muv[i]=(p-(p/i))*muv[p%i]%p;
inline int in(int &ret) {
    char c;
    int sgn ;
    if(c=getchar(),c==EOF)return -1;
    while(c!='-'&&(c<'0'||c>'9'))c=getchar();
    sgn = (c=='-')?-1:1;
    ret = (c=='-')?0:(c-'0');
    while(c=getchar(),c>='0'&&c<='9')ret = ret*10+(c-'0');
    ret *=sgn;
    return 1;
}
int dp[444][444];
vector<pii>v[444][444];
int a[maxn];
int main() {
#ifdef LOCAL
    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
#endif // LOCAL
    int n,m;
    sdd(n,m);
    r1(i,n)sd(a[i]);
    r1(i,m) {
        int a,b,c,d;
        sdd(a,b);
        sdd(c,d);
        v[a][b].pb(mp(c,d));
    }
    ll ans = 0;
    for(int i=1; i<=n; ++i) {
        int st = i;
        mst(dp,0x3f);
        for(int j=st+1; j<=n; ++j) {
            dp[j][0] = a[j] - a[st];
            int u = st;
            for(int k=1; k<=n; ++k) {
                for(; u<j&&dp[u+1][k-1] < a[j] - a[u+1];)++u;
                dp[j][k] = min(dp[u+1][k-1],a[j] - a[u]);
            }
            for(int k=0,sz = v[i][j].size(); k<sz; ++k) {
                ll c = v[i][j][k].X;
                int r = v[i][j][k].Y;
                ans = max(ans,c*dp[j][r]);
            }
        }
    }
    lansn();
    return 0;
}


