#include "../head/duLinkedList.h"

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
//��ʼ��
Status InitList_DuL(DuLinkedList *L) {
	 *L=(DuLinkedList)malloc(sizeof(DuLNode));
    (*L)->next=NULL;
	(*L)->prior=NULL;
	(*L)->data=0;
	if(*L==NULL) return ERROR ;
	else return SUCCESS;	
}
void new(DuLinkedList *head)
{
	Status b;

    b=InitList_DuL(head);
    if(b==SUCCESS) printf("\n                 *��ʼ�����ɹ�* \n\n");
        else printf("\n               *��ʼ����ʧ��* \n\n");	
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
//���ܡ�����
DuLinkedList DestroyList_DuL(DuLinkedList *L) {
	DuLinkedList p=*L;
	DuLinkedList k;
	char t;
	
	while(p!=NULL)
	{
		*L=p->next;
		free(p);
		p=*L;
	}
	printf("          <�ɹ������ѽ�����>");
    printf("\n�Ƿ��ؽ�����һ������(���� y / n)\n     ");
    fflush(stdin);
    scanf("%c",&t);
	if(t=='y')
	{
		k=(DuLinkedList)malloc(sizeof(DuLNode));
		new(&k);
		return k;
	}
	else
	{
		printf("�����Ѿ���������л���ʹ��\n");
		exit(0);
	}
	
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
//���ܡ�ǰ��
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
	int a;

	printf("��ǰ�塿����Ҫ���������\n        (������ĵ�һ������Ϊ׼):");
	fflush(stdin);
	a=scanf("%d",&q->data);
	if(a==0)
	{
		printf("\n          <�������>\n");
		exit(0);
	}
	if(p->prior!=NULL) p->prior->next=q;
	q->prior=p->prior;
	p->prior=q;
	q->next=p;
	return(SUCCESS);
}
void beinsert(DuLinkedList head)
{
	DuLinkedList p,q;
	Status b;
	int i,n,sum,a;

	for(sum=0,p=head;p!=NULL;p=p->next,sum++);
	sum--;
	printf("��ǰ�塿��������%d���ڵ㣬��ѡ��������ݵ��ڼ����ڵ��ǰ��\n        (������ĵ�һ������Ϊ׼):",sum);
	fflush(stdin);
	a=scanf("%d",&n);
	if(a==0)
	{
		printf("\n          <�������>\n");
		exit(0);
	}
	
	if(n<0||n>sum)
	{
		printf("�����롿������ֻ��%d���ڵ㣬�޷�����\n",sum);
		printf("          <�˳����빦��>\n");
	//	exit(0);
	}
	else
	{
		for(i=0,p=head;i<n;i++)
			p=p->next;
		q=(DuLinkedList)malloc(sizeof(DuLNode));
        b=InsertBeforeList_DuL(p,q);
		if(b==SUCCESS) printf("          <����ɹ�>\n");
		else printf("����ʧ��\n");
	}
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
//���ܡ����
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
	int a;

    printf("����塿����Ҫ���������\n        (������ĵ�һ������Ϊ׼):");
	fflush(stdin);
	a=scanf("%d",&q->data);
	if(a==0)
	{
		printf("\n          <�������>\n");
		exit(0);
	}
    if(p->next!=NULL) p->next->prior=q;
	q->next=p->next;
	p->next=q;
	q->prior=p;
	return(SUCCESS);	
}
void afinsert(DuLinkedList head)
{
	DuLinkedList p,q;
	Status b;
	int i,n,sum,a;

	for(sum=0,p=head;p!=NULL;p=p->next,sum++);
	sum--;
	printf("����塿��������%d���ڵ㣬��ѡ��������ݵ��ڼ����ڵ�ĺ���:\n        (������ĵ�һ������Ϊ׼)",sum);
	fflush(stdin);
	a=scanf("%d",&n);
	if(a==0)
	{
		printf("\n          <�������>\n");
		exit(0);
	}
	
	if(n<0||n>sum)
	{
		printf("����塿������ֻ��%d���ڵ㣬�޷�����\n",sum);
		printf("          <�˳����빦��>\n");
	//	exit(0);
	}
	else
	{
		for(i=0,p=head;i<n;i++)
			p=p->next;
		q=(DuLinkedList)malloc(sizeof(DuLNode));
        b=InsertAfterList_DuL(p,q);
		if(b==SUCCESS) printf("          <����ɹ�>\n");
		else printf("����ʧ��\n");
	}
}
/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
//���ܡ�ɾ��
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
	DuLinkedList k;

	if(p->next==NULL) 
	{
		return ERROR;
		printf("ɾ��ʧ��\n");
	}
	else
	{
		k=p->next;
	    p->next=k->next;
		k->next->prior=p;
	    *e=k->data;
        free(k);
	    return SUCCESS;
	}
}
 void del(DuLinkedList head)
{
    DuLinkedList p;
	Status b;
    ElemType e;
	int sum,n,a,i;

	for(sum=0,p=head;p!=NULL;p=p->next,sum++);
	sum--;
	printf("��ɾ������������%d���ڵ㣬��ѡ��ɾ���ڼ����ڵ������:\n        (������ĵ�һ������Ϊ׼)",sum);
	fflush(stdin);
	a=scanf("%d",&n);
	if(a==0)
	{
		printf("\n          <�������>\n");
		exit(0);
	}

	if(n<1||n>sum)
	{
		printf("��ɾ����������ֻ��%d���ڵ㣬�޷�ɾ����%d�ڵ�\n",sum,n);
		printf("          <�˳�ɾ������>\n");
	}
	else
	{
		for(i=0,p=head;i<n-1;i++)
			p=p->next;
        b=DeleteList_DuL(p,&e);
		if(b==SUCCESS) printf("          <ɾ����%d�ڵ�����%d�ɹ�>\n",n,e);
		else printf("ɾ��ʧ��\n");
	}
}
/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit 
 *	@return		 : Status
 *  @notice      : None
 */
 //���ܡ�������δ����
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	
}


