#include <iostream>

using namespace std;

#define MAX_SOMME 44

int main()
{
    int gemma, altri;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d", &gemma, &altri);
    altri--;

    for(int i = 1; i < MAX_SOMME; i++)
    {
        int somme = i*(i+1)/2;
        if(somme + i*altri > gemma) {
            printf("%d\n", gemma - altri*(i-1));
            return 0;
        }
    }
}
