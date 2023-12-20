#include "tobase.h"

void toBin(long result)
{
	int bin[65], i = 0;
	long temp = result;
	while (temp > 0)
	{
		bin[i++] = temp % 2;
		temp /= 2;
	}
	if (result == 0)
	{
		printf("0");
	}
	else
	{
		for (int k = i - 1; k >= 0; k--)
		{
			printf("%d", bin[k]);
		}
	}
}

void tobase(long result, int base)
{
	bool min = false;
	if (result < 0)
	{
		printf("-");
		result *= -1;
		min = true;
	}
	if (base == 2)
	{
		toBin(result);
	}
	if (base == 8)
	{
		printf("0%lo", result);
	}
	if (base == 16)
	{
		printf("0x%lx", result);
	}
	if (min)
	{
		result *= -1;
	}
	printf("  (%ld)\n", result);
}
