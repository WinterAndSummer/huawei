#include "predict.h"
#include "stdio.h"
#include <string.h>
#include <stdlib.h>


int main()
{

	char *data[MAX_DATA_NUM];
	char *info[MAX_INFO_NUM];
	int data_line_num;
	int info_line_num;


	char *data_file = (char*)"dataset.txt";
	printf("%s", data_file);


	data_line_num = read_file(data, MAX_DATA_NUM, data_file);


	printf("data file line num is :%d \n", data_line_num);
	if (data_line_num == 0)
	{
		printf("Please input valid data file.\n");
		return -1;
	}

	char *input_file = (char*)"input.txt";
	printf("%s", input_file);
	info_line_num = read_file(info, MAX_INFO_NUM, input_file);

	printf("input file line num is :%d \n", info_line_num);
	if (info_line_num == 0)
	{
		printf("Please input valid info file.\n");
		return -1;
	}
	int i = 0;
	char *output_file = (char*)"output.txt";
	//system("pause");
	predict_server(info, data, data_line_num, output_file);

	release_buff(info, info_line_num);
	release_buff(data, data_line_num);

	printf("End");
	return 0;
}

