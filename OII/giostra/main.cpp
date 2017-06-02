#include <cstdio>
#include <cctype>
#include <vector>

int main()
{
    vector<bool> A;
    size_t A_size, B_size;

    FILE* fin, *fout;
    fin = fopen("input.txt", "r");
    fout = fopen("output.txt", "w");

    fscanf(fin, "%d %d", &A_size, &B_size);

    A.resize(A_size);
    A[0] = true;
    for(size_t i = 0, count = 1; !A[(i + B_size) % A_size]; i = (i + B_size) % A_size, A[i] = true, count++)
        ;

    //(i + B_size) mod (A_size)
    return 0;

}
