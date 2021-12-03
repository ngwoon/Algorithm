import java.io.*;
import java.util.LinkedList;
import java.util.List;

/*
    w 함수에 들어갈 파라미터들이 주어졌을 때, 함수 결과값을 출력하는 문제

    <나의 풀이>
    w함수 실행이 오래 걸리는 이유는, 이전에 계산했던 값을 다시 계산해야하는 상황이 반복되기 때문이다.
    전형적인 dp 문제이며, 이전에 계산한 값을 저장해두고 필요 시 재사용하는 방법으로 문제를 해결했다.
 */

class 신나는_함수_실행 {

    static int IMP = -51;
    static int[][][] dp = new int[101][101][101];
    static FastIO io = new FastIO();

    static {
        for(int i=0; i<101; ++i) {
            for(int j=0; j<101; ++j) {
                for(int k=0; k<101; ++k) {
                    dp[i][j][k] = IMP;
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {

        List<Tuple> params = new LinkedList<>();
        while(true) {
            String line = io.readLine();
            String[] splited = line.split(" ");

            if(splited[0].equals("-1") && splited[1].equals("-1") && splited[2].equals("-1")) {
                break;
            }

            params.add(new Tuple(Integer.parseInt(splited[0]), Integer.parseInt(splited[1]), Integer.parseInt(splited[2])));
        }

        for (Tuple param : params) {
            int result = w(param.a, param.b, param.c);
            writeAnswerToBuffer(param.a, param.b, param.c, result);
        }

        io.flush();
    }

    public static int w(int a, int b, int c) {

        int da = a + 50;
        int db = b + 50;
        int dc = c + 50;
        if(dp[da][db][dc] != IMP) {
            return dp[da][db][dc];
        }

        if(a <= 0 || b <= 0 || c <= 0) {
            return 1;
        }

        if(a > 20 || b > 20 || c > 20) {
            dp[da][db][dc] = w(20, 20, 20);
        } else {
            if(a < b && b < c) {
                dp[da][db][dc] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
            } else {
                dp[da][db][dc] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
            }
        }

        return dp[da][db][dc];
    }

    public static void writeAnswerToBuffer(int a, int b, int c, int result) throws IOException {
        io.write("w(" + a + ", " + b + ", " + c + ") = " + result + "\n");
    }

    static class Tuple {
        int a, b, c;

        public Tuple(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }
    }

    static class FastIO {
        private final BufferedReader br;
        private final BufferedWriter bw;

        public FastIO() {
            br = new BufferedReader(new InputStreamReader(System.in));
            bw = new BufferedWriter(new OutputStreamWriter(System.out));
        }

        public String readLine() throws IOException {
            return br.readLine();
        }

        public void write(String content) throws IOException {
            bw.write(content);
        }

        public void flush() throws IOException {
            bw.flush();
        }
    }
}