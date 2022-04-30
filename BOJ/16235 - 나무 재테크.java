import java.io.*;
import java.util.*;

import static java.lang.Integer.parseInt;

/*
    문제 조건에 따라 나무 재테크를 했을 때, k년 후 살아남은 나무의 수를 구하는 문제.

    <나의 풀이>
    구현 문제이므로, 문제 조건에 맞게 구현하면 된다.

    한 칸에 여러 나무가 존재할 수 있으므로, 나무의 위치를 2차원 배열이 아닌 1차원 리스트로 관리했다.
    이 문제의 경우 나무를 삽입, 삭제하는 연산이 잦으므로, ArrayList보다 LinkedList를 사용하는 것이 합리적이다. (실제로 ArrayList를 쓰면 TLE 발생)
 */

class TreeFinance {

    static int[] dx = {0,1,1,1,0,-1,-1,-1};
    static int[] dy = {-1,-1,0,1,1,1,0,-1};
    static int n, m, k;
    static int[][] ground;
    static int[][] nurishments;
    static List<Tree> trees;
    static List<Tree> deadTrees;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer stzr = new StringTokenizer(br.readLine());
        n = parseInt(stzr.nextToken());
        m = parseInt(stzr.nextToken());
        k = parseInt(stzr.nextToken());

        nurishments = new int[n][n];
        ground = new int[n][n];
        for(int i=0; i<n; ++i) {
            stzr = new StringTokenizer(br.readLine());
            for(int j=0; j<n; ++j) {
                nurishments[i][j] = parseInt(stzr.nextToken());
                ground[i][j] = 5;
            }
        }

        deadTrees = new ArrayList<>(n*n); // n*n보다 많을 수도 있을듯
        trees = new LinkedList<>();
        for(int i=0; i<m; ++i) {
            stzr = new StringTokenizer(br.readLine());
            int y = parseInt(stzr.nextToken()) - 1;
            int x = parseInt(stzr.nextToken()) - 1;
            int age = parseInt(stzr.nextToken());
            trees.add(new Tree(age, y, x));
        }
        Collections.sort(trees);

        treeFinance();

        bw.write(String.valueOf(trees.size()));
        bw.flush();
    }

    public static void treeFinance() {
        while(k-- > 0) {
            spring();
            summer();
            fall();
            winter();
        }
    }

    // 나무가 자신의 나이만큼 양분을 먹고, 나이가 1 증가한다.
    // 나이가 어린 나무부터 양분을 먹는다.
    // 양분이 부족하면, 나무는 죽는다.
    public static void spring() {
        Iterator<Tree> iter = trees.iterator();
        while(iter.hasNext()) {
            Tree tree = iter.next();
            int ty = tree.y;
            int tx = tree.x;
            int age = tree.age;

            if(ground[ty][tx] < age) {
                iter.remove();
                deadTrees.add(tree);
            } else {
                ground[ty][tx] -= age;
                tree.age += 1;
            }
        }
    }

    // 봄에 죽은 나무가 양분으로 변한다.
    // 죽은 나무의 나이 / 2의 몫 만큼 양분이 된다.
    public static void summer() {
        for (Tree deadTree : deadTrees) {
            int nurishment = deadTree.age / 2;
            int ty = deadTree.y;
            int tx = deadTree.x;
            ground[ty][tx] += nurishment;
        }
        deadTrees.clear();
    }

    // 나무가 번식한다.
    // 나이가 5의 배수인 나무에게만 해당한다.
    // 인접한 8칸에 나이가 1인 나무가 생긴다.
    public static void fall() {
        List<Tree> newTrees = new ArrayList<>();
        for (Tree tree : trees) {
            if(tree.age % 5 == 0) {
                for(int i=0; i<8; ++i) {
                    int ny = tree.y + dy[i];
                    int nx = tree.x + dx[i];
                    if(ny < 0 || ny >= n || nx < 0 || nx >= n) {
                        continue;
                    }
                    newTrees.add(new Tree(1, ny, nx));
                }
            }
        }
        trees.addAll(newTrees);
        Collections.sort(trees);
    }

    // 상도가 땅에 양분을 뿌린다.
    public static void winter() {
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                ground[i][j] += nurishments[i][j];
            }
        }
    }

    static class Tree implements Comparable<Tree> {
        int age;
        int y, x;
        public Tree(int age, int y, int x) {
            this.age = age;
            this.y = y;
            this.x = x;
        }

        @Override
        public int compareTo(Tree o) {
            if (this.age == o.age) {
                if (this.y == o.y) {
                    return this.x - o.x;
                } else {
                    return this.y - o.y;
                }
            } else {
                return this.age - o.age;
            }
        }
    }
}