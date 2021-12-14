package 카카오_채용연계형_인턴쉽_2021;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

/*
    표 편집 명령들이 주어졌을 때, 모든 명령을 수행한 뒤 각 행의 삭제 여부를 구하는 문제.

    <나의 풀이>
    명령어의 최대 개수는 20만이고, 한 명령 당 위, 아래 커서 이동 최대 횟수는 30만이다.
    즉, 현재 위치에서 다음 위치를 일일이 찾으면 시간초과가 날 것이다. 현재 위치에서 다음 위치를 바로 알 수 있어야 하며, 삽입, 삭제가 빨라야 한다.
    이를 위해 배열에 링크드리스트의 특징을 섞었다.
    배열 요소는 Pair이며, 이는 현재 위치의 위, 아래 위치를 저장한다.
    행을 삭제할 때면 현재 위치의 위, 아래 요소의 up, down 값을 수정하여 이어주고,
    복구할 때는 복구할 위치에서 가장 가까운 위, 아래 요소의 up, down 값을 수정하여 복구한다.
    이런 방식은 삭제 O(1), 복구 O(n), 행 이동에 O(X) 시간복잡도를 갖으므로 시간초과 없이 문제를 풀 수 있다.
 */

class TableEdit {

    boolean[] deleted;
    int pos;
    List<Pair> table;
    Stack<Integer> history;

    public String solution(int n, int k, String[] cmd) {

        deleted = new boolean[n];
        pos = k;
        table = new ArrayList<>(n);
        history = new Stack<>();

        table.add(new Pair(0,1));
        for(int i=1; i<n-1; ++i) {
            table.add(new Pair(i-1, i+1));
        }
        table.add(new Pair(n-2, n-1));

        for (String s : cmd) {
            String[] splited = s.split(" ");
            if(splited[0].equals("U") || splited[0].equals("D")) {
                move(splited[0], Integer.parseInt(splited[1]));
            } else if(splited[0].equals("C")) {
                delete();
            } else {
                recover(n);
            }
        }

        StringBuilder ans = new StringBuilder();
        for (boolean b : deleted) {
            ans.append(b ? "X" : "O");
        }

        return ans.toString();
    }

    public void move(String dir, int dst) {

        while(dst-- > 0) {
            int next = dir.equals("U") ? table.get(pos).up : table.get(pos).down;
            if(next == pos) {
                break;
            } else {
                pos = next;
            }
        }
    }

    public void delete() {

        history.add(pos);
        deleted[pos] = true;

        int down = table.get(pos).down;
        int up = table.get(pos).up;
        if(down == pos) {
            table.get(up).down = up;
            pos = up;
        } else if(up == pos) {
            table.get(down).up = down;
            pos = down;
        } else {
            table.get(down).up = up;
            table.get(up).down = down;
            pos = down;
        }
    }

    public void recover(int n) {

        int idx = history.pop();
        deleted[idx] = false;

        int lookupUpside = idx-1;
        while(lookupUpside >= 0) {
            if(!deleted[lookupUpside]) {
                table.get(lookupUpside).down = idx;
                table.get(idx).up = lookupUpside;
                break;
            }
            --lookupUpside;
        }
        if(lookupUpside < 0) {
            table.get(idx).up = idx;
        }

        int lookupDownside = idx+1;
        while(lookupDownside < n) {
            if(!deleted[lookupDownside]) {
                table.get(lookupDownside).up = idx;
                table.get(idx).down = lookupDownside;
                break;
            }
            ++lookupDownside;
        }
        if(lookupDownside == n) {
            table.get(idx).down = idx;
        }
    }

    static class Pair {
        int up, down;
        public Pair(int up, int down) {
            this.up = up;
            this.down = down;
        }
    }
}