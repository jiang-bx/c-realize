#include <stdio.h>
#include "header.h"

void printRose()
{
	printf(" {@}\n");
	printf("  |\n");
	printf(" \\|/\n");
	printf("  |\n");
}

void printRoses(int value)
{
	for (int i = 0; i < value; i++)
	{
		printRose();
	}
}

int getNum(int num);

int main(int argc, const char * argv[])
{
	printRoses(5);
	getNum(3);

	printf("argc = %i\n", argc);
	printf("argv = %s\n", argv[0]);
	printf("argv = %s\n", argv[1]);
	printf("a = %i\n", test(21));

	return 0;
}

int getNum(int num)
{
	return num;
}