#include <iostream>
#include <string>

using namespace std;

class Person {
public:
	Person(string na, int hak) : hakbun(hak), name(na)
	{

	}
	void PrintShow() {
		cout << "�̸� : " << name << endl;
		cout << "�й� : " << hakbun  << endl;
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
		cout << "�б� : " << university << endl;
	}
private:
	string university;
};

int main() {
	Student* st1 = new Student("ȫ�浿", 2018, "�ѱ����б�");
	st1->PrintShow();

	return 0;
}