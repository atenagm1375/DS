def dfs(G, u, visited):
    visited[u] = True
    for v in G[u]:
        if not visited[v]:
            dfs(v, visited)

def connectedComponent(G):
    visited = [False]*(G.V)
    count = 0
    for u in range(G.V):
        if not visited[u]:
            count += 1
            dfs(G, u, visited)
