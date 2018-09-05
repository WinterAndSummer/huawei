#include "lib_io.h"

inline void write_file(const bool cover, const char * const buff, const char * const filename)
{
	if (buff == NULL)
		return;

	const char *write_type = cover ? "w" : "a";//1:覆盖写文件，0:追加写文件
	FILE *fp = fopen(filename, write_type);
	if (fp == NULL)
	{
		printf("Fail to open file %s.\n", filename);
		return;
	}
	printf("Open file %s OK.\n", filename);
	fputs(buff, fp);
	fputs("\n", fp);
	fclose(fp);
}

void write_result(const char * const buff, const char * const filename)
{
	// 以覆盖的方式写入
	write_file(1, buff, filename);

}


int read_file(char ** const buff, const unsigned int spec, const char * const filename)
{
	FILE *fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("Fail to open file %s.\n", filename);
		return 0;
	}
	printf("Open file %s OK.\n", filename);

	char line[55000 + 2];
	unsigned int cnt = 0;
	while ((cnt < spec) && !feof(fp))
	{
		line[0] = 0;
		if (fgets(line, 55000 + 2, fp) == NULL)  continue;
		if (line[0] == 0)   continue;
		buff[cnt] = (char *)malloc(55000 + 2);
		strncpy(buff[cnt], line, 55000 + 2 - 1);
		buff[cnt][55000 + 1] = 0;
		cnt++;
	}
	fclose(fp);
	printf("There are %d lines in file %s.\n", cnt, filename);

	return cnt;
}

void release_buff(char ** const buff, const int valid_item_num)
{
	for (int i = 0; i < valid_item_num; i++)
		free(buff[i]);
}