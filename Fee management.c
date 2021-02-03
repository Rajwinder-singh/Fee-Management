#include <stdio.h>
#include <conio.h>
#include<string.h>
struct student
{
	int fee,blnc;
	char name[20],fname[20],id[10];
}s1;
main()
{
	int i,j,k=0,tot=89000,fee,size;
	char chr,id[10];
	FILE *ptr;
	for(i=1;i<=4;i++,k=0)
	{
		for(j=1;j<=4-i;j++)
		{
			printf(" ");
		}
		while(k!=2*i-1)
		{
			printf("*");
		//	sleep(1);
			++k;
		}
		printf("\n");
	}
	printf("WELCOME\n");
	for(i=4;i>=1;--i)
	{
		for(j=0;j<4-i;++j)
		{
			printf(" ");
		}
		for(k=i;k<=2*i-1;++k)
		{
			printf("*");
		//	sleep(1);
			
		}
		for(k=0;k<i-1;++k)
			printf("*");
		printf("\n");
	}
	printf("Press any key to continue");
	getch();
	start: system("cls");
	printf("1. Add new Student\n");
	printf("2. Pay fee\n");
	printf("3. Exit\n");
	scanf("%d",&i);
	if(i<0 || i>4)
	{
		printf("Please Enter a valid number");
		sleep(2);
		goto start;
	}
	ptr=fopen("student.txt","w");
	if(ptr==NULL)
	{
		printf("\nError\n");
		sleep(2);
	}
	switch(i)
	{
		case 1: printf("Enter Student name");
				scanf("%s",s1.name);
				printf("Enter Father's name");
				scanf("%s",s1.fname);
				printf("Enter Student id");
				scanf("%s",&s1.id);
				fwrite(&s1,sizeof(struct student),1,ptr);
				fflush(ptr);
				if(fwrite!=0)
				{
					printf("Added successfull");
				}
				fclose(ptr);
				goto start;
		case 2: 
				ptr= fopen("student.txt","w+");
				if(NULL !=ptr)
				{
					fseek(ptr,0,SEEK_END);
					size=ftell(ptr);
					if(size==0)
					{
						printf("Please add student");
						sleep(2);
						goto start;
					}
				}
				printf("Enter student id");
				scanf("%s",&id);
				while(fread(&s1,sizeof(struct student),1,ptr))
				{
					if(s1.id==id)
					{
						printf("Please enter fee to be paid");
						scanf("%d",&fee);
						s1.blnc=tot-fee;
						printf("Your balance will be %d",s1.blnc);
						sleep(2);
						printf("Successfully paid");
						sleep(2);
						goto start;
					}
				}
		case 3: exit(1);
	}
}
