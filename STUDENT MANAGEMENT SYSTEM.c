#include <stdio.h>
#include <string.h>

void add_student ();
void edit_student_record ();
void search_information ();
void delete_student_record ();
void exit ();

struct student info;

FILE *file1,*file2;


int main()
{
    char password[100];
    int flag=0;
    for(int i=1; i<=3; i++)
    {
        printf("Enter the password : ");
        gets(password);
        if(strcmp(password,"tempo")==0)
        {
            system("cls");
            flag++;
            d_main();
            break;
        }
        else
        {
            printf("Invalid password.Try again\n");
            system("Pause");
            system("cls");
        }
    }
    if(flag==0)
    {
        printf("You enter invalid password 3 times.Try again");
        return 0;
    }
}

struct student
{
    char ID[15];
    char pnumber[20],batch[5];
    char name[20],add[20],pname[20];
};


void add_student ()
{
    system("cls");
    printf ("\n###Welcome to add_student###\n\n");
    struct student info[1000];
    file1=fopen("record.txt","ab+");
    int number;
    printf("How many student record do you want to save : ");
    scanf("%d",&number);
    for(int i=1; i<=number; i++)
    {
        fflush(stdin);
        printf("\nID           : ");
        gets(info[i].ID);

        printf("\nName         : ");
        gets(info[i].name);

        printf("\nAddress      : ");
        gets(info[i].add);

        printf("\nParents name : ");
        gets(info[i].pname);

        printf("\nBatch        : ");
        gets(info[i].batch);

        printf("\nPhone number : ");
        gets(info[i].pnumber);

        fwrite(&info[i],sizeof(info),1,file1);
        system("cls");
    }
    fclose(file1);
    printf("Press any key to menu");
    getch();
    system("cls");
    d_main();
}
void edit_student_record ()
{
    system("cls");
    printf ("\n###Welcome to edit_student record###\n\n");
    file1=fopen("record.txt","r+b");
    char id[15];
    int found=0,n;
    printf("Enter the ID : ");
    fflush(stdin);
    gets(id);
    system("cls");
    while(fread(&info,sizeof(info),1,file1))
    {
        if(strcmp(id,info.ID)==0)
        {
            found=1;
            break;
        }
    }
    if(found==1)
    {
        printf("ID           : %s\n",info.ID);
        printf("Name         : %s\n",info.name);
        printf("Address      : %s\n",info.add);
        printf("Parents name : %s\n",info.pname);
        printf("Batch        : %s\n",info.batch);
        printf("Phone number : %s\n\n",info.pnumber);
    }
    else
        {
            printf("Not found\n\n");
            printf("Press any key to menu");
            getch();
            system("cls");
            d_main();
        }

    printf("Which part do you want to change\n\n");
    printf(" 1 - Name\n");
    printf(" 2 - Address\n");
    printf(" 3 - Parents name\n");
    printf(" 4 - Batch\n");
    printf(" 5 - Phone number\n\n");
    printf("Enter your choice : ");
    scanf("%d",&n);
    system("cls");
    switch(n)
    {
    case 1 :

        printf("Name change\n\n");
        printf("Enter new name : ");
        fflush(stdin);
        gets(info.name);
        fseek(file1,-sizeof(info),SEEK_CUR);
        fwrite(&info,sizeof(info),1,file1);
        fclose(file1);
        printf("\n\n");
        printf("Press any key to menu");
        getch();
        system("cls");
        d_main();

        break;

    case 2 :

        printf("Address change\n\n");
        printf("Enter new address : ");
        fflush(stdin);
        gets(info.add);
        fseek(file1,-sizeof(info),SEEK_CUR);
        fwrite(&info,sizeof(info),1,file1);
        fclose(file1);
        printf("\n\n");
        printf("Press any key to menu");
        getch();
        system("cls");
        d_main();

        break;

    case 3 :

        printf("Parents name change\n\n");
        printf("Enter new name : ");
        fflush(stdin);
        gets(info.pname);
        fseek(file1,-sizeof(info),SEEK_CUR);
        fwrite(&info,sizeof(info),1,file1);
        fclose(file1);
        printf("\n\n");
        printf("Press any key to menu");
        getch();
        system("cls");
        d_main();

        break;

    case 4 :

        printf("Batch change\n\n");
        printf("Enter new batch : ");
        fflush(stdin);
        gets(info.batch);
        fseek(file1,-sizeof(info),SEEK_CUR);
        fwrite(&info,sizeof(info),1,file1);
        fclose(file1);
        printf("\n\n");
        printf("Press any key to menu");
        getch();
        system("cls");
        d_main();

        break;

    case 5 :

        printf("Phone number change\n\n");
        printf("Enter new phone number : ");
        fflush(stdin);
        gets(info.pnumber);
        fseek(file1,-sizeof(info),SEEK_CUR);
        fwrite(&info,sizeof(info),1,file1);
        fclose(file1);
        printf("\n\n");
        printf("Press any key to menu");
        getch();
        system("cls");
        d_main();

        break;
    }
}
void search_information ()
{
    system("cls");
    printf ("###Welcome to search_information###\n\n");
    file1=fopen("record.txt","rb");
    rewind(file1);
    int found=0;
    char id[10];
    printf("Enter the ID : ");
    fflush(stdin);
    gets(id);
    system("cls");
    while(fread(&info,sizeof(info),1,file1))
    {
        if(strcmp(id,info.ID)==0)
        {
            found=1;
            break;
        }
    }
    if(found==1)
    {
        printf("ID           : %s\n",info.ID);
        printf("Name         : %s\n",info.name);
        printf("Address      : %s\n",info.add);
        printf("Parents name : %s\n",info.pname);
        printf("Batch        : %s\n",info.batch);
        printf("Phone number : %s\n\n",info.pnumber);
    }
    else
        printf("Not found\n\n");
    fclose(file1);
    printf("Press any key to");
    getch();
    system("cls");
    d_main();
}
void delete_student_record ()
{
    system("cls");
    printf ("\n###Welcome to delete_student record###\n\n");
    file1=fopen("record.txt","rb");
    file2=fopen("temp.txt","ab");
    char id[15];
    printf("Enter the ID : ");
    fflush(stdin);
    gets(id);
    while(fread(&info,sizeof(info),1,file1))
    {
        if(strcmp(id,info.ID)==0)
        {
            printf("Item deleted\n\n");
        }
        else
            fwrite(&info,sizeof(info),1,file2);
    }
    fclose(file1);
    fclose(file2);
    remove("record.txt");
    rename("temp.txt","record.txt");
    printf("Press any key to menu");
    getch();
    system("cls");
    d_main();
}
void exit ()
{
    system("cls");
    printf ("\n###Welcome to exit###");
}
void d_main ()
{
    int number;
    printf ("###Welcome to student record###\n");
    printf (" 1.Add student\n");
    printf (" 2.Edit student record\n");
    printf (" 3.Search information\n");
    printf (" 4.Delete student record \n");
    printf (" 5.Exit\n");
    printf ("---_____---\n");
    printf ("Enter your choice : ");
    scanf ("%d",&number);
    switch (number)
    {
    case 1:
        add_student ();
        break;
    case 2:
        edit_student_record ();
        break;
    case 3:
        search_information ();
        break;
    case 4:
        delete_student_record ();
        break;
    case 5:
        exit ();
        break;
    default :
        printf ("try again!!!!\n");
    }
}


