import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import static java.lang.Integer.parseInt;

class SortPosition {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = parseInt(br.readLine());
        List<Pos> poses = new ArrayList<>(n);
        for(int i=0; i<n; ++i) {
            String[] splited = br.readLine().split(" ");
            int x = parseInt(splited[0]);
            int y = parseInt(splited[1]);
            poses.add(new Pos(y, x));
        }

        Collections.sort(poses);

        for (Pos pos : poses) {
            bw.write(pos.x + " " + pos.y + "\n");
        }
        bw.flush();
    }

    static class Pos implements Comparable<Pos> {
        int y,x;
        public Pos(int y, int x) {
            this.y = y;
            this.x = x;
        }

        @Override
        public int compareTo(Pos o) {
            if(this.y == o.y) {
                return this.x - o.x;
            } else {
                return this.y - o.y;
            }
        }
    }
}