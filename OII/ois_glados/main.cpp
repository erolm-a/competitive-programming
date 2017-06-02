#include <cstdio>

using namespace std;

#define MAX_H 100

char lab[MAX_H][MAX_H], state[MAX_H][MAX_H];
int H, W, r, c;
int direction = 0;

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

#define FREE 0
#define GLUE 1
#define BLOCKED 2
#define CYCLE 3
#define EXIT 4

inline bool wallAtRight() {
    switch(direction) {
        case UP: if(lab[r][c+1] == '#') return true; break;
    case RIGHT: if(lab[r+1][c] == '#') return true; break;
    case DOWN: if(lab[r][c-1] == '#') return true; break;
    case LEFT: if(lab[r-1][c] == '#') return true; break;
    }
    return false;
}

inline int inFront() {
    int new_r = r, new_c = c;
    switch(direction) {
        case UP: new_r--; break;
        case RIGHT: new_c++; break;
        case DOWN: new_r++; break;
        case LEFT: new_c--; break;
    }
    switch(lab[new_r][new_c]) {
        case '.': return FREE;
        case '#': return BLOCKED;
        case '@': return GLUE;
        case 'O': return EXIT;
    }
}

inline void goStraight() {
    switch (direction) {
    case UP: r--;
        break;
    case RIGHT: c++;
        break;
    case DOWN: r++;
        break;
    case LEFT: c--;
        break;
    }
}

const char* walk() {
    while(1) {
        if(state[r][c] & (1 << direction)) return "cycling";
        state[r][c] |= (1 << direction);
        if(wallAtRight()) {
            switch(inFront()) {
                case FREE:
                    goStraight();
                break;
                case GLUE: return "stuck"; break;
                case BLOCKED: state[r][c] |= (1 << direction);
                    direction = (direction + 3) % 4;
                break;
                case EXIT: return "free";
            }
        }
        else {
            direction = (direction + 1) % 4;
            state[r][c] |= (1 << direction);
            if(inFront() == GLUE) return "stuck";
            goStraight();
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d %d %d", &H, &W, &r, &c);
    for(int i = 0; i < H; i++)
        for(int j = 0; j < W; j++)
            scanf(" %c", &lab[i][j]);
    printf("%s\n", walk());

    return 0;
}
