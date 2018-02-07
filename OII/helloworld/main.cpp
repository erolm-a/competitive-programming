#include <cstdio>
#include <cstring>

using namespace std;

char S[1000002];
int main()
{
    int hello = 0;
    scanf("%s", S);
    int n = strlen(S);
    long long count = 0;
    for(int i = 0; i < n-4;) {
        if(strncmp(S+i, "hello", 5)==0) hello++,i+=5;
        else if(strncmp(S+i, "world", 5)==0) count+=hello,i+=5;
        else i++;
    }
    printf("%lld\n", count);
}
