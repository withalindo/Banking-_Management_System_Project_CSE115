#include <stdio.h>
#include<conio.h>
#include<string.h>
#include <stdlib.h>

struct login
{
    char name[100];
    int phn_num[100];
    char email[50];
    char acc[100];
    char pass[100];
    float balance;
} i;

struct job
{
    char name[100];
    char Phn_num[100];
    char mail[100];
    int birth_month;
    int birth_year;
    int birth_day;
    int a_month;
    int a_year;
    int a_day;

} j;

struct employee
{
    char name[100];
    int emp_id;
    char des[100];
    int cont_num;
    int age;
    int d, m, y;
    int salary;
} e;

// This is the function for sign in . This will create a new account..
char account_num[100],password[100];
int opt;

void signin()
{

    FILE * s1;
    s1 = fopen ( "login.txt","w");
    system("cls");

    printf("Enter your name : ");
    fflush(stdin);
    gets(i.name);

    printf("Enter your phone number: ");
    scanf("%d",&i.phn_num);
    printf("Enter your account number : ");
    fflush(stdin);
    scanf("%[^\n]",i.acc);
    printf("Set your password : ");
    fflush(stdin);
    scanf("%[^\n]",i.pass);

    fwrite(&i,sizeof(i),1,s1);
    fclose(s1);
    printf("\nYour Sigma account has been set. ");
    printf("\nNow you can login with your account number and password. ");
    printf("\nEnter any key to continue. ");
    getch();
    system("CLS");
    login();
}

//This is  he function for log in into an existing account..
void login()
{
    FILE * s1;
    s1 = fopen("login.txt","r");
    system("cls");

    printf("Enter your account number : ");
    fflush(stdin);
    scanf("%[^\n]",account_num);
    printf("Enter Your Password : ");
    fflush(stdin);
    scanf("%[^\n]",password);

    while ( fread(&i,sizeof(i),1,s1))
    {
        if( strcmp(account_num,i.acc) == 0 && strcmp(password,i.pass) == 0)
        {
            service();
        }
        else
        {
            printf("Incorrect account number or password. \nPlease try again later. ");
        }
    }
    fclose(s1);
}

//This the function for using customer service..
void service()
{
    FILE *fp, *filename;
    int amount;

    char cont, choice, pw;
    cont='y';
    while(cont == 'y')
    {
        system("CLS");
        printf("\n\t\t\t\tWelcome Back");
        printf("\n1. Balance inquiry.");
        printf("\n2. Add money to account.");
        printf("\n3. Withdraw money from account.");
        printf("\n4. On-line money transfer.");
        printf("\n5. Change account password.");
        printf("\n6. Exit.\n\n");

        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nYour current balance %.2f Taka ",i.balance);
            break;

        case 2:
            system("CLS");
            printf("Enter amount to be added : ");
            scanf("%d",&amount);
            i.balance += amount;

            fp = fopen(i.phn_num,"w");
            fwrite(&i,sizeof(i),1,fp);
            if(fwrite !=0) printf("\n\nYou have deposited %d Taka",amount);
            fclose(fp);
            break;

        case 3:
            system("CLS");
            printf("Enter amount you want to withdraw : ");
            scanf("%d",&amount);
            if(amount % 500 != 0)
                printf("\nSorry. Amount should be multiple of 500");
            else if(amount>i.balance)
                printf("\nSorry. Insufficient balance");
            else
            {
                i.balance -= amount;

                fp = fopen(i.phn_num,"w");
                fwrite(&i,sizeof(i),1,fp);
                if(fwrite !=0)
                    printf("\n\nYou have withdrawn %d Taka",amount);
                fclose(fp);
            }
            break;

        case 4:
            printf("Please enter a registered phone number to transfer balance:\t");
            scanf("%d",&i.phn_num);
            printf("Enter  amount to be transfered : ");
            scanf("%d",&amount);
            if(amount > i.balance)
                printf("\nSorry. Insufficient balance");
            else
            {
                fp = fopen(strcat(i.phn_num,".dat"),"r");
                if(fp==NULL)
                    printf("Sorry. Number is not registered");
                else
                {
                    fread(&i,sizeof(i),1,fp);
                    fclose(fp);

                    i.balance += amount;

                    fp = fopen(i.phn_num,"w");
                    fwrite(&i,sizeof(i),1,fp);
                    if(fwrite != 0)
                    {
                        printf("Account:%s",i.acc);
                        printf("\nPassword%s",i.pass);
                        printf("\nPhone%d",i.phn_num);
                        printf("\nBalance%f",i.balance);
                        printf("Your transfer is completed. You have transfered Rs.%.d to %d",amount,i.phn_num);
                        fclose(fp);

                        i.balance -= amount;
                        strcpy(filename,i.phn_num);
                        fp = fopen(strcat(filename,".dat"),"w");
                        fwrite(&i,sizeof(i),1,fp);
                        fclose(fp);
                    }
                }
            }
            break;
        case 5:
            printf("\n\nPlease enter your old password:\t");
            scanf("%s",&pw);
            if(!strcmp(pw,i.pass))
            {
                printf("\n\nPlease enter your new password:\t");
                scanf("%s",pw);
                strcpy(i.pass,pw);
                strcpy(filename,i.phn_num);
                fp = fopen(strcat(filename,".dat"),"w");
                fwrite(&i,sizeof(i),1,fp);
                fclose(fp);
                printf("\nPassword successfully changed");
            }
            else printf("\nSorry your password is wrong");

        default:
            break;

        case 6:
            fclose(fp);
            exit(0);
        }
        printf("\n\nDo you want to continue?[y/n] : ");
        scanf("%s",&cont);
    }
}

