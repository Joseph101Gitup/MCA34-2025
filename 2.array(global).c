#include<stdio.h>
int a[5],pos=-1;
void insert(int n)
{
	if(pos+1==5)
	{
		printf("Error:Array is full");
	}
	else
	{
		a[++pos]=n;
	}
}
void search(int s)
{
	int flag=0,i;
	for(i=0;i<=pos;i++)
	{
		if(a[i]==s)
		{
			flag=1;
			break;
		}
	}
	if(flag)
	{
		printf("%d found at location %d",s,i);
	}
	else
	{
		printf("Element not found");
	}
}
void del()
{
	if(pos==-1)
	{
		printf("Error:Array is empty");
    }
	else
	{
		printf("\n Deleted :%d",a[pos--]);	
    }
}
void display()
{
	int i;
	for(i=0;i<=pos;i++)
	{
		printf("%d ",a[i]);
	}
}
void sort()
{
	int temp,i,j;
	for(i=0;i<=pos;i++)
	{
		for(j=0;j<pos;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
			}
		}
	}
	display();
}
int menu()
{
	int ch;
	printf("\n 1.INSERT \n 2.DELETE \n 3.SEARCH \n 4.SORT \n 5.Display \n 6.EXIT \n Enter Your Choice:");
	scanf("%d",&ch);
	return ch;
}
void process()
{
	int ch,n;
	for(ch=menu();ch!=6;ch=menu())
	{
		switch(ch)
		{
			case 1:printf("Enter the value to insert:");
				   scanf("%d",&n);
				   insert(n);
				   break;
			case 2:del();
					break;
			case 3:printf("Enter the value to search:");
				   scanf("%d",&n);
				   search(n);
				   break;
			case 4:sort();
					break;
			case 5:display();
					break;
			default:printf("Error:Wrong Choice");
			
		}
	
	}
}

int main()
{
	process();
	return 0;
}

