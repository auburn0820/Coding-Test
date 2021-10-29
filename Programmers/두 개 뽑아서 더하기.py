from itertools import combinations


def solution(numbers):
    answer = []
    s = set()

    for i in combinations(numbers, 2):
        s.add(i[0] + i[1])

    answer = list(s)
    answer.sort()

    return answer