N = int(input())
paints = []

for _ in range(N):
    A, B = map(int, input().split())
    paints.append((A, B))

paints.sort()

start = paints[0][0]
end = paints[0][1]

for i in range(1, N):
    if end >= paints[i][0] or end == paints[i][0] - 1:
        if end < paints[i][1]:
            end = paints[i][1]
    else:
        print(start, end, end=" ")
        start = paints[i][0]
        end = paints[i][1]
    if i == N - 1:
        print(start, end, end=" ")
