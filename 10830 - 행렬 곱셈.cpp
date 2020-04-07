#include <bits/stdc++.h>
using namespace std;

/*  
    10830번 - 행렬 제곱

    분할 정복 + 거듭제곱의 성질을 이용한 문제
    행렬A를 B번 거듭제곱 할 때, 분할정복을 이용하면 A^B/2 를 2번 계산하게 된다.
    이렇게 중복되는 연산이 있음을 이용하여 해당 연산을 1번만 하고, 그 반환값을 다시 제곱하면 A^B를 구할 수 있다.
*/

#define LIT 1000

int matrix[5][5];
int n;
long long b;

int(*divmul(int(*base)[5], long long indices))[5] {

    if(indices == 1) {
        static int matrix_temp[5][5];
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                matrix_temp[i][j] = matrix[i][j]%LIT;
        return matrix_temp;
    }
    
    static int(*arr)[5];

    arr = divmul(base, indices/2);
    int temp[5][5];
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            temp[i][j] = arr[i][j];

    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            int sum=0;
            for(int k=0; k<n; ++k)
                sum += temp[i][k] * temp[k][j];
            arr[i][j] = sum%LIT;
        }
    }
    
    if(indices%2 == 0) return arr;
    
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            temp[i][j] = arr[i][j];
    
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            int sum=0;
            for(int k=0; k<n; ++k)
                sum += temp[i][k] * matrix[k][j];
            arr[i][j] = sum%LIT;
        }
    }
    return arr;
}

int main(void) {
    scanf("%d %lld", &n, &b);

    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            scanf(" %d", &matrix[i][j]);
    
    int(*arr)[5] = divmul(matrix,b);
    
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}