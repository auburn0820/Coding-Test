import collections


def bfs():
    q = collections.deque()
    q.append((A, B))
    is_visit[A][B] = True

    while len(q) > 0:
        x, y = q.popleft()
        z = D - x - y

        if x == y == z:
            return 1

        for a, b in (x, y), (x, z), (y, z):
            if a < b:
                b -= a
                a += a
            elif a > b:
                a -= b
                b += b
            else:
                continue

            c = D - a - b
            X = min(a, b, c)
            Y = max(a, b, c)

            if not is_visit[X][Y]:
                q.append((X, Y))
                is_visit[X][Y] = True
    return 0


if __name__ == '__main__':
    A, B, C = map(int, input().split())
    D = A + B + C
    is_visit = [[False] * D for _ in range(D)]

    if D % 3 != 0:
        print(0)
    else:
        print(bfs())