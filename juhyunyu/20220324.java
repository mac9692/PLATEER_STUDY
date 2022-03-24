// 프로그래머스
// 문자열에서 p P y Y 갯수 비교
class Solution {
    boolean solution(String s) {
        boolean answer = true;
        if(countChar(s,'p') + countChar(s,'P')
           == countChar(s, 'y') + countChar(s, 'Y'))
            answer = true;
        else answer = false;
        return answer;
    }
    
    long countChar(String str, char ch) {
        return str.chars()
            .filter(c -> c == ch)
            .count();
    }
}
