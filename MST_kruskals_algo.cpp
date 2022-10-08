//Minimum Spanning Tree by Kruskal's Algorithm
/*
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
*/
/**********
Sample I/O
Enter no. of vertices: 4
Enter no. of edges: 4
Input 4 lines, each line containing three integers:
Vertex1 Vertex2 Weight
1 2 62 3 21 3 2
1 0 2
Minimum spanning tree (by Kruskal's algorithm):
Vertex1 Vertex2 Weight
0       1       2
1       3       2
2       3       2
***********/
#include <iostream>
#include <algorithm>
using namespace std;
class Edge{
    public:
    int v1;
    int v2;
  	int weight;
};
bool compare(Edge &a, Edge &b)
{
    if(a.weight>b.weight)
        return false;
    return true;
}
int getparent(int x, int *parent)
{
    if(parent[x]==x) return x;
    return getparent(parent[x],parent);
}
bool isConnected(Edge inp,int *parent)
{
    int p1=getparent(inp.v1,parent);
    int p2=getparent(inp.v2,parent);
    if(p1==p2) return true;
    return false;
}

Edge *solve(Edge *inp, int v, int e)
{
    Edge *out=new Edge[v-1];
    int *parent=new int[v];
    for(int i=0;i<v;i++)
        parent[i]=i;
    sort(inp,inp+e,compare);   
    int count=0;
    int i=0;
    while(count!=v-1)
    {
        Edge curr=inp[i];
        int sourceparent=getparent(curr.v1,parent);
        int destparent=getparent(curr.v2,parent);
        if(sourceparent!=destparent)
        {
            out[count]=curr;
            count++;
            parent[sourceparent]=destparent;
        }
        i++;
    }
    return out;
}
int main() {
    int v,e;
    cout<<"Enter no. of vertices: ";
    cin>>v;
    cout<<"Enter no. of edges: ";
    cin>>e;
    cout<<"Input 4 lines, each line containing three integers:\n";
    cout<<"Vertex1\tVertex2\tWeight\n";
    Edge *a=new Edge[e];
    for(int i=0;i<e;i++)
        cin>>a[i].v1>>a[i].v2>>a[i].weight;
    Edge *output=solve(a,v,e);
    cout<<"Minimum spanning tree (by Kruskal's algorithm): \nVertex1\tVertex2\tWeight\n";
    for(int i=0;i<v-1;i++)
    {
        if(output[i].v1<=output[i].v2)
            cout<<output[i].v1<<"\t"<<output[i].v2<<"\t";
        else cout<<output[i].v2<<"\t"<<output[i].v1<<"\t";
        cout<<output[i].weight<<endl;
    }
}
