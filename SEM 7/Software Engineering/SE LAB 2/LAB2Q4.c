#include <stdio.h>

struct Point
{
	int x, y, z;
};

int main()
{
	/*@ unused @*/ struct Point p1 = {.y = 0, .z = 1};
	return 0;
}
