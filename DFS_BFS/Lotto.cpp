#include <iostream>

using namespace std;

int source[13];

int main(void) {
    
    cin.sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while(1) {
        int K;
        cin >> K;

        if(K == 0)
            break;

        for(int i=0; i<K; i++)
            cin >> source[i];
    
        for(int i=0; i<K - 5; i++) 
            for(int j=i+1; j<K - 4; j++) 
                for(int k=j+1; k<K - 3; k++) 
                    for(int m=k+1; m<K - 2; m++) 
                        for(int n=m+1; n<K - 1; n++) 
                            for(int p=n+1; p<K; p++) 
                                cout << source[i] << " " << source[j] << " " << source[k] << " " << source[m] << " " << source[n] << " " << source[p] << endl;
        
        cout << "\n"; 
    }

    return 0;
}