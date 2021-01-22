#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 300010;
int n,m;
vector<int>vec(maxn);
int getint(){
    long long x=0,s=1; char ch=' ';
    while(ch<'0' || ch>'9'){ ch=getchar(); if(ch=='-') s=-1;}
    while(ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar();}
    return x*s;
}
bool xiugai(int mid){
    int pre;
    if(vec[1]+mid>=m) pre = 0;
    else pre = vec[1];
    for(int i=2;i<=n;i++){
        int temp = -1;
        if(vec[i]+mid>=m&&(vec[i]+mid)%m>=pre) temp = pre;
        else if(vec[i]<=pre&&vec[i]+mid>=pre) temp = pre;
        else if(vec[i]>pre) temp = vec[i];
        if(temp==-1) return false;
        pre = temp;
    }
    return true;
}
int main(void){
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        vec[i]=getint();
    }
    int left = 0,right = m,res = 0;
    while(left<=right){
        int mid = (left+right)/2;
        if(xiugai(mid)){
            res = mid;
            right = mid-1;
        }
        else left = mid+1;
    }
    cout<<res;
}
