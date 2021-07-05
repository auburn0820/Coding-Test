//#include <iostream>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//int k;
//char number[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
//int comb[10];
//string symbolInput;
//string symbol = " ";
//
//void initialize() {
//    for(int i = 0; i <= k; i++) {
//        comb[i] = 1;
//    }
//    sort(comb, comb + 10);
//}
//
//bool checkExpression() {
//    for(int i = 0; i < (int)symbol.length() - 1; i++) {
//        if(symbol[i] == '<') {
//            if(symbol[i - 1] > symbol[i + 1])
//                return false;
//        } else if(symbol[i] == '>') {
//            if(symbol[i - 1] < symbol[i + 1])
//                return false;
//        } else
//            continue;
//    }
//    return true;
//}
//
//string parsingString() {
//    string temp;
//    temp.resize(k + 1);
//    int tempIdx = 0;
//
//    for(int i = 0; i < (int)symbol.length(); i++) {
//        if(symbol[i] >= '0' && symbol[i] <= '9') {
//            temp[tempIdx] = symbol[i];
//            tempIdx++;
//        }
//    }
//
//    return temp;
//}
//
//void combination() {
//    initialize();
//    long cur = 0;
//    string maxNum = "0";
//    string minNum = "9876543211";
//
//    char numString[k + 1];
//    do {
//        int stringIdx = 0;
//        for(int i = 0; i < 10; i++) {
//            if(comb[i] == 1) {
//                numString[stringIdx] = number[i];
//                stringIdx++;
//            }
//        }
//        do {
//            int stringIdx2 = 0;
//            for(int i = 0; i <= k; i++) {
//                symbol[stringIdx2] = numString[i];
//                stringIdx2 = stringIdx2 + 2;
//            }
//
//            if(checkExpression()) {
//                string temp = parsingString();
//                cur = stol(temp);
//                if(cur >= stol(maxNum)) {
//                    maxNum = temp;
//                }
//                if(cur <= stol(minNum)) {
//                    minNum = temp;
//                }
//            }
//        }while(next_permutation(numString, numString + k + 1));
//    }while(next_permutation(comb, comb + 10));
//
//    cout << maxNum << '\n' << minNum << '\n';
//}
//
//int main(void) {
//    cin >> k;
//    cin.ignore();
//    getline(cin, symbolInput, '\n');
//    symbol.append(symbolInput);
//    if(symbol[symbol.length() - 1] != ' ') {
//        symbol.append(" ");
//    }
//    combination();
//}