//�Զ��庯��
//���ܡ����ܱ�
void abc()
{
	printf("                 *��ѡ�����¹���*\n\n");
	printf("     |����������������  &&   ���ܡ�������������|\n");
	printf("     |-����������������������������������������|\n");
	printf("     |-------------a    TO   ����--------------|\n");
	printf("     |-------------b    TO   ǰ��--------------|\n");
	printf("     |-------------c    TO   ���--------------|\n");
	printf("     |-------------d    TO   ����--------------|\n");
	printf("     |-------------e    TO   ɾ��--------------|\n");
	printf("     |-------------f    TO   ����--------------|\n");
	printf("     |-------------g    TO   ���--------------|\n");
	printf("     |-------------j    TO   �˳�--------------|\n");
	printf("     |-����������������������������������������|\n");
	printf("     |-����������������������������������������|\n");
}
//���ܡ����
void print(DuLinkedList head)
{
	DuLinkedList p;

	printf("\n������������ʱ����:       ");
	for(p=head->next;p!=NULL;p=p->next)
		printf("��%d��",p->data);
	printf("\n          <������>\n");
}
//���ܡ�����
void creat(DuLinkedList head)
{
	DuLinkedList p1,p2;
	ElemType k,i,a,n;

	p2=head;
    printf("�����롿��Ҫ����������ڵ���\n        (������ĵ�һ������Ϊ׼):");
	fflush(stdin);
	a=scanf("%d",&n);
	fflush(stdin);
	if(a==0){
		printf("       <�������>\n�����¿�ʼ:\n");
        creat(head);
	}
	printf("�����롿���롾int��������%d��\n       (�Զ��Ŵ����������ÿո�������س���������):",n);
	i=0;
	while(i<n)
	{	
		a=scanf("%d",&k);
		if(a==1)
		{
		p1=(DuLinkedList)malloc(sizeof(DuLNode));
		p1->data=k;
	    p2->next=p1;
		p1->prior=p2;
		p2=p1;
		i++;
		}
		else 
			while(getchar()!='\n')
			     continue;
	}
	p2->next=NULL;
	printf("          <�������>\n");
}

void wsg()
{
	system("PAUSE");
	system("cls");
	abc();
	printf("##������ѡ��Ĳ���(������ĵ�һ���ַ�Ϊ׼)##       ");
}

//���ܡ�����
Status SearchList_Du(DuLinkedList L, ElemType e) {
	int n=1;
	
	for(L=L->next;L!=NULL;L=L->next)
	{		
		if(L->data==e) 
	    	break;
		n++;
	}
	if(L==NULL) return ERROR;
	else
	{	
		printf("���������ڵ�%d������ҵ�%d\n",n,e);
		return SUCCESS;
	}

}
void sea(DuLinkedList head)
{
	int n;
    Status b,a;

	printf("��������������������������:\n        (������ĵ�һ������Ϊ׼)");
	fflush(stdin);
	a=scanf("%d",&n);
	if(a==0)
	{
		printf("\n          <�������>\n");
		exit(0);
	}
    b=SearchList_Du(head,n);
	if(b==ERROR)
		printf("��������������û�и�����\n");
	printf("          <�������>\n");
}