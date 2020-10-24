const resist = {};
const N = parseInt(readline());
for (let i = 0; i < N; i++) {
    var inputs = readline().split(' ');
    const name = inputs[0];
    const R = parseFloat(inputs[1]);
    console.error(typeof R);
    resist[name] = R;
}
let circuit = readline().split(" ");

function calc(idx) {
    let dst, res = 0.0;
    if(circuit[idx] === "(") {
        dst = ")";
        idx += 1;
        while(circuit[idx] !== dst) {
            if(resist[circuit[idx]])
                res += resist[circuit[idx]];
            else {
                retObj = calc(idx);
                res += retObj.res;
                idx = retObj.idx;
            }
            ++idx;
        }
    }
    else if(circuit[idx] === "[") {
        dst = "]";
        idx += 1;
        while(circuit[idx] !== dst) {
            if(resist[circuit[idx]])
                res += 1 / resist[circuit[idx]];
            else {
                retObj = calc(idx);
                res += 1 / retObj.res;
                idx = retObj.idx;
            }
            ++idx;
        }
        res = 1 / res;
    }

    return {
        res,
        idx,
    };
}

console.log(calc(0).res.toFixed(1));
