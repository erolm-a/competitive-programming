#include <cstdio>

template<typename Int>
Int readInteger () {
    bool minus = false;
    Int result = 0;
    char ch;
    ch = getchar_unlocked();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar_unlocked();
    }
    if (ch == '-') minus = true; else result = ch-'0';
    while (true) {
        ch = getchar_unlocked();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}

#define readint readInteger<int>

int main()
{
  int N, K=100, S[101], num, promossi=0;

  N = readint();
  while(N--) {
    num = readint();
    while(K > num) S[K--]=promossi;
    S[K]=++promossi;
  }
  while(K>=0) S[K] = promossi, K--;

  for(int i = 0; i <= 100; i++)
    printf("%d ", S[100-i]);

  return 0;
}
