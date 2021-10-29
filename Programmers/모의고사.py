def solution(answers):
    answer = []

    first_num = [1, 2, 3, 4, 5]
    second_num = [2, 1, 2, 3, 2, 4, 2, 5]
    third_num = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]

    first = [0 for _ in range(0, len(answers))]
    second = [0 for _ in range(0, len(answers))]
    third = [0 for _ in range(0, len(answers))]

    index = 0
    for i in range(0, len(first)):
        first[i] = first_num[index]
        index = (index + 1) % len(first_num)

    index = 0
    for i in range(0, len(second)):
        second[i] = second_num[index]
        index = (index + 1) % len(second_num)

    index = 0
    for i in range(0, len(third)):
        third[i] = third_num[index]
        index = (index + 1) % len(third_num)

    max_count = -1
    correct_count = [0 for _ in range(0, 3)]
    for i in range(0, len(answers)):
        if first[i] == answers[i]:
            correct_count[0] = correct_count[0] + 1
            max_count = max(max_count, correct_count[0])
        if second[i] == answers[i]:
            correct_count[1] = correct_count[1] + 1
            max_count = max(max_count, correct_count[1])
        if third[i] == answers[i]:
            correct_count[2] = correct_count[2] + 1
            max_count = max(max_count, correct_count[2])

    for i in range(0, 3):
        if max_count == correct_count[i]:
            answer.append(i + 1)

    answer.sort()

    return answer