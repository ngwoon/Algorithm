import java.io.*;

/*
    두 문자열이 주어질 때, 두 문자열의 LCS를 찾는 문제.

    <나의 풀이>
    풀지 못해서 구글링을 통해 아이디어를 얻었다.
    두 문자열의 최장 공통 부분 수열을 찾는 가장 기본적인 문제이다. LCS를 찾는 방법을 모르면 풀기 어려운 문제라고 생각한다.
    이 문제의 핵심은 두 문자열을 행, 열로 표현한 2차원 배열을 두고, (i, j) 요소를 "a문자열 i인덱스까지의 부분 문자열과 b문자열 j인덱스까지의 부분 문자열을 비교할 때의 LCS 길이" 로 여기면서
    배열을 채워나가는 것이다.
    짧게 설명하기는 어렵다. 아래 참고한 링크에 이해하기 쉽게 자세한 설명이 나와있다.

    <참고>
    https://st-lab.tistory.com/139
 */

class LCS {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String a = br.readLine();
        String b = br.readLine();

        int alen = a.length();
        int blen = b.length();

        int[][] dp = new int[alen + 1][blen + 1];
        for(int i=0; i<=alen; ++i) {
            for(int j=0; j<=blen; ++j) {
                dp[i][j] = (i == 0 || j == 0) ? 0 : -1;
            }
        }

        for(int i=1; i<=alen; ++i) {
            for(int j=1; j<=blen; ++j) {
                if(a.charAt(i-1) == b.charAt(j-1)) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        bw.write(String.valueOf(dp[alen][blen]));
        bw.flush();
    }
}