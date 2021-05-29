#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pi;
#define mp make_pair

ll allocation[5][3]={ {0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2} };
ll request[5][3] { {100, 100, 100}, {1, 2, 2}, {6, 0, 0}, {0, 1, 1}, {4, 3, 1} };
ll totalResources[3]={ 10, 5, 7 };
ll available[3]={3, 3, 2};

void printAll()
{
    cout << "Allocation matrix\n";
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout << allocation[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "Request matrix\n";
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout << request[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "Total Resources\n";
    cout << "A B C\n";
    for(int i=0;i<3;i++) cout << totalResources[i] << " ";
    cout << "\n";
}

vector<ll> ans;
int resourceFlag[5]={0};

bool isSafe(int i)
{
    bool flag=true;
    for(int j=0;j<3;j++)
    {
        if(request[i][j]>available[j]) flag=false;
    }
    return flag;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    printAll(); cout << "\n";
    ll finishCounter=0;
    int deadLockFlag=0;
    for(int i=0;i<5;i++)
    {
        int flag=0;
        for(int j=0;j<3;j++)
        {
            if(allocation[i][j]!=0) flag=1;
        }
        if(!flag) { finishCounter++;
        resourceFlag[i]=1; }
    }

    while(finishCounter<5)
    {
        if(deadLockFlag) break;
        int pickedFlag=0;
        for(int i=0;i<5;i++)
        {
            if(!resourceFlag[i])
            if(isSafe(i))
            {
                pickedFlag=1;
                for(int j=0;j<3;j++)
                {
                    available[j]+=allocation[i][j];
                }
                resourceFlag[i]=1;
                ans.push_back(i); finishCounter++;
            }

        }if(pickedFlag==0) deadLockFlag=1;

    }

    if(deadLockFlag) cout << "Deadlock exists \n";
    else cout << "Deadlock does not exist\n";

    cout << "\n";
    printAll(); cout << "\n";
    allocation[0][1]=0;
    memset(resourceFlag, 0, sizeof resourceFlag);
    available[0]=3; available[1]=3; available[2]=2;
//cout << resourceFlag[4] << "\n";
    finishCounter=0;
    deadLockFlag=0;
    for(int i=0;i<5;i++)
    {
        int flag=0;
        for(int j=0;j<3;j++)
        {
            if(allocation[i][j]!=0) flag=1;
        }
        if(!flag) { finishCounter++; //cout << i << "\n";
        resourceFlag[i]=1; }
    }


    while(finishCounter<5)
    {
        //cout << deadLockFlag << " " << finishCounter << "\n";
        if(deadLockFlag) break;
        int pickedFlag=0;
        for(int i=0;i<5;i++)
        {
            if(!resourceFlag[i]) { //cout << i << "\n";
            if(isSafe(i))
            {
                //cout << i << "\n";
                pickedFlag=1;
                for(int j=0;j<3;j++)
                {
                    available[j]+=allocation[i][j];
                }
                resourceFlag[i]=1;
                ans.push_back(i); finishCounter++;
                break;
            } }

        }if(pickedFlag==0) deadLockFlag=1;
        //cout << available[0] << " " << available[1] << " " << available[2] << "\n";
    }

    if(deadLockFlag) cout << "Deadlock exists ";
    else cout << "Deadlock does not exist";

}


