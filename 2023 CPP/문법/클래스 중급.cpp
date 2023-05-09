#include <iostream>
#include <string.h>

using namespace std;

class MString {
public:
	// 일반생성자
	MString(const char* str)	// str은 "I will be back"의 주소값을 가리키는 중
	{
		unsigned int l = strlen(str);
		c_str_ = new char[l+1];			// '\0'(널문자)가 들어갈 공간 +1
		strcpy(c_str_, str);		// c_str을 str로 복사
		size_ = l;
		cout << "MString 생성자 호출 완료" << endl;
	}

	// 복수생성자(별도의 정의가 없으면 컴파일러가 알아서 만들어 줌)
	MString(const MString& rhs)
		: c_str_(rhs.c_str_), size_(rhs.size_)
	{
	}

	// 소멸자(destructor) : 객체가 사라질때 호출되는 함수
	~MString()
	{
		// 소멸자로 생성자에서 동적할당한 메모리 해제
		// 소멸자는 매개변수를 갖지 않는다
		delete[] c_str_;
		cout << "MString 소멸자 호출 완료" << endl;
	}
	unsigned int size(void) { return size_; }
	char* c_str(void) { return c_str_; }
private:
	unsigned int size_;		// 문자열의 길이
	char* c_str_;		// 문자열의 시작주소
};

int main(void)
{
	// 일반 생성자 호출
	MString str = MString("I will be back");

	// 복사생성자 호출
	MString str2 = str;

	return 0;
}