#include <bits/stdc++.h>

using namespace std;

unordered_set<string> good_dict, bad_dict;

int B, G, E;

#define MAX_E 1000
#define MAX_S 22
#define DIM MAX_E*MAX_S + 1

char bad_buffer[DIM], good_buffer[DIM];
char email_buffer[MAX_E][DIM];

int good_mails, bad_mails;

int main()
{
    decltype(good_dict)::const_iterator it;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // fast in
    scanf(" %d", &B);
    getchar_unlocked();
    fgets_unlocked(bad_buffer, B*MAX_S, stdin);
    scanf(" %d", &G);
    getchar_unlocked();
    fgets_unlocked(good_buffer, G*MAX_S, stdin);
    scanf(" %d", &E);
    for(int i = 0; i < E; i++) {
        int to_read;
        scanf(" %d", &to_read);
        getchar_unlocked();
        fgets_unlocked(email_buffer[i], to_read*MAX_S, stdin);
    }

    char *s, *reentrant = nullptr;
    const char *d = " \n";
    int flag = 0;
    while((s = strtok_r(flag++ ? nullptr : bad_buffer, d, &reentrant)))
        bad_dict.insert(s);

    reentrant = nullptr;
    flag = 0;
    while((s = strtok_r(flag++ ? nullptr : good_buffer, d, &reentrant)))
        good_dict.insert(s);

    for(int i = 0; i < E; i++) {

        bool bad = false, good = false;
        flag = 0;
        while((s = strtok_r((flag++ ? nullptr : email_buffer[i]), d, &reentrant)) &&
              !(bad && good)) {
#ifndef EVAL
            fprintf(stderr, "Letta la stringa %s\n", s);
#endif
            if(good_dict.find(s) != good_dict.end())
                good = true;
            if(bad_dict.find(s) != bad_dict.end())
                bad = true;
        }
        if(good && !bad) good_mails++;
        else if(bad && !good) bad_mails++;
    }

    printf("%d %d\n", bad_mails, good_mails);
}
