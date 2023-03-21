#include <iostream>

using namespace std;

int main(void) {
	int a = 30;		// a : 30
	int& ra = a;	// ra : a의 주소값(&a)

	ra = 100;		// ra가 가리키고 있는 대상(a) : 100
	cout << "a의 값은 " << a << endl;

	return 0;
}
