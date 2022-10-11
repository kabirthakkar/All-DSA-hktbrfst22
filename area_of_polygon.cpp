//Area of convex polygon
//The no. of vertices and coordinates of vertices are entered by the user. Code outputs the area of the polygon so formed. 

/***************
Sample I/O
Enter no. of vertices in the polygon: 4
Enter coordinates of each vertex in a new line:
1 5
2 2
9 2
7 5
Area of the polygon is: 19
*****************/
#include<bits/stdc++.h>
using namespace std;
#define int int64_t
double crossproduct(pair<double,double> &a,pair<double,double> &b)
{
    return a.first*b.second-a.second*b.first;
}
pair<double,double> makevector(pair<double,double> &a, pair<double,double> &b)
{
    return make_pair(b.first-a.first,b.second-a.second);
}
void solve()
{
    int n;
    cout<<"Enter no. of vertices in the polygon: ";
    cin>>n;
    double ans=0.0;
    vector<pair<double,double>> v(n);
    cout<<"Enter coordinates of each vertex in a new line: \n";
    for(int i=0;i<n;i++)
        cin>>v[i].first>>v[i].second;

    for(int i=2;i<n;i++)
    {
        pair<double,double> v1=makevector(v[0],v[i-1]);
        pair<double,double> v2=makevector(v[i-1],v[i]);
        ans+=crossproduct(v1,v2)/2;
    }
    cout<<"Area of the polygon is: ";
    cout<<(int)ans<<'\n';
}
int32_t main()
{
    solve();
}
