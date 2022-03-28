#include <string>
#include <vector>
#include <math.h>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(n > s) {
        answer.push_back(-1);
        return answer;
    }
    int num = s / n;
    int k = s % n;
    for(int i = k; i < n;i++) {
        answer.push_back(num);
    }
    for(int i = 0; i <k;i++) {
        answer.push_back(num + 1);
    }  
    return answer;
}
