#include <stdio.h>
#include <stdlib.h>

#define Size 6

typedef struct Table {
	int head[Size];//声明了一个名为head的长度确定的数组
	int length;//记录当前顺序表的长度
} table;

table* initTable() {
    table* t;
	t = (table*)malloc(Size * sizeof(int));//生成顺序表的存储空间
	t->length = 0;
	return t;
}

//插入函数，其中，elem为插入的元素，add为插入到顺序表的位置
table* addTable(table* t, int elem, int add) {
	int i = 0;
	//判断插入本身是否存在问题（如果插入元素位置比整张表的长度+1还大（如果相等，是尾随的情况），
	//或者插入的位置本身不存在，程序作为提示并自动退出）
	if (add > t->length + 1 || add < 1) {
		printf("插入位置有问题");
		return t;
	}
	//做插入操作时，首先需要看顺序表是否有多余的存储空间提供给插入的元素，如果没有，需要申请
	if (t->length == Size) {
		printf("表已满!\n");
		return t;
	}
	//插入操作，需要将从插入位置开始的后续元素，逐个后移
	for (i = t->length - 1; i >= add - 1; i--) {
		t->head[i + 1] = t->head[i];
	}
	//后移完成后，直接将所需插入元素，添加到顺序表的相应位置
	t->head[add - 1] = elem;
	//由于添加了元素，所以长度+1
	t->length++;
	return t;
}

table* deleteTable(table* t, int del) {
	int i = 0;
	if (del < 1 || del > t->length) {
		printf("删除位置不合法");
		return t;
	}
	if (t->length == 0) {
		printf("表内无元素");
		return t;
	}
	for (i = del - 1; i < t->length; i++) t->head[i] = t->head[i + 1];
	t->head[t->length] = 0;
	t->length--;
	return t;
}

int findElem(table* t, int elem) {
	int i = 0;
	for (i = 1; i <= t->length; i++) {
		if (t->head[i] == elem) {
			//printf("%d", i);
			return i;
		}
	}
	return -1;
}

table* replaceElem(table* t, int beforeElem, int afterElem) {
	t->head[findElem(t, beforeElem)] = afterElem;
	return t;
}

//显示当前顺序表中各元素的值
void displayTable(table* t){
	int i = 0; 
	for (i = 0; i < t->length; i++) {
		printf("%d\t", t->head[i]);
	}
	printf("\n");
}

int main() {
	int i = 0;
	table* t1 = initTable();
	for (i = 1; i <= 4; i++) {
		t1->head[i - 1] = i;
		t1->length++;
	}
	printf("原数组:\n");
	displayTable(t1);

	printf("\n在第二个位置插入5:\n");
	addTable(t1, 5, 2);
	displayTable(t1);

	printf("\n删除第一项元素:\n");
	deleteTable(t1, 1);
	displayTable(t1);
	
	printf("\n\n元素3在第 %d 项。\n\n", findElem(t1, 3) + 1);

	printf("\n将元素4替换为7:\n");
	replaceElem(t1, 4, 7);
	displayTable(t1);
	return 0;
}
