struct sequence{
	int a[100];
};
program FIB_PROG{
	version FIB_VERS{
		sequence fib(int)=1;
	}=1;
}=0x23411000;
