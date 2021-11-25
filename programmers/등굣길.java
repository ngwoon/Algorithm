
/*
    집과 학교 사이의 물웅덩이 좌표가 주어졌을 때, 등교할 수 있는 경로의 수를 구하는 문제.

    <나의 풀이>
    학창시절 수학 시간에 마주한 2차원 경로에서의 경우의 수 구하는 문제이다.
    현재 좌표가 y,x일 때, 집에서 현재 좌표까지 도달할 수 있는 경우의 수를 a(y,x)라 하면 아래와 같은 식이 나온다.
    a(y,x) = a(y-1,x) + a(y, x-1)
    다만, 이 문제는 물웅덩이가 있으므로 (y-1,x)나 (y,x-1) 좌표가 물웅덩이일 경우 해당 경로를 통해 현재 경로로 오는 경우의 수는 0이라고 판단해야한다.
 */

class WayToSchool {
    public static int solution(int m, int n, int[][] puddles) {

        int DIV = 1000000007;

        int[][] map = new int[n][m];

        for(int i=0; i<puddles.length; ++i) {
            map[puddles[i][1] - 1][puddles[i][0] - 1] = -1;
        }

        boolean isPuddleExist = false;
        for(int i=0; i<n; ++i) {
            if(map[i][0] == -1) {
                isPuddleExist = true;
            } else {
                map[i][0] = isPuddleExist ? -1 : 1;
            }
        }

        isPuddleExist = false;
        for(int i=0; i<m; ++i) {
            if(map[0][i] == -1) {
                isPuddleExist = true;
            } else {
                map[0][i] = isPuddleExist ? -1 : 1;
            }
        }

        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(i == 0 || j == 0 || map[i][j] == -1) {
                    continue;
                }

                int top = map[i-1][j];
                int left = map[i][j-1];
                if(top == -1 && left == -1) {
                    map[i][j] = 0;
                } else if(top == -1) {
                    map[i][j] = left;
                } else if(left == -1) {
                    map[i][j] = top;
                } else {
                    map[i][j] = (top + left) % DIV;
                }
            }
        }

        return map[n-1][m-1];
    }

    public static void main(String[] args) {
        int[][] puddles = new int[3][2];
        puddles[0][0] = 1;
        puddles[0][1] = 2;
        puddles[1][0] = 2;
        puddles[1][1] = 1;
        puddles[2][0] = 2;
        puddles[2][1] = 3;

        int solution = solution(3, 4, puddles);
        System.out.println(solution);
    }
}