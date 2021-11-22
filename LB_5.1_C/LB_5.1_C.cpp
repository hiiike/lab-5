#include <iostream>

#include "FuzzyNumber_Private.h"
#include "FuzzyNumber_Public.h"
#include "Exception.h"


int main(void) {
	using std::cout;

	FuzzyNumber_Private A1, B1, C1;
	FuzzyNumber_Public A2, B2, C2;

	bool init;
	do
	{
		try
		{
			init = true;
			std::cout << "Private" << endl;
			std::cout << "A" << endl;
			std::cin >> A1;
			std::cout << "\nB\n" << endl;
			std::cin >> B1;
			std::cout << "Public" << endl;
			std::cout << "A" << endl;
			std::cin >> A2;
			std::cout << "\nB\n" << endl;
			std::cin >> B2;
		}
		catch (Exception& e)
		{
			init = false;
			cout << e.what() << endl;
		}
		catch (invalid_argument e)
		{
			init = false;
			cout << e.what() << endl;
		}
		catch (bad_exception& e)
		{
			init = false;
			cerr << e.what() << endl;
		}
	} while (!init);

	std::cout << "\n\nPrivate\n";

	cout << A1;
	cout << B1;

	C1 = A1 - B1;

	cout << "\n\nA1 - B1: ";
	cout << C1;
	cout << C1.operator std::string();

	C1 = A1 / B1;
	cout << "\n\nA1 / B1: ";
	cout << C1;
	cout << C1.operator std::string();

	FuzzyNumber_Private K;
	K = FuzzyNumber_Private::Function(A1, B1);
	cout << endl << "1 / A: " << endl << "(" << K.GetX() << ";" << K.GetL() << ";" << K.GetR() << ")" << endl << endl;

	std::cout << "\n\nPublic\n";

	cout << A2;
	cout << B2;

	C2 = A2 - B2;

	cout << "\n\nA1 - B1: ";
	cout << C2;
	cout << C2.operator std::string();

	C2 = A2 / B2;
	cout << "\n\nA1 / B1: ";
	cout << C2;
	cout << C2.operator std::string();

	FuzzyNumber_Public G;
	G = FuzzyNumber_Public::Function(A2, B2);
	cout << endl << "1 / A: " << endl << "(" << G.GetX() << ";" << G.GetL() << ";" << G.GetR() << ")" << endl << endl;

	return 0;
}
