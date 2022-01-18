package KAKAO_BLIND_RECRUITMENT_2022;

/*
    맵과 수행될 스킬들이 주어질 때, 스킬 수행 후 파괴되지 않은 건물 개수를 구하는 문제.

    <나의 풀이>
    풀지 못해서 구글링을 통해 아이디어를 얻었다.

    이 문제는 대놓고 시간복잡도를 어떻게 줄이는지가 핵심이라고 나와있다. 맵의 최대 크기는 1000x1000이고, 스킬의 최대 개수는 250000이다.
    즉, 매 스킬마다 해당 구역의 수를 늘리거나 줄이는 식으로 풀면 시간초과가 날 수밖에 없다.
    시간복잡도를 줄일 수 있는 획기적인 방법은 바로 "누적합" 이다.
    프로그래머스 질문하기 란에 이 내용에 대해 자세히 적어둔 게시글이 있다. 카카오 2022 블라인드 코테 해설에도 상세히 설명되어 있다.
 */

class NotDestroyed {
    public int solution(int[][] board, int[][] skill) {
        int n = board.length;
        int m = board[0].length;
        int[][] variation = new int[n+1][m+1];
        for (int[] s : skill) {
            int degree = s[0] == 1 ? -s[5] : s[5];
            variation[s[1]][s[2]] += degree;
            variation[s[3] + 1][s[4] + 1] += degree;
            variation[s[3] + 1][s[2]] -= degree;
            variation[s[1]][s[4] + 1] -= degree;
        }

        for(int i=0; i<n; ++i) {
            int sum = 0;
            for(int j=0; j<m; ++j) {
                variation[i][j] += sum;
                sum = variation[i][j];
            }
        }

        for(int j=0; j<m; ++j) {
            int sum = 0;
            for(int i=0; i<n; ++i) {
                variation[i][j] += sum;
                sum = variation[i][j];
            }
        }

        int ans = 0;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(board[i][j] + variation[i][j] > 0) {
                    ++ans;
                }
            }
        }

        return ans;
    }
}