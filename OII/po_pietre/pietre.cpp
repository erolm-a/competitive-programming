#include <algorithm>

using namespace std;
int Confronta(int a, int b);

int sub_trova(int begin1, int sz1, int begin2, int sz2, int G)
{
    if(sz1 > sz2) {
        swap(begin1, begin2);
        swap(sz1, sz2);
    }
    if(sz1 == 0)
        return begin2 + G - 1;
    if(G <= 1)
        return Confronta(begin1, begin2) ? begin2 : begin1;

    int mid1 = min(sz1, G/2), mid2 = min(sz2, G/2);

    if(Confronta(begin1 + mid1 - 1, begin2 + mid2 - 1) == 0)
        // è più grande il secondo... allora devo escludere begin1 + mid1
        // dunque, se mid1 == 0, allora devo togliere solo un elemento
        // se mid1 == 1, allora devo togliere 2 elementi (quello estremo
        return sub_trova(begin1 + mid1, sz1 - mid1, begin2, sz2, G - mid1);
    else return sub_trova(begin1, sz1, begin2 + mid2, sz2 - mid2, G - mid2);
}

int Trova(int N, int G)
{
    return sub_trova(1, N, N+1, N, G);
}
