import java.io.*;
import java.util.StringTokenizer;

import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Long.toBinaryString;

/*
    거듭제곱을 구하고자 하는 행렬 A와 거듭제곱 횟수 b가 주어질 때, A^b를 구하는 문제.

    <나의 풀이>
    구글링을 통해 힌트를 얻었다.

    거듭제곱의 횟수가 최대 1000억이므로, 당연히 단순 곱셈을 하면 시간초과가 난다.
    행렬의 거듭제곱을 쉽게 구할 수 있는 방법을 아래 참고 사이트에서 찾았다.

    우선, 거듭제곱하고자 하는 수 (b)를 이진수로 바꾼다.
    예시로 b = 11 인 상황을 가정하자.
    십진수 11은 이진수로 1011(2) 이다.
    이 이진수를 MSB -> LSB 방향으로 순차 탐색하면서, 아래와 같은 규칙을 따른다.
        * 현재 인덱스의 숫자가 1이면, 현재까지의 결과 (이하 X) 를 제곱하고, 거기에 A를 곱한다.
        * 현재 인덱스의 숫자가 0이면, X를 제곱한다.
    위 규칙 그대로 A^11을 구해보면
        * 이진수의 첫 번째 인덱스가 1이므로, (A^0)^2 * A = A
        * 이진수의 두 번째 인덱스가 0이므로, (A^1)^2 = A^2
        * 이진수의 세 번째 인덱스가 1이므로, (A^2)^2 * A = A^5
        * 이진수의 네 번째 인덱스가 1이므로, (A^5)^2 * A = A^11
    다음과 같이 구하고자 했던 A^11을 구할 수 있다.

    <참고한 사이트>
    https://greeksharifa.github.io/algorithm%20&%20data%20structure/2018/07/04/algorithm-matrix-power/
 */

class MatrixPower {

    static int LIMIT = 1000;
    static int n;
    static long b;
    static int[][] matrix;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer stzr = new StringTokenizer(br.readLine());
        n = parseInt(stzr.nextToken());
        b = parseLong(stzr.nextToken());

        matrix = new int[n][n];
        for(int i=0; i<n; ++i) {
            stzr = new StringTokenizer(br.readLine());
            for(int j=0; j<n; ++j) {
                matrix[i][j] = parseInt(stzr.nextToken());
            }
        }

        String bn = toBinaryString(b);

        int[][] ans = new int[n][n];
        for(int i=0; i<n; ++i) {
            ans[i][i] = 1;
        }
        for(int i=0; i<bn.length(); ++i) {
            char cb = bn.charAt(i);
            if(cb == '0') {
                ans = matrixMul(ans, ans);
            } else {
                ans = matrixMul(matrixMul(ans, ans), matrix);
            }
        }

        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                bw.write(ans[i][j] + " ");
            }
            bw.write("\n");
        }
        bw.flush();
    }

    public static int[][] matrixMul(int[][] a, int [][] b) {
        int[][] res = new int[n][n];
        int rIdx = 0;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                int sum = 0;
                for(int k=0; k<n; ++k) {
                    sum += a[i][k] * b[k][j];
                }
                res[rIdx/n][rIdx%n] = sum % LIMIT;
                ++rIdx;
            }
        }
        return res;
    }
}