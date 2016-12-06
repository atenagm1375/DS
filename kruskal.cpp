// Ashena Gorgan Mohammadi, 610394128

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

    Edge *kruskal(){
        sort(graph.begin(), graph.end(), comp);
        Edge *ans = new Edge[V];
        vector< vector<int> > connected;
        int u = 0;
        int i = 0;
        while(i < E){
            bool t = true, f = true, mark = false;
            int x = 0;
            for(; x < connected.size(); x++){
                cout << "hi" << endl;
                for(int y = 0; y < connected[x].size(); y++){
                    cout << "bye" << endl;
                    if(connected[x][y] == graph[i].v)
                        t = false;
                    if(connected[x][y] == graph[i].u)
                        f = false;
                }
            }
            if(t || f){
                ans[u++] = graph[i];
                if(t)
                    connected[x].push_back(graph[i].u);
                if(f)
                    connected[x].push_back(graph[i].v);
            }
            i++;
        }
        return ans;
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
    Edge *ans = g.kruskal();
    for(int i = 0; i < V; i++)
        cout << ans[i].u << "-->" << ans[i].v << " " << ans[i].weight << endl;
    return 0;
}
