/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "leap.h"

bool_t *leap_1_svc(int *argp, struct svc_req *rqstp)
{
	static bool_t result;

	printf("Function to check leap year was called\n");
	if (*argp % 400 == 0)
	{
		result = TRUE;
	}
	else if (*argp % 100 == 0)
	{
		result = FALSE;
	}
	else if (*argp % 4 == 0)
	{
		result = TRUE;
	}
	else
	{
		result = FALSE;
	}

	return &result;
}
