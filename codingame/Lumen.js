const N = parseInt(readline());
const L = parseInt(readline());
const room = [];
const candles = [];
for (let i = 0; i < N; i++) {
    const inputs = readline().split(' ');
    room.push(inputs);
    for (let j = 0; j < N; j++) {
        const cell = inputs[j];
        if(cell === "C")
            candles.push({y: i, x: j});
    }
}

const light = new Array(N);
for(let i=0; i<N; ++i) {
    light[i] = [];
    for(let j=0; j<N; ++j)
        light[i][j] = 0;
}


for(let cpos of candles) {
    let cnt=0;
    do {
        const sy = cpos.y - cnt;
        const ey = cpos.y + cnt;
        const sx = cpos.x - cnt;
        const ex = cpos.x + cnt;

        for(let i=sy; i<=ey; ++i) {
            for(let j=sx; j<=ex; ++j) {
                if(i < 0 || i >= N || j < 0 || j >= N)   
                    continue;
                ++light[i][j];
            }
        }

        ++cnt;
    } while(L !== cnt);
}

let ans=0;
for(let row of light) {
    for(let cell of row) {
        if(cell === 0)
            ++ans;
    }
}

console.log(ans);
