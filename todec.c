#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "todec.h"

long todec(char *num, int *base)
{
	int i = 0;
	bool min = false;
	if (num[0] == '-')
	{
		min = true;
		i++;
	}
	if (num[i] == '0' && num[i+1] == 'x')
	{
		*base = 16;
		i += 2;
	}
	else
	{
		if (num[i] == '0' && strlen(num) != 1)
		{
			*base = 8;
			i++;
		}
		else
		{
			*base = 2;
		}
	}

	long result = 0;


	for (i; num[i] != '\0'; i++)
	{
		result *= *base;
		if (*base == 2 && num[i] != '1' && num[i] != '0')
		{
			fprintf(stderr, "Error\n");
			exit(EXIT_FAILURE);
		}
		if (*base == 8 && (num[i] < '0' || num[i] > '7'))
		{
			fprintf(stderr, "Error\n");
			exit(EXIT_FAILURE);
		}
		if (num[i] >= '0' && num[i] <= '9')
		{
			result += num[i] - '0';
		}
		else
		{
			if ((*base == 16) && (tolower(num[i]) >= 'a' && tolower(num[i]) <= 'f'))
			{
				if (tolower(num[i]) >= 'a')
				{
					result += tolower(num[i]) - 'a' + 10;
				}
			}
			else
			{
				fprintf (stderr,"Error\n");
				exit(EXIT_FAILURE);
			}
		}


	}

	if (min)
	{
		return -result;
	}
	else
	{
		return result;
	}

}
