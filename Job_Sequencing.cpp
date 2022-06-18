//Job Sequencing - Practice

#include <bits/stdc++.h>

using namespace std;

struct jobs
{
  char id;
  int deadline;
  int profit;
};

bool compare(jobs a,jobs b)
{
    return a.profit>b.profit;
}

void jobsequencing(jobs arr[], int n)
{
    int i,j;
    int result[n];
    bool slot[n];
    sort(arr,arr+n,compare);
    for(i=0;i<n;i++)
        slot[i]=false;
    for(i=0;i<n;i++)
    {
        for(j=min(arr[i].deadline,n)-1;j>=0;j--)
        {
            if(slot[j]==false)
            {
                slot[j]=true;
                result[j]=i;
                break;
            }
        }
    }
    cout << "\nFollowing is maximum profit sequence of jobs ";
    for(i=0;i<n;i++)
    {
        if(slot[i])
           cout<<arr[result[i]].id<<" ";
    }
}

int main()
{
    int n;
    cin>>n;
    jobs arr[n];
    cout<<"ENTER ID, DEADLINE, PROFIT \n";
    int i;
    for(i=0;i<n;i++)
    {
        cin>>arr[i].id;
        cin>>arr[i].deadline;
        cin>>arr[i].profit;
    }
    jobsequencing(arr,n);
    return 0;
}
