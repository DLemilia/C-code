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
//����˳����е�i��Ԫ��

ElementType findKth(List list, int i ) {
	//TODO
ElementType p=0;
while(p<=list->last&&list->data[p]!=i)
i++;
return p; 
}


//����ĳ��Ԫ��x�Ƿ���˳�����ڵĻ�������ţ����ڷ���-1

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

//��˳���ĵ�i��λ�ò���ĳһ��Ԫ��X��
bool insert(List list, ElementType x, int i) {
	//TODO
ElementType j;
if(list->last==MAXSIZE-1)
{
	printf("����");
	return false; 
}
if(i<1||i>list->last+2)
{
	printf("λ�򲻺Ϸ�");
	return false; 
}
for(j=list->last;j>=i-1;j--)
	list->data[j+1]=list->data[j];
	list->data[i-1]=x;
	list->last++;
	return true;
}
//ɾ��˳����е�i��Ԫ��
bool deleted(List list, int  i) {
	//TODO
ElementType j;
if(i<1||i>list->last+1)
{
printf("λ��%d������Ԫ��",i);
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
	printf("˳���ĳ��ȣ�%d\n",length(list));
	printf("������Ҫɾ�������(��0��ʼ)��");
	int h;
	scanf("%d\n",&h);
	deleted(list,h);
	printf("ɾ��ѧ��%d֮���˳����Ԫ�أ�\n");
	printfList(list);
	printf("˳���ĳ��ȣ�%d\n",length(list));
	printf("����������ֵ����һ��Ϊ��ţ��ڶ���Ϊ����ľ���ֵ��\n");
	int e,f;
	scanf("%d%d\n",&e,&f);
	insert(list,e,f);
	printfList(list);
	return 0;
}
