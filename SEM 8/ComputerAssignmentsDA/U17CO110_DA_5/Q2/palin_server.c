/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "palin.h"

int *plain_1_svc(str *argp, struct svc_req *rqstp)
{
	static int result;

	printf("Check Palindrome function was called\n");
	result = 1;
	int len = 0;
	for (int i = 0; i < argp->arr[i] != '\0'; i++)
	{
		len++;
	}
	for (int i = 0; i < len / 2; i++)
	{
		if (argp->arr[i] != argp->arr[len - i - 1])
		{
			result = 0;
			break;
		}
	}
	return &result;
}
