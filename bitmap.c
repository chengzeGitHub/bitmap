#include <stdio.h>
#include <stdlib.h>

#define SHIFT 5
#define MASK 0x1F

/**
 * �������ڵ�bitλΪ1
 *
 * T = O(1)
 *
 */
void set(int n, int *arr)
{
	int index_loc, bit_loc;

	index_loc = n >> SHIFT; // �ȼ���n / 32
	bit_loc = n & MASK;	// �ȼ���n % 32

	arr[index_loc] |= 1 << bit_loc;
}

/**
 * ��ʼ��arr[index_loc]����bitλΪ0
 *
 * T = O(1)
 *
 */
void clr(int n, int *arr)
{
	int index_loc;

	index_loc = n >> SHIFT;

	arr[index_loc] &= 0;
}

/**
 * ����n���ڵ�bitλ�Ƿ�Ϊ1
 *
 * T = O(1)
 *
 */
int test(int n, int *arr)
{
	int i, flag;
    //���� 
	i = 1 << (n & MASK);
	flag = arr[n >> SHIFT] & i;

	return flag;
}

int main(void)
{
	int i, num, space, *arr;

	while (scanf("%d", &num) != EOF) {
		// ȷ����С&&��̬��������
		space = num / 32 + 1;
		arr = (int *)malloc(sizeof(int) * space);

		// ��ʼ��bitλΪ0
		for (i = 0; i <= num; i ++)
			clr(i, arr);

		// ����num�ı���λΪ1
		set(num, arr);
		
		// ����
		if (test(num, arr)) {
			printf("�ɹ���\n");
		} else {
			printf("ʧ��!\n");
		}
	}

	return 0;
}

