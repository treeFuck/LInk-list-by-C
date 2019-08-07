#include "linkedList.c"
#include "../head/linkedList.h"

int main()
{
    LinkedList head;
	char t;

	new(&head);
	abc();
	printf("##输入你选择的操作(以输入的第一个字符为准)##       ");

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
			printf("输入错误，请重新输入:        ");
		while(getchar()!='\n')
			continue;
	
	}
	printf("程序已经结束，感谢你的使用\n");
    getchar();

}
