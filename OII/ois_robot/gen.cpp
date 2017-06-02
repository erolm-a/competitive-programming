#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

constexpr auto LIMIT = 10;
int main(int argc, char** argv)
{
	ofstream file_gen("input.txt");
	srand((unsigned) time(NULL));


	int M, N;
	enum modo {
		XOPLUS,
		LR,
		LRPLUS,
		LRPLUS2,
		ALL
	} mode;

	if(argc == 4)
		mode = static_cast<modo>(atoi(argv[1])), N = atoi(argv[2]), M = atoi(argv[3]);
	else if(argc == 2)
		mode = static_cast<modo>(atoi(argv[1])), N = rand() % LIMIT + 1, M = rand() % LIMIT + 1;
	else {
		cout << "Uso: " << argv[0] << " modalità [N M]" << endl;
		return 1;
	}

	char utilizzabili[5];
	int m;
	switch(mode)
	{
		case XOPLUS:
			utilizzabili[0] = 'X';
			utilizzabili[1] = 'O';
			utilizzabili[2] = '+';
			m = 3;
			break;
		case LR:
			utilizzabili[0] = 'R';
			utilizzabili[1] = 'L';
			m = 2;
			break;
		case LRPLUS:
			utilizzabili[0] = 'R';
			utilizzabili[1] = 'L';
			utilizzabili[2] = '+';
			m = 3;
			break;
		case LRPLUS2:
			utilizzabili[0] = 'R';
			utilizzabili[1] = 'L';
			utilizzabili[2] = '+';
			utilizzabili[3] = 'O';
			m = 4;
			break;
		default:
		case ALL:
			utilizzabili[0] = 'R';
			utilizzabili[1] = 'L';
			utilizzabili[2] = '+';
			utilizzabili[3] = 'O';
			utilizzabili[4] = 'X';
			m = 5;
			break;
	}

	file_gen << N << ' ' << M << endl;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++)
			file_gen << utilizzabili[rand() % m];

		file_gen << endl;
	}
		
}
