// 프로그래머스
// 나누어 떨어지는 숫자 배열
import java.util.Arrays;
class Solution {
    public int[] solution(int[] arr, int divisor) {
        //int[] answer = {};
        int cnt = 0;
        for(int i : arr) {
            if(i % divisor == 0) cnt++;
        }
        if(cnt == 0) {
            int[] answer = {-1};
            return answer;
        }
        else {
            int[] answer = new int[cnt];
            int len = 0;
            for(int i = 0; i < arr.length; i++) {
                if(arr[i] % divisor == 0) {
                    answer[len] = arr[i];
                    len++;
                }
            }
            Arrays.sort(answer);
            return answer;
        }
        
    }
}
