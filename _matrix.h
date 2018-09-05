#ifndef _MATRIX_H
#define _MATRIX_H

#include <stdio.h>
#include <stdlib.h>

class _Matrix
{
public:
	int m;
	int n;
	float *arr;

	//��ʼ��
	_Matrix(int mm = 0, int nn = 0);
	//����m
	void set_m(int mm);
	//����n
	void set_n(int nn);
	//��ʼ��
	void init_matrix();
	//�ͷ�
	void free_matrix();
	//��ȡi,j���������
	//ʧ�ܷ���-31415,�ɹ�����ֵ
	float read(int i, int j);
	//д��i,j���������
	//ʧ�ܷ���-1,�ɹ�����1
	int write(int i, int j, float val);
};

//��ά������
class _Matrix_Calc
{
private:
public:
	_Matrix_Calc();
	//C = A + B
	//�ɹ�����1,ʧ�ܷ���-1
	int add(_Matrix *A, _Matrix *B, _Matrix *C);
	//C = A - B
	//�ɹ�����1,ʧ�ܷ���-1
	int subtract(_Matrix *A, _Matrix *B, _Matrix *C);
	//C = A * B
	//�ɹ�����1,ʧ�ܷ���-1
	int multiply(_Matrix *A, _Matrix *B, _Matrix *C);
	//����ʽ��ֵ,ֻ�ܼ���2 * 2,3 * 3
	//ʧ�ܷ���-31415,�ɹ�����ֵ
	float det(_Matrix *A);
	//��ת�þ���,B = AT
	//�ɹ�����1,ʧ�ܷ���-1
	int transpos(_Matrix *A, _Matrix *B);
	//��ӡ2ά����
	void printff_matrix(_Matrix *A);
	//�������,B = A^(-1)
	//�ɹ�����1,ʧ�ܷ���-1
	int inverse(_Matrix *A, _Matrix *B);
};


#endif