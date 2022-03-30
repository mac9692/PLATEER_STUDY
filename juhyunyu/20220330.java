//프로그래머스
//같은 숫자는 싫어
import java.util.Arrays;
import java.util.ArrayList;

public class Solution {
    public int[] solution(int []arr) {
        ArrayList<Integer> temp_arr =
            new ArrayList<Integer>();
        for(int i = 0; i < arr.length; i++) {
            if(i == 0) {
                temp_arr.add(arr[i]);
            } else {
                if(arr[i] != temp_arr.get(temp_arr.size() - 1)) {
                    temp_arr.add(arr[i]);
                }
            }
        }
        int[] answer = new int[temp_arr.size()];
        for(int i =0; i < temp_arr.size(); i++) {
            answer[i] = temp_arr.get(i);
        }
        return answer;
    }
}
