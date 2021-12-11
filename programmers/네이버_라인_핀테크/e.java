package 네이버_라인_핀테크;

class E {

    String regex = "(AAB+|BAB+A)+";

    public int solution(String[] strs) {

        int ans = 0;
        for (String str : strs) {
            if(str.matches(regex)) {
                ++ans;
            }
        }

        return ans;
    }
}
