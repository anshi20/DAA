
#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2)
{
    double v1 = (double) p1.first/p1.second;
    double v2 = (double) p2.first/p2.second;
    return v1 > v2;
}

int main()
{
    
    int n;
    cout<<"Enter no of items : ";
    cin>>n;
    vector<pair<int,int>> a(n);
    int i, ans=0, w;
    cout<<endl;
    cout<<"Values  : ";
    for(i=0;i<n;i++)
    {
        cin>>a[i].first;
    }
    cout<<"Weights : ";
    for(i=0;i<n;i++)
    {
        cin>>a[i].second;
    }
    cout<<endl;
    cout<<"Enter size of knapsack : ";
    cin>>w;
    sort(a.begin(), a.end(), compare);
    
    for(i=0;i<n;i++)
    {
        if(w>=a[i].second)
        {
            ans+=a[i].first;
            w-=a[i].second;
            continue;
        }
        double vw = (double) a[i].first/a[i].second;
        ans+=vw*w;
        w=0;
        break;
    }
    cout<<"\nAnswer : "<<ans;
    cout<<endl;
    return 0;
}
