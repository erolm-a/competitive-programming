#include <iostream>
#include <algorithm>

using namespace std;

void mergesort(int* begin, int* end);

int main()
{
    int N;
    cout << "Inserisci N: ";
    cin >> N;

    int V[N];
    for(int i = 0; i < N; i++)
        cin >> V[i];

    mergesort(V, V + N);
    for(int i = 0; i < N; i++)
        cout << V[i] << ' ';
    cout << endl;
}

void mergesort(int *begin, int *end)
{
    if(end - begin == 1)
        return;
    else {
        int mid = (end - begin) / 2;
        mergesort(begin, begin + mid);
        mergesort(begin + mid, end);
        inplace_merge(begin, begin + mid, end);
    }
}
