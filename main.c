#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "op.h"
#include "todec.h"
#include "tobase.h"

int main()
{
	int base1 = 0, base2 = 0;
	char znak, *input = NULL, num1[64], num2[64];
	size_t size = 0;
	long a, b, res;

	getline(&input, &size, stdin);

	if (strchr(input, '~') == NULL)
	{
		sscanf(input, "%s %c %s", &num1, &znak, &num2);
		a = todec(num1, &base1);
		b = todec(num2, &base2);

		if (base1 != base2)
		{
			fprintf(stderr, "Error\n");
			exit(EXIT_FAILURE);
		}
		res = op(a, b, znak);
		tobase(res, base1);
	}
	else
	{
		sscanf(input, "%c%s", &znak, &num1);
		a = todec(num1, &base1);
		res = op(a, 0, znak);
		tobase(res, base1);
	}

	free(input);

	return 0;
}
