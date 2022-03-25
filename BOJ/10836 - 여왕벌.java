import java.io.*;

import static java.lang.Integer.parseInt;

/*
    문제 조건에 맞게 애벌레가 성장할 때, 마지막 날이 지난 뒤 애벌레의 성장 상태를 구하는 문제.

    <나의 풀이>
    성장일이 최대 백만이고, 애벌레집 크기가 최대 700x700 이므로 날마다 모든 애벌레의 성장을 계산하는 건 TLE를 받을 수 밖에 없다.
    여기서 한 가지 아이디어가 필요하다.

    애벌레의 성장 정도는 현재 애벌레의 왼쪽, 왼쪽 상단 대각, 위쪽 이렇게 세 애벌레의 성장 정도 중 가장 큰 성장 정도로 결정된다.
    문제 조건을 살펴보면, 왼쪽 하단에서 오른쪽 상단 순서로 0, 1, 2 숫자의 개수가 주어진다고 했다. 그리고 이 수열은 감소하지 않는 수열이다.
    즉, 어느 배열 요소든 자신의 왼쪽 보단 왼쪽 상단 대각이, 왼쪽 상단 대각보다는 위쪽의 성장 정도가 같거나 크다는 것이 보증된다.
    따라서 1, 1 부터 m-1, m-1까지의 정사각형 영역은 결국 열끼리 동일한 숫자를 갖게 된다.

    그렇다면, 이제 우리는 왼쪽 하단부터 오른쪽 상단까지 이어지는 외곽 부분(이하 외곽 수열)만 구하면 된다.
    외곽 수열의 크기는 2m-1이다. m이 최대일 경우 1399가 된다.
    만약 외곽 수열의 성장 정도를 모든 날마다 계산한다면, 1399 x 백만 = 약 140억이 된다. TLE가 발생할 수 밖에 없다.
    여기서 또 하나의 아이디어가 필요하다.

    이 문제와 같이 임의의 구간마다 감소하지 않는 수를 증가시켜야 할 때, 해당 수가 증가해야하는 시작 인덱스에 수를 배치하는 테크닉이 있다.
    나는 우선 외곽 수열을 1차원 배열로 표현했다. (m=4일 때, 외곽 수열의 크기는 7이고, 배열의 크기는 8로 잡는다.)
    만약 증가 조건으로 1 3 3이 주어졌다면, 1~1범위는 0, 2~4 인덱스는 1, 5~7 인덱스는 2가 증가해야 한다.
        * 0은 적용할 필요가 없으므로 무시한다.
        * 0의 개수로 주어진 1에다가 1을 더한 인덱스 2에 +=1 연산을 수행한다.
        * 2의 개수가 0이 아니라면, 인덱스 (8 - 2의 개수로 주어진 수) 에 +=1 연산을 수행한다.
    이렇게 마지막 날의 숫자까지 연산해주고, 마지막으로 0번째 인덱스부터 2m-1인덱스까지 누적합을 수행하면 올바른 외곽 수열의 성장 정도를 O(n)에 구할 수 있다.

    배열의 크기를 2m-1이 아닌 2m으로 잡은 이유는, 0 0 7과 같이 모든 외곽 수열이 2만큼 성장해야하는 조건이 들어왔을 때 +=1 만 수행되버린다.
    따라서 1의 개수가 0이면 0번째 인덱스에 +=1을 수행하고, 이어서 2의 개수가 2m-1이면 1번째 인덱스에 +=1을 수행하여 이후 누적합을 구할 때 외곽 수열의 모든 요소에 +=2가 반영되도록 했다.
 */

class BeeQueen {

    static int[] dx = {0, 1};
    static int[] dy = {-1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String varsLine = br.readLine();
        String[] varsStr = varsLine.split(" ");
        int m = parseInt(varsStr[0]);
        int n = parseInt(varsStr[1]);

        int[][] larvas = new int[m][m];

        int roundSize = m*2;
        int[] round = new int[roundSize];
        for(int i=0; i<n; ++i) {
            String line = br.readLine();
            String[] numsStr = line.split(" ");
            int zero = parseInt(numsStr[0]);
            int two = parseInt(numsStr[2]);

            if(zero < roundSize - 1) {
                round[zero+1] += 1; // 1의 인덱스를 계산하는 부분
            }
            if(two > 0) {
                round[roundSize-two] += 1; // 2의 인덱스를 계산하는 부분
            }
        }

        for(int i=1; i<roundSize; ++i) {
            round[i] += round[i-1];
        }
        for(int i=1; i<roundSize; ++i) {
            round[i] += 1;
        }

        int cy = m-1, cx = 0;
        int rIdx = 1;
        int dir = 0;
        while(rIdx < roundSize) {
            larvas[cy][cx] = round[rIdx++];
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];
            if(ny < 0) {
                dir += 1;
                cy = 0; cx = 1;
            } else {
                cy = ny; cx = nx;
            }
        }

        for(int i=1; i<m; ++i) {
            for(int j=1; j<m; ++j) {
                larvas[i][j] = larvas[i-1][j];
            }
        }

        for(int i=0; i<m; ++i) {
            for(int j=0; j<m; ++j) {
                bw.write(String.valueOf(larvas[i][j]));
                if(j != m-1) {
                    bw.write(" ");
                }
            }
            if(i != m-1) {
                bw.write("\n");
            }
        }
        bw.flush();
    }
}