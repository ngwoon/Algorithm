/*
    미로 왼쪽, 오른쪽 법칙 문제

    문제의 핵심은 현재 바라보고 있는 방향의 왼쪽 혹은 오른쪽이 막혀있는가이다.
    막혀있다면 바라보고 있는 방향으로 전진할 수 있고, 그렇지 않다면 그 방향으로 회전해야한다.
    
    따라서 현재 위치에서 우선적으로 확인해야할 방향은 아래와 같다.
        1. 현재 위치의 왼쪽 혹은 오른쪽 (막혀있는지 아닌지)
            만약 막혀있다면 현재 바라보고 있는 방향 그대로 전진 가능. 그렇지 않다면 해당 방향으로 전환
        
        2. 현재 방향의 한 칸 앞
            1번에서 이미 왼쪽 혹은 오른쪽을 확인했으므로, 나올 수 있는 경우의 수는 아래와 같다.
            (side가 L일 경우)
                1) 1번에서 왼쪽이 막혀있어서 방향전환 하지 않았고, 현재 바라보고 있는 방향의 한 칸 앞이 막혀있지 않은 경우
                    이 경우 현재 바라보는 방향으로 한 칸 전진하면 된다.

                2) 1번에서 왼쪽이 막혀있어서 방향전환 하지 않았고, 현재 바라보고 있는 방향의 한 칸 앞이 막혀있는 경우
                    이 경우 자신의 왼쪽과 정면이 막혀있으므로, 현재 방향의 우측으로 회전해야 한다.

                3) 1번에서 왼쪽이 막혀있지 않아 방향전환 했고, 현재 바라보고 있는 방향의 한 칸 앞이 막혀있지 않은 경우 (당연한 경우)
                    이 경우 1번에서 전환한 방향(현재 바라보는 방향) 으로 한 칸 전진하면 된다.

                4) 1번에서 왼쪽이 막혀있지 않아 방향전환 했고, 현재 바라보고 있는 방향의 한 칸 앞이 막혀있는 경우 (불가능한 경우)
                    이미 1번에서 왼쪽이 막혀있지 않아서 방향전환 했는데, 현재 바라보고 있는 방향 한 칸 앞이 막혀있을 수 없다.
                    즉, 고려하지 않아도 되는 경우

    * 주의점
        한 칸 앞으로 전진할 때만 해당 cell의 접근 수를 1 증가시켜야 함을 주의해야한다.
        4방위가 전부 막혀있을 수 있으므로, count 변수를 이용하여 4방위를 전부 확인했는데도 전진하지 못하면 반복문을 끝내야 한다.


    
    2차원배열을 이용한 방위 문제에 쓰이는 테크닉이 몇 가지 존재한다.
        1. dy, dx 배열 이용
            이 문제와 같이 동, 서, 남, 북 방위의 전환이 있는 문제는 시계방향(북, 동, 남, 서) 혹은 반시계방향(북, 서, 남, 동) 으로 방위를 설정해둔다.
            시계방향으로 방위를 설정했을 때를 예로 들면, dir 변수를 두어 nextY = currentY + dy[dir], nextX = currentX + dx[dir]와 같은 식으로
            쉽게 방위에 따른 좌표 이동이 가능하다.
            
        2. dir 변수
            이 문제처럼 방향 전환이 고정되어 있다면, dir = (dir + 1) % 4와 같은 식으로 쉽게 방위 전환이 가능하다.
            
        3. 다음 좌표 유효한지 검사
            다음 좌표가 ny, nx라고 할 때, ny < 0 || ny >= height || nx < 0 || nx >= width || map[ny][nx] === "#" 와 같은 조건식으로
            다음 좌표가 맵의 바깥으로 벗어나는지, 혹은 맵 안의 벽과 충돌하는지 검사할 수 있다.
*/

// 북, 동, 남, 서
const dx = [0,1,0,-1];
const dy = [-1,0,1,0];

let inputs, width, height;
let map, result;
let sx, sy;
let side;

function move() {
    let cy = sy, cx = sx;
    let dir, checkDir; // checkDir은 side에 따른 왼쪽 혹은 오른쪽을 확인하기 위한 변수
    let startPoint = true; // while문 진입하자마자 break 되는 것을 방지하기 위한 flag

    switch(map[sy][sx]) {
        case "^": dir = 0; break;
        case ">": dir = 1; break;
        case "v": dir = 2; break;
        case "<": dir = 3; break;
    }

    while(true) {

        if(!startPoint && cy === sy && cx === sx)
            break;

        checkDir = (side === "L") ? (dir + 3) % 4 : (dir + 1) % 4;
        let ty = cy + dy[checkDir];
        let tx = cx + dx[checkDir];

        // 현재 바라보고 있는 방향의 왼쪽 혹은 오른쪽이 막혀있는지 확인
				// 막혀있지 않다면 그쪽으로 방향전환
        if(!(ty < 0 || ty >= height || tx < 0 || tx >= width || map[ty][tx] === "#"))
            dir = checkDir;

				// 현재 바라보고 있는 방향 한 칸 앞 좌표
        let ny = cy + dy[dir]; 
        let nx = cx + dx[dir];
				
				// 4방위가 전부 막힌 경우를 체크하기 위한 변수
        let cnt=0;
        while(ny < 0 || ny >= height || nx < 0 || nx >= width || map[ny][nx] === "#") {
            dir = (side === "L") ? (dir + 1) % 4 : (dir + 3) % 4;
            ny = cy + dy[dir];
            nx = cx + dx[dir];

            if(++cnt === 4)
                return;
        }

        cy = ny; cx = nx;
        ++result[cy][cx];
        startPoint = false;
    }
}


function init() {

    inputs = readline().split(' ');
    width = parseInt(inputs[0]);
    height = parseInt(inputs[1]);
    map = new Array(height);
    
    for (let i=0; i < height; ++i) {
        const line = readline();
        for(let j=0; j < width; ++j) {
            const cell = line[j];
            if(cell !== "0" && cell !== "#") {
                sy = i; sx = j;
                break;
            }
        }
        map[i] = line;
    }
    side = readline();

    result = new Array(height);
    for(let i=0; i<height; ++i)
        result[i] = new Array(width);

    for(let i=0; i<height; ++i) {
        for(let j=0; j<width; ++j) {
            const cell = map[i][j];
            if(cell === "#")
                result[i][j] = "#";
            else
                result[i][j] = 0;
        }
    }

    move();

    result.forEach((row) => {
        console.log(row.join(''));
    });
    console.log(result);
}


init();