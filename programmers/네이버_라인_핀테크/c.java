package 네이버_라인_핀테크;

import java.util.HashMap;

class C {

    HashMap<String[], String> hm;

    public String solution(String[] pixels) {

        init();

        int width = pixels[0].length();
        StringBuilder ans = new StringBuilder();
        for(int s=0; s<width; s+=3) {
            for (String[] board : hm.keySet()) {
                boolean isSame = true;
                for(int i=0; i<5; ++i) {
                    for(int j=0; j<3; ++j) {
                        if(board[i].charAt(j) != pixels[i].charAt(s + j)) {
                            isSame = false;
                            break;
                        }
                    }
                }

                if(isSame) {
                    ans.append(hm.get(board));
                    break;
                }
            }
        }

        return ans.toString();
    }

    public void init() {

        hm = new HashMap<>();

        String[] zero = {"111", "101", "101", "101", "111"};
        hm.put(zero, "0");

        String[] one = {"110", "010", "010", "010", "111"};
        hm.put(one, "1");

        String[] two = {"111", "001", "111", "100", "111"};
        hm.put(two, "2");

        String[] three = {"111", "001", "111", "001", "111"};
        hm.put(three, "3");

        String[] four = {"101", "101", "111", "001", "001"};
        hm.put(four, "4");

        String[] five = {"111", "100", "111", "001", "111"};
        hm.put(five, "5");

        String[] six = {"111", "100", "111", "101", "111"};
        hm.put(six, "6");

        String[] seven = {"111", "101", "001", "001", "001"};
        hm.put(seven, "7");

        String[] eight = {"111", "101", "111", "101", "111"};
        hm.put(eight, "8");

        String[] nine = {"111", "101", "111", "001", "111"};
        hm.put(nine, "9");
    }
}