#include <iostream>
#include <list>

using namespace std;

class Graph{
public:
    Graph(int n){
        v = n;
        adj_list = new list<int>[v];
    }

    void add_edge(int v, int w){
        adj_list[v].push_back(w);
        adj_list[w].push_back(v);
    }

    bool has_cycle(){
        bool *visited = new bool[v];
        for(int i = 0; i < v; i++)
            visited[i] = false;
        for(int i = 0; i < v; i++)
            if(!visited[i] && dfs(i, visited, -1))
                return true;
        return false;
    }

private:
    int v;
    list<int> *adj_list;
    
    bool dfs(int u, bool *visited, int parent){
        visited[u] = 1;
        list<int>::iterator i = adj_list[u].begin();
        for( ; i != adj_list[u].end(); i++){
            if(!visited(u) && dfs(*i, visited, u))
                return true;
            else if(*i != parent)
                return true;
        }
        return false;
    }
};
