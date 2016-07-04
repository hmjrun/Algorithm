#include<stdio.h>
#include<malloc.h>
#include<conio.h>
/*
 *任务：
 *一群小孩围成一圈，任意假定一个数m,从第一个小孩起，顺时针方向数，每数到第m个小孩时，该小孩便离开。
 *小孩不断离开，圈子不断缩小。最后剩下的一个小孩便是胜者。求胜者的编号？
 */
typedef struct node{
	int Nomber;
	struct node* next;
}Node,*Link;

/******************************/
/* 建立循环链表 
/* 返回创建好的循环链表头指针 
/******************************/
Link CreateLinkList(int n){
	Link head=NULL,tail=NULL; 
	for(int i=1;i<=n;i++){
		if(i == 1){
			head = tail = (Link)malloc(sizeof(Node));
			//因为head 和 tail 指针都是指向同一块内存区域，故：
			// tail->Nomber = i; <=> head->Nomber = i;
			tail->Nomber = i;
		}else{
			//有新节点时新建一个节点插入尾部 
			tail->next = (Link)malloc(sizeof(Node));
			//移动 tail 尾指针指向最后一个节点 
			tail = tail->next;
			tail->Nomber = i;
		}	
	}
	//首尾相连，形成循环链表 
	tail->next = head;
	//返回该循环链表的头指针，即该链表 
	return head;
} 

/***********************************/
/* 从链表中删除节点,
/* 返回该删除节点的下一个节点指针 
/***********************************/
 Link DeleteLinkNode(Link deleteNode){
 	Link p=deleteNode;
 	//寻找deleteNode的前一个节点，
    //当执行完while后p就是deleteNode的前一个结点 
 	while(p->next != deleteNode){
	 	p = p->next;
	 }
	 //更改指针指向，删除deleteNode节点，回收内存 
	 p->next = deleteNode->next;
	 free(deleteNode);
	 return p->next;
 }
 
/***********************************/
/* 按 josephus 规则删除节点， 
/* 并按顺序输出序号 
/* count:总人数
/* beginNuber:开始报数的人编号 
/* deadNUmber:周期数，即出列数 
/***********************************/
void josephu(Link p,int count,int deadNUmber,int beginNuber){
	int i,j;
	printf("出列的序列为：\n(");
	//找到开始报数的节点 
	for(i = 1;i<beginNuber;i++){
		p = p->next;	
	}
	//每次循环一次出一节点，总共count个节点，循环count次 
	for(i = 0;i<count;i++){
		//执行完该循环，p指向目标节点 
		for(j=1;j<deadNUmber;j++){
			p = p->next;	
		} 
		//对p节点进行业务操作 
		printf("%d,",p->Nomber);
		p = DeleteLinkNode(p); 
	
	} 
	printf("\b)\n");
}

int main(){
	int count,deadNumber,beginNumber;
	Link head = NULL;
	printf("\n总人数：");
	scanf("%d",&count);	
	printf("\n周期数：");
	scanf("%d",&beginNumber);
	printf("\n开始报数节点：(1<X<%d)",count);
	scanf("%d",&deadNumber);
	head = CreateLinkList(count);
 	josephu(head,count,deadNumber,beginNumber);
 	return 0;
}