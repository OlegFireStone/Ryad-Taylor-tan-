#include<iostream>
#include<cmath>
using namespace std;
const int  n = 10;
//Ряд Тейлора для тангенса
//tan x = x + (x^3)/3 + (2x^5)/15 + (17x^7)/315 + (62x^9)/2835 + ..., |x| < Pi/2
//f(x) = SUM[k=0;oo] ((f^(k) производная (a))/k!)/(x - a)^k) разложение в окрестности точки a.При a = 0 (ч.с)
class Taylor {
private:
	double a[n];
public:
	double &operator[](int k) {
		return a[k];
	}

	Taylor(int p=0) {
		for (int i = 0; i < n; i++) {
			(*this)[i] = p;
		}
	}

	Taylor(double *b) {
		for (int i = 0; i < n; i++) {
			(*this)[i] = b[i];
		}
	}

	double operator()(double x) {
		double S = 0, q = 1;
		for (int k = 0; k < n; k++) {
			S += (*this)[k] * q;
			q *= x;
		}
		return S;
	}
};


int main() {
	setlocale(0, "rus");
	double b[n] = { 0,1,0,1. / 3,0,2. / 15,0,17. / 315,0,62. / 2835 };
	Taylor Mytan(b);
	cout << Mytan(1) << " - тангенс для X = 1" << endl;
	cout << Mytan[3] << " - 3 элемент поля a[n]" << endl;

	cin.get();
	return 0;
}