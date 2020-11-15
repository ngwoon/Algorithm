const MAX_TIME = Math.pow(5, 8) * Math.pow(10, 8);
const times = [];
const robbers = [];
const R = parseInt(readline());
const V = parseInt(readline());

let nextIdx = 0; // 자신이 맡은 금고를 해체한 강도가 맡을 다음 금고의 인덱스를 가리킴.

// 모든 금고의 해체가 끝났는지를 리턴
function allDone() {
    let isDone = true;
    for(let i=0; i<R; ++i) {
        if(robbers[i] !== -1) {
            isDone = false;
            break;
        }
    }
    return isDone;
}

// 현재 각 강도가 맡고있는 인덱스의 금고 중 해체하는데 가장 짧게 걸리는 시간을 리턴한다.
function getMinTime() {
    let minTime = MAX_TIME;
    for(let i=0; i<R; ++i) {
        if(robbers[i] === -1)
            continue;
        if(times[robbers[i]] < minTime)
            minTime = times[robbers[i]];
    }
    return minTime;
}

// 현재 각 강도가 맡고있는 금고의 해체를 진행함.
// R 명의 강도 중 가장 빨리 금고를 해체하는 강도가 들인 시간만큼만 진행하며,
// 해체를 완료한 해당 강도는 다음으로 해체할 금고가 있는지 확인하고 있다면 맡으며, 없다면 아무것도 하지 않게 하기 위해
// -1을 할당한다.
function heistVault(minTime) {
    for(let i=0; i<R; ++i) {
        if(robbers[i] === -1)
            continue;
        
        times[robbers[i]] -= minTime;

        if(times[robbers[i]] === 0) {
            if(nextIdx !== V)
                robbers[i] = nextIdx++;
            else
                robbers[i] = -1;
        }
    }
}

function init() {
    for (let i = 0; i < V; i++) {
        var inputs = readline().split(' ');
        const N = parseInt(inputs[1]);
        const C = parseInt(inputs[0]) - N;
        times.push(Math.pow(5, C) * Math.pow(10, N)); // 각 금고 당 걸리는 시간을 저장하는 배열.
    }
    
    // 각 강도가 맡을 index 초기화
    // 강도 수보다 금고의 수가 적을 경우, 나머지 강도는 아무것도 하지 않아야 한다.
    for(let i=0; i<V && i<R; ++i) {
        robbers.push(i);
        ++nextIdx;
    }
    if(R > V) {
        for(let i=V; i<R; ++i)
            robbers.push(-1);
    }

    // 총 걸린 시간 누적 변수.
    let ans = 0;

    // 작업 시작
    while(!allDone()) {
        const minTime = getMinTime();
        ans += minTime;
        heistVault(minTime);
    }
    console.log(ans);
}

init();

