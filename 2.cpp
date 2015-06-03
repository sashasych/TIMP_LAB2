#include "stdafx.h"

double mediana(unsigned __int8 *MasQuick, int size)
{
	unsigned int max, min;
	max = min = MasQuick[0];
	for (int i = 1; i < size; i++)
	{
		if (max < MasQuick[i])
			max = MasQuick[i];
		if (min > MasQuick[i])
			min = MasQuick[i];
	}
	
	return ((double)max + (double)min) / 2.0;
}
void quicksort(unsigned __int8 *Mas, int size)
{


	int i, r, j, swap;
	float x;
	if (size > 1) 
	{
		i = 0; r = size - 1;
		x = mediana(Mas, size);
		while (i < r)
		{
			while (Mas[i] <= x) i++;
			while (Mas[r] >= x) r--;
			if (i < r)
			{
				swap = Mas[r];
				Mas[r] = Mas[i];
				Mas[i] = swap;
			}
		}
		if (i <= r){
			quicksort(Mas, i);
			quicksort(Mas + i, size - i);
		}
	}
}

void main()
{
	unsigned __int8 *p;
	unsigned int n;
	int i;
	scanf_s("%d", &n);
	p = (unsigned __int8 *)malloc(n*sizeof(unsigned __int8));
	for (i = 0; i<n; i++)
		scanf_s("%d", &p[i]);
	quicksort(p, n);
	for (i = 0; i < n; i++)
		printf("%d ", p[i]);
	_getch();
}
