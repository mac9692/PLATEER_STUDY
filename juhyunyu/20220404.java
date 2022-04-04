// 프로그래머스
import java.util.Arrays;

class Solution {
    public int solution(int[] people, int[] tshirts) {
        int answer = 0;
        int cnt = 0;
        Arrays.sort(people);
        Arrays.sort(tshirts);
        for(int i = 0; i < people.length; i++) {
            for(int j = cnt; j < tshirts.length; j++) {
                cnt++;
                if(people[i] <= tshirts[j]) {
                    answer++;
                    break;
                }
            }
        }
        return answer;
    }
}
