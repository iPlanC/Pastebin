#include <stdio.h>
#include <stdlib.h>
#define StudentNumber 5

struct Stu {
	char name[20];
	int number;
	int C_Score;
	int Linux_Score;
	int Math_Score;
	int English_Score;
} Student[StudentNumber];

int main() {
	int i = 0;
	for (i = 0; i < StudentNumber; i++) {
		printf("请输入第 %d 位学生的信息：\n", i + 1);
		
		printf("学号:\n");
		scanf("%d", &Student[i].number);
		
		printf("姓名:\n");
		scanf("%s", Student[i].name);
		
		printf("C语言成绩:\n");
		scanf("%d", &Student[i].C_Score);
		
		printf("Linux系统成绩:\n");
		scanf("%d", &Student[i].Linux_Score);
		
		printf("数学成绩:\n");
		scanf("%d", &Student[i].Math_Score);
		
		printf("英语成绩:\n");
		scanf("%d", &Student[i].English_Score);
		
		system("cls");
	}

	printf("学号\t姓名\tC\tLinux\tMath\tEnglish\n");

	for (i = 0; i < StudentNumber; i++) {
		printf("%d\t%s\t%d\t%d\t%d\t%d\n",	Student[i].number,
		       								Student[i].name,
											Student[i].C_Score,
											Student[i].Linux_Score,
											Student[i].Math_Score,
											Student[i].English_Score);
	}

	return 0;
}
