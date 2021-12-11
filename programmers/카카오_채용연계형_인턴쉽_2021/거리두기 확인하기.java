package 카카오_채용연계형_인턴쉽_2021;

import java.util.ArrayList;

/*
    학생들이 앉아있는 교실들이 주어질 때, 거리두기 지키기 여부를 판단하는 문제.

    <나의 풀이>
    학생들이 앉아있는 좌표를 저장해둔 뒤, 완전탐색으로 모든 학생 쌍을 비교하면서
    거리가 2이면 사이에 가림판이 설치되어 있는지를 확인하고
    거리가 1이면 거리두기를 지키지 않았다고 판단한다.
 */

class KeepDistance {

    int n;
    ArrayList<Pos> people;

    public int[] solution(String[][] places) {

        n = places[0].length;
        people = new ArrayList<>(n*n);
        int[] ans = new int[places.length];

        int idx = 0;
        for(int k=0; k<places.length; ++k) {
            String[] cur = places[k];
            for (int i=0; i<n; ++i) {
                for(int j=0; j<n; ++j) {
                    if(cur[i].charAt(j) == 'P') {
                        people.add(new Pos(i, j));
                    }
                }
            }

            if(judge(cur)) {
                ans[idx] = 1;
            } else {
                ans[idx] = 0;
            }
            ++idx;
            people.clear();
        }

        return ans;
    }

    public boolean judge(String[] room) {

        for(int i=0; i<people.size() - 1; ++i) {
            for(int j=i+1; j<people.size(); ++j) {
                Pos a = people.get(i);
                Pos b = people.get(j);
                int dst = Math.abs(a.y - b.y) + Math.abs(a.x - b.x);

                if(dst == 2) {
                    if(a.y == b.y) {
                        if(room[a.y].charAt((a.x + b.x) / 2) != 'X') {
                            return false;
                        }
                    } else if(a.x == b.x) {
                        if(room[(a.y + b.y) / 2].charAt(a.x) != 'X') {
                            return false;
                        }
                    } else {
                        if(room[a.y].charAt(b.x) != 'X' || room[b.y].charAt(a.x) != 'X') {
                            return false;
                        }
                    }
                } else if(dst == 1) {
                    return false;
                }
            }
        }

        return true;
    }

    static class Pos {
        int y, x;
        public Pos(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}