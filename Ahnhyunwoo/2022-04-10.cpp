#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

int solution(int N, int number) {
    int answer = 0;
    set<int>s[9];
    string str;
    if(N == number) {
        return 1;
    }
    for(int k = 1; k <= 8;k++) {
        str += N + '0';
        s[k].insert(stoi(str));
        for(int i = 1; i <= k;i++) {
            for(int j = 1; j <= k;j++) {
                if(i + j != k) {
                    continue;
                }
                for(int first : s[i]) {
                    for(int second : s[j]) {
                        s[k].insert(first + second);
                        s[k].insert(first * second);
                        if(first - second > 0) {
                            s[k].insert(first - second);
                        }
                        if(second !=0 && first / second != 0) {
                            s[k].insert(first / second);
                        }
                    }
                }
                if(s[k].find(number) != s[k].end()) {
                    return k;
                }
            }
        }
    }
    
    return -1;
}
