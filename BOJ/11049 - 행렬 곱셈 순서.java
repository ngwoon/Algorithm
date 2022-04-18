import java.io.*;
import java.util.StringTokenizer;

import static java.lang.Integer.parseInt;

/*
    행렬들의 행과 열 크기가 주어질 때, 행렬을 모두 곱하는데 필요한 최소 곱셈 횟수를 구하는 문제.

    <나의 풀이>
    모든 행렬을 곱할 수 있는 케이스만 주어지므로, 가능한 모든 계산 순서를 전부 다 해보면 되는 문제다.
    단, 이미 계산한 범위를 또 계산할 필요는 없다. 그래서 dp를 사용한다.
    dp의 의미와 점화식은 아래와 같다.
    dp[a][b] = a번째 행렬부터 b번째 행렬을 계산할 때 필요한 곱셈 횟수
    dp[a][b] = a <= i && i < b인 i에 대해 dp[a][b] = min(dp[a][i] + dp[i+1][b] + matrix[a].row * matrix[a].column * matrix[b].column ... )

    비슷한 문제 : 백준 - 11066 - 파일 합치기
 */

class MatrixMulti {

    static int INF = -1;
    static int n;
    static Matrix[] matrices;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        n = parseInt(br.readLine());

        matrices = new Matrix[n];
        for(int i=0; i<n; ++i) {
            StringTokenizer stzr = new StringTokenizer(br.readLine());
            matrices[i] = new Matrix(parseInt(stzr.nextToken()), parseInt(stzr.nextToken()));
        }

        dp = new int[n][n];
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                dp[i][j] = i == j ? 0 : INF;
            }
        }

        bw.write(String.valueOf(solve(0, n-1)));
        bw.flush();
    }

    public static int solve(int start, int end) {
        if(dp[start][end] == INF) {
            dp[start][end] = Integer.MAX_VALUE;
            for(int i=start; i<end; ++i) {
                dp[start][end] = Math.min(dp[start][end], solve(start, i) + solve(i+1, end) + getMultiCount(start, i, i+1, end));
            }
        }
        return dp[start][end];
    }

    static int getMultiCount(int as, int ae, int bs, int be) {
        return matrices[as].row * matrices[ae].column * matrices[be].column;
    }

    static class Matrix {
        int row, column;
        public Matrix(int row, int column) {
            this.row = row;
            this.column = column;
        }
    }
}