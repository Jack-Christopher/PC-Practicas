import sys
import heapq

queries = []

result_queries = []
k = 0
for line in sys.stdin:
    if line.split()[0] != "#":
        queries.append((int(line.split()[2]), int(line.split()[1]), int(line.split()[2])))
        heapq.heapify(queries)
    else:
        k = int(input())
        break


for i in range(k):
  v = heapq.heappop(queries)
  print(v[1])
  heapq.heappush(queries, (v[0] + v[2], v[1], v[2]))






  