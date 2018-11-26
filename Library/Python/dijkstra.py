from heapq import *

class UnWeightedEdge:
    """Data structure for weighted graph"""
    def __init__(self, src, to):
        self.src = src
        self.to = to

class WeightedEdge(UnWeightedEdge):
    """Data structure for weighted graph"""
    def __init__(self, src, to, cost):
        super().__init__(src, to)
        self.cost = cost

def Dijkstra(G, s):
    INF = 10^18+10
    dist = [INF] * len(G)
    dist[s] = 0
    pq = []
    heappush(pq, (0, s))
    while len(pq) != 0:
        top = heappop(pq)
        cost = top[0]
        v = top[1]
        if dist[v] < cost:
            continue
        for edge in G[v]:
            next_cost = cost + edge.cost
            if dist[edge.to] <= next_cost:
                continue
            dist[edge.to] = next_cost
            heappush(pq, (next_cost, edge.to))
    return dist

if __name__ == "__main__":
    """
    入力
    V E u v (V:=頂点数, E:=辺数, u:=スタートのインデックス, v:=ゴールのインデックス)
    src0 to0 cost0
    src1 to1 cost1
    .
    .
    srcE-1 toE-1 costE-1
    """
    V, E, u, v = map(int, input().split())
    G = [list()] * V
    for i in range(E):
        src, to, cost = map(int, input().split())
        G[src].append(WeightedEdge(src, to, cost))
    
    dist = Dijkstra(G, u)
    print(dist[v])