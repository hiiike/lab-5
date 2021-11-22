#include "Pair.h"
#include "Complex_Public.h"
#include "Complex_Private.h"
#include "Exception.h"

int main()
{
	Complex_Public pair_1(1, 1), pair_2(1, 1);
	Pair pair1, pair2, k;

	bool init;

	do
	{
		try
		{
			init = true;
			cout << " pair (a,b) - ?"; cin >> pair1;
			cout << " pair (c,d) - ?"; cin >> pair2;
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

	cout << " ( a , b )";
	cout << pair1;

	cout << " ( c , d )";
	cout << pair2;

	Pair a = pair1 + pair2;
	cout << "(a, b) + (c, d) = (a + c), (b + d)";
	cout << a;

	cout << endl << "Private" << endl;
	Complex_Private p;
	p.Init(k);
	p.Display(pair1, pair2);

	cout << endl << "Public" << endl;
	Complex_Public g;
	g.Init(k);
	g.Display(pair1, pair2);
	return 0;
}
