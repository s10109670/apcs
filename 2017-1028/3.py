n = int(input())
parent=[0]*(n+1)
leaf = []
for i in range(1,n+1):
    kid_num, *kid = map(int,input().split())
    if kid_num == 0:
        leaf.append(i)
    else:
        for j in range(kid_num):
            parent[kid[j]] = i
root = 1
#find root
while parent[root]>0:
    root = parent[root]

height = [0]*(n+1)
for node in leaf:
    while node != root and height[parent[node]] < height[node]+1:
        height[parent[node]] = height[node]+1
        node = parent[node]
print(root)
print(sum(height))
