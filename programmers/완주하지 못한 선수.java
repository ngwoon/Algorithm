import java.util.HashMap;

class NotCompletePlayer {
    public String solution(String[] participant, String[] completion) {
        String answer = "";

        HashMap<String, Integer> map = new HashMap<>();

        for (String c : completion) {
            if(map.containsKey(c)) {
                map.put(c, map.get(c) + 1);
            } else {
                map.put(c, 1);
            }
        }

        for (String p : participant) {
            if(map.containsKey(p)) {
                int cnt = map.get(p);
                if(cnt == 0) {
                    answer = p;
                    break;
                } else {
                    map.put(p, cnt - 1);
                }
            } else {
                answer = p;
                break;
            }
        }

        if(answer.equals("")) {
            answer = participant[participant.length - 1];
        }

        return answer;
    }
}