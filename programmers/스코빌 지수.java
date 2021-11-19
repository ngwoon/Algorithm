import java.util.PriorityQueue;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;

        PriorityQueue<Integer> pq = new PriorityQueue<>();

        for (int s : scoville)
            pq.add(s);

        int cnt = 0;
        while(pq.peek() < K) {
            if(pq.size() < 2) {
                answer = -1;
                break;
            }

            ++cnt;

            // a <= b
            int a = pq.poll();
            int b = pq.poll();
            pq.add(a + b * 2);
        }

        if(answer != -1)
            answer = cnt;

        return answer;
    }
}