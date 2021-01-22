#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int findTrueV(vector<int> &cityDis,int start, int d, int consume,int time)
{
    for (int i = start+1; i < cityDis.size(); i++)
    {
        if ((cityDis[i] - cityDis[start])*consume >= d)
        {
            if ((cityDis[i-1] - cityDis[start])*consume*time >= d)
            {
                return (cityDis[i-1] - cityDis[start])*consume;
            }
            
            return (cityDis[i] - cityDis[start])*consume;
        }
    }
    return (cityDis[cityDis.size()-1] - cityDis[start])*consume;
    
}

int main()
{
    int n, m;
    cin>>n>>m;

    vector<int> cityDis(n);

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        cin>>cityDis[i];
    }
    
    for (int i = 0; i < m; i++)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;

        int dis = cityDis[b-1]-cityDis[a-1];
        int oil = dis * c;
        float v_f = oil*1.0/(d+1.0);
        int v_i = ceil(v_f);
        int truth_v_i = findTrueV(cityDis,a-1,v_i,c,d+1);
        ans = max(ans,truth_v_i);
    }
    
    cout<<ans<<endl;

    return 0;
}