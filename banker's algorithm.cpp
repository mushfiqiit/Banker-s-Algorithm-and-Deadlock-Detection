#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pi;
#define mp make_pair

ll allocation[5][3]={ {0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2} };
ll need[5][3] { {7, 4, 3}, {1, 2, 2}, {6, 0, 0}, {0, 1, 1}, {4, 3, 1} };
ll totalResources[3]={ 10, 5, 7 };
ll available[3]={3, 3, 2};

vector<ll> ans;
int resourceFlag[4]={0};

bool isSafe(int i)
{
    bool flag=true;
    for(int j=0;j<3;j++)
    {
        if(need[i][j]>available[j]) flag=false;
    }
    return flag;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    while(ans.size()<5)
    {
        for(int i=0;i<5;i++)
        {
            if(!resourceFlag[i])
            if(isSafe(i))
            {
                for(int j=0;j<3;j++)
                {
                    available[j]+=allocation[i][j];
                }
                resourceFlag[i]=1;
                ans.push_back(i);
            }
        }

    }
    for(int i=0;i<ans.size();i++)
        {
            cout<< "P" << ans[i] << " ";
        }
}

