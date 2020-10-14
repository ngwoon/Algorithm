
const IMP = 1000000;
const N = parseInt(readline());
const dem = new Array(N).fill(IMP);

const wait = [];
for (let i = 0; i < N; i++) {
    var inputs = readline().split(' ');
    const operation = inputs[0];
    const arg1 = inputs[1];
    const arg2 = inputs[2];

    wait.push({
        "operation": operation,
        "arg1": arg1,
        "arg2": arg2,
    });
}

function checkDependency(arg) {
    let trans;
    if(arg[0] === "$") {
        trans = arg.slice(1);
        trans = +trans;
        if(dem[trans] === IMP)
            return {"type": "FAIL", "data": trans};
        else
            return {"type": "SUCCESS", "data": dem[trans]};
    }

    trans = +arg;
    return {"type": "SUCCESS", "data": trans};
}

function calc(idx) {
    const cur = wait[idx];
    const operation = cur.operation;
    const arg1 = cur.arg1;
    const arg2 = cur.arg2;

    if(operation === "VALUE") {
        const res = checkDependency(arg1);
        if(res.type === "SUCCESS")
            dem[idx] = res.data;
        else {
            calc(res.data);
            dem[idx] = dem[res.data];
        }
    } else {
        const res1 = checkDependency(arg1);
        const res2 = checkDependency(arg2);

        if(res1.type === "FAIL") {
            calc(res1.data);
            res1.data = dem[res1.data];
        }
        if(res2.type === "FAIL") {
            calc(res2.data);
            res2.data = dem[res2.data];
        }
        console.error(res1.data, res2.data);
        switch(operation) {
            case "ADD": dem[idx] = res1.data + res2.data; break;
            case "SUB": dem[idx] = res1.data - res2.data; break;
            case "MULT": dem[idx] = res1.data * res2.data; break;
        }
    }
}

for(let i=0; i<N; ++i) {
    if(dem[i] !== IMP)
        continue;
    calc(i);
}

for (let i = 0; i < N; i++) {
    console.log(dem[i] === -0 ? 0 : dem[i]);
}
