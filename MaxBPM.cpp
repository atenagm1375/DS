//Ashena G.Mohammadi, 610394128

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class MaxBPM{

public:
    MaxBPM(){
        cout << "Enter number of vertices:" << endl;
        cin >> V;
        cout << "Enter number of edges:" << endl;
        cin >> E;
        cout << "Enter connected vertices:" << endl;
        graph = new vector<int>[V];
        for(int i = 0; i < E; i++){
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        state = new int[V];
        for(int i = 1; i < V; i++)
            state[i] = -1;
        state[0] = 1;
    }

    bool isBipartite(){
        queue<int> Q;
        Q.push(0);
        while(!Q.empty()){
            int u = Q.front();
            Q.pop();
            for(int v = 0; v < V; v++){
                if(find(graph[u].begin(), graph[u].end(), v) != graph[u].end() && state[v] == -1){
                    state[v] = 1 - state[u];
                    Q.push(v);
                }
                else if(find(graph[u].begin(), graph[u].end(), v) != graph[u].end() && state[v] == state[u])
                    return false;
            }
        }
        return true;
    }

    void findMax(){
        state1 = 0;
        for(int i = 0; i < V; i++)
            if(state[i] == 1)
                state1++;
        match = new int[V];
        for(int i = 0; i < V; i++)
            match[i] = -1;
        for(int i = 0; i < V; i++){
            bool *visited = new bool[V];
            bpm(visited, i);
        }
        for(int i = 0; i < V; i++)
            if(match[i] != -1)
                cout << i << "--->" << match[i] << endl;
    }

    bool bpm(bool *visited, int u){
        for(int v = 0; v < V; v++)
            if(state[u] != state[v] && find(graph[u].begin(), graph[u].end(), v) != graph[u].end() && !visited[v]){
                visited[v] = true;
                if(match[v] == -1 || bpm(visited, v)){
                    match[v] = u;
                    return true;
                }
            }
        return false;
    }

private:

    int V;
    int E;
    vector<int> *graph;
    int *state;
    int state1;
    int *match;
};

int main(){
    MaxBPM bpm;
    if(!bpm.isBipartite())
        cout << "The graph is not bipatite!" << endl;
    else
        bpm.findMax();
    return 0;
}
