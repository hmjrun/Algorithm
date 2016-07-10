#include<stdio.h>
#define maxsize 10
typedef int dataType;
//Á´Ê½Õ»,Õ»µÄÁ´Ê½´æ´¢½á¹¹ 
typedef struct node{
	datatype data;
	struct node *next;
}snode,*slink;//Á´Ê½Õ»ËµÃ÷·û

//ÖÃ¿ÕÕ»
void ClearLinkStack(slink top){
	top=NULL;
}

//ÅÐ¿Õ
int isEmptLinkStack(slink top){
	if(top==NULL){
		return 1;
	}else{
		return 0;
	}
}

//½øÕ»
int LinkPush(slink top,dataType e){
	slink p;
	p = (slink)malloc(sizeof(snode));
	p->data = e;
	p->next = top;
	top = p;
	return 1;
} 

//³öÕ»
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