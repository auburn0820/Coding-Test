import re


def make_new_id(id):
    # make string to lower case
    id = id.lower()

    # delete non-rules characters
    id = re.sub('[^a-z0-9\.\-\_]', '', id)

    # delete continuous dot
    id = re.sub('\.+', '.', id)

    # delete dot that located first or last
    if len(id) > 0 and id[0] == '.':
        id = id[1:]
    if len(id) > 0 and id[-1] == '.':
        id = id[:-1]

    # if id is empty, add 'a'
    if len(id) == 0:
        id = 'a'

    # if length of id is more than 16, remove character located index that more than 15
    id = id[0:15]
    if len(id) > 0 and id[0] == '.':
        id = id[1:]
    if len(id) > 0 and id[-1] == '.':
        id = id[:-1]

    # if length of id is not more than 2, add last character of id until length become 3
    if len(id) <= 2:
        while len(id) < 3:
            id = id + id[-1]

    return id


def solution(new_id):
    answer = ''

    answer = make_new_id(new_id)

    return answer