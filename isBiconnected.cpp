// Ashena Gorgan Mohammadi, 610394128

#include <iostream>
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

    bool isConnective(int u){
        bool *visited = new bool[v];
        for(int i = 0; i < v; i++)
            visited[i] = false;
        return dfs(u, visited, u);
    }

private:
    int v;
    list<int> *adj_list;

    bool dfs(int u, bool *visited, int src){
        visited[u] = true;
        for(list<int>::iterator i = adj_list[u].begin(); i != adj_list[u].end(); i++){
            if(!visited[*i] && !dfs(*i, visited, src)){
                bool t = true;
                for(int j = 0; j < v; j++)
                    t = t && visited[j];
                if(!t && u == src)
                    return true;
            }
        }
        return false;
    }
};

int main(){
    int v;
    cout << "Enter the number of vertices:" << endl;
    cin >> v;
    Graph g(v);
    cout << "Enter connected vertices(CTRL+D to end input):" << endl;
    int a, b;
    while(cin >> a >> b)
        g.addEdge(a, b);
    bool isBiconnected = true;
    for(int i = 0; i < v; i++){
        bool ans = g.isConnective(i);
        if(ans){
            isBiconnected = false;
            cout << i << " is a connective" << endl;
        }
    }
    if(isBiconnected)
        cout << "The graph is biconnected" << endl;
    return 0;
}
