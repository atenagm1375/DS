#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

class Graph{
public:
    Graph(int n){
        v = n;
        adj_list = new list<int>[v];
    }

    void addEdge(int u, int w){
        adj_list[u].push_back(w);
        adj_list[w].push_back(u);
    }

    list<int> operator[](int i){
        return adj_list[i];
    }

    bool isSubGraph(Graph G){
        bool *visited = new bool[v];
        for(int i = 0; i < v; i++)
            visited[i] = false;
        for(int i = 0; i < v; i++)
            if(!visited[i] && dfs(i, visited, G))
                return true;
        return false;
    }

private:
    int v;
    list<int> *adj_list;

    bool find(list<int> G, int u){
        for(list<int>::iterator j = G.begin(); j != G.end(); j++)
            if(*j == u)
                return true;
        return false;
    }

    bool dfs(int u, bool *visited, Graph G){
        visited[u] = true;
        for(list<int>::iterator i = adj_list[u].begin(); i != adj_list[u].end(); i++){
            if(find(G[*i], u))
                return true;
            if(!visited[*i])
                if(!dfs(*i, visited, G))
                    return false;
        }
        return false;
    }
};

int main(){
    int v;
    cout << "Enter number of vertices:" << endl;
    cin >> v;
    Graph G1(v);
    Graph G2(v);
    cout << "Enter number of edges in G1 and G2:" << endl;
    int d, e;
    cin >> d >> e;
    cout << "Enter each two connected vertex of G1(zero base):" << endl;
    for(int i = 0; i < d; i++){
        int a, b;
        cin >> a >> b;
        G1.addEdge(a, b);
    }
    cout << "Enter each two connected vertex of G2(zero base):" << endl;
    for(int i = 0; i < e; i++){
        int a, b;
        cin >> a >> b;
        G2.addEdge(a, b);
    }
    G1.isSubGraph(G2) ? cout << "YES" : cout << "NO";
    return 0;
}
