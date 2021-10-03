import sys

def create_data_structure(n):
    rank =[1]*n
    parent = []
    for i in range(n):
        parent.append(i)
    return parent, rank

def find_parent(n, parent):
    if n == parent[n]:
        return n
    else:
        parent[n] = find_parent(parent[n], parent)
        return parent[n]

def make_pair(a, b, parent, rank):
    u = find_parent(a, parent)
    v = find_parent(b, parent)

    if(u==v):
        return

    if rank[u] < rank[v]:
        parent[u] = v

    if(rank[u]>=rank[v]):
        parent[v] = u
        rank[u]+=rank[v]

    else:
        parent[u] = v
        rank[v]+=rank[u]




for line in sys.stdin:
    # each test_case
    [n, m] = [int(x) for x in line.split()]
    if n != 0 or m != 0:        
        parent, rank = create_data_structure(n)
        for t in range(m):
            # each group
            temp = [int(x) for x in input().split()][1:]
            for i in range(1, len(temp)):
                make_pair(temp[i-1], temp[i], parent, rank)
            2
        print(rank[find_parent(0, parent)])
        
