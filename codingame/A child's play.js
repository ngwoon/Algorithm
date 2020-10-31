
/*
    2차원 배열 맵 안에서 좌표의 이동을 추적하는 문제.

    이동 횟수(n)가 2^53 미만이라 BigInt를 사용해야 했다.

    <문제 해석>
    문제를 해석해보면, 장애물을 만나면 현재 방향에서 오른쪽으로 이동한다.
    예를 들어, 북쪽으로 이동하다가 장애물을 만나면 동쪽으로 이동해야하고, 서쪽으로 이동하다가 장애물을 만나면 북쪽으로 이동해야한다.
    만약 오른쪽으로 돌았는데 또 장애물이 있다면 다시 한 번 오른쪽으로 돌아야 한다.

    로봇이 맵을 벗어나지 않게끔 장애물이 주어진다고 했으므로, 좌표를 이동시키면서 맵 밖으로 나가는 경우는 고려하지 않아도 된다.

    이 문제의 포인트는 이동 횟수가 최대 2^53 - 1번이라는 점이다. 단순히 while문으로 좌표를 n번 이동시키면 시간초과가 난다.
    JS에서 BigInt의 범위가 2^53 - 1까지이므로, 우선 n을 입력받을 때 BigInt로 입력받아야 한다.

    만약 로봇이 맵을 이동하다가 시작점에 돌아왔다면, 이 로봇은 동일한 경로를 계속 지나간다는 사실을 알 수 있다.
    로봇이 k번의 이동만에 처음으로 시작점에 돌아왔다고 가정하면, parseInt(n / k) 번 동안 동일한 경로를 반복해서 돌고, 
    n % k 번 째 이동을 마치면 그 좌표가 정답이다.

    이렇게 반복되는 이동 횟수를 일일이 수행하지 않고 건너뛰는 것이 시간초과를 방지하는 방법이다.
*/


// 북 동 남 서 이동 좌표
const dx = [0, 1, 0, -1];
const dy = [-1, 0, 1, 0];
const map = [];

function move(y, x, n) {
    let cy = y;
    let cx = x;
    let cnt = BigInt(0);
    let dir = 0; // 0,1,2,3은 북, 동, 남, 서 방향을 의미한다.
    while(cnt < n) {
        ++cnt;

        // ny, nx = 현재 설정된 방향으로 한 칸 진행한 좌표
        let ny = cy + dy[dir];
        let nx = cx + dx[dir];

        // 좌표 검사. 만약 이동한 좌표가 벽이라면, 그곳으로 이동하지 않고 방향을 오른쪽으로 틀어야한다.
        // dir = (dir + 1) % 4 식으로 방향을 오른쪽으로 전환한다.
        // 전환한 방향에 또 벽이 있을 수 있으므로, 벽이 아닐 때까지 방향을 전환한다.
        // 사방이 벽에 막힌 경우는 없다고 문제에서 제시했으므로, 이 경우는 고려하지 않아도 된다.
        if(map[ny][nx] === '#') {
            while(map[ny][nx] === '#') {
                dir = (dir + 1) % 4;
                ny = cy + dy[dir];
                nx = cx + dx[dir];
            }
        }

        cy = ny; cx = nx;

        // 로봇이 돌다가 시작좌표로 돌아왔다면, 예상되는 반복 이동을 건너뛴다.
        if(cy == y && cx == x) {
            const rest = n % cnt;
            cnt = n - rest;
        }
    }

    return {
        cy,
        cx,
    }
}

function main() {
    var inputs = readline().split(' ');
    const w = parseInt(inputs[0]);
    const h = parseInt(inputs[1]);
    const n = BigInt(readline());
    let y, x;
    for (let i = 0; i < h; i++) {
        const line = readline();
        map.push(line);

        // 시작좌표 기억
        const startIdx = line.indexOf('O');
        if(startIdx !== -1) {
            y = i; x = startIdx;
        }
    }

    const pos = move(y, x, n);
    console.log(pos.cx, pos.cy);
}

main();



