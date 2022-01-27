//Simple phonebook project- SAHITHIYA
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
struct person
{
    char name[35];
    char address[50];
    long int mble_no;
    char sex[8];
    char mail[100];
    char citizanship[20];

    };
void menu();
void got();
void start();
void back();
void addrecord();
void listrecord();
void modifyrecord();
void deleterecord();
void searchrecord();
int main()
{
    system("color 5f");
    start();
    return 0;
}
void back()
{
    start();
}
void start()
{
    menu();
}
void menu()
{
    system("cls");
printf("\t\t------------WELCOME TO PHONEBOOK-------------");

printf("\n\n\t\t\t  MENU\t\t\n\n");
printf("\t1.Add New   \t2.List   \t3.Exit  \n\t4.Modify \t5.Search\t6.Delete");
printf("\n\n\n\n\n Enter a Choice: ");

switch(getch())
{
    case '1':

                addrecord();
    break;
   case '2': listrecord();
    break;
    case '3': exit(0);
    break;
    case '4': modifyrecord();
    break;
    case '5': searchrecord();
    break;
    case '6': deleterecord();
    break;
    default:
                system("cls");
                printf("\nEnter 1 to 6 only");
                printf("\n Enter any key");
                getch();

menu();
}
}
        void addrecord()
{
        system("cls");
        FILE *f;
        struct person p;
        f=fopen("project","ab+");
        printf("\n Enter name: ");
        got(p.name);
        printf("\nEnter the address: ");
        got(p.address);
        printf("\nEnter phone no.:");
        scanf("%ld",&p.mble_no);
        printf("Enter sex:");
        got(p.sex);
        printf("\nEnter e-mail:");
         got(p.mail);
        printf("\nEnter citizen :");
        got(p.citizanship);
        fwrite(&p,sizeof(p),1,f);

      fflush(stdin);
        printf("\nRecord saved");

fclose(f);

    printf("\n\nEnter any key");

	 getch();
    system("cls");
    menu();
}
void listrecord()
{
    struct person p;
    FILE *f;
f=fopen("project","rb");
if(f==NULL)
{
printf("\nfile opening error in listing :");

exit(1);
}
while(fread(&p,sizeof(p),1,f)==1)
{
     printf("\n\n\n YOUR RECORD IS\n\n ");
        printf("\nName=%s\nAdress=%s\nMobile no=%ld\nSex=%s\nE-mail=%s\nCitizen=%s",p.name,p.address,p.mble_no,p.sex,p.mail,p.citizanship);

	 getch();
	 system("cls");
}
fclose(f);
 printf("\n Enter any key");
 getch();
    system("cls");
menu();
}
void searchrecord()
{
    struct person p;
FILE *f;
char name[100];

f=fopen("project","rb");
if(f==NULL)
{
    printf("\n error in opening\a\a\a\a");
    exit(1);

}
printf("\nEnter name of person to search\n");
got(name);
while(fread(&p,sizeof(p),1,f)==1)
{
    if(strcmp(p.name,name)==0)
    {
        printf("\n\tDetail Information About %s",name);
        printf("\nName:%s\naddress:%s\nMobile no:%ld\nsex:%s\nE-mail:%s\nCitizan:%s",p.name,p.address,p.mble_no,p.sex,p.mail,p.citizanship);
    }
        else
        printf("File not found");

}
 fclose(f);
  printf("\n Enter any key");

	 getch();
    system("cls");
menu();
}
void deleterecord()
{
    struct person p;
    FILE *f,*ft;
	int flag;
	char name[100];
	f=fopen("project","rb");
	if(f==NULL)
		{

			printf("CONTACT'S DATA NOT ADDED YET.");

		}
	else
	{
		ft=fopen("temp","wb+");
		if(ft==NULL)

            printf("file opening error");
		else

        {


		printf("Enter CONTACT'S NAME:");
		got(name);

		fflush(stdin);
		while(fread(&p,sizeof(p),1,f)==1)
		{
			if(strcmp(p.name,name)!=0)
				fwrite(&p,sizeof(p),1,ft);
			if(strcmp(p.name,name)==0)
                flag=1;
		}
	fclose(f);
	fclose(ft);
	if(flag!=1)
	{
		printf("NO CONACT'S RECORD TO DELETE.");
		remove("temp.txt");
	}
		else
		{
			remove("project");
			rename("temp.txt","project");
			printf("RECORD DELETED SUCCESSFULLY.");

		}
	}
}
 printf("\n Enter any key");

	 getch();
    system("cls");
menu();
}

void modifyrecord()
{
    int c;
    FILE *f;
    int flag=0;
    struct person p,s;
	char  name[50];
	f=fopen("project","rb+");
	if(f==NULL)
		{

			printf("CONTACT'S DATA NOT ADDED YET.");
			exit(1);


		}
	else
	{
	    system("cls");
		printf("\nEnter CONTACT'S NAME TO MODIFY:\n");
            got(name);
            while(fread(&p,sizeof(p),1,f)==1)
            {
                if(strcmp(name,p.name)==0)
                {



                    printf("\n Enter name:");
                    got(s.name);
                    printf("\nEnter the address:");
                    got(s.address);
                    printf("\nEnter phone no:");
                    scanf("%ld",&s.mble_no);
                    printf("\nEnter sex:");
                    got(s.sex);
                    printf("\nEnter e-mail:");
                    got(s.mail);
                    printf("\nEnter citizen \n");
                    got(s.citizanship);
                    fseek(f,-sizeof(p),SEEK_CUR);
                    fwrite(&s,sizeof(p),1,f);
                    flag=1;
                    break;



                }
                fflush(stdin);


            }
            if(flag==1)
            {
                printf("\n your data id modified");

            }
            else
            {
                    printf(" \n Data is not found");

            }
            fclose(f);
	}
	 printf("\n Enter any key");
	 getch();
    system("cls");
	menu();

}
void got(char *name)
{

   int i=0,j;
    char c,ch;
    do
    {
        c=getch();
                if(c!=8&&c!=13)
                {
                    *(name+i)=c;
                        putch(c);
                        i++;
                }
                if(c==8)
                {
                    if(i>0)
                    {
                        i--;
                    }
                   // printf("h");
                    system("cls");
                    for(j=0;j<i;j++)
                    {
                        ch=*(name+j);
                        putch(ch);

                    }

                }
    }while(c!=13);
      *(name+i)='\0';
}
