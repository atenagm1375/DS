#Atena G.Mohammadi

from collections import defaultdict

class Graph:
    
    def __init__(self, v):
        self.v = v
        self.graph = defaultdict(list)

    def addEdge(self, v, w):
        self.graph[v].append(w)
        self.graph[w].append(v)

    def dfs(self, v, visited):
        visited[v] = True
        for i in self.graph:
            if not visited[i]:
                dfs(i, visited)

    def isConnected(self):
        visited = [False]*(self.v)
        for i in range(self.v):
            if len(self.graph[i]) > 1:
                dfs(i, visited)
                break
            if i == self.v - 1:
                return True
        for i in range(self.v):
            if not visited[i] and len(self.graph[i]) > 0:
                return False
        return True

    def isEulerianPath(self):
        if not isConnected():
            return False
        odd_count = 0
        for i in range(self.v):
            if len(self.graph[i]) % 2 == 1:
                odd_count += 1
        if odd > 2:
            return False
        else:
            return True