//This is the function for apply for a job on-line..
void job_application()
{
    int ch;
    FILE*file;
    printf("If you have completed your B.Sc degree then you can apply for the job.\nIf your answer is yes, hit 1 and if your answer is no, then hit 0. ");
    printf("\nPlease enter you choice : ");
    scanf("%d",&ch);

    file=fopen("job.txt","w");
    switch(ch)
    {
    case 1:
    {
        system("CLS");
        printf("Name:  ");
        fflush(stdin);
        gets(j.name);
        printf("Phone Number:  ");
        fflush(stdin);
        gets(j.Phn_num);
        printf("Email Address:  ");
        fflush(stdin);
        gets(j.mail);
        printf("Date of birth:  ");
        fflush(stdin);
        scanf("%d",&j.birth_day);
        printf("month of birth:  ");
        fflush(stdin);
        scanf("%d",&j.birth_month);
        printf("Year of birth:  ");
        fflush(stdin);
        scanf("%d",&j.birth_year);
        printf("Date of application:  ");
        fflush(stdin);
        scanf("%d",&j.a_day);
        printf("month of application:  ");
        fflush(stdin);
        scanf("%d",&j.a_month);
        printf("Year of application:  ");
        fflush(stdin);
        scanf("%d",&j.a_year);
        if((j.a_year-j.birth_year)>25||(j.a_year-j.birth_year)<20)
        {
            printf("You are not eligible for the job");
            exit(1);
        }
        else
        {
            printf("Your interview will be on %d/%d/%d \n Good luck for the interview .",j.a_day,j.a_month+1,j.a_year);
        }
        break;


    }
    case 0:
    {
        printf("Sorry");
        break;
    }
    default:
    {
        printf("Something went wrong. Please try again later.");
        break;
    }

    }
    fwrite(&j,sizeof(j),1,file);

    fclose(file);


}

//This is the function for showing bank employee's details..
void empInfo()
{
    int choice;
    while(1)
    {
        system("cls");
        printf("\t\t\t\t\tWelcome to Sigma on-line Banking\n");
        printf("\t\t\t\t   We are here to ensure safe and easy banking\n");
        printf("\t\t\t\t\t Employee Section(Confidential)\n\n");
        printf("1. Add Employee's Records\n");
        printf("2. Show Employee's Records\n");
        printf("3. Search Employee's Records\n");
        printf("4. Delete Employee's Records\n");
        printf("5. Return to main menu.\n");
        printf("6. Exit\n");
        printf("Your Choice : ");
        fflush(stdin);
        scanf("%d", &choice);

        switch(choice)
        {
        case 1 :
            system("cls");
            addRecords();
            system("cls");
            break;

        case 2 :
            system("cls");
            listRecords();
            system("cls");
            break;

        case 3 :
            system("cls");
            searchRecords();
            printf("\nEnter any key to continue : ");
            getch();
            system("cls");
            break;

        case 4 :
            system("cls");
            deleteRecords();
            printf("\nEnter any key to continue : ");
            getch();
            system("cls");
            break;

        case 5 :
            system("cls");
            main();
            break;

        case 6 :
            system("cls");
            printf("Thank you for being with us.\n");
            exit(0);

        default :
            system("cls");
        }
    }
}
void addRecords()
{
    char another;
    FILE *fp;


    another = 'y';
    while(another == 'y')
    {
        system("cls");
        printf("\t\t\t\tAdd Employee Information\n\n");
        fp = fopen("emp_info.txt","a");

        printf("\nEnter Name : ");
        scanf("%s", &e.name);
        fflush(stdin);
        printf("Enter Designation : ");
        scanf("%s", &e.des);
        fflush(stdin);
        printf("Enter the 5 Digit Employee ID : ");
        scanf("%d",&e.emp_id);
        printf("Enter Contact Number : ");
        scanf("%d", &e.cont_num);
        printf("Enter Age : ");
        scanf("%d", &e.age);
        printf("Enter joining date : ");
        scanf("%d%d%d",&e.d, &e.m, &e.y);
        printf("Enter salary : ");
        scanf("%d", &e.salary);

        if(fp==NULL)
        {
            fprintf(stderr,"\t\tCan't Open File.\n");
        }
        else
            printf("\t\t\nRecords stored successfully.\n\n");

        fwrite(&e,sizeof(struct employee),1,fp);
        fclose(fp);

        printf("Add another record?(y/n) : ");
        scanf("%s", &another);

    }
}

