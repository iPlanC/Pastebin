#include <stdio.h>

int main() {
	int i = 0;
	int j = 0;
	int insert = 0;
	int array[6] = {0};
	
	for (i = 0; i < 5; i++) scanf("%d", &array[i]);
	scanf("%d", &insert);
	
	for (i = 0; i < 5; i++) {
		if (array[i] > insert) {
			for (j = 5; j >= i; j--) {
				array[j] = array[j - 1];
			}
			array[i] = insert;
			break;
		}
		if (i == 4) {
			array[5] = insert;
		}
	}
	
	for (i = 0; i < 6; i++) printf("%d ", array[i]);
	return 0;
} 
