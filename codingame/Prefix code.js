const table = {};
const n = parseInt(readline());
for (let i = 0; i < n; i++) {
    var inputs = readline().split(' ');
    const b = inputs[0];
    const c = parseInt(inputs[1]);
    table[b] = String.fromCharCode(c);
}
const s = readline();

function search() {
    let decoded = "";
    let curIdx = 0;
    let done = true;
    while(curIdx < s.length) {
        let found = false;
        for(key of Object.keys(table)) {
            const idx = s.indexOf(key, curIdx);
            if(idx === curIdx) {
                decoded += table[key];
                curIdx += key.length;
                found = true;
                break;
            }
        }
        if(!found) {
            done = false;
            break;
        }
    }
    return done ? decoded : "DECODE FAIL AT INDEX " + curIdx;
}

console.log(search());