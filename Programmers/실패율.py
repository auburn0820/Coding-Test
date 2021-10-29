def solution(N, stages):
    answer = []

    stage_info = [[0 for _ in range(0, 2)] for _ in range(0, N)]

    for i in stages:
        max_index = i
        if i <= len(stage_info):
            stage_info[i - 1][0] += 1
        else:
            max_index -= 1
        for j in range(0, max_index):
            stage_info[j][1] += 1

    rate = []
    for i in range(0, len(stage_info)):
        if stage_info[i][1] != 0:
            rate.append((i + 1, stage_info[i][0] / stage_info[i][1]))
        else:
            rate.append((i + 1, 0))

    rate.sort(key=lambda x: -x[1])

    for i in rate:
        answer.append(i[0])

    return answer