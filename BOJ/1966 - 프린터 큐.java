import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Collections;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

class PrinterQueue {

    static class CustomPair {
        private final int first;
        private final boolean second;

        CustomPair(int first, boolean second) {
            this.first = first;
            this.second = second;
        }

        public int getFirst() {
            return first;
        }

        public boolean getSecond() {
            return second;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int t = Integer.parseInt(br.readLine());

        while(t-- > 0) {
            int n,m;
            String[] splited = br.readLine().split(" ");
            n = Integer.parseInt(splited[0]);
            m = Integer.parseInt(splited[1]);

            String[] temp = br.readLine().split(" ");
            Queue<CustomPair> que = new LinkedList<>();
            PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
            for(int i=0; i<n; ++i) {
                int priority = Integer.parseInt(temp[i]);
                pq.add(priority);
                que.add(new CustomPair(priority, i == m));
            }

            int ans = 1;
            while(!pq.isEmpty()) {
                CustomPair cur = que.poll();
                if(cur.getFirst() == pq.peek()) {
                    boolean isTarget = cur.getSecond();
                    if(isTarget) {
                        bw.write(ans + "\n");
                        break;
                    }
                    pq.poll();
                    ++ans;
                } else {
                    que.add(cur);
                }
            }
        }

        bw.flush();
    }
}