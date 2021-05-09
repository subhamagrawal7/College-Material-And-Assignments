#include <stdio.h>
extern void setVal(/*@out@*/ int *x);
extern int getVal(/*@in@*/ int *x);
extern int mysteryVal(int *x);
/*void setVal(int *x) {}
int getVal(int *x)
{
	return 1;
}
int mysteryVal(int *x)
{
	return 1;
}*/
int dumbfunc(/*@out@*/ int *x, int i)
{
	if (i > 3)
		return *x;
	else if (i > 1)
		return getVal(x);
	else if (i == 0)
		return mysteryVal(x);
	else
	{
		setVal(x);
		return *x;
	}
}
int main()
{
	printf("Checking Using possibly undefined storage or returning storage that is not properly defined");
	return 0;
}
