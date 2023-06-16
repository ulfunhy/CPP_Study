#include <iostream>
#include <string>

using namespace std;

class Person {
public:
	Person(string na, int hak) : hakbun(hak), name(na)
	{

	}
	void PrintShow() {
		cout << "이름 : " << name << endl;
		cout << "학번 : " << hakbun  << endl;
	}
private:
	string name;
	int hakbun;
};
class Student : public Person
{
public:
	Student(string name, int hakbun, string uni) : Person(name, hakbun) , university(uni)
	{
	}
	void PrintShow() {
		Person::PrintShow();
		cout << "학교 : " << university << endl;
	}
private:
	string university;
};

int main() {
	Student* st1 = new Student("홍길동", 2018, "한국대학교");
	st1->PrintShow();

	return 0;
}