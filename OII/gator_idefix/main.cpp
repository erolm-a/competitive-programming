#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x = 0, y = 0;
    FILE* in = fopen("input.txt", "r");
    FILE* out = fopen("output.txt", "w");

    int N;
    fscanf(in, "%d", &N);
    while(N--)
    {
        int a; char c;
        fscanf(in, "%d %c", &a, &c);
        switch (c) {
        case 'N':
            y += a;
            break;
        case 'S':
            y -= a;
            break;
        case 'E':
            x += a;
            break;
        case 'O':
            x -= a;
            break;
        default:
            break;
        }
    }

    char x_c = x < 0 ? 'E' : 'O';
    char y_c = y < 0 ? 'N' : 'S';
    x = x < 0 ? -x : x;
    y = y < 0 ? -y : y;

    if(x == 0 && y == 0) fprintf(out, "0\n");
    else if(x == 0)
        fprintf(out, "1\n%d %c\n", y, y_c);
    else if(y == 0)
        fprintf(out, "1\n%d %c\n", x, x_c);
    else
        fprintf(out, "2\n%d %c\n%d %c\n", x, x_c, y, y_c);

    fclose(in);
    fclose(out);
}
