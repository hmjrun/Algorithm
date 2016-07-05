#include<stdio.h>
#include<conio.h>
#define MAXSIZE 10 
typedef char dataType;
typedef struct{
	dataType data;
	int next;
}staticNode;
/*********************************************************************
 * ��̬���� 
 * ����һ���ϴ�Ľṹ������Ϊ���ý��ռ�(���洢��)��
 * ��������ʱ��ÿ�����Ӧ����������data���cursor��
 * data��������Ž���������Ϣ����ʱ��cursor������ָ������α�ָʾ����
 * �α�ָʾ��ָʾ���̽���ڽṹ�����е����λ��(�������±�)�� 
**********************************************************************/

/*******************************************************************/
/* ��ʼ����̬������������Ϊʹ�ñ�ͷָʾ�� 
/*����0Ԫ��ָ���������� ��������Ԫ������δ�ñ�
/*******************************************************************/ 
void sInit(staticNode spool[],int *unused){
	int j;
	//���������ÿ� 
	spool[0].next = 1;
	//ÿһδ�ýڵ�������һ�� 
	for(j = 1;j<MAXSIZE-1;j++){
		spool[j].next = j+1;
	}
	//�����β 
	spool[j].next = 0;
	*unused = 1;
} 

/*******************************************************************/
/* �ڵ����
/* ���ӵ�ǰδʹ�������ȡһ���ڵ㣬����ŷ��� 
/*******************************************************************/ 
int sMalloc(staticNode spool[],int *unused){
	int p = 0;
	if(*unused != 0){
		p = *unused;
		*unused = spool[p].next;
	}
	//�п���ʱ������Ӧ��ţ����򷵻�0 
	return p;
} 

/*******************************************************************/
/* �ڵ���� 
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
/* ǰ�� 
/* �ȴ�δʹ�ñ���ȡһ��Ԫ�أ�������e��ֵ����������
/* ֮���ҵ�����λ��i֮ǰ��Ԫ�أ���e�嵽���
/* e ���� spool �� position ֮ǰ 
/*******************************************************************/  
int sInsert(staticNode spool[],int position,dataType e,int *unused){
	int j,k,m;
	//ȡ���ÿռ� 
	j = sMalloc(spool,unused);
	if(j == 0){
		//ERROR()�� 
		printf("�ñ�������û�п��ÿռ�"); 
	}
 	//�ҵ�position-1��Ԫ��
	m = 0;
	for(k=0;k<position-1;k++){
		m = spool[m].next;
		if(m == 0){
			printf("����û����");
			return 0;
		}
	} 
	//����Ԫ��
	spool[j].data = e;
	spool[j].next =spool[m].next;
	spool[m].next = j;
	return 1; 
}

/*******************************************************************/
/* ɾ�� 
/* �ȴ�δʹ�ñ����ҵ�Ԫ�أ�ɾ������ռ����δʹ�ñ� 
/*******************************************************************/ 
int sDelete(staticNode spool[],int position,int*unused){
	int k,m;
	//�ҵ�position-1λ�� 
	for(k=0;k<position-1;k++){
		m = spool[m].next;
		if(m == 0){
			printf("����û����");
			return 0;
		}
	} 
	//ɾ���ڵ� 
	int j = spool[m].next;
	spool[m].next= spool[j].next;
	sFree(spool,unused,j);
	return 1;
} 

/*******************************************************************/
/* ������̬������  
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
    printf("������\n");
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
 *����һ����̬������ 
 */
int main(){
	dataType e;
	//���徲̬������ 
	staticNode spool[MAXSIZE]; 

	//δ�þ�̬�����ͷָʾ��
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