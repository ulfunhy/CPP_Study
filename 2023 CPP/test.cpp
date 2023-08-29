#include <iostream>
#include <string.h>

using namespace std;

class Tem {
public:
    Tem(string _name, int _health, int _attack, int _defense)
        : name(_name), health(_health), attack(_attack), defense(_defense) {}

    void print() {
        cout << "�̸�: " << name << endl;
        cout << "ü��: " << health << endl;
        cout << "����: " << attack << endl;
        cout << "���: " << defense << endl;
    }

private:
    string name;
    int health;
    int attack;
    int defense;
};

int main() {
    Tem* MyTem = new Tem("������", 100, 30, 20);
    MyTem->print();

    delete MyTem;

    return 0;
}