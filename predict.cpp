#include "predict.h"
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

int FlavorInFo[15][2] =
{
	1, 1, 1, 2, 1, 4, 2, 2, 2, 4, 2, 8, 4, 4, 4, 8, 4, 16, 8, 8, 8, 16, 8, 32, 16, 16, 16, 32, 16, 64
};
//��Ҫ��ɵĹ��������
void predict_server(char * info[MAX_INFO_NUM], char * data[MAX_DATA_NUM], int data_num, char * filename)
{
	//���������ļ�������
	//��һ�з������Ĳ���
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
	////�ڶ��п���

	////������

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
	////������Ĺ����

	//vector<int> InFoFlavoer;//������Ϣ�Ĺ��

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
	////��һ��

	////�ж���CUP����MEM
	//int CpuOrMem = 0;//0����cpu��1����mem
	//if (*(info[flavorNum + 4]) == 'C')
	//{
	//	CpuOrMem = 0;
	//}
	//else if (*(info[flavorNum + 4]) == 'M')
	//{
	//	CpuOrMem = 1;
	//}



	// ��Ҫ���������
	char * result_file = (char *)"17\n\n0 8 0 20";

	// ֱ�ӵ�������ļ��ķ��������ָ���ļ���(ps��ע���ʽ����ȷ�ԣ�����н⣬��һ��ֻ��һ�����ݣ��ڶ���Ϊ�գ������п�ʼ���Ǿ�������ݣ�����֮����һ���ո�ָ���)
	write_result(result_file, filename);
}
