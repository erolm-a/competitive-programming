#include <fstream>
#include <vector>

using namespace std;

int main()
{
    int N;
    ifstream in("input.txt");
    ofstream of("output.txt");

    in>>N;

    int V[N];

    for(int i=0;i<N;i++) in>>V[i];
    /*
    bool sale=true;

    int num_continuita = 0, prec= V[0];
    int ris=1;

    for(int i=1;i<N;i++) {
        if(num_continuita == 3) {
            if(sale) {
                while(V[i]>prec) i++;
                sale=false;
            }
            else {
                while(V[i]<prec) i++;
                sale=true;
            }
            num_continuita = 0;
        }

        else {

            ris++;
            if()
        }
    }*/

    if(N <= 2 ) {of << N; return 0;}
    vector<int> taken;
    taken.push_back(V[0]);
    taken.push_back(V[1]);

    for(int i = 2; i < N; i++) {
        if(V[i] > taken.back() && taken.back() > taken[taken.size()-2]) taken.back() = V[i];
        else if(V[i] < taken.back() && taken.back() < taken[taken.size()-2]) taken.back() = V[i];
        else taken.push_back(V[i]);
    }

    of<<taken.size();
}
