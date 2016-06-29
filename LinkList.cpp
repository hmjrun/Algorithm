#include <stdio.h>
#include <malloc.h>
typedef int dataType;
typedef struct node{	//节点类型 
	dataType data;		//节点数据域 
	struct node *next;	//节点的后继指针域 
}linknode,*link;		//linknode 为节点说明符，link为节点指针说明符！ 

//创建单链表，链表任意多节点，写入数据，返回该链表的头指针 
link CreateList(){
	int a;
	link H,P,r;
	H = (link)malloc(sizeof(linknode));//建立链表的头节点 
	r = H;//保持r指针指向链表的尾部节点，即头节点 
	scanf("%d",&a);
	while(a != -1){
		P = (link)malloc(sizeof(linknode));//申请链表的新节点 
		P->data = a;//写入数据 
		r->next = P;
		r = P;//保持r指针指向链表的尾部节点 
		scanf("%d",&a);
	} 
	r->next= NULL;
	return H;//返回链表的头部指针 
}

//查找单链表 H 中第 i 个节点，返回该节点指针
link GetElementById(link H,int i){
	int j=-1;//从头结点为 A-1，第一个节点为 A1 ... 
	link P = H;//令指针P指向头结点 
	
	//遍历链表,(P->next)表示当前节点，当前节点存在且不为第 i 个节点
	while(P->next && j<i){ 
		P = P->next;
		j++;	
	}
	if(j==i){//返回第 i 个节点指针
		return P;
	}else{//查找失败，即 i > 表长 
		return NULL;
	}
} 

//查找单链表 H 中和给定值一样的节点，返回该节点指针
link GetElementByValue(link H,dataType value){
	link P = H->next;//令指针P指向头结点 
	
	//遍历链表,当前节点存在且
	while(P && P->data != value){ 
		P = P->next;	
	}
	return P;//若查找成功 (即某个P->data == e),则返回指针P;否者P必然为空，返回NULL 
} 

//在单链表H中将节点 x 插入到目标节点 A(position) 之前 
void ListInsertBefore(link H,int position,dataType value){
	link beforeNode,newNode;
	if(position == 0){
		beforeNode = H;
	}else{
		//取节点A(position-1)的指针,此时目标节点=> beforeNode->next
		beforeNode = GetElementById(H,position-1);
	}
	if(beforeNode == NULL){
		//ERROR(position);
		printf("前插链表节点，参数%d错误！",position);
	}else{
		newNode = (link)malloc(sizeof(linknode));
		newNode->data = value;
		//插入的新节点(newNode)的指针域(newNode->next)指向目标节点(beforeNode->next) 
		newNode->next = beforeNode->next; 
		//前一节点指针域指向新插入节点 ,重构一条新链表 
		beforeNode->next = newNode; 
	}
} 

//删除单链表中第 position 个的目标节点
void ListDelete(link H,int position){
	link pointBefor,point;
	if(position == 0){
		pointBefor = H;
	}else{
		pointBefor = GetElementById(H,position-1);//获取目标节点的前一个节点指针 
	}
	if(pointBefor && pointBefor->next){//当 pointBefor 以及 pointBefor->next 节点存在时 
		point = pointBefor->next;
		pointBefor->next = point->next;
		free(point);//释放被删除节点 
	}else{
		//ERROR(position);
		printf("删除单链表中第 %d 个的节点,position参数错误！\n",position); 
	}
} 

//给定单链表倒置
void ListInvert(link H){
	link p,q;
	p = H->next;
	H->next = NULL;//原链表置空
	while(p){
		q = p;
		p = p->next;
		q->next = H->next;
		H->next = q;	
	}	
}

//遍历单链表各节点值
void QueryAllNode(link H){
	link point;
	if(H->next == NULL){
		printf("该链表为NULL!");	
	}else{
		point = H->next;//第一个节点 
		printf("遍历链表：%d,",point->data);
		while(point->next){
			point = point->next;
			printf("%d,",point->data);	
		}
		printf("\n"); 
	} 	 
} 

//返回单链表中连续两个节点的值(int 类型）的和最大中的前一个节点的指针 
//return P(n){Max(P(n)->data + P(n+1)->data)}
link ReturnNodeByTwoNodeSumMax(link	H){
	link point,pointNext,returnPoint;
	int sumMax,sumMin;
	point = returnPoint = H->next;
	if(returnPoint == NULL){
		return returnPoint;//链表为空，返回NULL 
	}
	pointNext = point->next;
	if(pointNext == NULL){
		return returnPoint;//链表长度为1，自然返回 
	}
	sumMax = point->data + pointNext->data;//初始化sunMax为最开始的两个节点值的和 
	while(pointNext->next){
		point = pointNext;
		pointNext = pointNext->next;
		sumMin = point->data + pointNext->data;//下一对节点值的和 
		if(sumMin > sumMax){
			returnPoint = point;//记录和最大时对应的节点指针 
			sumMax = sumMin;
		}
	}
	return returnPoint;//返回和最大时的节点指针 
}

//将两个递增单链表合并成一个递增有序表
void Merge(link A,link B){
	link r,p,q;
	p = A->next;
	q = B->next;
	free(B);
	r = A;
	while(p&&q){
		if(p->data <= q->data){
			r->next = p;//p节点进新链表 
			r = p;
			p = p->next;
		}else{
			r->next = q;//q节点进新链表 
			r = q;
			q = q->next;
		}	
	}
	if(p==NULL){
		p=q;
	} 
	r->next = p;
} 


int main()
{
	link G = CreateList();
	
	link K = CreateList();
	
	QueryAllNode(G);
	QueryAllNode(K);
	
	Merge(G,K);
 	QueryAllNode(G);

	ListInvert(G);
	return 0;
}