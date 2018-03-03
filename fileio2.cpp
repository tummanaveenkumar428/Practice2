#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *ft;
	char const *name = "abc.txt";
	int ch;
	ft = fopen(name, "r+");
	if (ft == NULL)
	{
		fprintf(stderr, "cannot open target file %s\n", name);
		exit(1);
	}
	while ((ch = fgetc(ft)) != EOF)
	{
		if (ch == 'i')
		{
			fseek(ft, -1, SEEK_CUR);
			fwrite("a",1,1,ft);
			fseek(ft, 0, SEEK_CUR);
		}
	}
	fclose(ft);
	return 0;
}
