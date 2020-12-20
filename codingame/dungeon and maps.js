class Queue {
    constructor() {
        this._arr = [];
    }
    enqueue(item) {
        this._arr.push(item);
    }
    dequeue() {
        return this._arr.shift();
    }
    empty() {
        return this._arr.length === 0;
    }
}

function bfs(map) {
    const que = new Queue();
    const visited = new Array(h);
    for(let i=0; i<h; ++i) {
        visited[i] = new Array(w).fill(false);
    }
    que.enqueue({"y": startRow, "x": startCol, "cnt": 0});
    visited[startRow][startCol] = true;

    while(!que.empty()) {
        const cur = que.dequeue();
        const y = cur.y;
        const x = cur.x;
        const cnt = cur.cnt;
    
        if(map[y][x] === 'T')
            return cnt;

        let ny, nx;
        switch(map[y][x]) {
            case '<': ny = y; nx = x-1; break;
            case '>': ny = y; nx = x+1; break;
            case 'v': ny = y+1; nx = x; break;
            case '^': ny = y-1; nx = x; break;
        }

        if(ny < 0 || ny >= h || nx < 0 || nx >= w)
            continue;
        if(map[ny][nx] === '.' || map[ny][nx] === '#')
            continue;
        if(visited[ny][nx])
            continue;
        
        visited[ny][nx] = true;
        que.enqueue({"y": ny, "x": nx, "cnt": cnt + 1});
    }

    return 30;
}

var inputs = readline().split(' ');
const w = parseInt(inputs[0]);
const h = parseInt(inputs[1]);
var inputs = readline().split(' ');
const startRow = parseInt(inputs[0]);
const startCol = parseInt(inputs[1]);
const n = parseInt(readline());

const maps = {};
for (let i = 0; i < n; i++) {
    maps[i] = [];
    for (let j = 0; j < h; j++) {
        const mapRow = readline();
        maps[i].push(mapRow);
    }
}

let shortestLen = 30;
let shortestIdx = -1;
let idx=0;
for(key in maps) {
    const cur = maps[key];
    
    if(cur[startRow][startCol] === '.' || cur[startRow][startCol] === '#')
        continue;
    
    const res = bfs(cur);

    if(shortestLen > res) {
        shortestLen = res;
        shortestIdx = idx;
    }

    ++idx;
}

console.log(shortestIdx === -1 ? "TRAP" : shortestIdx);
