#include <iostream>

using namespace std;

int main(void)
{
	int arr[4] = { 1, 2, 3, 4 };

	// 누가봐도 a의 자료형은 int이다
	auto a = 4;

	// x의 자료형은 int로 자동설정
	for (auto x : arr) {
		cout << x << endl;
	}

	return 0;
}