// https://www.acmicpc.net/problem/2525

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int A = scan.nextInt();	// 시
		int B = scan.nextInt();	// 분
		int C = scan.nextInt();	// 필요시간

		A += (B + C) / 60;
		B += C - (60 * ((B + C) / 60));
		if(A >= 24)
			A -= 24;
		System.out.println(A + " " + B);


		scan.close();
	}

}
