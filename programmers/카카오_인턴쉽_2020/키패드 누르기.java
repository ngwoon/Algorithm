package 카카오_인턴쉽_2020;

import java.util.HashMap;

/*
    누를 키패드 목록과 누르는 사람이 주로 쓰는 손이 주어질 때, 각 숫자를 어떤 엄지손가락으로 누르는지 구하는 문제.

    <나의 풀이>
    특별한 알고리즘이 필요한 문제는 아니다. 구현 문제이다.
 */

class PressKeypad {

    HashMap<Integer, Pair> hm;

    public String solution(int[] numbers, String hand) {

        init();

        Pair left = new Pair(3, 0);
        Pair right = new Pair(3, 2);
        StringBuilder sb = new StringBuilder();
        for (int number : numbers) {
            if(number == 1 || number == 4 || number == 7) {
                sb.append("L");
                left = hm.get(number);
            } else if(number == 3 || number == 6 || number == 9) {
                sb.append("R");
                right = hm.get(number);
            } else {
                Pair cur = hm.get(number);
                int ldst = calcDst(left, cur);
                int rdst = calcDst(right, cur);
                if(ldst < rdst) {
                    sb.append("L");
                    left = hm.get(number);
                } else if(rdst < ldst) {
                    sb.append("R");
                    right = hm.get(number);
                } else {
                    if(hand.equals("left")) {
                        sb.append("L");
                        left = hm.get(number);
                    } else {
                        sb.append("R");
                        right = hm.get(number);
                    }
                }
            }
        }

        return sb.toString();
    }

    public void init() {

        hm = new HashMap<>();
        for(int i=0; i<4; ++i) {
            for(int j=1; j<=3; ++j) {
                hm.put(i*3 + j, new Pair(i, j-1));
            }
        }
        hm.put(0, new Pair(3,1));
    }

    public int calcDst(Pair a, Pair b) {
        return Math.abs(a.y - b.y) + Math.abs(a.x - b.x);
    }

    static class Pair {
        int y,x;
        public Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}