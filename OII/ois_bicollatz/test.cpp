#include <iostream>
#include <fstream>
#include <cstdlib>

int main()
{
	srand((unsigned) time(NULL));
	std::cout << "Prova con i dati in input: ";
	std::ofstream test_input("input.txt");
	int A = rand() % 1000000;
	int B = rand() % 1000000;

	std::cout << "A: " << A << "; B: " << B << std::endl;

	test_input << A << ' ' << B << std::endl;

	system("/usr/bin/time ./bicollatz");

	return 0;
}
