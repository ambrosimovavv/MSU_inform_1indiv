#include <stdio.h>

int main (void)
{
	int sum = 1;
    double prev, next;
    char filename[256];
    FILE *fin;
	printf("input filename ->");
	scanf("%s", filename);
	fin = fopen (filename, "r");
	if (fin == NULL)
	{
		printf("Unable to open the file");
		return -1;
	}
	if (fscanf(fin, "%lf", &prev) != 1) 
	{
		printf("This file is empty");
		return -1;
	}
	while (fscanf(fin, "%lf", &next) != EOF)
	{
		if (next < prev) 
		{
			printf("ERROR! This sequence is not non-descending");
			return -1;
		}
		else if (next != prev) sum++;
		prev = next;
	}
	if (sum != 1) printf("%d\n", sum);
	else printf("ERROR! This is not sequence");
	return 0;
}
