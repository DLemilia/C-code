#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define MAXSIZE  20
#define SIZE  10
#define ERROR -1
typedef int ElementType;
typedef struct LNode * List;


struct LNode {
	ElementType data[MAXSIZE];
	int last;
};

List makeEmpty();
ElementType findKth(List list, int i );
int find(List list, ElementType X );
bool insert(List list, ElementType X, int i);
bool deleted(List list, int i);
int length( List list );
void printfList(List list);

struct LNode * makeEmpty() {
	struct LNode * list;
	list=(struct LNode *)malloc(sizeof(struct LNode));
	list->last=-1;
	return list;
}
//查找顺序表中第i个元素

ElementType findKth(List list, int i ) {
	//TODO
ElementType p=0;
while(p<=list->last&&list->data[p]!=i)
i++;
return p; 
}


//查找某个元素x是否在顺序表里，在的话返回序号，不在返回-1

int find(List list, ElementType x) {
	//TODO
ElementType p=0;
while(p<=list->last&&list->data[p]!=x)
x++;
if(p>list->last)
return ERROR;
else
return p;
}

//在顺序表的第i个位置插入某一个元素X；
bool insert(List list, ElementType x, int i) {
	//TODO
ElementType j;
if(list->last==MAXSIZE-1)
{
	printf("表满");
	return false; 
}
if(i<1||i>list->last+2)
{
	printf("位序不合法");
	return false; 
}
for(j=list->last;j>=i-1;j--)
	list->data[j+1]=list->data[j];
	list->data[i-1]=x;
	list->last++;
	return true;
}
//删除顺序表中第i个元素
bool deleted(List list, int  i) {
	//TODO
ElementType j;
if(i<1||i>list->last+1)
{
printf("位序%d不存在元素",i);
return false;	
}
for(j=i;j<=list->last;j++)
list->data[j-1]=list->data[j];
list->last--;
return true; 
}
void printfList(List list) {
	int i=0;
	while(i<=list->last) {
		printf("%d\t",list->data[i]);
		i++;
	}
}
int length( List list ) {
	return list->last+1;
}
int main(int argc, char *argv[]) {
	int test[]= {1,2,3,4,5,6,7,8,9,10};
	int i;
	List list=makeEmpty();
	for(i=0; i<SIZE; i++) {
		insert(list,test[i],i+1);
	}
	printfList(list);
	printf("\n");
	printf("顺序表的长度：%d\n",length(list));
	printf("请输入要删除的序号(从0开始)：");
	int h;
	scanf("%d\n",&h);
	deleted(list,h);
	printf("删除学号%d之后的顺序表的元素：\n");
	printfList(list);
	printf("顺序表的长度：%d\n",length(list));
	printf("请输入两个值（第一个为序号，第二个为插入的具体值）\n");
	int e,f;
	scanf("%d%d\n",&e,&f);
	insert(list,e,f);
	printfList(list);
	return 0;
}
