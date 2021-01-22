#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class myPair
{
public:
    int a;
    int b;
    void mySwap()
    {
        a = a+b;
        b = a-b;
        a = a-b;
    };
};


bool cmp(myPair p1, myPair p2)
{
    return p1.a<p2.a ? true:false;
}

int main()
{
    int n, m;
    cin>>n>>m;

    vector<myPair> v(m);
    vector<myPair> numV(n);//a is num, b is index
    for (int i = 0; i < n; i++)
    {
        numV[i].a = 0;
        numV[i].b = i;
    }
    

    for (int i = 0; i < m; i++)
    {
        cin>>v[i].a>>v[i].b;
        if (v[i].a > v[i].b)
        {
            v[i].mySwap();
        }
        numV[v[i].a-1].a++;
        numV[v[i].b-1].a++;  
    }
    
    sort(v.begin(),v.end(), cmp);
    sort(numV.begin(),numV.end(), cmp);

    


    return 0;
}