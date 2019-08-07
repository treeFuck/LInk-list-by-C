#include "../head/linkedList.h"

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
//初始化
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
    if(b==SUCCESS) printf("\n                 *初始化·成功* \n\n");
        else printf("\n               *初始化·失败* \n\n");	
}

    
/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
//功能·销毁
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
	printf("          <成功销毁已建链表>");
	printf("\n是否重建链表一个链表：(输入 y / n)\n     ");
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
		printf("程序已经结束，感谢你的使用\n");
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
//功能·插入
Status InsertList(LNode *p, LNode *q) {      
	int a;

	printf("【插入】你想要插入的数据\n        (以输入的第一个数字为准):");
	fflush(stdin);
	a=scanf("%d",&q->data);
	if(a==0)
	{
		printf("\n          <输入错误>\n");
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
	printf("【插入】该链表共有%d个节点，你选择插入数据到第几个节点的后面\n        (以输入的第一个数字为准): ",sum);
	fflush(stdin);
	a=scanf("%d",&n);
	if(a==0)
	{
		printf("\n          <输入错误>\n");
		insert(head);
	}
	
	if(n<0||n>sum)
	{
		printf("【插入】该链表只有%d个节点，无法插入\n",sum);
		printf("          <退出插入功能>\n");
	}
	else
	{
		for(i=0,p=head;i<n;i++)
			p=p->next;
		q=(LinkedList)malloc(sizeof(LNode));
        b=InsertList(p,q);
		if(b==SUCCESS) printf("          <插入成功>\n");
		else printf("插入失败\n");
	}
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
//功能·删除
Status DeleteList(LNode *p, ElemType *e) {
    LinkedList k;

	if(p->next==NULL) 
	{
		return ERROR;
		printf("删除失败\n");
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
	printf("【删除】该链表共有%d个节点，你选择删除第几个节点的数据\n        (以输入的第一个数字为准):",sum);
	fflush(stdin);
	a=scanf("%d",&n);
	if(a==0)
	{
		printf("\n          <输入错误>\n");
		del(head);
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
        b=DeleteList(p,&e);
		if(b==SUCCESS) printf("          <删除第%d节点数据%d成功>\n",n,e);
		else printf("删除失败\n");
	}
}
/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
//功能·遍历（未做）
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {

}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
//功能·搜索
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
		printf("【搜索】在第%d个结点找到%d\n",n,e);
		return SUCCESS;
	}

}
void sea(LinkedList head)
{
	int n,a;
    Status b;

	printf("【搜索】输入你想搜索的数据\n        (以输入的第一个数字为准):      ");
	fflush(stdin);
	a=scanf("%d",&n);
	if(a==0)
	{
		printf("\n          <输入错误>\n");
		sea(head);
	}
    b=SearchList(head,n);
	if(b==ERROR)
		printf("【搜索】链表中没有该数据\n");
	printf("          <搜索完毕>\n");
}


/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
//功能·反转
Status ReverseList(LinkedList *L) {

    LNode *current, *pre, *pnext;    //分别是当前节点，直接前驱节点，直接后继节点

    current=(*L)->next;                //初始化
    pre=NULL;
    while(current!= NULL)
	{   
        pnext = current -> next;      //保留后继节点   
        current -> next = pre;        //新的后继指向前驱实现反转
        pre = current;
        current = pnext;              //将当前节点向后移动
    }
    (*L)->next=pre;
	return SUCCESS;
}
void rev(LinkedList L)
{
	Status b;

	b=ReverseList(&L);
	if(b==SUCCESS)
		printf("          <反转成功>\n");

}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
//功能·判断是否有环（未应用）
Status IsLoopList(LinkedList L) {
	LinkedList p1,p2;
	int a=0;

	for(p1=p2=L;p2!=NULL;p1=p1->next,p2=p2->next->next)
		if(p1==p2)
			a=1;
	if(a==1) printf("该链表有环\n");
	else printf("该链表没有环\n");
    return SUCCESS;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
//功能·偶节点反转
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
	printf("          <反转成功>\n");
	return(*L);
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
//功能·寻找中间点（未做）
void FindMidNode(LinkedList L) {
	LinkedList a,b;
	int n=0;
    
	if(L->next!=NULL)
	{
		for(a=b=L;b!=NULL&&b->next!=NULL;a=a->next,b=b->next->next,n++)
    
	    if(b==NULL)
		     printf("中间节点为第%d节点【%d】\n",n,a->data);
	    else if(b->next==NULL) 
		     printf("中间节点为第%d节点【%d】与第%d节点【%d】",n,a->data,n+1,a->next->data);
	}
	else
		printf("    <链表为空>\n");
}

//以下为自定义函数
//功能·功能表
void abc()
{
	printf("                 *请选择以下功能*\n\n");
	printf("     |——————输入  &&   功能———————|\n");
	printf("     |-————————————————————|\n");
	printf("     |-------------a    TO   生成--------------|\n");
	printf("     |-------------b    TO   插入--------------|\n");
	printf("     |-------------c    TO   删除--------------|\n");
	printf("     |-------------d    TO   搜索--------------|\n");
	printf("     |-------------e    TO   输出--------------|\n");
	printf("     |-------------f    TO   销毁--------------|\n");
	printf("     |-------------g    TO   反转--------------|\n");
	printf("     |-------------h    TO   反转偶数结点------|\n");
	printf("     |-------------i    TO   寻找中间点--------|\n");
	printf("     |-------------j    TO   退出--------------|\n");
	printf("     |-————————————————————|\n");
	printf("     |-————————————————————|\n");
}
//功能·输出
void print(LinkedList head)
{
	LinkedList p;

	printf("\n【输出】输出此时链表:      ");
	for(p=head->next;p!=NULL;p=p->next)
		printf("【%d】",p->data);
	printf("\n          <输出完毕>\n");
}
//功能·生成
void creat(LinkedList head)
{
	LinkedList p1,p2;
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
	printf("          <输入完成>\n");
}

void wsg()
{	
	system("PAUSE");
	system("cls");
	abc();
	printf("##输入你选择的操作(以输入的第一个字符为准)##       ");
}