void listRecords()
{
    FILE *fp;

    fp = fopen("emp_info.txt","r");

    printf("\t\t\t\t\tOn-line Sigma Bank Ltd's Employee List : \n\n");

    if(fp==NULL)
    {
        fprintf(stderr,"No Records to Show. Enter any key to continue.\n");
    }

    while(fread(&e,sizeof(struct employee),1,fp))
    {
        printf("Employee Name : %s",e.name);
        printf("\nDesignation : %s",e.des);
        printf("\nEmployee ID : %d",e.emp_id);
        printf("\nContact Number : 0%d",e.cont_num);
        printf("\nAge : %d",e.age);
        printf("\nDate of joining : %d-%d-%d",e.d, e.m, e.y);
        printf("\nSalary  : %d",e.salary);
        printf("\n");
        printf(".......................................\n\n");
    }
    fclose(fp);
    getch();
}

void searchRecords()
{
    FILE *fp;
    char another;


    printf("\t\t\t\tSearch For Employee With Unique Employee ID");

    another = 'y';
    while(another == 'y')
    {
        int search_id, f=0;
        fp = fopen("emp_info.txt","r");

        printf("\nEnter Employee ID : ");
        scanf("%d",&search_id);

        while(fread(&e,sizeof(struct employee),1,fp))
        {
            if(e.emp_id == search_id)
            {
                f=1;
                printf("Employee Name : %s",e.name);
                printf("\nDesignation : %s", e.des);
                printf("\nUnique Employee ID : %d", e.emp_id);
                printf("\nContact Number : 0%d", e.cont_num);
                printf("\nAge : %d", e.age);
                printf("\nDate of joining : %d-%d-%d",e.d, e.m, e.y);
                printf("\nSalary : %d", e.salary);
                printf("\n\n");
            }
        }
        if(!f)
        {
            printf("Records not found.\n");
        }
        fclose(fp);
        getch();

        printf("Search another record ? (y/n) : ");
        fflush(stdin);
        another = getch();
    }
}

void deleteRecords()
{
    FILE *fp, *ft;
    char another;


    another = 'y';
    while(another == 'y')
    {
        int search_id;

        fp = fopen("emp_info.txt","r");
        ft = fopen("temp.txt","a");

        printf("Enter Employee ID to delete info : ");
        scanf("%d", &search_id);

        if(fp==NULL)
        {
            fprintf(stderr,"Can't open file\n");
            exit(0);
        }

        while(fread(&e,sizeof(struct employee),1,fp))
        {
            if(e.emp_id != search_id)
            {
                fwrite(&e,sizeof(struct employee),1,ft);
            }
        }
        fclose(fp);
        fclose(ft);

        remove("emp_info.txt");
        rename("temp.txt","emp_info.txt");

        printf("Records deleted successfully.\n");

        printf("\nDelete another record? (y/n) : ");
        fflush(stdin);
        another = getch();
    }
}

//This the main function..

int main()

{

    printf("\t\t\t\tWelcome to Sigma on-line Banking\n\t\t\tWe are here to ensure your safe and easy banking ");

    printf("\n\nPlease tell us what you want to do.");

    printf("\n\n1. Register a sigma banking account.");

    printf("\n2. Log-in to your sigma banking account.");

    printf("\n3. Apply for a job:");

    printf("\n4. See bank staff's information(Confidential).");

    printf("\n\nEnter your choice : ");

    scanf("%d",&opt);

    int password = 12345, pw;

    switch(opt)

    {

    case 1:

    {
        signin();

        break;

    }

    case 2:

    {
        login();

        break;

    }

    case 3:

    {

        job_application();

        break;
    }

    case 4:

    {

        system("cls");

        printf("\nYou need to enter the 5 digit sigma corporate password to see details.\n");

        printf("Please enter the password : ");

        scanf("%d",&pw);

        if(password == pw)

        {

            empInfo();

        }
        else

        {

            printf("Wrong password. Try again.\n");

        }

    }
    default:

    {
        printf("\nSomething went wrong . Please try again later.");

        break;
    }

    }

    return 0;

}