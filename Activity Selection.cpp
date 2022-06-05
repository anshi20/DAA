
#include<bits/stdc++.h>
using namespace std;

bool compare(vector<int> a, vector<int> b)
{
    return a[1]<b[1];
}

int main()
{
    int n;
    cout<<"Enter no. of activities : ";
    cin>>n;
    int i;
    vector<int> ac;
    vector<vector<int>> v;
    cout<<"START\tEND\n";
    for(i=0;i<n;i++)
    {
        int start, end;
        cin>>start>>end;
        v.push_back({start,end});
    }
    sort(v.begin(), v.end(), compare);
    int ans=1;
    int end = v[0][1];
    ac.push_back(0);
    for(i=1;i<n;i++)
    {
        if(v[i][0]>=end)
        {
            ans++;
            ac.push_back(i);
            end=v[i][1];
        }
    }
    cout<<"Maximum no. of activities that can be selected : "<<ans;
    cout<<"\nSelected activities are : ";
    for(i=0;i<ac.size();i++)
    {
        cout<<ac[i]<<", ";
    }
}
