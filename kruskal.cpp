// Ashena Gorgan Mohammadi, 610394128

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class connectedComponent{
public:
    connectedComponent(int n){
        parent = new int[n + 1];
        rank = new int[n + 1];
        for(int i = 0; i <= n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int v){
        if(v != parent[v])
            parent[v] = find(parent[v]);
        return parent[v];
    }

    void connect(int u, int v){
        u = find(u);
        v = find(v);
        if(rank[u] > rank[v])
            parent[v] = u;
        else
            parent[u] = v;
        if(rank[u] == rank[v])
            rank[v]++;
    }

private:
    int *parent;
    int *rank;
};

struct Edge{
    int u;
    int v;
    int weight;
};

bool comp(Edge e1, Edge e2){
    return e1.weight < e2.weight;
}

class Graph{
public:
    Graph(int v, int e){
        V = v;
        E = e;
    }

    void addEdge(int u, int v, int w){
        Edge e;
        e.u = u;
        e.v = v;
        e.weight = w;
        graph.push_back(e);
    }

    int kruskal(){
        sort(graph.begin(), graph.end(), comp);
        int w = 0;
        connectedComponent cc(V);
        for(int i = 0; i < E; i++){
            int u = graph[i].u;
            int v = graph[i].v;
            int ccu = cc.find(u);
            int ccv = cc.find(v);
            if(ccv != ccu){
                cc.connect(ccu, ccv);
                w += graph[i].weight;
                cout << u << "<-->" << v << " " << graph[i].weight << endl;
            }
        }
        return w;
    }

private:
    int V;
    int E;
    vector<Edge> graph;
};

int main(){
    int V, E;
    cout << "Enter the number of vertices and edges:" << endl;
    cin >> V >> E;
    Graph g(V, E);
    cout << "Enter two connected vertices and the edge's weight:" << endl;
    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    int ans = g.kruskal();
    cout << "MST weight: " << ans << endl;
    return 0;
}
