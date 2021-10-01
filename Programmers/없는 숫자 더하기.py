is_exist = [False] * 10

def solution(numbers):
    answer = 0

    for number in numbers:
        is_exist[number] = True

    for i in range(len(is_exist)):
        if is_exist[i] == False:
            answer += i

    return answer