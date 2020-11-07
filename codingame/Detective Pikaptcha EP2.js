/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

const dx = [0,1,0,-1];
const dy = [-1,0,1,0];

let inputs, width, height;
let map, result;
let sx, sy;
let side;

function move() {
    let cy = sy, cx = sx;
    let dir, checkDir;
    let startPoint = true;

    switch(map[sy][sx]) {
        case "^": dir = 0; break;
        case ">": dir = 1; break;
        case "v": dir = 2; break;
        case "<": dir = 3; break;
    }

    checkDir = side === "L" ? (dir + 3) % 4 : (dir + 1) % 4;

    while(true) {

        if(!startPoint && cy === sy && cx === sx)
            break;

        checkDir = (side === "L") ? (dir + 3) % 4 : (dir + 1) % 4;
        let ty = cy + dy[checkDir];
        let tx = cx + dx[checkDir];

        if(!(ty < 0 || ty >= height || tx < 0 || tx >= width || map[ty][tx] === "#"))
            dir = checkDir;

        let ny = cy + dy[dir]; 
        let nx = cx + dx[dir];

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