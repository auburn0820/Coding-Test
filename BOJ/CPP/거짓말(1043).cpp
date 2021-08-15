#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> person_know_truth;
vector<int> party_people[51];
int parent[51];

void set_parent() {
    for(int i = 1; i < N; i++) {
        parent[i] = i;
    }
}

int get_parent(int a) {
    if(a == parent[a])
        return a;
    else
        return a = get_parent(parent[a]);
}

bool is_same_parent(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);
    
    if(a == b)
        return true;
    else
        return false;
}

void union_parent(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);
    
    if(a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

void union_party_people() {
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < (int)party_people[i].size() - 1; j++) {
            if(!is_same_parent(party_people[i][j], party_people[i][j + 1])) {
                union_parent(party_people[i][j], party_people[i][j + 1]);
            }
        }
    }
}

int count_can_join_party() {
    int ans = 0;
    int i = 0;
    CANT_GO_PARTY:
    for(; i < M; i++) {
        for(int j = 0; j < (int)party_people[i].size(); j++) {
            for(int k = 0; k < (int)person_know_truth.size(); k++) {
                if(is_same_parent(person_know_truth[k], party_people[i][j])) {
                    i++;
                    goto CANT_GO_PARTY;
                }
            }
        }
        ans++;
    }
    
    return ans;
}

int main(void) {
    cin >> N >> M;
    
    set_parent();
    
    int number_of_know_truth_person;
    cin >> number_of_know_truth_person;
    
    for(int i = 0; i < number_of_know_truth_person; i++) {
        int person_number;
        cin >> person_number;
        person_know_truth.push_back(person_number);
    }
    
    for(int i = 0; i < M; i++) {
        int number_of_join_party_person;
        cin >> number_of_join_party_person;
        for(int j = 0; j < number_of_join_party_person; j++) {
            int person_number;
            cin >> person_number;
            party_people[i].push_back(person_number);
        }
    }
    
    union_party_people();
    
    cout << count_can_join_party() << '\n';
}
