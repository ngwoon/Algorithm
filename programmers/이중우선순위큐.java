import java.util.Collections;
import java.util.PriorityQueue;

/*
    주어지는 명령에 따라 이중우선순위큐를 조작하고, 모든 명령을 수행한 뒤 남아있는 최소, 최대값을 구하는 문제

    <나의 풀이>
    java의 PriorityQueue 자료구조에 remove라는, 특정 요소를 지울 수 있는 메서드의 존재를 몰라서 한참 헤맸다.
    최대 힙, 최소 힙을 각각 선언하고, 요소 추가 명령일 땐 두 pq에 모두 추가하고, 요소 추출 명령일 땐 최대, 최소에 따라
    한 쪽 pq에서 poll하고, 다른 한 쪽에선 remove로 지워준다.
 */

class DoublePriorityQueue {
    public static int[] solution(String[] operations) {

        int[] answer = new int[2];

        PriorityQueue<Integer> minPq = new PriorityQueue<>();
        PriorityQueue<Integer> maxPq = new PriorityQueue<>(Collections.reverseOrder());

        for (String operation : operations) {
            char order = operation.charAt(0);
            if(order == 'I') {
                String[] splited = operation.split("\\s+");
                int cur = Integer.parseInt(splited[1]);
                minPq.add(cur);
                maxPq.add(cur);
            } else {
                if(operation.charAt(2) == '1') {
                    if(maxPq.size() == 0) {
                        continue;
                    }
                    int val = maxPq.poll();
                    minPq.remove(val);
                } else {
                    if(minPq.size() == 0) {
                        continue;
                    }
                    int val = minPq.poll();
                    maxPq.remove(val);
                }
            }
        }

        int maxPqSize = maxPq.size();
        int minPqSize = minPq.size();
        if(maxPqSize == 0 && minPqSize == 0) {
            answer[0] = 0; answer[1] = 0;
        } else if(maxPqSize == 0 || minPqSize == 0) {
            int val = maxPqSize == 0 ? minPq.poll() : maxPq.poll();
            answer[0] = val; answer[1] = val;
        } else {
            answer[0] = maxPq.poll(); answer[1] = minPq.poll();
        }

        return answer;
    }

    public static void main(String[] args) {
        String[] operations = new String[4];
        operations[0] = "I 7";
        operations[1] = "I 5";
        operations[2] = "I -5";
        operations[3] = "D -1";

        int[] solution = solution(operations);
        for (int i : solution) {
            System.out.println(i);
        }
    }
}