import java.io.*;

/*
    스위치의 상태와 스위치를 누를 사람의 성별, 동작들이 주어질 때, 모든 동작 후 스위치의 상태를 구하는 문제.

    <나의 풀이>
    단순한 구현 문제이다.
    문제는 쉬우나, 출력 형식이 한 줄에 20개의 스위치만 입력하는 방식이라 한 번 틀렸다.
 */

class SwitchTurnOnOff {

    static int[] switches;
    static int n;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        String switchLine = br.readLine();
        String[] switchStrs = switchLine.split(" ");
        switches = new int[n];
        for (int i=0; i<n; ++i) {
            switches[i] = Integer.parseInt(switchStrs[i]);
        }

        int m = Integer.parseInt(br.readLine());
        for(int i=0; i<m; ++i) {
            String line = br.readLine();
            String[] splited = line.split(" ");
            String gender = splited[0];
            int num = Integer.parseInt(splited[1]);

            if("1".equals(gender)) {
                boySwitch(num);
            } else {
                girlSwitch(num);
            }
        }

        int count = 0;
        boolean isLineBreakNeed = false;
        for (int sw : switches) {
            if (isLineBreakNeed) {
                bw.write("\n");
                isLineBreakNeed = false;
            }
            bw.write(String.valueOf(sw));

            ++count;
            if(count == 20) {
                isLineBreakNeed = true;
                count = 0;
            } else {
                bw.write(" ");
            }
        }
        bw.flush();
    }

    public static void boySwitch(int num) {
        for(int i=0; i<n; ++i) {
            if((i+1) % num == 0) {
                switches[i] ^= 1;
            }
        }
    }

    public static void girlSwitch(int num) {
        num -= 1;
        switches[num] ^= 1;

        int width = 1;
        while(num - width >= 0 && num + width < n) {
            int left = num - width;
            int right = num + width;
            if(switches[left] == switches[right]) {
                switches[left] ^= 1;
                switches[right] ^= 1;
            } else {
                break;
            }
            ++width;
        }
    }
}