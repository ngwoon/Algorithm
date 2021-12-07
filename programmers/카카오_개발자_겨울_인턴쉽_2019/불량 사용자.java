package 카카오_개발자_겨울_인턴쉽_2019;

import java.util.*;

class AbuseUser {

    static HashSet<Integer> hs;
    static boolean[] visited;
    static String[] regex;
    static String[] user;

    public static int solution(String[] userId, String[] bannedId) {

        user = userId;
        regex = new String[bannedId.length];
        for(int i=0; i< bannedId.length; ++i) {
            regex[i] = bannedId[i].replace("*", ".");
        }

        visited = new boolean[userId.length];
        hs = new HashSet<>();

        backtracking(0);

        return hs.size();
    }

    public static void backtracking(int idx) {
        if(idx == regex.length) {
            int binary = boolToInt();
            hs.add(binary);
            return;
        }

        for(int i=0; i<user.length; ++i) {
            if(!visited[i] && user[i].matches(regex[idx])) {
                visited[i] = true;
                backtracking(idx+1);
                visited[i] = false;
            }
        }
    }

    public static int boolToInt() {
        int ret = 0;
        for(int i=0; i<user.length; ++i) {
            ret += visited[i] ? Math.pow(2, i) : 0;
        }
        return ret;
    }

    public static void main(String[] args) {

        String[] userId = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
        String[] bannedId = {"*rodo", "*rodo", "******"};

        solution(userId, bannedId);
    }
}