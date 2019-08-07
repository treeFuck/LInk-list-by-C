
#include "duLinkedList.c"
#include "../head/duLinkedList.h"

int main()
{
    DuLinkedList head;
	char t;

	new(&head);
	abc();
	printf("##输入你选择的操作(以输入的第一个字符为准)##       ");

	while((t=getchar())!='k')
	{
		if(t=='\n') continue;
		
		if('a'<=t&&t<='j')
		{	
			switch(t)
			{
	    	case'a':
				 creat(head);wsg();break;
			case'b':
				 beinsert(head);wsg();break;
			case'c':
				 afinsert(head);wsg();break;	 
			case'd':
				 sea(head);wsg();break;
			case'e':
				 del(head);wsg();break;			 
			case'f':
				 head=DestroyList_DuL(&head);wsg();break;
			case'g':
				 print(head);wsg();break;
			}		
		}
		else
			printf("输入错误，请重新输入:        ");
		while(getchar()!='\n')
			continue;
	}
	printf("程序已经结束，感谢你的使用\n");
    getchar();

}