#include <iostream>
#include <string>

using namespace std;

// 여러 data들을 하나의 의미있는 구조체로 묶어서 관리
// 구조체, 클래스는 일반적으로 단어의 첫글자를 대문자로 한다
// 클래스가 디폴트 private (struct는 디폴트가 public)
class Student {
	// 성능때문에 num을 문자열로 하지 않음
	// 일반적으로 문자열은 정수형 데이텁다 많은 메모리 공간을 요구하며
	// 정수는 비교연산을 한번에 할 수 있으나, 문자열은 글자수 만큼 반복하여 비교해야함
public:
	int num;
	string name;
	string tel;
	string department;
	string address;

	// class 멤버 함수를 가질 수 있다
	void print(void)
	{
		cout << "학번 : " << num << endl;
		cout << "이름 : " << name << endl;
		cout << "전화번호 : " << tel << endl;
		cout << "학과 : " << department << endl;
		cout << "주소 : " << address << endl;
	}
};

int main(void) 
{
	// 자료형 : struct Student(C++에서는 pizza만 써도 가능
	Student stu1;
	stu1.num = 2213;
	stu1.name = "이현진";
	stu1.tel = "010-8641-3308";
	stu1.department = "뉴미디어소프트웨어과";
	stu1.address = "경기도 과천시";

	stu1.print();

	return 0;
}