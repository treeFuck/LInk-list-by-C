#include "../head/linkedList.h"

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
//��ʼ��
Status InitList(LinkedList *L)          
{
    *L=(LinkedList)malloc(sizeof(LNode));
    (*L)->next=NULL;
	if(*L==NULL) return ERROR ;
	else return SUCCESS;
	
	
}
void new(LinkedList *head)
{
	Status b;

    b=InitList(head);
    if(b==SUCCESS) printf("\n                 *��ʼ�����ɹ�* \n\n");
        else printf("\n               *��ʼ����ʧ��* \n\n");	
}

    
/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
//���ܡ�����
LinkedList DestroyList(LinkedList *L) {           
	LinkedList p=*L;
    LinkedList k;
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
		k=(LinkedList)malloc(sizeof(LNode));
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
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
//���ܡ�����
Status InsertList(LNode *p, LNode *q) {      
	int a;

	printf("�����롿����Ҫ���������\n        (������ĵ�һ������Ϊ׼):");
	fflush(stdin);
	a=scanf("%d",&q->data);
	if(a==0)
	{
		printf("\n          <�������>\n");
		InsertList(p,q);
	}
	q->next=p->next;
	p->next=q;
	return(SUCCESS);
}
void insert(LinkedList head)
{
	LinkedList p,q;
	Status b;
	int i,n,sum,a;

	for(sum=0,p=head;p!=NULL;p=p->next,sum++);
	sum--;
	printf("�����롿��������%d���ڵ㣬��ѡ��������ݵ��ڼ����ڵ�ĺ���\n        (������ĵ�һ������Ϊ׼): ",sum);
	fflush(stdin);
	a=scanf("%d",&n);
	if(a==0)
	{
		printf("\n          <�������>\n");
		insert(head);
	}
	
	if(n<0||n>sum)
	{
		printf("�����롿������ֻ��%d���ڵ㣬�޷�����\n",sum);
		printf("          <�˳����빦��>\n");
	}
	else
	{
		for(i=0,p=head;i<n;i++)
			p=p->next;
		q=(LinkedList)malloc(sizeof(LNode));
        b=InsertList(p,q);
		if(b==SUCCESS) printf("          <����ɹ�>\n");
		else printf("����ʧ��\n");
	}
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
//���ܡ�ɾ��
Status DeleteList(LNode *p, ElemType *e) {
    LinkedList k;

	if(p->next==NULL) 
	{
		return ERROR;
		printf("ɾ��ʧ��\n");
	}
	else
	{
		k=p->next;
	    p->next=k->next;
	    *e=k->data;
        free(k);
	    return SUCCESS;
	}
}
void del(LinkedList head)
{
    LinkedList p;
	Status b;
    ElemType e;
	int sum,n,i,a;

	for(sum=0,p=head;p!=NULL;p=p->next,sum++);
	sum--;
	printf("��ɾ������������%d���ڵ㣬��ѡ��ɾ���ڼ����ڵ������\n        (������ĵ�һ������Ϊ׼):",sum);
	fflush(stdin);
	a=scanf("%d",&n);
	if(a==0)
	{
		printf("\n          <�������>\n");
		del(head);
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
        b=DeleteList(p,&e);
		if(b==SUCCESS) printf("          <ɾ����%d�ڵ�����%d�ɹ�>\n",n,e);
		else printf("ɾ��ʧ��\n");
	}
}
/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
//���ܡ�������δ����
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {

}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
//���ܡ�����
Status SearchList(LinkedList L, ElemType e) {
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
void sea(LinkedList head)
{
	int n,a;
    Status b;

	printf("��������������������������\n        (������ĵ�һ������Ϊ׼):      ");
	fflush(stdin);
	a=scanf("%d",&n);
	if(a==0)
	{
		printf("\n          <�������>\n");
		sea(head);
	}
    b=SearchList(head,n);
	if(b==ERROR)
		printf("��������������û�и�����\n");
	printf("          <�������>\n");
}


/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
//���ܡ���ת
Status ReverseList(LinkedList *L) {

    LNode *current, *pre, *pnext;    //�ֱ��ǵ�ǰ�ڵ㣬ֱ��ǰ���ڵ㣬ֱ�Ӻ�̽ڵ�

    current=(*L)->next;                //��ʼ��
    pre=NULL;
    while(current!= NULL)
	{   
        pnext = current -> next;      //������̽ڵ�   
        current -> next = pre;        //�µĺ��ָ��ǰ��ʵ�ַ�ת
        pre = current;
        current = pnext;              //����ǰ�ڵ�����ƶ�
    }
    (*L)->next=pre;
	return SUCCESS;
}
void rev(LinkedList L)
{
	Status b;

	b=ReverseList(&L);
	if(b==SUCCESS)
		printf("          <��ת�ɹ�>\n");

}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
//���ܡ��ж��Ƿ��л���δӦ�ã�
Status IsLoopList(LinkedList L) {
	LinkedList p1,p2;
	int a=0;

	for(p1=p2=L;p2!=NULL;p1=p1->next,p2=p2->next->next)
		if(p1==p2)
			a=1;
	if(a==1) printf("�������л�\n");
	else printf("������û�л�\n");
    return SUCCESS;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
//���ܡ�ż�ڵ㷴ת
LNode* ReverseEvenList(LinkedList *L) {
	LinkedList p1,p2,p3,p4;
	int i=0;
	
	p1=*L;
	p2=p1->next;
	p3=p2->next;
	p4=p3->next;

	for(;;)
	{
		p1->next=p3;
		p3->next=p2;
		p2->next=p4;

		p1=p2;
		p2=p4;
		if(p2==NULL) break;
		p3=p4->next;
		if(p3==NULL) break;
		p4=p3->next;
	}
	printf("          <��ת�ɹ�>\n");
	return(*L);
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
//���ܡ�Ѱ���м�㣨δ����
void FindMidNode(LinkedList L) {
	LinkedList a,b;
	int n=0;
    
	if(L->next!=NULL)
	{
		for(a=b=L;b!=NULL&&b->next!=NULL;a=a->next,b=b->next->next,n++)
    
	    if(b==NULL)
		     printf("�м�ڵ�Ϊ��%d�ڵ㡾%d��\n",n,a->data);
	    else if(b->next==NULL) 
		     printf("�м�ڵ�Ϊ��%d�ڵ㡾%d�����%d�ڵ㡾%d��",n,a->data,n+1,a->next->data);
	}
	else
		printf("    <����Ϊ��>\n");
}

//����Ϊ�Զ��庯��
//���ܡ����ܱ�
void abc()
{
	printf("                 *��ѡ�����¹���*\n\n");
	printf("     |����������������  &&   ���ܡ�������������|\n");
	printf("     |-����������������������������������������|\n");
	printf("     |-------------a    TO   ����--------------|\n");
	printf("     |-------------b    TO   ����--------------|\n");
	printf("     |-------------c    TO   ɾ��--------------|\n");
	printf("     |-------------d    TO   ����--------------|\n");
	printf("     |-------------e    TO   ���--------------|\n");
	printf("     |-------------f    TO   ����--------------|\n");
	printf("     |-------------g    TO   ��ת--------------|\n");
	printf("     |-------------h    TO   ��תż�����------|\n");
	printf("     |-------------i    TO   Ѱ���м��--------|\n");
	printf("     |-------------j    TO   �˳�--------------|\n");
	printf("     |-����������������������������������������|\n");
	printf("     |-����������������������������������������|\n");
}
//���ܡ����
void print(LinkedList head)
{
	LinkedList p;

	printf("\n������������ʱ����:      ");
	for(p=head->next;p!=NULL;p=p->next)
		printf("��%d��",p->data);
	printf("\n          <������>\n");
}
//���ܡ�����
void creat(LinkedList head)
{
	LinkedList p1,p2;
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
	{	a=scanf("%d",&k);	    
	    if(a==1)
		{
			p1=(LinkedList)malloc(sizeof(LNode));
		    p1->data=k;
	        p2->next=p1;		
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


