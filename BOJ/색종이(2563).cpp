#include <iostream>

using namespace std;

bool paper[100][100];

void paste_confetti(int a, int b) {
    for(int i = b; i < b + 10; i++) {
        for(int j = a; j < a + 10; j++) {
            paper[i][j] = true;
        }
    }
}

int get_area() {
    int count = 0;
    
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            if(paper[i][j])
                count++;
        }
    }
    
    return count;
}

int main(void) {
    int N;
    cin >> N;
    
    while(N--) {
        int a, b;
        cin >> a >> b;
        paste_confetti(a, b);
    }
    
    cout << get_area() << '\n';
}
