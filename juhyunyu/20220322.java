// 프로그래머스
// 문자열을 정수로
class Solution {
    public int solution(String s) {
        return Integer.parseInt(s);
    }
}
// 수박수박수박수?
/*
class Solution {
    public String solution(int n) {
        String answer = "";
        answer = "수";
        for(int i = 2; i <= n; i++) {
            if(i % 2 == 0)
                answer += "박";
            else
                answer += "수";
        }
        return answer;
    }
}
*/
