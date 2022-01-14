package KAKAO_BLIND_RECRUITMENT_2022;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

import static java.lang.Integer.parseInt;

/*
    주차 요금 정보와 주차 기록들이 주어졌을 때, 각 자동차의 주차 요금을 구하는 문제.

    <나의 풀이>
    주차 기록에 같은 차량의 서로 다른 입,출차 내역이 존재할 수 있고, 누적 주차 시간으로 요금을 계산한다는 점만 주의하면 된다.
    해시맵을 활용하여 차 번호에 대응하는 주차 시간 탐색 시간을 줄였다.
 */

class CalcParkingFee {
    public int[] solution(int[] fees, String[] records) {
        Map<String, Integer> recordsMap = new HashMap<>();
        Map<String, Integer> timeSum = new HashMap<>();
        for (String record : records) {
            String[] splited = record.split(" ");
            int min = hhmmToMin(splited[0]);
            if(!recordsMap.containsKey(splited[1])) {
                recordsMap.put(splited[1], 0);
            }
            if("IN".equals(splited[2])) {
                recordsMap.put(splited[1], min);
            } else {
                int in = recordsMap.get(splited[1]);
                timeSum.put(splited[1], timeSum.getOrDefault(splited[1], 0) + (min - in));
                recordsMap.remove(splited[1]);
            }
        }

        int lastOutMin = hhmmToMin("23:59");
        for (String carNum : recordsMap.keySet()) {
            int in = recordsMap.get(carNum);
            timeSum.put(carNum, timeSum.getOrDefault(carNum, 0) + (lastOutMin - in));
        }

        ArrayList<String> carNums = new ArrayList<>(timeSum.keySet());
        Collections.sort(carNums);

        int[] ans = new int[carNums.size()];
        int idx = 0;
        for (String carNum : carNums) {
            ans[idx++] = calcFee(timeSum.get(carNum), fees[0], fees[1], fees[2], fees[3]);
        }

        return ans;
    }

    public int hhmmToMin(String time) {
        String[] splited = time.split(":");
        return parseInt(splited[0]) * 60 + parseInt(splited[1]);
    }

    public int calcFee(int parkingTime, int baseTime, int baseFee, int unitTime, int unitFee) {
        int curFee = baseFee;
        if(parkingTime > baseTime) {
            int overTime = parkingTime - baseTime;
            int overUnit = overTime % unitTime != 0 ? overTime / unitTime + 1 : overTime / unitTime;
            int overFee = unitFee * overUnit;
            curFee += overFee;
        }
        return curFee;
    }

    static class ParkingInfo implements Comparable<ParkingInfo> {
        String carNum;
        int in;
        ParkingInfo(String carNum) {
            this.carNum = carNum;
        }

        @Override
        public int compareTo(ParkingInfo o) {
            return this.carNum.compareTo(o.carNum);
        }
    }
}