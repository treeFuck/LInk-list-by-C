
#include "duLinkedList.c"
#include "../head/duLinkedList.h"

int main()
{
    DuLinkedList head;
	char t;

	new(&head);
	abc();
	printf("##������ѡ��Ĳ���(������ĵ�һ���ַ�Ϊ׼)##       ");

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
			printf("�����������������:        ");
		while(getchar()!='\n')
			continue;
	}
	printf("�����Ѿ���������л���ʹ��\n");
    getchar();

}