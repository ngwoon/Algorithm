import java.io.*;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

import static java.lang.Integer.parseInt;

/*
    세 개의 돌 그룹의 돌 개수가 주어질 때, 문제 조건에 맞게 돌을 이동시켜 세 그룹의 돌 개수를 동일하게 만들 수 있는지 그 여부를 구하는 문제.

    <나의 풀이>
    우선 돌을 이동시키는 과정에서, 세 그룹의 돌의 총량은 변하지 않는다. 즉, 세 그룹의 돌 개수를 입력받고, 그 합이 3의 배수가 아니면 0을 출력해도 무방하다.
    돌의 개수의 합이 3의 배수라면, 이때부터는 완전탐색으로 모든 경우의 수를 따져보아야 한다. 단, 이전에 수행했던 경우를 중복해서 수행하는 경우는 없어야 한다.
    이를 위해 수행 이력 여부를 확인하는 Set을 활용했다. Set에는 오름차순으로 정렬된 세 그룹의 돌 개수가 공백으로 구분된 문자열이 저장된다.
 */

class StoneGroup {

    static Set<String> visited;
    static int[] rocks;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer  stzr = new StringTokenizer(br.readLine());

        rocks = new int[3];
        rocks[0] = parseInt(stzr.nextToken());
        rocks[1] = parseInt(stzr.nextToken());
        rocks[2] = parseInt(stzr.nextToken());

        int sum = rocks[0] + rocks[1] + rocks[2];
        if(sum % 3 != 0) {
            bw.write("0");
        } else {
            visited = new HashSet<>();
            bw.write(dfs(rocks) ? "1" : "0");
        }
        bw.flush();
    }

    public static boolean dfs(int[] rocks) {

        boolean isAllSame = true;
        for(int i=0; i<3; ++i) {
            for(int j=i+1; j<3; ++j) {
                if(rocks[i] != rocks[j]) {
                    isAllSame = false;
                    int[] newRocks = moveRock(rocks, i, j);
                    String stat = groupToString(newRocks);
                    if(visited.contains(stat)) {
                        continue;
                    }

                    visited.add(groupToString(newRocks));
                    if(dfs(newRocks)) {
                        return true;
                    }
                }
            }
        }

        return isAllSame;
    }

    public static String groupToString(int[] group) {
        Arrays.sort(group);
        StringBuilder sb = new StringBuilder();
        for (int g : group) {
            sb.append(g).append(" ");
        }
        return sb.toString();
    }

    public static int[] moveRock(int[] rocks, int aIdx, int bIdx) {
        int[] newRocks = Arrays.copyOf(rocks, 3);
        if(newRocks[aIdx] > newRocks[bIdx]) {
            aIdx ^= bIdx; bIdx ^= aIdx; aIdx ^= bIdx;
        }
        newRocks[bIdx] -= newRocks[aIdx];
        newRocks[aIdx] *= 2;

        return newRocks;
    }
}