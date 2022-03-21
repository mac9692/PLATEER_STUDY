// 프로그래머스
// 정수 내림차순으로 배치하기
import java.util.Arrays;
import java.util.Collections;

class Solution {
    public long solution(long n) {
        long answer = 0;
        String nn = Long.toString(n);
        String[] arr = new String[nn.length()];
        
        arr = nn.split("");
        
        Arrays.sort(arr,Collections.reverseOrder());
        String str = String.join("", arr);
        return Long.parseLong(str);
    }
}
