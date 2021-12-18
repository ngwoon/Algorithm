package 카카오_블라인드_채용_2018;

import java.util.ArrayList;
import java.util.Objects;
import java.util.PriorityQueue;

import static java.lang.Integer.parseInt;

/*
    라디오에서 들었던 음악 문자열과 라디오 음악 방송 시간표가 주어졌을 때, 들었던 곡의 후보를 찾는 문제.

    <나의 풀이>
    특별한 알고리즘이 필요한 문제는 아니었다.
    문제 조건에 맞게 라디오에서 방송한 음악의 악보를 재구성하는 부분이 핵심이다.

    음악 악보가 주어지지만, 라디오에서 이 음악을 어느 시간만큼 방송했는지를 통해 청취자에게 들린 음악을 구해야한다.
        * 음악 길이보다 라디오 방송시간이 짧은 경우
          음악 악보 전체가 방송되지 않았다. 1분에 한 음이므로 방송되지 않은 만큼 음악 악보 뒷부분을 자른다.
        * 음악 길이보다 라디오 방송시간이 긴 경우
          음악 길이보다 방송시간이 긴 만큼 반복 재생된다.

    추가로, 나는 # 문자 때문에 list 자료구조로 재구성했지만, #이 포함된 음을 아예 다른 문자 (소문자 a같은) 로 치환하는 방법도 있다.
 */

class 방금그곡 {
    public String solution(String m, String[] musicinfos) {

        PriorityQueue<Tuple> pq = new PriorityQueue<>();

        ArrayList<String> guessArr = new ArrayList<>();
        musicToList(guessArr, m);

        for (String musicinfo : musicinfos) {
            String[] splited = musicinfo.split(",");
            int startMin = strToMin(splited[0]);
            int endMin = strToMin(splited[1]);
            int playTime = endMin - startMin;

            String musicTitle = splited[2];
            String music = splited[3];

            ArrayList<String> musicArr = new ArrayList<>();
            musicToList(musicArr, splited[3]);

            int cnt = playTime / musicArr.size();
            int rest = playTime % musicArr.size();
            for(int i=0; i<cnt; ++i) {
                musicToList(musicArr, music);
            }
            if(rest > 0) {
                if(cnt == 0) {
                    int musicLen = musicArr.size();
                    for(int i=0; i<musicLen - rest; ++i) {
                        musicArr.remove(musicArr.size() - 1);
                    }
                }
                for(int i=0; i<rest; ++i) {
                    musicArr.add(musicArr.get(i));
                }
            }

            if(isSimilar(guessArr, musicArr)) {
                pq.add(new Tuple(startMin, playTime, musicTitle));
            }
        }

        if(pq.isEmpty()) {
            return "(None)";
        }
        return pq.poll().musicTitle;
    }

    public void musicToList(ArrayList<String> arr, String music) {
        for(int i=0; i<music.length(); ++i) {
            if(i != music.length() - 1 && music.charAt(i+1) == '#') {
                arr.add(music.substring(i, i+2));
                ++i;
            } else {
                arr.add(music.substring(i, i+1));
            }
        }
    }

    public boolean isSimilar(ArrayList<String> guess, ArrayList<String> music) {

        if(guess.size() > music.size()) {
            return false;
        }

        for(int i=0; i<music.size() - guess.size() + 1; ++i) {
            boolean isSame = true;
            for(int j=0; j<guess.size(); ++j) {
                if(!Objects.equals(guess.get(j), music.get(i + j))) {
                    isSame = false;
                    break;
                }
            }
            if(isSame) {
                return true;
            }
        }

        return false;
    }

    public int strToMin(String str) {
        String[] splited = str.split(":");
        return parseInt(splited[0]) * 60 + parseInt(splited[1]);
    }

    static class Tuple implements Comparable<Tuple> {
        int startMin, playTime;
        String musicTitle;
        public Tuple(int startMin, int playTime, String musicTitle) {
            this.startMin = startMin;
            this.playTime = playTime;
            this.musicTitle = musicTitle;
        }

        @Override
        public int compareTo(Tuple o) {
            if(this.playTime == o.playTime) {
                return this.startMin - o.startMin;
            }
            return o.playTime - this.playTime;
        }
    }
}