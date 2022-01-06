package 카카오_블라인드_채용_2021;

import java.util.*;

/*
    지원자들이 적어낸 조건들과 쿼리가 주어질 때, 각 쿼리를 만족하는 지원자의 수를 구하는 문제.

    <나의 풀이>
    풀지 못해서 구글링을 통해 아이디어를 얻었다.
    info 배열로 주어진 지원자들의 조건들을 해시맵에 저장할 때, 각 조건이 '-'가 되는 경우의 수도 같이 구한다.
    이후 각 조건들에 대응하는 점수 배열을 오름차순 정렬해준 뒤, 쿼리 배열을 탐색할 때 이분 탐색으로 쿼리로 주어진 점수 중 가장 낮은 인덱스를 구하면
    (해당 점수 배열의 크기 - 이분 탐색으로 구한 인덱스) 가 해당 쿼리를 만족하는 지원자의 수가 된다.

    이 문제를 풀면서 해시맵의 value로 linkedlist를 사용하면, 이분 탐색 시 엄청난 비효율성으로 인해 시간초과가 난다.
 */

class temp {

    static Map<String, List<Integer>> hm;

    public static int[] solution(String[] info, String[] query) {

        hm = new HashMap<>();
        for (String s : info) {
            dfs("", 0, s.split(" "));
        }

        for (List<Integer> list : hm.values()) {
            Collections.sort(list);
        }

        int[] ans = new int[query.length];
        int aIdx = 0;
        for (String q : query) {
            q = q.replaceAll(" and ", "");
            String[] splited = q.split(" ");

            int score = Integer.parseInt(splited[1]);
            String conditions = splited[0];

            List<Integer> list = hm.get(conditions);
            if(list == null) {
                ans[aIdx++] = 0;
            } else {
                int idx = lowerBound(list, score);
                int count = list.size() - idx;
                ans[aIdx++] = count;
            }
        }

        return ans;
    }

    public static int lowerBound(List<Integer> list, int target) {
        int low = 0, high = list.size()-1;
        int ret = list.size();
        while(low <= high) {
            int mid = (low + high) / 2;
            int score = list.get(mid);
            if(score >= target) {
                ret = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ret;
    }

    public static void dfs(String str, int level, String[] info) {
        if(level == 4) {
            System.out.println(str);
            int score = Integer.parseInt(info[4]);
            if(hm.containsKey(str)) {
                hm.get(str).add(score);
            } else {
                List<Integer> list = new ArrayList<>();
                list.add(score);
                hm.put(str, list);
            }
            return;
        }

        dfs(str+"-", level+1, info);
        if(!info[level].equals("-")) {
            dfs(str+info[level], level+1, info);
        }
    }

    public static void main(String[] args) {
        String[] info = {
                "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"
        };
        String[] query = {
                "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"
        };

        int[] ans = solution(info, query);
    }
}