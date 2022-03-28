// 프로그래머스
// 가운데 수 가져오기
class Solution {
    public String solution(String s) {
        String answer = "";
        int len = s.length();
        if(len % 2 != 0) {
            answer = s.substring((len-1)/2,(len-1)/2+1);
        }
        else {
            answer = s.substring((len-1)/2,(len-1)/2+2);                                                        
        }
        return answer;
    }
}
