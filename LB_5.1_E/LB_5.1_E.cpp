#include <iostream>
#include "FuzzyNumber.h"
#include "Exception.h"

int main(void)
{
	using std::cout;

	cout << "Number of elements : " << Object::Counter() << endl;

	FuzzyNumber A,
		B,
		C;

	bool init;

	do
	{
		try
		{
			init = true;
			cout << " pair (a,b) - ?"; cin >> A;
			cout << " pair (c,d) - ?"; cin >> B;
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
		catch (const char* str)
		{
			init = false;
			cerr << str << endl;
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

	

	FuzzyNumber K;
	K = FuzzyNumber::Function(A, B);
	cout << endl << "1 / A: " << endl << "(" << K.GetX() << ";" << K.GetL() << ";" << K.GetR() << ")" << endl << endl;

	cout << "Number of elements : " << Object::Counter() << endl;

	return 0;
}

