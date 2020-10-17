function encode(message, n) {
    // 1차 변환
    let weight=n;
    let weightedMessage = "";
    for(let i=0; i<message.length; ++i) {
        let convertedCharCode = message.charCodeAt(i) + weight;

        // 변환 시 weight값이 커져서 26을 한 번 빼주는 것만으로는 90이하로 만들 수 없을 수도 있음
        while(convertedCharCode > 90)
            convertedCharCode -= 26;
        weightedMessage = weightedMessage.concat(String.fromCharCode(convertedCharCode));
        ++weight;
    }

    for(let i=0; i<3; ++i) {
        let converted = "";
        for(let j=0; j<weightedMessage.length; ++j)
            converted = converted.concat(table[i][weightedMessage[j]]);
        
        weightedMessage = converted;
    }

    return weightedMessage;
}

function decode(message, n) {
    for(let i=2; i>=0; --i) {
        let converted = "";
        for(let j=0; j<message.length; ++j)
            converted = converted.concat(table[i][message[j]]);
            
        message = converted;
    }

    let weight = n;
    let unWeightedMessage = "";
    for(let i=0; i<message.length; ++i) {
        let convertedCharCode = message.charCodeAt(i) - weight;
        while(convertedCharCode < 65)
            convertedCharCode += 26;
        unWeightedMessage = unWeightedMessage.concat(String.fromCharCode(convertedCharCode));
        ++weight;
    }

    return unWeightedMessage;
}

const operation = readline();
const pseudoRandomNumber = parseInt(readline());
const table = [{}, {}, {}];
for (let i = 0; i < 3; i++) {
    const rotor = readline();
    for(let j=0; j<26; ++j) {
        if(operation === "ENCODE")
            table[i][String.fromCharCode(j + 65)] = rotor[j];
        else
            table[i][rotor[j]] = String.fromCharCode(j + 65);
    }
}
const message = readline();

let res;
if(operation === "ENCODE")
    res = encode(message, pseudoRandomNumber);
else
    res = decode(message, pseudoRandomNumber);

console.log(res);
