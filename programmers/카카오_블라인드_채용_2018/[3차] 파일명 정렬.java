package 카카오_블라인드_채용_2018;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Locale;

/*
    파일명 리스트가 주어질 때, 문제 조건에 맞게 파일명을 정렬한 결과를 반환하는 문제.

    <나의 풀이>
    특별한 알고리즘이 필요한 문제는 아니다. 정렬 기능을 얼마나 잘 활용하고 이해하는지가 관건인 문제이다.
 */

class SortingFileName {
    public String[] solution(String[] files) {

        List<FileStructure> fileList = new ArrayList<>(files.length);
        for (String file : files) {
            fileList.add(splitFile(file));
        }

        Collections.sort(fileList);

        String[] ans = new String[fileList.size()];
        for (int i=0; i<fileList.size(); ++i) {
            ans[i] = fileList.get(i).origin;
        }

        return ans;
    }

    public FileStructure splitFile(String file) {

        int idx=0;
        int len = file.length();

        while(idx < len) {
            char c = file.charAt(idx);
            if('0' <= c && c <= '9') {
                break;
            }
            ++idx;
        }
        String head = file.substring(0, idx);

        int numStartIdx = idx;
        idx += 1;
        while(idx < len) {
            char c = file.charAt(idx);
            if(!('0' <= c && c <= '9')) {
                break;
            }
            ++idx;
        }
        String numStr = file.substring(numStartIdx, idx);
        String tail = file.substring(idx);

        return new FileStructure(file, head.toLowerCase(Locale.ROOT), Integer.parseInt(numStr), tail);
    }

    static class FileStructure implements Comparable<FileStructure> {

        String origin;
        String head, tail;
        int number;

        public FileStructure(String origin, String head, int number, String tail) {
            this.origin = origin;
            this.head = head;
            this.number = number;
            this.tail = tail;
        }

        @Override
        public int compareTo(FileStructure o) {
            if(this.head.equals(o.head)) {
                return this.number - o.number;
            }
            return this.head.compareToIgnoreCase(o.head);
        }
    }
}