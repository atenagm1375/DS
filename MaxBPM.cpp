//Ashena G.Mohammadi, 610394128

/* This is one of the projects for Data Structure course 2016-2017.
 * It finds Maximum bipartite matching graph for a given graph which
 * might not be bipartite.
 */

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
        graph = new int *[V];
        for(int i = 0; i < V; i++)
            graph[i] = new int[V];
        for(int i = 0; i < E; i++){
            int a, b;
            cin >> a >> b;
            graph[a][b] = 1;
            graph[b][a] = 1;
        }
        state = new int[V];
        for(int i = 0; i < V; i++)
            state[i] = -1;
    }

    //checks if the graph is bipartite
    bool isBipartite(){
        for(int i = 0; i < V; i++)
            if(state[i] == -1 && !bp(i))
                return false;
        return true;
    }

    //main function for finding the maximum BPM
    void findMax(){
        match = new int[V];
        for(int i = 0; i < V; i++)
            match[i] = -1;
        for(int i = 0; i < V; i++){
            bool *visited = new bool[V];
            bpm(visited, i);
        }
        cout << "The maximum matching bipartite graph is:" << endl;
        for(int i = 0; i < V; i++)
            if(match[i] != -1)
                cout << i << "---->" << match[i] << endl;
    }

    //maximum BPM helper function using dfs algorithm to specify the matching vertices
    bool bpm(bool *visited, int u){
        for(int v = 0; v < V; v++)
            if(state[u] == 0 && graph[u][v] && !visited[v]){
                visited[v] = true;
                if(match[v] == -1 || bpm(visited, match[v])){
                    match[v] = u;
                    return true;
                }
            }
        return false;
    }

private:

    int V; //number of vertices
    int E; //number of edges
    int **graph; //adjacency matrix of the graph
    int *state; //shows if a vertex is in the left part or right part of the bipartite graph
    int *match; //shows matching vertices of the MaxBPM

    //bipartite helper function using bfs algorithm to specify the states
    bool bp(int w){
        state[w] = 1;
        queue<int> Q;
        Q.push(w);
        while(!Q.empty()){
            int u = Q.front();
            Q.pop();
            for(int v = 0; v < V; v++){
                if(graph[u][v] && state[v] == -1){
                    state[v] = 1 - state[u];
                    Q.push(v);
                }
                else if(graph[u][v] && state[v] == state[u])
                    return false;
            }
        }
        return true;
    }

};

int main(){
    MaxBPM bpm;
    if(!bpm.isBipartite())
        cout << "The graph is not bipatite!" << endl;
    else
        bpm.findMax();
    return 0;
}
