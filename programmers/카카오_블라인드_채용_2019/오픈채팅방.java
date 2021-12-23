package 카카오_블라인드_채용_2019;

import java.util.HashMap;

/*
    오픈채팅방의 유저 입장, 퇴장, 닉네임 변경 기록이 주어질 때, 최종적으로 오픈채팅방 관리자가 보는 로그를 구하는 문제.

    <나의 풀이>
    특별한 알고리즘이 필요한 문제는 아니다.
    관리자가 최종적으로 보는 로그에는 닉네임이 여러 차례 변경되고 난 뒤 마지막 닉네임을 보는 것이므로, 해시맵을 이용해서 각 유저 아이디의 마지막 닉네임 상태를 기억하면 된다.
 */

class OpenChat {
    public String[] solution(String[] record) {

        HashMap<String, String> hm = new HashMap<>();

        int inAndOut = 0;
        for (String line : record) {
            String[] words = line.split(" ");
            if(words[0].equals("Enter") || words[0].equals("Change")) {
                hm.put(words[1], words[2]);
            }
            if(words[0].equals("Enter") || words[0].equals("Leave")) {
                ++inAndOut;
            }
        }

        String[] ans = new String[inAndOut];
        int idx=0;
        for(String line : record) {
            String[] words = line.split(" ");
            if(words[0].equals("Enter")) {
                ans[idx] = hm.get(words[1])+"님이 들어왔습니다.";
                ++idx;
            } else if(words[0].equals("Leave")) {
                ans[idx] = hm.get(words[1])+"님이 나갔습니다.";
                ++idx;
            }
        }

        return ans;
    }
}