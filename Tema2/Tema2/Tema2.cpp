#include <iostream>
using namespace std;


long long Euler_function(long long n) {
	long long rez = n;
	for (long long i = 2; i * i <= n; i++) {
		if (n % i == 0) {  //verif daca i e factor prim al lui n
			while (n % i == 0) {  //daca da, at il eliminam pe el si multiplii lui
				n = n / i;
			}
			rez = rez - rez / i; //formula fct lui Euler
		}
	}
	if (n > 1) {  //verif daca n e prim
		rez -= rez / n;
	}
	return rez;
}


int main()
{
	long long n;
	cout << "n= ";
	cin >> n;
	cout << "Fct lui Euler(" << n << ") = " << Euler_function(n) << endl;
	return 0;
}

