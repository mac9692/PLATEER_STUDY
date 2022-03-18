// 프로그래머스 최대공약수와 최소공배수
class Solution {
    public int[] solution(int n, int m) {
        int[] answer = new int[2];
        int min = (n < m)?n:m;
        int gcd = 0;
        for(int i = 1; i <= min; i++) {
            if(n % i == 0 && m % i == 0) {
                gcd = i;
            }
        }
        answer[0] = gcd;
        answer[1] = n * m / gcd;
        return answer;
    }
}
// 콜라츠 추측
/*
class Solution {
    public int solution(int num) {
        int answer = 0; // 반복횟수
        long n = num; // 입력된 수
        while(n != 1 && answer < 500) { // n 연산
            // 1-1
            if(n % 2 == 0) n /= 2;
            // 1-2
            else n = (n * 3) + 1;
            answer++;
        }
        if(n != 1) answer = -1;
        return answer;
    }
}
*/
// 하샤드 수
/*
class Solution {
    public boolean solution(int x) {
        boolean answer = true;
        int sum = 0;
        int n = x;
        while(n != 0) {
            sum += n % 10;
            n /= 10;
        }
        // if(x % sum == 0) answer = true;
        // else answer = false;
        return (x % sum == 0)?true:false;
    }
}
*/
