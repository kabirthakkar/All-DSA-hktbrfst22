//Minimum Spanning Tree (MST) by Prim's Algorithm
//An undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges is given.

/********************
Sample I/O:
Enter no. of vertices: 3
Enter no. of edges: 3
Input 3 lines, each line containing three integers: 
Vertex1 Vertex2 Weight
1 2 6
2 0 2
1 0 2

Minimum spanning tree (by Prim's algorithm): 
Vertex1 Vertex2 Weight
0       1       2
0       2       2
*********************/
#include <bits/stdc++.h>
using namespace std;
int findMinvertex(int* weights, bool* visited, int n){
    int minVertex = -1;
    for(int i=0; i<n; i++){
        if(!visited[i] && (minVertex == -1 || weights[i] < weights[minVertex]))
            minVertex = i;
    }
    return minVertex;
}
void primsMST(int** edges, int n){
    bool* visited = new bool[n];
    int* parent = new int[n];
    int* weights = new int[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
        weights[i] = INT_MAX;
    }
    parent[0] = -1;
    weights[0] = 0;

    for(int i=0; i<n; i++){
        // find min vertex
        int m = findMinvertex(weights, visited, n);
        visited[m] = true;
        // explore unvisited vertex neighbours
        for(int j=0; j<n; j++){
            if(!visited[j] && edges[m][j] != 0 && edges[m][j] < weights[j]){
                weights[j] = edges[m][j];
                parent[j] = m;
            }
        }
    }
    cout<<"\nMinimum spanning tree (by Prim's algorithm): \nVertex1\tVertex2\tWeight\n";
    for(int i=1; i<n; i++){
        if(parent[i]<i)
            cout<<parent[i]<<"\t"<<i<<  "\t" << weights[i] << endl;
         else 
            cout << i <<  "\t" << parent[i] << "\t" << weights[i] << endl;
    }
}
int main(){
    int v, e;
    cout<<"Enter no. of vertices: ";
    cin >> v;
    cout<<"Enter no. of edges: ";
    cin>>e;
    int** edges = new int*[v];
    for(int i=0; i<v; i++){
        edges[i] = new int[v];
        for(int j=0; j<v; j++)
            edges[i][j] = 0;
    }
    cout<<"Input "<<e<<" lines, each line containing three integers: \nVertex1\tVertex2\tWeight\n";
    for(int k=0; k<e; k++){
        int sv, lv, w;
        cin >> sv >> lv >> w;
        edges[sv][lv] = edges[lv][sv] =w; 
    }
    primsMST(edges, v);
    for(int i=0; i<v; i++)
        delete [] edges[i];
    delete [] edges;
    return 0;
}
