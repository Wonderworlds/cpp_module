#include <iostream>
#include <iomanip>
#include <Array.hpp>
#include <ctime>
#include <cstdlib>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define STOPC "\033[0m"

#define PRINT(A) std::cout << A << std::endl

#define TITLE(A) PRINT(std::endl               \
					   << std::setw(30)        \
					   << YELLOW << A << STOPC \
					   << std::endl)

#ifdef DEBUG
#define DEBUG_LOG(A) PRINT(A)
#else
#define DEBUG_LOG(A)
#endif

#define MAX_VAL 750
int main(int, char **)
{
	TITLE("Constructor parametric");
	Array<int> numbers(MAX_VAL);
	PRINT(GREEN "OK" STOPC);
	int *mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	// SCOPE
	TITLE("Constructor copy and assignement");
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
		for (int i = 0; i < MAX_VAL / 10; i++)
		{
			DEBUG_LOG("tmp: " << std::setw(10) << tmp[i] << " | " << numbers[i] << "\t:numbers | " << ((numbers[i] == tmp[i]) ? GREEN "OK" STOPC : RED "KO" STOPC));
			if (tmp[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		DEBUG_LOG("");
		for (int i = 0; i < MAX_VAL / 10; i++)
		{
			DEBUG_LOG("test: " << std::setw(10) << test[i] << " | " << numbers[i] << "\t:numbers | " << ((numbers[i] == test[i]) ? GREEN "OK" STOPC : RED "KO" STOPC));
			if (test[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		PRINT(GREEN "OK" STOPC);
	}

	TITLE("CHECK MIRROR == NUMBERS");
	for (int i = 0; i < MAX_VAL; i++)
	{
		DEBUG_LOG("mirror: " << std::setw(10) << mirror[i] << " | " << numbers[i] << "\t:numbers | " << ((numbers[i] == mirror[i]) ? GREEN "OK" STOPC : RED "KO" STOPC));
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	PRINT(GREEN "OK" STOPC);
	TITLE("CHECK index ==-2");
	try
	{
		numbers[-2] = 0;
		PRINT(RED "KO" STOPC);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
		PRINT(GREEN "OK" STOPC);
	}
	try
	{
		numbers[MAX_VAL] = 0;
		PRINT(RED "KO" STOPC);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
		PRINT(GREEN "OK" STOPC);
	}

	TITLE("LEAKS");
	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete[] mirror; //
	return 0;
}