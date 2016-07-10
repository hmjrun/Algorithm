#include<stdio.h>
#define maxsize 10
typedef int dataType;
//Ë³ÐòÕ»,Õ»µÄË³Ðò´æ´¢½á¹¹ 
typedef struct {
	datatype data[maxsize];
	int top;
}sqstack,*sqslink;//Ë³ÐòÕ»ËµÃ÷·û

//ÖÃ¿ÕÕ»
void ClearStack(sqslink s){
	s->top=-1;
} 

//Õ»µÄÅÐ¿Õ
int isEmptyStack(sqslink s){
	if(s->top < 0){
		return 1;
	}else{
		return 0;
	}
} 

//Õ»µÄÅÐÂú
int isFullStack(sqslink s){
	if(s->top >= maxsize-1){
		return 1;
	}else{
		return 0;
	}
}

//ÈëÕ»
int Push(sqslink s,dataType e){
	if(isFullStack(s)>0){
		return 0;
	}else{
		s->top++;
		s->data[s->top] = e;
		return 1;
	}
} 

//³öÕ»
dataType Pop(sqslink s){
	if(isEmptyStack(s)>0){
		return NULL
	}else{
		s->top--;
		return s->data[s->top+1];
	}
}

