#include<stdio.h>
#define maxsize 10
typedef int dataType;
//��ʽջ,ջ����ʽ�洢�ṹ 
typedef struct node{
	datatype data;
	struct node *next;
}snode,*slink;//��ʽջ˵����

//�ÿ�ջ
void ClearLinkStack(slink top){
	top=NULL;
}

//�п�
int isEmptLinkStack(slink top){
	if(top==NULL){
		return 1;
	}else{
		return 0;
	}
}

//��ջ
int LinkPush(slink top,dataType e){
	slink p;
	p = (slink)malloc(sizeof(snode));
	p->data = e;
	p->next = top;
	top = p;
	return 1;
} 

//��ջ
dataType LinkPop(slink top){
	dataType e;
	slink p;
	if(isEmptLinkStack(top)>0){
		return NULL;
	}else{
		e = top->data;
		p = top;
		top = top->next;
		free(p);
		return e
	}
} 