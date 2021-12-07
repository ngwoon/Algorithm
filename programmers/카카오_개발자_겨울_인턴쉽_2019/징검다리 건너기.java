package 카카오_개발자_겨울_인턴쉽_2019;

import java.util.PriorityQueue;

class CrossStoneBridge {
    public int solution(int[] stones, int k) {

        PriorityQueue<Pair> pq = new PriorityQueue<>();
        for (int i=0; i<stones.length; ++i) {
            pq.add(new Pair(stones[i], i));
        }

        boolean[] isStoneBroke = new boolean[stones.length];

        while(!pq.isEmpty()) {
            Pair pair = pq.poll();
            int idx = pair.idx;
            int stone = pair.acrossable;

            isStoneBroke[idx] = true;

            // left stone idx
            int leftIdx = -1, rightIdx = stones.length;
            int tmpIdx = idx-1;
            while(tmpIdx >= 0) {
                if(isStoneBroke[tmpIdx]) {
                    --tmpIdx;
                } else {
                    leftIdx = tmpIdx;
                    break;
                }
            }

            tmpIdx = idx+1;
            while(tmpIdx < stones.length) {
                if(isStoneBroke[tmpIdx]) {
                    ++tmpIdx;
                } else {
                    rightIdx = tmpIdx;
                    break;
                }
            }

            int gap = rightIdx - leftIdx;
            if(gap > k) {
                return stone;
            }
        }

        return 0;
    }

    static class Pair implements Comparable<Pair> {

        int acrossable;
        int idx;

        public Pair(int acrossable, int idx) {
            this.acrossable = acrossable;
            this.idx = idx;
        }

        @Override
        public int compareTo(Pair o) {

            if(this.acrossable == o.acrossable) {
                return this.idx - o.idx;
            } else {
                return this.acrossable - o.acrossable;
            }
        }
    }
}