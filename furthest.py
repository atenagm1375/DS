def furthest(G, S):
    S.visied = 1
    Q = queue.Queue()
    Q.put(S)
    P = queue.Queue()
    P.put(0)
    while not Q.empty():
        S = Q.get()
        a = P.get()
        for v in G[S]:
            if v.visited = 0:
                Q.put(v)
                P.put(a + 1)
                v.visited = 1
    return(S)
