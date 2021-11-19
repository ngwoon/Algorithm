import java.util.*;

/*
    음악의 장르, 고유번호, 재생횟수가 주어졌을 때, 문제에서 제시한 조건에 맞춰 베스트앨범의 고유번호들을 골라내는 문제

    <나의 풀이>
    사실 문제에서 음악을 골라내는 방법을 다 제시해줘서, 알고리즘을 고민하기보단 자료구조 활용 능력을 보는 문제인 느낌이다.
    모든 장르에 대해 (장르, 총 재생횟수) 를 먼저 구하고, 이를 pq에 넣고 꺼내어 총 재생횟수가 놓은 장르순으로 순회한다.
    장르를 key로 하고, (고유번호, 재생횟수) 들을 저장하는 pq(이하 Q)를 value로 하는 해시맵(이하 M)을 만들어둔 뒤,
    장르순 탐색 시 M에서 현재 장르에 대응하는 Q를 꺼내고, Q에서 최대 2회 poll()하여 재생횟수가 높은 순으로 음악을 조회한다.
    물론 문제 조건에 따라 Q는 재생횟수가 같다면, 고유번호가 작은 순으로 음악을 poll()할 수 있도록 compareTo()를 재정의 해두어야 한다.
 */

class BestAlbum {
    public int[] solution(String[] genres, int[] plays) {
        List<Integer> bestAlbumList = new LinkedList<>();

        int albumNum = genres.length;
        HashMap<String, Integer> sumHm = new HashMap<>();
        HashMap<String, PriorityQueue<MusicPair>> pqHm = new HashMap<>();

        for(int i=0; i<albumNum; ++i) {
            sumHm.put(genres[i], sumHm.getOrDefault(genres[i], 0) + plays[i]);

            if(pqHm.containsKey(genres[i])) {
                pqHm.get(genres[i]).add(new MusicPair(i, plays[i]));
            } else {
                PriorityQueue<MusicPair> pq = new PriorityQueue<>();
                pq.add(new MusicPair(i, plays[i]));
                pqHm.put(genres[i], pq);
            }
        }

        PriorityQueue<SumPair> sumPq = new PriorityQueue<>();
        for (Map.Entry<String, Integer> entry : sumHm.entrySet()) {
            sumPq.add(new SumPair(entry.getValue(), entry.getKey()));
        }

        while(!sumPq.isEmpty()) {
            SumPair sp = sumPq.poll();

            PriorityQueue<MusicPair> pq = pqHm.get(sp.genre);
            int inserted = 0;
            while(!pq.isEmpty() && inserted < 2) {
                MusicPair mp = pq.poll();
                bestAlbumList.add(mp.idx);
                ++inserted;
            }
        }

        int[] answer = new int[bestAlbumList.size()];
        int tmp = 0;
        for (int idx : bestAlbumList) {
            answer[tmp++] = idx;
        }
        return answer;
    }

    static class SumPair implements Comparable<SumPair> {

        public int sum;
        public String genre;

        SumPair(int sum, String genre) {
            this.sum = sum;
            this.genre = genre;
        }

        @Override
        public int compareTo(SumPair a) {
            return a.sum - this.sum;
        }
    }

    static class MusicPair implements Comparable<MusicPair> {

        public int idx;
        public int play;

        MusicPair(int idx, int play) {
            this.idx = idx;
            this.play = play;
        }

        @Override
        public int compareTo(MusicPair a) {
            if(a.play == this.play) {
                return this.idx - a.idx;
            }
            return a.play - this.play;
        }
    }
}