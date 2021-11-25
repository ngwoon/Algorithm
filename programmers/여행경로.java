import java.util.*;

/*
    항공 티겟 배열이 주어졌을 때, 티켓을 모두 사용하면서 모든 도시를 여행하는 경로를 구하는 문제.

    <나의 풀이>
    이 문제의 핵심은 항공권을 모두 사용해야하며, 모든 도시를 여행하는 경로가 2가지 이상일 때 사전순으로 가장 앞에 있는 경로를 반환해야 한다.
    그러기 위해서 우선 주어진 항공티겟을 사전순 오름차순으로 정렬하고, 각 도시를 노드로 하는 단방향 그래프를 만든 뒤 dfs로 탐색하면서 가장 먼저 발견한
    모든 도시 여행 경로가 정답이 된다.
 */

class TripPath {

    List<String> answer;
    int ticketCnt;

    public String[] solution(String[][] tickets) {

        ticketCnt = tickets.length;

        Arrays.sort(tickets, (a,b) -> {
            if(a[0].equals(b[0])) {
                return a[1].compareTo(b[1]);
            } else {
                return a[0].compareTo(b[0]);
            }
        });

        Map<String, LinkedList<Pair>> adj = new HashMap<>();
        for (String[] ticket : tickets) {
            if(!adj.containsKey(ticket[0])) {
                adj.put(ticket[0], new LinkedList<>());
            }
            if(!adj.containsKey(ticket[1])) {
                adj.put(ticket[1], new LinkedList<>());
            }
            adj.get(ticket[0]).add(new Pair(ticket[1], false));
        }


        List<String> answer = new LinkedList<>();
        String start = "ICN";
        answer.add(start);
        dfs(start, adj, answer);

        return answer.toArray(new String[0]);
    }

    public boolean dfs(String cur, Map<String, LinkedList<Pair>> adj, List<String> path) {

        if(path.size() == ticketCnt + 1) {
            answer = path;
            return true;
        }

        LinkedList<Pair> list = adj.get(cur);
        for (Pair ticket : list) {
            if(!ticket.isUsed) {
                path.add(ticket.dest);
                ticket.isUsed = true;
                if(dfs(ticket.dest, adj, path)) {
                    return true;
                }
                path.remove(path.size() - 1);
                ticket.isUsed = false;
            }
        }

        return false;
    }

    static class Pair {
        String dest;
        boolean isUsed;

        public Pair(String dest, boolean isUsed) {
            this.dest = dest;
            this.isUsed = isUsed;
        }
    }
}