#include <iostream>
#include <cstring>

using namespace std;

void rotate_gear_wheel(string &gear_wheel, int direction) {
    if(direction == 1) {
        int temp = gear_wheel[gear_wheel.length() - 1];
        
        for(int i = (int)gear_wheel.length() - 1; i > 0; i--) {
            gear_wheel[i] = gear_wheel[i - 1];
        }
        gear_wheel[0] = temp;
    } else if(direction == -1) {
        int temp = gear_wheel[0];
        
        for(int i = 0; i < (int)gear_wheel.length() - 1; i++) {
            gear_wheel[i] = gear_wheel[i + 1];
        }
        gear_wheel[gear_wheel.length() - 1] = temp;
    }
}

void set_gear_wheel_rotate_direction(string *gear_wheels, int current_gear_wheel, int current_direction, int *gear_wheel_rotate_directions) {
    memset(gear_wheel_rotate_directions, 0, sizeof(int) * 4);
    gear_wheel_rotate_directions[current_gear_wheel] = current_direction;
    
    // 왼쪽 톱니바퀴 방향 설정
    for(int i = current_gear_wheel; i > 0; i--) {
        if(gear_wheels[i][6] != gear_wheels[i - 1][2]) {
            gear_wheel_rotate_directions[i - 1] = -gear_wheel_rotate_directions[i];
        }
    }
    
    // 오른쪽 톱니바퀴 방향 설정
    for(int i = current_gear_wheel; i < 3; i++) {
        if(gear_wheels[i][2] != gear_wheels[i + 1][6]) {
            gear_wheel_rotate_directions[i + 1] = -gear_wheel_rotate_directions[i];
        }
    }
}

int main(void) {
    string gear_wheels[4];
    
    for(auto &gear_wheel : gear_wheels) {
        cin >> gear_wheel;
    }
    
    int K;
    cin >> K;
    
    int gear_wheel_rotate_directions[4];
    
    for(int i = 0; i < K; i++) {
        int gear_wheel_index, direction;
        cin >> gear_wheel_index >> direction;
        set_gear_wheel_rotate_direction(gear_wheels, gear_wheel_index - 1, direction, gear_wheel_rotate_directions);
        
        for(int j = 0; j < 4; j++) {
            rotate_gear_wheel(gear_wheels[j], gear_wheel_rotate_directions[j]);
        }
    }
    
    int result = 0;
    
    for(int i = 0; i < 4; i++) {
        int num_added_to_result = (gear_wheels[i][0] - '0') << i;
        result += num_added_to_result;
    }
    
    cout << result << '\n';
}
