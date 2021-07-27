#include <iostream>
#include <cstring>

using namespace std;

int students_pick[100001];
bool visit[100001];
bool grouped[100001];
int result;

void make_group(int cur_student) {
    int cur_student_pick = students_pick[cur_student];

    visit[cur_student] = true;

    if(!visit[cur_student_pick])
        make_group(cur_student_pick);
    else if(visit[cur_student_pick] && !grouped[cur_student_pick]) {
        int idx = cur_student_pick;
        
        while(idx != cur_student) {
            result++;
            idx = students_pick[idx];
        }
        result++;
    }

    grouped[cur_student] = true;
}

int main(void) {
    int t;
    cin >> t;

    while(t--) {
        memset(visit, false, sizeof(visit));
        memset(grouped, false, sizeof(grouped));
        result = 0;

        int number_of_students;
        cin >> number_of_students;

        for(int i = 1; i <= number_of_students; i++) {
            cin >> students_pick[i];
        }

        for(int i = 1; i <= number_of_students; i++) {
            if(!visit[i])
                make_group(i);
        }

        cout << number_of_students - result << '\n';
    }
}
