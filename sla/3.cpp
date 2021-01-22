//
// Created by 26538 on 2021/1/22.
//
//https://blog.csdn.net/weixin_44351043/article/details/104442577
//lei si
//unsolved  WA
#include <iostream>
#include<vector>
using namespace std;
int count;
int n,m;
vector<int>v(2,0);
vector<vector<int>>vec(100010,v);
vector<int>sugar;
int max_count=0;
int getint(){
    long long x=0,s=1; char ch=' ';
    while(ch<'0' || ch>'9'){ ch=getchar(); if(ch=='-') s=-1;}
    while(ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar();}
    return x*s;
}
void backtrack(int i){
    if (i==m){
        return ;
    }
    bool flag=false;
    for (int j=0;j<2;j++){
        if (sugar[vec[i][j]]==0){
            flag=true;
            sugar[vec[i][j]]=1;
            count++;
            max_count=max(count,max_count);
            backtrack(i+1);
            sugar[vec[i][j]]=0;
            count--;
        }
    }

}
int main()
{
    cin>>n>>m;
    for (int i=0;i<m;i++){
        vec[i][0]=getint();
        vec[i][1]=getint();
    }
    for (int i=0;i<n;i++){
        sugar.push_back(0);
    }
    count=0;
    backtrack(0);
    cout<<m-max_count;

}



