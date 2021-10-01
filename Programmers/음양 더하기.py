def solution(absolutes, signs):
    answer = 0
    size = len(absolutes)

    for i in range(size):
        absolute = absolutes[i]
        sign = signs[i]

        if sign == False:
            absolute = -absolute
        answer += absolute

    return answer