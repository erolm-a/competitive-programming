#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    FILE* fin = fopen("input.txt", "r");
    FILE* fout = fopen("output.txt", "w");
    int N, M, R[101], W[2001], where[2001], sum = 0;
    int query[4000];

    queue<int> waiting;
    priority_queue<int, vector<int>, std::greater<int>> parkings;
    fscanf(fin, "%d %d", &N, &M);
    for(int i = 1; i <= N; i++) {
        parkings.push(i);
        fscanf(fin, "%d", R + i);
    }
    for(int i = 1; i <= M; i++)
        fscanf(fin, "%d", W + i);

    for(int i = 0; i < 2 * M; i++)
        fscanf(fin, "%d", query + i);

    for(int i = 0; i < 2 * M; i++) {
        int arrived = query[i];
        if(arrived>0)
            if(parkings.size() == 0)
                waiting.push(arrived);
            else {
                where[arrived] = parkings.top();
                sum += (R[parkings.top()] * W[arrived]);
                parkings.pop();
            }
        else {
            parkings.push(where[-arrived]);
            while(waiting.size() && parkings.size()) {
                where[waiting.front()] = parkings.top();
                sum += (R[parkings.top()] * W[waiting.front()]);
                parkings.pop();
                waiting.pop();
            }
        }
    }
    fprintf(fout, "%d\n", sum);
    return 0;
}
