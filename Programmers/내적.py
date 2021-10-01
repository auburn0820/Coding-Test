def solution(a, b):
    answer = 0
    size = len(a)

    for i in range(size):
        answer += a[i] * b[i]

    return answer