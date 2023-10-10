#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE  20
#define SIZE  10
typedef int ElementType;
typedef struct LNode* List;

struct LNode {
	ElementType data[MAXSIZE];
	int last;
};

List makeEmpty();
ElementType findKth(List list, int i);
int find(List list, ElementType X);
bool insert(List list, ElementType X, int i);
bool deleted(List list, int i);
int length(List list);
void printList(List list);

List makeEmpty() {
	List list = (List)malloc(sizeof(struct LNode));
	list->last = -1;
	return list;
}

ElementType findKth(List list, int i) {
	if (i < 1 || i > list->last + 1) {
		return -1; // 处理无效的索引，返回错误值
	}
	else {
		return list->data[i - 1];
	}
}

int find(List list, ElementType X) {
	for (int i = 0; i <= list->last; i++) {
		if (list->data[i] == X) {
			return i + 1; // 索引从 1 开始
		}
	}
	return -1; // 未找到元素
}

bool insert(List list, ElementType X, int i) {
	if (list->last == MAXSIZE - 1 || i < 1 || i > list->last + 2) {
		return false; // 处理溢出或无效的索引
	}

	for (int j = list->last; j >= i - 1; j--) {
		list->data[j + 1] = list->data[j];
	}

	list->data[i - 1] = X;
	list->last++;
	return true;
}

bool deleted(List list, int i) {
	if (i < 1 || i > list->last + 1) {
		return false; // 处理无效的索引
	}

	for (int j = i; j <= list->last; j++) {
		list->data[j - 1] = list->data[j];
	}

	list->last--;
	return true;
}

int length(List list) {
	return list->last + 1;
}

void printList(List list) {
	int i = 0;
	while (i <= list->last) {
		printf("%d ", list->data[i]);
		i++;
	}
	printf("\n");
}

int main(int argc, char* argv[]) {
	int test[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int i;
	List list = makeEmpty();

	// 插入10个整数数据元素
	for (i = 0; i < SIZE; i++) {
		insert(list, test[i], i + 1);
	}

	printf("插入之后的顺序表元素：");
	printList(list);

	printf("顺序表的长度：%d\n", length(list));

	int indexToDelete;
	printf("请输入要删除的序号（从1开始）：");
	scanf("%d", &indexToDelete,1);
	if (deleted(list, indexToDelete)) {
		printf("删除序号之后的顺序表的元素：");
		printList(list);
		printf("顺序表的长度：%d\n", length(list));
	}
	else {
		printf("删除失败，无效的索引 %d\n", indexToDelete);
	}

	int insertIndex;
	int insertValue;
	printf("请输入两个值（第一个为插入值的位置，第二个为插入值的具体值）：");
	scanf("%d %d", &insertIndex, &insertValue,1);
	if (insert(list, insertValue, insertIndex)) {
		printf("插入之后顺序表的元素：");
		printList(list);
	}
	else {
		printf("插入失败，无效的索引 %d\n", insertIndex);
	}

	return 0;
}
