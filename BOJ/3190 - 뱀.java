import java.io.*;
import java.util.Deque;
import java.util.LinkedList;
import java.util.Queue;

class Snake {

    static class CustomPair<E, T> {
        private E first;
        private T second;

        CustomPair(E first, T second) {
            this.first = first;
            this.second = second;
        }

        public E getFirst() {
            return first;
        }

        public T getSecond() {
            return second;
        }
    }

    private static final int[] dx = {0,1,0,-1};
    private static final int[] dy = {1,0,-1,0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n, k, l;
        int dir = 1;
        int hx = 0, hy = 0;
        int[][] board;
        Queue<CustomPair<Integer, String>> que = new LinkedList<>();
        Deque<CustomPair<Integer, Integer>> snake = new LinkedList<>();

        n = Integer.parseInt(br.readLine());
        board = new int[n][n];
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j)
                board[i][j] = 0;
        }
        board[0][0] = 2;

        k = Integer.parseInt(br.readLine());
        for(int i=0; i<k; ++i) {
            String[] splited = br.readLine().split(" ");
            int y = Integer.parseInt(splited[0]) - 1;
            int x = Integer.parseInt(splited[1]) - 1;

            board[y][x] = 1;
        }

        l = Integer.parseInt(br.readLine());
        for(int i=0; i<l; ++i) {
            String[] splited = br.readLine().split(" ");
            int sec = Integer.parseInt(splited[0]);
            String md = splited[1];
            que.add(new CustomPair<>(sec, md));
        }

        int sec = 0;
        snake.addFirst(new CustomPair<>(0,0));
        while(true) {

            ++sec;
            int nx = hx + dx[dir];
            int ny = hy + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n || board[ny][nx] == 2)
                break;

            if(board[ny][nx] == 0) {
                CustomPair<Integer, Integer> tail = snake.pollLast();
                board[tail.getFirst()][tail.getSecond()] = 0;
            }
            board[ny][nx] = 2;
            snake.addFirst(new CustomPair<>(ny, nx));

            hx = nx; hy = ny;

            if(!que.isEmpty()) {
                CustomPair<Integer, String> order = que.peek();
                if(order.getFirst() == sec) {
                    if(order.getSecond().equals("L"))
                        dir = (dir + 1) % 4;
                    else
                        dir = (dir + 3) % 4;

                    que.poll();
                }
            }
        }

        bw.write(String.valueOf(sec));
        bw.flush();
    }
}