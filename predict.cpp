#include "predict.h"
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

int FlavorInFo[15][2] =
{
	1, 1, 1, 2, 1, 4, 2, 2, 2, 4, 2, 8, 4, 4, 4, 8, 4, 16, 8, 8, 8, 16, 8, 32, 16, 16, 16, 32, 16, 64
};
//你要完成的功能总入口
void predict_server(char * info[MAX_INFO_NUM], char * data[MAX_DATA_NUM], int data_num, char * filename)
{
	//分析输入文件的内容
	//第一行服务器的参数
	int ServerPosition1 = 0, ServerPosition2 = 0;

	for (int j = 0; j < 70; j++)
	{
		if (*(info[0] + j) == '\t')
		{
			ServerPosition1 = j;
			break;
		}
	}
	
	for (int j = ServerPosition1 + 1; j < 70; j++)
	{
		if (*(info[0] + j) == '\t')
		{
			ServerPosition2 = j;
			break;
		}
	}
	//int ServerNumCPU = 0, ServerNumMEM = 0;
	//int bitValue = 1;
	//for (int NumCUPBit = ServerPosition1 - 1; NumCUPBit >= 0; NumCUPBit--)
	//{
	//	ServerNumCPU += *(info[0] + NumCUPBit)*bitValue;
	//	bitValue = bitValue * 10;
	//}
	//bitValue = 1;
	//for (int NumEMEBit = ServerPosition2 - 1; NumEMEBit >= ServerPosition1 + 1; NumEMEBit--)
	//{
	//	ServerNumMEM += *(info[0] + NumEMEBit)*bitValue;
	//	bitValue = bitValue * 10;
	//}
	//bitValue = 1;
	////第二行空行

	////第三行

	//int flavorNumPosition, flavorNum = 0;
	//for (int j = 0; j < 70; j++)
	//{
	//	if (*(info[2] + j) == '\n')
	//	{
	//		flavorNumPosition = j;
	//		break;
	//	}
	//}

	//for (int NumFlavorBit = flavorNumPosition - 1; NumFlavorBit >= 0; NumFlavorBit--)
	//{
	//	flavorNum += *(info[2] + NumFlavorBit)*bitValue;
	//	bitValue = bitValue * 10;
	//}
	//bitValue = 1;
	////虚拟机的规格行

	//vector<int> InFoFlavoer;//输入信息的规格

	//int flavorPosition1 = 0, flavorPosition2 = 0;
	//for (int i = 0; i < flavorNum; i++)
	//{
	//	for (int j = 0; j < 70; j++)
	//	{
	//		if (*(info[i + 3] + j) == '\t')
	//		{
	//			flavorPosition1 = j;
	//			break;
	//		}
	//	}
	//	for (int j = flavorPosition1 + 1; j < 70; j++)
	//	{
	//		if (*(info[i + 3] + j) == '\t')
	//		{
	//			flavorPosition2 = j;
	//			break;
	//		}
	//	}

	//	int flavorType = 0;

	//	for (int NumFlavorBit = flavorPosition1 - 1; NumFlavorBit >= 6; NumFlavorBit--)
	//	{
	//		flavorType += *(info[i + 3] + NumFlavorBit)*bitValue;
	//		bitValue = bitValue * 10;
	//	}
	//	bitValue = 1;

	//	InFoFlavoer.push_back(flavorType);

	//}
	////空一行

	////判断是CUP或者MEM
	//int CpuOrMem = 0;//0代表cpu，1代表mem
	//if (*(info[flavorNum + 4]) == 'C')
	//{
	//	CpuOrMem = 0;
	//}
	//else if (*(info[flavorNum + 4]) == 'M')
	//{
	//	CpuOrMem = 1;
	//}



	// 需要输出的内容
	char * result_file = (char *)"17\n\n0 8 0 20";

	// 直接调用输出文件的方法输出到指定文件中(ps请注意格式的正确性，如果有解，第一行只有一个数据；第二行为空；第三行开始才是具体的数据，数据之间用一个空格分隔开)
	write_result(result_file, filename);
}
