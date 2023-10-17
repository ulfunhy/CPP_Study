#include <iostream>

using namespace std;

int main(void)
{
	int arr[4] = { 1, 2, 3, 4 };

	for (int x : arr) {
		cout << x << endl;
	}

	return 0;
}