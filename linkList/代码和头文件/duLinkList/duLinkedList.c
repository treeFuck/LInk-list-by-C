#include "../head/duLinkedList.h"

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
//初始化
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
    if(b==SUCCESS) printf("\n                 *初始化·成功* \n\n");
        else printf("\n               *初始化·失败* \n\n");	
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
//功能·销毁
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
	printf("          <成功销毁已建链表>");
    printf("\n是否重建链表一个链表：(输入 y / n)\n     ");
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
		printf("程序已经结束，感谢你的使用\n");
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
//功能·前插
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
	int a;

	printf("【前插】你想要插入的数据\n        (以输入的第一个数字为准):");
	fflush(stdin);
	a=scanf("%d",&q->data);
	if(a==0)
	{
		printf("\n          <输入错误>\n");
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
	printf("【前插】该链表共有%d个节点，你选择插入数据到第几个节点的前面\n        (以输入的第一个数字为准):",sum);
	fflush(stdin);
	a=scanf("%d",&n);
	if(a==0)
	{
		printf("\n          <输入错误>\n");
		exit(0);
	}
	
	if(n<0||n>sum)
	{
		printf("【插入】该链表只有%d个节点，无法插入\n",sum);
		printf("          <退出插入功能>\n");
	//	exit(0);
	}
	else
	{
		for(i=0,p=head;i<n;i++)
			p=p->next;
		q=(DuLinkedList)malloc(sizeof(DuLNode));
        b=InsertBeforeList_DuL(p,q);
		if(b==SUCCESS) printf("          <插入成功>\n");
		else printf("插入失败\n");
	}
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
//功能·后插
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
	int a;

    printf("【后插】你想要插入的数据\n        (以输入的第一个数字为准):");
	fflush(stdin);
	a=scanf("%d",&q->data);
	if(a==0)
	{
		printf("\n          <输入错误>\n");
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
	printf("【后插】该链表共有%d个节点，你选择插入数据到第几个节点的后面:\n        (以输入的第一个数字为准)",sum);
	fflush(stdin);
	a=scanf("%d",&n);
	if(a==0)
	{
		printf("\n          <输入错误>\n");
		exit(0);
	}
	
	if(n<0||n>sum)
	{
		printf("【后插】该链表只有%d个节点，无法插入\n",sum);
		printf("          <退出插入功能>\n");
	//	exit(0);
	}
	else
	{
		for(i=0,p=head;i<n;i++)
			p=p->next;
		q=(DuLinkedList)malloc(sizeof(DuLNode));
        b=InsertAfterList_DuL(p,q);
		if(b==SUCCESS) printf("          <插入成功>\n");
		else printf("插入失败\n");
	}
}
/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
//功能·删除
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
	DuLinkedList k;

	if(p->next==NULL) 
	{
		return ERROR;
		printf("删除失败\n");
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
	printf("【删除】该链表共有%d个节点，你选择删除第几个节点的数据:\n        (以输入的第一个数字为准)",sum);
	fflush(stdin);
	a=scanf("%d",&n);
	if(a==0)
	{
		printf("\n          <输入错误>\n");
		exit(0);
	}

	if(n<1||n>sum)
	{
		printf("【删除】该链表只有%d个节点，无法删除第%d节点\n",sum,n);
		printf("          <退出删除功能>\n");
	}
	else
	{
		for(i=0,p=head;i<n-1;i++)
			p=p->next;
        b=DeleteList_DuL(p,&e);
		if(b==SUCCESS) printf("          <删除第%d节点数据%d成功>\n",n,e);
		else printf("删除失败\n");
	}
}
/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit 
 *	@return		 : Status
 *  @notice      : None
 */
 //功能·遍历（未做）
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	
}


//自定义函数
//功能·功能表
void abc()
{
	printf("                 *请选择以下功能*\n\n");
	printf("     |——————输入  &&   功能———————|\n");
	printf("     |-————————————————————|\n");
	printf("     |-------------a    TO   生成--------------|\n");
	printf("     |-------------b    TO   前插--------------|\n");
	printf("     |-------------c    TO   后插--------------|\n");
	printf("     |-------------d    TO   搜索--------------|\n");
	printf("     |-------------e    TO   删除--------------|\n");
	printf("     |-------------f    TO   销毁--------------|\n");
	printf("     |-------------g    TO   输出--------------|\n");
	printf("     |-------------j    TO   退出--------------|\n");
	printf("     |-————————————————————|\n");
	printf("     |-————————————————————|\n");
}
//功能·输出
void print(DuLinkedList head)
{
	DuLinkedList p;

	printf("\n【输出】输出此时链表:       ");
	for(p=head->next;p!=NULL;p=p->next)
		printf("【%d】",p->data);
	printf("\n          <输出完毕>\n");
}
//功能·生成
void creat(DuLinkedList head)
{
	DuLinkedList p1,p2;
	ElemType k,i,a,n;

	p2=head;
    printf("【输入】想要创建的链表节点数\n        (以输入的第一个数字为准):");
	fflush(stdin);
	a=scanf("%d",&n);
	fflush(stdin);
	if(a==0){
		printf("       <输入错误>\n请重新开始:\n");
        creat(head);
	}
	printf("【输入】输入【int】型数据%d个\n       (自动排错，输入数字用空格隔开，回车结束输入):",n);
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
	printf("          <输入完成>\n");
}

void wsg()
{
	system("PAUSE");
	system("cls");
	abc();
	printf("##输入你选择的操作(以输入的第一个字符为准)##       ");
}

//功能·搜索
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
		printf("【搜索】在第%d个结点找到%d\n",n,e);
		return SUCCESS;
	}

}
void sea(DuLinkedList head)
{
	int n;
    Status b,a;

	printf("【搜索】输入你想搜索的数据:\n        (以输入的第一个数字为准)");
	fflush(stdin);
	a=scanf("%d",&n);
	if(a==0)
	{
		printf("\n          <输入错误>\n");
		exit(0);
	}
    b=SearchList_Du(head,n);
	if(b==ERROR)
		printf("【搜索】链表中没有该数据\n");
	printf("          <搜索完毕>\n");
}