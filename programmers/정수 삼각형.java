
/*
    정수 삼각형이 주어졌을 때, 맨 꼭대기부터 맨 아래까지 이동하면서 만나는 숫자의 합이 가장 높을 때, 그 값을 구하는 문제

    <나의 풀이>
    k번째 줄에서 k+1번째 줄로 이동할 때 대각 왼쪽 혹은 대각 오른쪽으로만 이동할 수 있다.
    즉, dp[i][j]를 i번째 줄의 j번째 요소까지 도달하는 경우의 수 중 가장 높은 합이라고 할 때, 점화식은 아래와 같다.
        * j가 0일 때, dp[i][j] = triangle[i][j] + dp[i-1][j]
        * j가 i일 때(해당 줄의 마지막 원소), dp[i][j] = triangle[i][j] + dp[i-1][j-1]
        * 그 외의 경우, dp[i][j] = Math.max(triangle[i][j] + dp[i-1][j-1], triangle[i][j] + dp[i-1][j])

    <더 나은 풀이>
    풀이 자체는 내가 사용한 방법과 거의 비슷했는데, 코딩 방식 중 Arrays.stream()을 사용하여 최대값을 찾는 코드가 인상깊어서 기록해둔다.
    Arrays.stream(triangle[triangle.length-1]).max().getAsInt();
 */

class IntegerTriangle {
    public int solution(int[][] triangle) {

        int n = triangle.length;
        int[][] dp = new int[n][n];
        dp[0][0] = triangle[0][0];

        for(int i=1; i<n; ++i) {
            for(int j=0; j<=i; ++j) {
                if(j == 0) {
                    dp[i][j] = triangle[i][j] + dp[i-1][j];
                } else if (j == i) {
                    dp[i][j] = triangle[i][j] + dp[i-1][j-1];
                } else {
                    dp[i][j] = Math.max(triangle[i][j] + dp[i-1][j-1], triangle[i][j] + dp[i-1][j]);
                }
            }
        }

        for(int i=0; i<n; ++i) {
            for(int j=0; j<=i; ++j) {
                System.out.print(dp[i][j] + " ");
            }
            System.out.println();
        }

        int answer = 0;
        for(int i=0; i<n; ++i) {
            answer = Math.max(dp[n-1][i], answer);
        }

        return answer;
    }
}