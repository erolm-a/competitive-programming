#include <bits/stdc++.h>

#define MAX_L 50

using namespace std;

int tc;

char A[MAX_L+1], B[MAX_L+1];

vector<int> counter(26);
set<vector<int>> pattern;

int main()
{
    scanf("%d", &tc);

    for(int t = 1; t <= tc; t++) {
        int l; scanf("%d%s%s", &l, A, B);
        int ris = 0;

        for(int length = 1; length <= l; length++) {
            pattern.clear();
            fill(counter.begin(), counter.end(), 0);
            // compute every substring of A of size [i..i+length-1]
            for(int i = 0; i < l - length+1; i++) {
                if(i == 0)
                    for(int j = 0; j < length; j++)
                        counter[B[j]-'A']++;
                else counter[B[i + length-1]-'A']++;

                pattern.insert(counter);
                counter[B[i]-'A']--;
            }
            fill(counter.begin(), counter.end(), 0);
            for(int i = 0; i < l - length+1; i++) {
                if(i == 0)
                    for(int j = 0; j < length; j++)
                        counter[A[j]-'A']++;
                else counter[A[i + length-1]-'A']++;

                if(pattern.find(counter) != pattern.end())
                    ris++;
                counter[A[i]-'A']--;
            }
        }

        printf("Case #%d: %d\n", t, ris);
    }
}
