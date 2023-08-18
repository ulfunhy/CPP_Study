#include <stdlib.h>
#include <time.h>


class Shape {
public:
	Shape(int point, int position)	// ¼±¾ð
		: point_(point), position_(position)
	{
	}

	~Shape() {}

	// getter
	int get_point_count(void) { return point_; }
	int get_position(void) { return position_; }

	// setter	
	void set_point(int val) { point_ = val; }
	void set_position(int val) { position_ = val; }

private:	// ¸â¹ö
	int point_;
	int position_;
};

int main(void)
{
	srand((unsigned int)time(NULL));

	

	return 0;
}