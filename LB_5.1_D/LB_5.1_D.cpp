#include <iostream>
#include "FuzzyNumber_Public.h"
#include "Exception.h"


int main(void) 
{
	using std::cout;

	FuzzyNumber_Public A2, B2, C2;

	bool init;
	do
	{
		try
		{
			init = true;
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

	cout << "\nA > B" << endl;
	if (A2 > B2) cout << "Yes" << endl; else cout << "No" << endl;

	cout << "\nA < B" << endl;
	if (A2 < B2) cout << "Yes" << endl; else cout << "No" << endl;

	cout << "\nA == B" << endl;
	if (A2 == B2) cout << "Yes" << endl; else cout << "No" << endl;

	return 0;
}
