from itertools import combinations


def is_prime(num):
    if num <= 1:
        return False

    for i in range(2, num):
        if i * i > num:
            break

        if num % i == 0:
            return False
    return True


def solution(nums):
    answer = 0

    result = list(combinations(nums, 3))
    for j in result:
        ans = sum(j)
        if is_prime(ans):
            answer += 1

    return answer
