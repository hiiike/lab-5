#include "Triad.h"


void Triad::SetFirst(double first) { this->first = first; }
void Triad::SetSecond(double second) { this->second = second; }
void Triad::SetThird(double third) { this->third = third; }

double Triad::GetFirst() const { return first; }
double Triad::GetSecond() const { return second; }
double Triad::GetThird() const { return third; }

Triad::Triad() 
{
	this->first = 0;
	this->second = 0;
	this->third = 0;
}

Triad::Triad(double  f, double s, double c) 
{
	SetFirst(first);
	SetSecond(second);
	SetThird(third);
}

Triad::Triad(Triad& A)
{
	first = A.first;
	second = A.second;
	third = A.third;
}


bool operator > (Triad& A, Triad& B)
{
	return ((A.first > B.first) || (A.first == B.first && A.second > B.second) ||
		(A.first == B.first && A.second == B.second && A.third > B.third));
}
bool operator < (Triad& A, Triad& B)
{
	return ((A.first < B.first) || (A.first == B.first && A.second < B.second) ||
		(A.first == B.first && A.second == B.second && A.third < B.third));
}
bool operator == (Triad& A, Triad& B)
{
	return (A.first == B.first && A.second == B.second && A.third == B.third);
}

