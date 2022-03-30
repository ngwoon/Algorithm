import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

import static java.lang.Integer.parseInt;

/*
    다리의 길이와 최대 하중, 각 트럭의 하중이 주어질 때, 트럭이 모두 다리를 건너는 데 걸리는 최소 시간을 구하는 문제.

    <나의 풀이>
    단순 시뮬레이션 문제이다.
    다리를 상징하는 Queue를 두고, Queue.size()가 다리의 길이를 넘지 않고 Queue에 들어간 트럭들의 하중의 합이 다리의 하중을 초과하지 않는 선에서
    Queue에 트럭을 넣고, 빼는 식으로 풀었다.
    다리가 여유로워도, 한 단위 시간에 하나의 트럭만 다리에 진입할 수 있다는 점을 유의하자.
 */

class TruckBridge {

    static int n, w, l;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String varsLine = br.readLine();
        String[] varsStr = varsLine.split(" ");
        n = parseInt(varsStr[0]);
        w = parseInt(varsStr[1]);
        l = parseInt(varsStr[2]);

        List<Integer> loads = new ArrayList<>(n);
        String loadsLine = br.readLine();
        String[] loadsStr = loadsLine.split(" ");
        for (String loadStr : loadsStr) {
            loads.add(parseInt(loadStr));
        }

        Queue<TruckInfo> bridge = new LinkedList<>();
        int curLoad = 0;
        int time = 1;
        int ans = 0;
        for (int i=0; i<n; ++i) {
            int load = loads.get(i);
            // 다리를 다 건넌 트럭
            if(!bridge.isEmpty()) {
                TruckInfo front = bridge.peek();
                if(front.escapeTime == time) {
                    bridge.poll();
                    curLoad -= front.load;
                }
            }
            
            // 트럭의 다리 진입
            if(bridge.size() < w && curLoad + load <= l) {
                int escapeTime = time + w;
                bridge.add(new TruckInfo(load, escapeTime));
                curLoad += load;
                ans = escapeTime;
            } else {
                i -= 1;
            }

            ++time;
        }

        bw.write(String.valueOf(ans));
        bw.flush();
    }

    static class TruckInfo {
        int escapeTime, load;
        public TruckInfo(int load, int escapeTime) {
            this.load = load;
            this.escapeTime = escapeTime;
        }
    }
}