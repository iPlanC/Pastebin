#include <stdio.h>

int main() {
	int i = 0;
	int j = 0;
	int del = 7;
	int insert = 2;
	int array[6] = {1,3,5,7,9,0};

	printf("\n原数组：");
	for (i = 0; i < 5; i++) printf("%d ", array[i]);
	getchar();

	for (i = 0; i < 5; i++) {
		if (array[i] > insert) {
			for (j = 5; j >= i; j--) array[j] = array[j - 1];
			array[i] = insert;
			break;
		}
		if (i == 4) {
			array[5] = insert;
			break;
		}
	}

	printf("\n插入数：%d\n", insert);
	for (i = 0; i < 6; i++) printf("%d ", array[i]);
	getchar();

	for (i = 0; i < 6; i++) {
		if (array[i] == del) {
			for (j = i; j < 5; j++) array[j] = array[j + 1];
		}
	}

	printf("\n删除数：%d\n", del);
	for (i = 0; i < 5; i++) {
		//if (array[i] == insert) continue;
		//取消注释输出插入的数 
		printf("%d ", array[i]);
	}
}
