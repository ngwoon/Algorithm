package 카카오_블라인드_채용_2020;

/*
    자물쇠와 열쇠가 2차원 배열로 주어졌을 때, 문제 조건에 맞게 열쇠로 자물쇠를 열 수 있는지를 판단하는 문제.

    <나의 풀이>
    자물쇠의 모든 홈에 열쇠의 돌기를 끼워 맞출 수 있으면 열 수 있다.
    열쇠는 시계방향 90도로 회전할 수 있으므로, 총 4가지의 열쇠 상태 각각 자물쇠와 비교하면 된다.
    나의 경우, 자물쇠를 기존 n*n에서 (n+2*m-2)*(n+2*m-2) 크기로 확장하고, 정가운데에 기존 자물쇠의 상태를 복사하여
    기존 자물쇠와 열쇠가 단 한 칸이라도 겹치는 경우에도 탐색하게끔 했다.
 */

class LockAndKey {

    int n, m;

    public boolean solution(int[][] key, int[][] lock) {

        n = lock.length;
        m = key.length;

        int exsize = n+2*m-2;
        int totalCount = 0;
        int[][] expandedLock = new int[exsize][exsize];
        for(int i=0; i<exsize; ++i) {
            for(int j=0; j<exsize; ++j) {
                if(i >= m && i < m+n && j >= m && j < m+n) {
                    expandedLock[i][j] = lock[i-m][j-m];
                    if(expandedLock[i][j] == 0) {
                        ++totalCount;
                    }
                } else {
                    expandedLock[i][j] = -1;
                }
            }
        }

        for(int i=0; i<4; ++i) {
            key = rotate(key);
            for(int j=0; j<n+m-1; ++j) {
                for(int k=0; k<n+m-1; ++k) {
                    int count = 0;
                    for(int y=0; y<m; ++y) {
                        for(int x=0; x<m; ++x) {
                            if(expandedLock[j+y][k+x] == 1 && key[y][x] == 1) {
                                break;
                            } else if(expandedLock[j+y][k+x] == 0 && key[y][x] == 1) {
                                ++count;
                            }
                        }
                    }
                    if(count == totalCount) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    public int[][] rotate(int[][] key) {

        int[][] rotated = new int[m][m];
        for(int i=0; i<m; ++i) {
            for(int j=0; j<m; ++j) {
                rotated[j][m-1-i] = key[i][j];
            }
        }
        return rotated;
    }
}