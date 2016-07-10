#include<stdio.h>
#define maxsize 10
typedef int dataType;
//˳��ջ,ջ��˳��洢�ṹ 
typedef struct {
	datatype data[maxsize];
	int top;
}sqstack,*sqslink;//˳��ջ˵����

//�ÿ�ջ
void ClearStack(sqslink s){
	s->top=-1;
} 

//ջ���п�
int isEmptyStack(sqslink s){
	if(s->top < 0){
		return 1;
	}else{
		return 0;
	}
} 

//ջ������
int isFullStack(sqslink s){
	if(s->top >= maxsize-1){
		return 1;
	}else{
		return 0;
	}
}

//��ջ
int Push(sqslink s,dataType e){
	if(isFullStack(s)>0){
		return 0;
	}else{
		s->top++;
		s->data[s->top] = e;
		return 1;
	}
} 

//��ջ
dataType Pop(sqslink s){
	if(isEmptyStack(s)>0){
		return NULL
	}else{
		s->top--;
		return s->data[s->top+1];
	}
}

