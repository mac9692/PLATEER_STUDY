// 프로그래머스
// 서울에서 김서방 찾기
import java.util.ArrayList;
import java.util.Arrays;

class Solution {
    public String solution(String[] seoul) {
        ArrayList<String> seo = new ArrayList<>(Arrays.asList(seoul));
        String answer = "";
        answer = "김서방은 "
            + seo.indexOf("Kim")
            + "에 있다";
        return answer;
    }
}
