#include "linkedList.c"
#include "../head/linkedList.h"

int main()
{
    LinkedList head;
	char t;

	new(&head);
	abc();
	printf("##������ѡ��Ĳ���(������ĵ�һ���ַ�Ϊ׼)##       ");

	while((t=getchar())!='j')
	{
		if('\n'==t)
			continue;
		if('a'<=t&&t<='i')
		{
			switch(t)
			{
				case'a':
					creat(head);
					wsg();
					break;
			    case'b':
					insert(head);
					wsg();
					break;
			    case'c': 
					del(head);
					wsg();
					break;
			    case'd':
					sea(head);
					wsg(); 
					break;
			    case'e':
					print(head);
					wsg();
					break;
			    case'f':
					head=DestroyList(&head); 
					wsg();
					break;
			    case'g':
					rev(head);
					wsg();
					break;
			    case'h':
					head=ReverseEvenList(&head);
				    wsg();
					break;
			    case'i':
					FindMidNode(head);
					wsg();
					break;
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
