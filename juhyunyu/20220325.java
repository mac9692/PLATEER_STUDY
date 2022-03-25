// 프로그래머스
// 문자열 내림차순
import java.util.Arrays;
import java.util.Collections;

class Solution {
    public String solution(String s) {
        String answer = "";
        String[] str = s.split("");
        Arrays.sort(str, Collections.reverseOrder());
        answer = String.join("", str);
        return answer;
    }
}
