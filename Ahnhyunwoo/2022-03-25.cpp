#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int>a,b;
int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    a = A;
    b = B;
    for(int i = 0; i < B.size();i++) {
        int num = lower_bound(A.begin(), A.end(),B[i]) - A.begin();
        if(num - answer > 0) {
            answer++;
        }
    }
    
    return answer;
}
