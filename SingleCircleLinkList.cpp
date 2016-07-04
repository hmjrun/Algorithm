#include<stdio.h>
#include<malloc.h>
#include<conio.h>
/*
 *����
 *һȺС��Χ��һȦ������ٶ�һ����m,�ӵ�һ��С����˳ʱ�뷽������ÿ������m��С��ʱ����С�����뿪��
 *С�������뿪��Ȧ�Ӳ�����С�����ʣ�µ�һ��С������ʤ�ߡ���ʤ�ߵı�ţ�
 */
typedef struct node{
	int Nomber;
	struct node* next;
}Node,*Link;

/******************************/
/* ����ѭ������ 
/* ���ش����õ�ѭ������ͷָ�� 
/******************************/
Link CreateLinkList(int n){
	Link head=NULL,tail=NULL; 
	for(int i=1;i<=n;i++){
		if(i == 1){
			head = tail = (Link)malloc(sizeof(Node));
			//��Ϊhead �� tail ָ�붼��ָ��ͬһ���ڴ����򣬹ʣ�
			// tail->Nomber = i; <=> head->Nomber = i;
			tail->Nomber = i;
		}else{
			//���½ڵ�ʱ�½�һ���ڵ����β�� 
			tail->next = (Link)malloc(sizeof(Node));
			//�ƶ� tail βָ��ָ�����һ���ڵ� 
			tail = tail->next;
			tail->Nomber = i;
		}	
	}
	//��β�������γ�ѭ������ 
	tail->next = head;
	//���ظ�ѭ�������ͷָ�룬�������� 
	return head;
} 

/***********************************/
/* ��������ɾ���ڵ�,
/* ���ظ�ɾ���ڵ����һ���ڵ�ָ�� 
/***********************************/
 Link DeleteLinkNode(Link deleteNode){
 	Link p=deleteNode;
 	//Ѱ��deleteNode��ǰһ���ڵ㣬
    //��ִ����while��p����deleteNode��ǰһ����� 
 	while(p->next != deleteNode){
	 	p = p->next;
	 }
	 //����ָ��ָ��ɾ��deleteNode�ڵ㣬�����ڴ� 
	 p->next = deleteNode->next;
	 free(deleteNode);
	 return p->next;
 }
 
/***********************************/
/* �� josephus ����ɾ���ڵ㣬 
/* ����˳�������� 
/* count:������
/* beginNuber:��ʼ�������˱�� 
/* deadNUmber:���������������� 
/***********************************/
void josephu(Link p,int count,int deadNUmber,int beginNuber){
	int i,j;
	printf("���е�����Ϊ��\n(");
	//�ҵ���ʼ�����Ľڵ� 
	for(i = 1;i<beginNuber;i++){
		p = p->next;	
	}
	//ÿ��ѭ��һ�γ�һ�ڵ㣬�ܹ�count���ڵ㣬ѭ��count�� 
	for(i = 0;i<count;i++){
		//ִ�����ѭ����pָ��Ŀ��ڵ� 
		for(j=1;j<deadNUmber;j++){
			p = p->next;	
		} 
		//��p�ڵ����ҵ����� 
		printf("%d,",p->Nomber);
		p = DeleteLinkNode(p); 
	
	} 
	printf("\b)\n");
}

int main(){
	int count,deadNumber,beginNumber;
	Link head = NULL;
	printf("\n��������");
	scanf("%d",&count);	
	printf("\n��������");
	scanf("%d",&beginNumber);
	printf("\n��ʼ�����ڵ㣺(1<X<%d)",count);
	scanf("%d",&deadNumber);
	head = CreateLinkList(count);
 	josephu(head,count,deadNumber,beginNumber);
 	return 0;
}