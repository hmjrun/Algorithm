#include <stdio.h>
#include <malloc.h>
typedef int dataType;
typedef struct node{	//�ڵ����� 
	dataType data;		//�ڵ������� 
	struct node *next;	//�ڵ�ĺ��ָ���� 
}linknode,*link;		//linknode Ϊ�ڵ�˵������linkΪ�ڵ�ָ��˵������ 

//�������������������ڵ㣬д�����ݣ����ظ������ͷָ�� 
link CreateList(){
	int a;
	link H,P,r;
	H = (link)malloc(sizeof(linknode));//���������ͷ�ڵ� 
	r = H;//����rָ��ָ�������β���ڵ㣬��ͷ�ڵ� 
	scanf("%d",&a);
	while(a != -1){
		P = (link)malloc(sizeof(linknode));//����������½ڵ� 
		P->data = a;//д������ 
		r->next = P;
		r = P;//����rָ��ָ�������β���ڵ� 
		scanf("%d",&a);
	} 
	r->next= NULL;
	return H;//���������ͷ��ָ�� 
}

//���ҵ����� H �е� i ���ڵ㣬���ظýڵ�ָ��
link GetElementById(link H,int i){
	int j=-1;//��ͷ���Ϊ A-1����һ���ڵ�Ϊ A1 ... 
	link P = H;//��ָ��Pָ��ͷ��� 
	
	//��������,(P->next)��ʾ��ǰ�ڵ㣬��ǰ�ڵ�����Ҳ�Ϊ�� i ���ڵ�
	while(P->next && j<i){ 
		P = P->next;
		j++;	
	}
	if(j==i){//���ص� i ���ڵ�ָ��
		return P;
	}else{//����ʧ�ܣ��� i > �� 
		return NULL;
	}
} 

//���ҵ����� H �к͸���ֵһ���Ľڵ㣬���ظýڵ�ָ��
link GetElementByValue(link H,dataType value){
	link P = H->next;//��ָ��Pָ��ͷ��� 
	
	//��������,��ǰ�ڵ������
	while(P && P->data != value){ 
		P = P->next;	
	}
	return P;//�����ҳɹ� (��ĳ��P->data == e),�򷵻�ָ��P;����P��ȻΪ�գ�����NULL 
} 

//�ڵ�����H�н��ڵ� x ���뵽Ŀ��ڵ� A(position) ֮ǰ 
void ListInsertBefore(link H,int position,dataType value){
	link beforeNode,newNode;
	if(position == 0){
		beforeNode = H;
	}else{
		//ȡ�ڵ�A(position-1)��ָ��,��ʱĿ��ڵ�=> beforeNode->next
		beforeNode = GetElementById(H,position-1);
	}
	if(beforeNode == NULL){
		//ERROR(position);
		printf("ǰ������ڵ㣬����%d����",position);
	}else{
		newNode = (link)malloc(sizeof(linknode));
		newNode->data = value;
		//������½ڵ�(newNode)��ָ����(newNode->next)ָ��Ŀ��ڵ�(beforeNode->next) 
		newNode->next = beforeNode->next; 
		//ǰһ�ڵ�ָ����ָ���²���ڵ� ,�ع�һ�������� 
		beforeNode->next = newNode; 
	}
} 

//ɾ���������е� position ����Ŀ��ڵ�
void ListDelete(link H,int position){
	link pointBefor,point;
	if(position == 0){
		pointBefor = H;
	}else{
		pointBefor = GetElementById(H,position-1);//��ȡĿ��ڵ��ǰһ���ڵ�ָ�� 
	}
	if(pointBefor && pointBefor->next){//�� pointBefor �Լ� pointBefor->next �ڵ����ʱ 
		point = pointBefor->next;
		pointBefor->next = point->next;
		free(point);//�ͷű�ɾ���ڵ� 
	}else{
		//ERROR(position);
		printf("ɾ���������е� %d ���Ľڵ�,position��������\n",position); 
	}
} 

//������������
void ListInvert(link H){
	link p,q;
	p = H->next;
	H->next = NULL;//ԭ�����ÿ�
	while(p){
		q = p;
		p = p->next;
		q->next = H->next;
		H->next = q;	
	}	
}

//������������ڵ�ֵ
void QueryAllNode(link H){
	link point;
	if(H->next == NULL){
		printf("������ΪNULL!");	
	}else{
		point = H->next;//��һ���ڵ� 
		printf("��������%d,",point->data);
		while(point->next){
			point = point->next;
			printf("%d,",point->data);	
		}
		printf("\n"); 
	} 	 
} 

//���ص����������������ڵ��ֵ(int ���ͣ��ĺ�����е�ǰһ���ڵ��ָ�� 
//return P(n){Max(P(n)->data + P(n+1)->data)}
link ReturnNodeByTwoNodeSumMax(link	H){
	link point,pointNext,returnPoint;
	int sumMax,sumMin;
	point = returnPoint = H->next;
	if(returnPoint == NULL){
		return returnPoint;//����Ϊ�գ�����NULL 
	}
	pointNext = point->next;
	if(pointNext == NULL){
		return returnPoint;//������Ϊ1����Ȼ���� 
	}
	sumMax = point->data + pointNext->data;//��ʼ��sunMaxΪ�ʼ�������ڵ�ֵ�ĺ� 
	while(pointNext->next){
		point = pointNext;
		pointNext = pointNext->next;
		sumMin = point->data + pointNext->data;//��һ�Խڵ�ֵ�ĺ� 
		if(sumMin > sumMax){
			returnPoint = point;//��¼�����ʱ��Ӧ�Ľڵ�ָ�� 
			sumMax = sumMin;
		}
	}
	return returnPoint;//���غ����ʱ�Ľڵ�ָ�� 
}

//����������������ϲ���һ�����������
void Merge(link A,link B){
	link r,p,q;
	p = A->next;
	q = B->next;
	free(B);
	r = A;
	while(p&&q){
		if(p->data <= q->data){
			r->next = p;//p�ڵ�������� 
			r = p;
			p = p->next;
		}else{
			r->next = q;//q�ڵ�������� 
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