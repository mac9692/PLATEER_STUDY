#include <string>
#include <vector>

using namespace std;
int ar[60001];
int solution(int n) {
    int answer = 0;
    ar[1] = 1;
    ar[2] = 2;
    for(int i = 3; i <= n;i++) {
        ar[i] = ar[i - 1] + ar[i - 2];
        ar[i] %=  1000000007;
    }
    return ar[n];
}
