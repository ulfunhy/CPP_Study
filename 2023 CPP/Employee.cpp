#include <iostream>
#include <string>

using namespace std;

class Employee {
public:
	Employee()
	{
		name_ = "������";
		id_ = 34;
		age_ = 18;
		salary_ = 45.3;
	}

	Employee (string name, int id, int age, double salary)	// ������ �ʱ�ȭ
		: name_(name), id_(id), age_(age), salary_(salary)
	{
	}

	void PrintInfo(void) {
		cout << "�̸� : " << name_ << endl;
		cout << "��� : " << id_ << endl;
		cout << "���� : " << age_ << endl;
		cout << "�޿� : " << salary_ << endl;
	}

	void set_name(string name) { name_ = name; }
	void set_id(int id) { id_ = id; }
	void set_age(int age) { age_ = age; }
	void set_salary(double salary) { salary_ = salary; }

private:

	string name_;
	int id_;
	int age_;
	double salary_;
};

int main(void) {
	Employee* emp1 = new Employee("������", 12, 18, 43.5);

	delete emp1;

	Employee* emp2 = new Employee[2];

	emp2[0].set_name("������");
	emp2[0].set_id(64);
	emp2[0].set_age(59);
	emp2[0].set_salary(14.8);
		
	for (int i = 0; i < 2; i++)
		emp2[i].PrintInfo();
	delete[] emp2;

	return 0;
	
}