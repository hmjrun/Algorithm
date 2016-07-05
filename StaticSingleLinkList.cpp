#include<stdio.h>
#include<conio.h>
#define MAXSIZE 10 
typedef char dataType;
typedef struct{
	dataType data;
	int next;
}staticNode;
/*********************************************************************
 * 静态链表 
 * 定义一个较大的结构数组作为备用结点空间(即存储池)。
 * 当申请结点时，每个结点应含有两个域：data域和cursor域。
 * data域用来存放结点的数据信息，此时的cursor域不在是指针而是游标指示器，
 * 游标指示器指示其后继结点在结构数组中的相对位置(即数组下标)。 
**********************************************************************/

/*******************************************************************/
/* 初始化静态单链表，并设置为使用表头指示器 
/*将第0元素指向自身，并将 其余数组元素链成未用表
/*******************************************************************/ 
void sInit(staticNode spool[],int *unused){
	int j;
	//已用链表置空 
	spool[0].next = 1;
	//每一未用节点链向下一点 
	for(j = 1;j<MAXSIZE-1;j++){
		spool[j].next = j+1;
	}
	//标记链尾 
	spool[j].next = 0;
	*unused = 1;
} 

/*******************************************************************/
/* 节点分配
/* 即从当前未使用链表获取一个节点，将序号返回 
/*******************************************************************/ 
int sMalloc(staticNode spool[],int *unused){
	int p = 0;
	if(*unused != 0){
		p = *unused;
		*unused = spool[p].next;
	}
	//有空闲时返回相应序号，否则返回0 
	return p;
} 

/*******************************************************************/
/* 节点回收 
/* 
/*******************************************************************/
int sFree(staticNode spool[],int *unused, int p){
	if(p>=0 && p<MAXSIZE){
		spool[p].next = *unused;
		*unused = p;
		return 1;
	}else{
		return 0;
	}
} 

/*******************************************************************/
/* 前插 
/* 先从未使用表中取一个元素，将数据e赋值给其数据域，
/* 之后找到插入位置i之前的元素，把e插到其后
/* e 插入 spool 第 position 之前 
/*******************************************************************/  
int sInsert(staticNode spool[],int position,dataType e,int *unused){
	int j,k,m;
	//取可用空间 
	j = sMalloc(spool,unused);
	if(j == 0){
		//ERROR()； 
		printf("该表已满，没有可用空间"); 
	}
 	//找第position-1个元素
	m = 0;
	for(k=0;k<position-1;k++){
		m = spool[m].next;
		if(m == 0){
			printf("错误，没找着");
			return 0;
		}
	} 
	//插入元素
	spool[j].data = e;
	spool[j].next =spool[m].next;
	spool[m].next = j;
	return 1; 
}

/*******************************************************************/
/* 删除 
/* 先从未使用表中找到元素，删除后将其空间存入未使用表 
/*******************************************************************/ 
int sDelete(staticNode spool[],int position,int*unused){
	int k,m;
	//找第position-1位置 
	for(k=0;k<position-1;k++){
		m = spool[m].next;
		if(m == 0){
			printf("错误，没找着");
			return 0;
		}
	} 
	//删除节点 
	int j = spool[m].next;
	spool[m].next= spool[j].next;
	sFree(spool,unused,j);
	return 1;
} 

/*******************************************************************/
/* 遍历静态单链表  
/*******************************************************************/ 
void sBrowse(staticNode spool[],int unused){
	int i;
	for(i = 0;i<MAXSIZE;i++){
		printf("\n[%d]{%c}[%d]",i,spool[i].data,spool[i].next);
	}
	printf("\n unused=%d",unused);
	printf("\nPress any key to continue\n");
	getch();
}

void print_s(staticNode slist[],int start){  
    int p=slist[start].next;  
    int i;
    printf("遍历：\n");
    for(i=0;i<MAXSIZE;i++) 
    {  
    	if(slist[p].data!=NULL){
	    	printf("%c, ",slist[p].data);  
	    }
        p=slist[p].next;  
        if(p==1)break;
    }  
    printf("\n");  
}  

/*
 *建立一个静态单链表 
 */
int main(){
	dataType e;
	//定义静态单链表 
	staticNode spool[MAXSIZE]; 

	//未用静态链表的头指示器
	int unused;
	sInit(spool,&unused);
	sBrowse(spool,unused);
	printf("\n Input 6 chars \n"); 
	int i;
	for(i=1;i<=6;i++){
		e = getch();
		sInsert(spool,i,e,&unused);
	}
	sBrowse(spool,unused);
	print_s(spool,0);
	sDelete(spool,3,&unused);
	sBrowse(spool,unused);
	print_s(spool,0);
	sInsert(spool,3,'g',&unused);
	sBrowse(spool,unused);
	print_s(spool,0);
	return 0;
}  