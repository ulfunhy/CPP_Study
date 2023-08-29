#include <iostream>
#include <string.h>

using namespace std;

class Tem {
public:
    Tem(string _name, int _health, int _attack, int _defense)
        : name(_name), health(_health), attack(_attack), defense(_defense) {}

    void print() {
        cout << "이름: " << name << endl;
        cout << "체력: " << health << endl;
        cout << "공격: " << attack << endl;
        cout << "방어: " << defense << endl;
    }

private:
    string name;
    int health;
    int attack;
    int defense;
};

int main() {
    Tem* MyTem = new Tem("이현진", 100, 30, 20);
    MyTem->print();

    delete MyTem;

    return 0;
}