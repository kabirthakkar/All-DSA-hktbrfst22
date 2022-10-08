//Dijkstra's Algorithm
/*
An undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges is given.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also).
*/

/*
Sample I/O:
Enter no. of vertices: 4
Enter no. of edges: 4
Input 4 lines, each line containing three integers:
Vertex1 Vertex2 Weight
1 2 6 
2 3 2 
1 3 2
1 0 2
Shortest distance from vertex 0 to other vertices are:
Vertex  Weight
0       0
1       2
2       6
3       4
*/
#include <iostream>
#include <climits>
using namespace std;
int findmin(int *weight, int v, bool *visited)
{
    int ans=-1;
    for(int i=0;i<v;i++)
    {
        if(!visited[i] && (ans==-1 || weight[i]<weight[ans]))
            ans=i;
    }
    return ans;
}
void dijkstra(int **edge, int v, int e)
{
	int *parent=new int[v]{0};
    int *weight=new int[v]{0};
    bool *visited=new bool[v];
    for(int i=0;i<v;i++)
    {
        parent[i]=-1;
        weight[i]=INT_MAX;
    }
    parent[0]=0;
    weight[0]=0;
    for(int i=0;i<v;i++)
    {
        int mv=findmin(weight,v,visited);
        if(mv==-1) {
            cout<<"bu";
            break;
        }
        visited[mv]=true;
        for(int j=0;j<v;j++)
        {
            if(!visited[j] && edge[mv][j]!=0)
            {
                if(weight[mv]+edge[mv][j]<weight[j]) 
                    weight[j]=weight[mv]+edge[mv][j];
                parent[j]=mv;
            }
        }
    }
    cout<<"Shortest distance from vertex 0 to other vertices are: \n";
    cout<<"Vertex\tWeight\n";
    for(int i=0;i<v;i++)
    {
        cout<<i<<"\t"<<weight[i]<<'\n'; 
    }
}
int main() {
    
    int v,e;
    cout<<"Enter no. of vertices: ";
    cin>>v;
    cout<<"Enter no. of edges: ";
    cin>>e;
    int **edge=new int*[v];
    for(int i=0;i<v;i++)
    	edge[i]=new int[v]{0};
    cout<<"Input "<<e<<" lines, each line containing three integers:\n";
    cout<<"Vertex1\tVertex2\tWeight\n";
    for(int i=0;i<e;i++)
    {
        int ei,ej,wi;
        cin>>ei>>ej>>wi;
        edge[ei][ej]=wi;
        edge[ej][ei]=wi;
    }
    dijkstra(edge,v,e);
    for(int i=0;i<v;i++)
        delete [] edge[i];
    delete [] edge;
}
