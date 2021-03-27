#include <iostream>
using namespace std;

long long solution(int w,int h) {
    long long answer;
    
    if(w > h) {
        w ^= h; h ^= w; w ^= h;
    }

    long long dw=w, dh=h;
    int div=2;
    while(div <= dw) {
        if(dw % div == 0 && dh % div == 0) {
            dw /= div; dh /= div;
        } else
            ++div;
    }
    
    int p = w / dw;
    long long cut = p * (dh + dw - 1);
    // if(w % dw != 0)
    //     cut += (dh + dw);

    answer = (long long)h * w - cut;

    return answer;
}

int main(void) {
    int a,b;
    cin >> a >> b;
    cout << solution(a,b);
}