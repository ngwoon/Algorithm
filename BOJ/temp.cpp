// #include <bits/stdc++.h>
// using namespace std;

// int main(void)
// {
// 	int T, test_case;
	
// 	setbuf(stdout, NULL);

// 	scanf("%d", &T);
// 	for(test_case = 0; test_case < T; test_case++)
// 	{
//         int n;
//         scanf("%d", &n);

//         vector<int> a(n), b(n);

//         for(int i=0; i<n; ++i)
//             scanf("%d", &a[i]);

//         for(int i=0; i<n; ++i)
//             scanf("%d", &b[i]);
        
//         sort(a.begin(), a.end());
//         sort(b.begin(), b.end());

//         int maxGap=0, sum=0, lastClose=-1;
//         for(int i=0; i<n; ++i) {
//             auto iter = lower_bound(a.begin(), a.end(), b[i]);
//             if(iter == a.end()) {
//                 --iter;
//             } else if(iter == a.begin()) {

//             } else {

//             }
//         }

//         sum -= maxGap;

// 		printf("Case #%d\n", test_case+1);
//         printf("%d\n", sum);
// 	}

// 	return 0;//Your program should return 0 on normal termination.
// }


/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <bits/stdc++.h>
using namespace std;

long long init(vector<long long>& cost, vector<long long>& tree, int start, int end, int idx) {
    if(start == end)
        return tree[idx] = cost[start];
    
    int mid = (start + end) / 2;

    return tree[idx] = init(cost, tree, start, mid, idx*2) + init(cost, tree, mid+1, end, idx*2+1);
}

long long getPsum(vector<long long>& tree, int start, int end, int nodeIdx, int left, int right) {
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[nodeIdx];
    int mid = (start + end) / 2;
    return getPsum(tree, start, mid, nodeIdx*2, left, right) + getPsum(tree, mid+1, end, nodeIdx*2+1, left, right);
}

void update(vector<long long>& tree, int start, int end, int nodeIdx, int chIdx, int chVal) {
    if(chIdx < start || chIdx > end) return;

    tree[nodeIdx] += chVal;
    
    if(start == end) return;
    int mid = (start + end) / 2;
    update(tree, start, mid, nodeIdx*2, chIdx, chVal);
    update(tree, mid+1, end, nodeIdx*2+1, chIdx, chVal);
}

int main(void)
{
	int T, test_case;
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
        int n,k,q;
        scanf("%d %d %d", &n, &k, &q);

        vector<long long> cost(n+1);
        for(int i=1; i<=n; ++i)
            scanf("%lld", &cost[i]);

        vector<long long> tree(n*4, 0);
        init(cost, tree, 1, n, 1);

        int psumSize = n-k+1;
        string ans;
        for(int i=-1; i<q; ++i) {
            vector<long long> sums(psumSize);
            if(i != -1) {
                int chIdx, chVal;
                scanf("%d %d", &chIdx, &chVal);
                
                update(tree, 1, n, 1, chIdx, chVal - cost[chIdx]);

                cost[chIdx] = chVal;
            } 

            for(int j=1; j<=psumSize; ++j) {
                if(j == 1)
                    sums[j-1] = getPsum(tree, 1, n, 1, j, j+k-1);
                else
                    sums[j-1] = sums[j-2] - cost[j-1] + cost[j+k-1];
            }

            sort(sums.begin(), sums.end());

            if(sums.size() % 2 == 0) {
                long long f = sums[sums.size()/2];
                long long b = sums[sums.size()/2-1];
                ans.append(to_string(f >= b ? f : b));
            } else
                ans.append(to_string(sums[sums.size()/2]));

            ans.append(" ");
        }

        printf("Case #%d\n", test_case+1);
        printf("%s\n", ans.c_str());
	}

	return 0;//Your program should return 0 on normal termination.
}