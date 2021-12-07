import java.util.Stack;

class CraneDollGame {
    public int solution(int[][] board, int[] moves) {

        int n = board.length;
        Stack<Integer> bucket = new Stack<>();

        int ans = 0;
        for (int move : moves) {
            int doll = 0;
            int x = move - 1;
            for(int i=0; i<n; ++i) {
                if(board[i][x] != 0) {
                    doll = board[i][x];
                    board[i][x] = 0;
                    break;
                }
            }
            if(doll != 0) {
                int recentDoll = bucket.isEmpty() ? 0 : bucket.peek();
                if(recentDoll == doll) {
                    ans += 2;
                    bucket.pop();
                } else {
                    bucket.add(doll);
                }
            }
        }

        return ans;
    }
}