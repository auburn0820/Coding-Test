#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int N, K;
    cin >> N >> K;
    
    int sensor_locations[N];
    
    for(auto &sensor_location : sensor_locations)
        cin >> sensor_location;
    
    sort(sensor_locations, sensor_locations + N);
    
    int distance_between_sensors[N - 1];
    
    for(int i = 0; i < N - 1; i++) {
        distance_between_sensors[i] = sensor_locations[i + 1] - sensor_locations[i];
    }
    
    sort(distance_between_sensors, distance_between_sensors + N - 1);
    
    int min_distance = 0;
    
    for(int i = 0; i < N - K; i++) {
        min_distance += distance_between_sensors[i];
    }
    
    cout << min_distance << '\n';
}
