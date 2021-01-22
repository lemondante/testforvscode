// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main()
// {
//     int n, m;
//     cin>>n>>m;

//     int ans = 0;

//     vector<int> v(n);

//     for (int i = 0; i < n; i++)
//     {
//         cin>>v[i];
//     }

//     for (int i = 0; i < n-1; i++)
//     {
//         // for (int j = i; j < n; j++)
//         // {
//         //     if (v[i] > v[j])
//         //     {
//         //         ans = max(ans,min(v[i]-v[j],m-v[i]));
//         //     }

//         // }

//         if (v[i] > v[i+1])
//         {
//             //i!=0
//             if (v[i]-v[i+1]>m-v[i]+v[i-1])
//             {
//                 /* code */
//             }

//             ans = max(ans,min(v[i]-v[i+1],m-v[i]+v[i-1]));
//         }

//     }

//     cout<<ans<<endl;

//     return 0;
// }

// #include <algorithm>

#include <iostream>
#include <vector>

using namespace std;

int returnMax(int a, int b)
{
    int ans =  0;
    if (a >= b)
    {
        ans = a;
    }
    else
    {
        ans = b;
    }
    return ans;
}
int returnMin(int a, int b)
{
    int ans =  0;
    if (a >= b)
    {
        ans = b;
    }
    else
    {
        ans = a;
    }
    return ans;
}

int main()
{
    int n, m;

    cin>>n>>m;

    vector<int> v(300010);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    int left = 0;
    int right = m;
    int ans = 0;
    while (left <= right)
    {
        int pre = 0;
        int mid;

        int flag = 0;
        mid = (left + right) / 2;

        for (int i = 1; i <= n; i++)
        {
            int flagV;

            flagV = (v[i] + mid >= m ? 1:0);
      
            if (flagV == 0)
            {
                if (v[i] + mid >= pre)
                {
                    pre = returnMax(v[i], pre);
                    if (i == n)
                    {
                        flag = 1;
                    }
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (v[i] + mid - m < pre)
                {
                    if (v[i] >= pre)
                    {
                        pre = v[i];
                    }
                }
                if (i == n)
                {
                    flag = 1;
                }
            }
        }
        if (flag == 1)
        {
            right = mid - 1;
            ans = mid;
        }
        else
        {
            left = mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}