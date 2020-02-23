#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    2x1 타일과 2x2타일의 "예쁨" 정도를 내림차순으로 우선 정렬한다.
    가능한 한 많은 2x2타일로 정보대 화장실 타일을 채우고, 만약 빈 공간이 있다면 2x1타일로 채운다.
    사용하지 않은 2x1타일 2개로, "예쁨" 정도가 가장 작은 2x2타일을 대체할 수 있는지 반복적으로 확인한다.
    대체할 수 없는 상황은 아래와 같다.
    1. 2x2타일의 예쁨 정도가 2x1 타일 2개의 예쁨 정도보다 큰 경우
    2. 남은 2x1타일이 1개뿐이라 2x2타일을 대체할 수 없는 경우

    위와 같은 상황이 나오면 break 후 tiles배열의 모든 요소를 더한 값을 출력한다.
*/

vector<int> small;
vector<int> big;
vector<int> tiles;

int main(void) {
    int N, A, B;

    cin >> N >> A >> B;

    for(int i=0; i<A; i++) {
        int temp;
        cin >> temp;
        small.push_back(temp);
    }
    for(int i=0; i<B; i++) {
        int temp;
        cin >> temp;
        big.push_back(temp);
    }

    sort(big.begin(), big.end(), greater<int>());
    sort(small.begin(), small.end(), greater<int>());

    int res = N - (B << 1);

    int cIndex; // small 배열의 사용하지 않은 타일 위치 저장
    int bIndex; // tiles배열 내에서 big tile이 사용된 가장 큰 인덱스 저장

    if(res > 0) {
        for(int i=0; i<big.size(); i++)
            tiles.push_back(big[i]);
        
        for(int i=0; i<res; i++)
            tiles.push_back(small[i]);
        
        cIndex = res;
        bIndex = big.size() - 1;
    } else {

        int temp = N;
        
        int i=0;
        while(temp > 1) {
            tiles.push_back(big[i++]);
            temp -= 2;
        }

        bIndex = i - 1;

        if(temp > 0) {
            tiles.push_back(small[0]);

            cIndex = 1;
        } else
            cIndex = 0;
    }

    for(int i=bIndex; i>=0; i--) {
        if(tiles[i] < small[cIndex] + small[cIndex + 1]) {
            tiles[i] = small[cIndex] + small[cIndex + 1];
            cIndex += 2;

            if(cIndex > small.size() - 2)
                break;
        } else
            break;
    }

    int sum = 0;
    for(int i=0; i<tiles.size(); i++)
        sum += tiles[i];

    cout << sum;

    return 0;
}  