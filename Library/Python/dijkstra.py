from heapq import heappush, heappop

INF = float('inf')

class WeightedEdge():
    def __init__(self, src, to, cost):
        self.src = src
        self.to = to
        self.cost = cost

def Dijkstra(G, s):
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
    This library is verified by AOJ(https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_1_A/review/3256417/kobaryo222/Python3)
    入力
    V E r (V:=頂点の数, E:=辺の数, r:=始点のインデックス)
    src0 to0 cost0
    src1 to1 cost1
    .
    .
    srcE-1 toE-1 costE-1
    """
    V, E, r = map(int, input().split())
    G = [[] for i in range(V)]
    for i in range(E):
        src, to, cost = map(int, input().split())
        G[src].append(WeightedEdge(src, to, cost))
    dist = Dijkstra(G, r)
    for i in range(V):
        if dist[i] == INF:
            print("INF")
        else:
            print(dist[i])