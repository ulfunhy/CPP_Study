#include <iostream>
#include <string.h>

int main(void) {
	std::string str1;
	std::string str2 = "Jiwo";

	//str1에 str2의 내용을 집어넣는나
	str1 = str2;

	std::cout << str1 << std::endl;

	return 0;
}