#include <iostream>
#include "FuzzyNumber.h"
#include "Exception.h"


int main(void)
{
	using std::cout;

	FuzzyNumber A, B, C, K;

	bool init;
	do
	{
		try
		{
			init = true;
			cin >> A;
			cin >> B;
		}
		catch (bad_exception& e)
		{
			init = false;
			cerr << e.what() << endl;
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
	} while (!init);

	cout << "\nValue A: " << A;
	cout << A.operator std::string();
	cout << endl;
	cout << "\nValue B: " << B;
	cout << B.operator std::string();

	C = A - B;
	cout << "\n\n A - B: ";
	cout << C.operator std::string();

	C = A / B;
	cout << "\n\n A / B: ";
	cout << C.operator std::string();
	cout << endl;

	K = FuzzyNumber::Function(A, B);
	cout << endl << "1 / A: " << endl << "(" << K.GetL() << ";" << K.GetX() << ";" << K.GetR() << ")" << endl << endl;

	return 0;
}


