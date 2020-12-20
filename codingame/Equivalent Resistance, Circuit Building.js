/*
    열린 괄호와 닫힌 괄호를 기준으로 삼는다.

    괄호가 열리면, 괄호의 타입에 따라 직렬 혹은 병렬 계산방법을 정할 수 있다.
    직렬일 경우 피연산자들을 누적 덧셈하면 되고, 병렬일 경우 피연산자들의 역수를 누적 덧셈 후, 누적 덧셈값의 역수를 취하면 된다.
  
    이 문제에서는 괄호 안에 괄호식이 등장할 경우가 있을 수 있다. 이 상황을 해결하기 위해 calc 함수를 이용했다.
    calc 함수는 열린 괄호를 만나면 호출되며, 해당 괄호와 같은 모양의 닫힌 괄호를 최초로 만날 때까지 내부의 피연산자들을 모두 덧셈한다.
    아래 예시를 통해 조금 더 자세히 설명해보겠다.
    [ A (A B) B]
    
    calc(0)가 호출되고, 첫 번째로 열린 괄호 '[' 를 만나게 된다. 이 때 괄호의 모양을 판단하고, 피연산자들을 병렬 계산하기 위한 준비를 한다.
    피연산자 A 역수를 누적 덧셈하고, 다음 피연산자를 탐색할 때 열린 괄호를 만나게 된다.
    이 때 calc 함수를 재귀 호출한다. 현재 인덱스인 2를 함께 넘겨준다. (calc(2) 호출)
    지금 호출된 calc 함수는 열린 괄호의 모양을 확인하고, 직렬 계산을 위한 준비를 한다.
    같은 모양의 닫힌 괄호 ')'를 만날 때 까지 내부의 피연산자 (A, B) 를 모두 덧셈하고, 덧셈 결과와 이 calc 함수에서 어느 인덱스까지
    계산했는지를 객체로 만들어 리턴한다. (res, idx)

    다시 calc(0) 함수로 돌아와서, 리턴된 calc(2)의 결과값 (A B)의 역수를 구해 덧셈한다. 아울러 calc(0)에서는 현재 인덱스가 2인데,
    calc(2)에서 인덱스 5까지 계산했으므로 이 만큼을 건너뛰어 주어야 한다. (중복 계산 방지)
    
    이어서 마지막 피연산자 B의 역수를 덧셈하면, 다음 요소가 닫힌 괄호 ']' 이므로 계산을 종료하고 리턴한다.
*/


const resist = {};
const N = parseInt(readline());
for (let i = 0; i < N; i++) {
    var inputs = readline().split(' ');
    const name = inputs[0];
    const R = parseFloat(inputs[1]);
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
