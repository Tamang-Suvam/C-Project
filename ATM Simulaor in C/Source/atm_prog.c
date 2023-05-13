  //AUM SRI SAI RAM
  //The following contains the C project for the academic session 2018-19
  //Done By:Suvam Tamang

  #include<stdio.h>
  #include<time.h>
  #include<stdlib.h>
  #include<string.h>
  #include"atm_header.h"
  
void main()
{
    char name[20];
    int i;
    char *pin;
    char acc_no[15];
    int choice;
    FILE *f1,*f2;
    int option;
    float balance;
    bank_details help;
    do
    {
    system("clear");
    printf("\n\t\t*******************************************************************************************");//printing the main menu
    printf("\n\t\t*******************************************************************************************");
    printf("\n\t\t*** |                                                                                 | ***");
    printf("\n\t\t*** |%s       !!!!!!>>>>>>>>>>>STATE BANK OF INDIA WELCOMES YOU<<<<<<<<<<<!!!!!!!%s       | ***",Red,Reset);
    printf("\n\t\t*** |       State Bank of India services now available 24*7                           | ***");
    printf("\n\t\t*** |       Please let us know what services you would like to get from us??....      | ***");
    printf("\n\t\t*** |                                                                                 | ***");
    printf("\n\t\t*** |    %s [1]: Registration for a new account %s                                        | ***",Cyan);
    printf("\n\t\t*** |    %s [2]: Make withdrawl and deposit     %s                                        | ***");
    printf("\n\t\t*** |    %s [3]: View account details           %s                                        | ***");
    printf("\n\t\t*** |    %s [4]: Modify customer details        %s                                        | ***");
    printf("\n\t\t*** |    %s [5]: Make Balance Transfer          %s                                        | ***");
    printf("\n\t\t*** |    %s [6]: Recent transaction details     %s                                        | ***");
    printf("\n\t\t*** |    %s [7]: Make pin change                %s                                        | ***");
    printf("\n\t\t*** |    %s [8]: Fast Cash                       %s                                       | ***");
    printf("\n\t\t*** |    %s [9]: exit                            %s                                       | ***",Cyan,Reset);
    printf("\n\t\t*** |                                                                                 | ***");
    printf("\n\t\t*******************************************************************************************");
    printf("\n\t\t*******************************************************************************************");
    printf("\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:  
                 system("clear");//allows a user to register himself 
                 //f1=fopen("../Data/ALL_BANK_DETAILS.txt","r+");
                 f1=fopen("/home/suvam/PROJECT_2018-19(163244)/Data/ALL_BANK_DETAILS.txt","r+");
                 if(f1==NULL)
                 {
                      printf("%sSorry!...File can't be opened%s\n",Red,Reset);
                      exit(1);
                 }
                 create_new_account(f1);
                 break;
        case 2:
                 system("clear");//allows a user to deposit or withdraw amount 
                 f1=fopen("/home/suvam/PROJECT_2018-19(163244)/Data/ALL_BANK_DETAILS.txt","r+");
                 if(f1==NULL)
                 {
                      printf("%sSorry!...File can't be opened%s\n",Red,Reset);
                      exit(1);
                 }
                 printf("\n\t\tPlease select the option below\n");
                 printf("\n\t\t--> 1: DEPOSIT CASH             2: <-- WITHDRAW CASH\n");
                 printf("\t\t");
                 scanf("%d",&choice);
                 switch(choice)
                 {
                     case 1://deposit amount
                           system("clear");
                           printf("\n\t\tPlease enter the amount you would like to deposit \n");
                           printf("\t\t");
                           scanf("%f",&balance);
                           printf("\n\t\tPlease enter the account number of the customer into whose account you would like to deposit\n");
                           printf("\t\t");
                           getchar();
                           gets(acc_no);
                           printf("\n\t\tEnter the four digit PIN:\n");
                           printf("\t\t");
                           pin=pass_word();
                           deposit(f1,acc_no,pin,balance);
                           break;
                     case 2://withdraw amount
                           system("clear");
                           printf("\n\t\tPlease enter the amount you would like to withdraw\n");
                           printf("\t\t");
                           scanf("%f",&balance);
                           if(balance<=0)
                           {
                               printf("\n\t\tSorry you cannot withdraw\n");
                           }
                           else
                           {
                           printf("\n\t\tPlease enter the account number of the customer from whose account you would like to withdraw\n");
                           printf("\t\t");
                           getchar();
                           gets(acc_no);
                           printf("\n\t\tEnter the four digit PIN:\n");
                           printf("\t\t");
                           pin=pass_word();
                           withdraw(f1,acc_no,pin,balance);
                           }
                           break;
                           
                     default:
                           printf("\n\t\tInvlaid Input!!..\n");
                           break;
                 }
                 break;

        case 3://Know the details of a customer
                 system("clear");
                 f1=fopen("/home/suvam/PROJECT_2018-19(163244)/Data/ALL_BANK_DETAILS.txt","r+");
                 if(f1==NULL)
                 {
                      printf("%sSorry!...File can't be opened%s\n",Red,Reset);
                      exit(1);
                 }
                 printf("\n\t\tPlease enter the account number of the customer whose details you would like to know\n");
                 printf("\t\t");
                 getchar();
                 gets(acc_no);
                 printf("\n\t\tEnter the four digit PIN:\n");
                 printf("\t\t");
                 pin=pass_word();
                 display(f1,acc_no,pin);
                 break;  
        case 4://Modify the details of a customer
                 system("clear");
                 f1=fopen("/home/suvam/PROJECT_2018-19(163244)/Data/ALL_BANK_DETAILS.txt","r+");
                 if(f1==NULL)
                 {
                      printf("%sSorry!...File can't be opened%s\n",Red,Reset);
                      exit(1);
                 }
                 printf("\n\t\tPlease enter the account number of the customer whose details you would like to modify\n");
                 printf("\t\t");
                 getchar();
                 gets(acc_no);
                 printf("\n\t\tEnter the four digit PIN:\n");
                 printf("\t\t");
                 pin=pass_word();
                 Modify(f1,acc_no,pin);
                 break;
        case 5://Balance transfer 
                 system("clear");
                 f1=fopen("/home/suvam/PROJECT_2018-19(163244)/Data/ALL_BANK_DETAILS.txt","r+");
                 if(f1==NULL)
                 {
                      printf("%sSorry!...File can't be opened\n%s",Red,Reset);
                      exit(1);
                 }
                 balance_transfer(f1);
                 break;
       case 6://Know the transaction history of a customer
                  system("clear");
                  printf("\n\t\tPlease enter the account no of the customer of whom you would like to know the transcation history..\n");
                  printf("\t\t");
                  getchar();
                  gets(acc_no);
                  printf("\n\t\tEnter the four digit PIN:\n");
                  printf("\t\t");
                  pin=pass_word();
                  transaction_details(acc_no,pin);
                  break;
      case 7://Change the pin of the customer
                  system("clear");
                  f1=fopen("/home/suvam/PROJECT_2018-19(163244)/Data/ALL_BANK_DETAILS.txt","r+");
                  if(f1==NULL)
                  {
                      printf("%sSorry!...File can't be opened%s\n",Red,Reset);
                      exit(1);
                  }
                  printf("\n\t\tPlease enter the account number of the customer\n");
                  printf("\t\t");
                  getchar();
                  gets(acc_no);
                  printf("\n\t\tEnter the four digit PIN:\n");
                  printf("\t\t");
                  pin=pass_word();
                  change_pin(f1,acc_no,pin);
                  break;
           case 8://Allow fast cash to a user
                  system("clear");
                  f1=fopen("/home/suvam/PROJECT_2018-19(163244)/Data/ALL_BANK_DETAILS.txt","r+");
                  if(f1==NULL)
                  {
                      printf("%sSorry!...File can't be opened%s\n",Red,Reset);
                      exit(1);
                  }
                  printf("\n\t\tPlease enter your account number\n");
                  printf("\t\t");
                  getchar();
                  gets(acc_no);
                  printf("\n\t\tEnter the four digit PIN:\n");
                  printf("\t\t");
                  pin=pass_word();
                  fast_cash(f1,acc_no,pin);
                  break;
           case 9://exit from the program
                  exit(1);
           default:
                 printf("\n\t\tInvalid option\n");
                 break;
    }
    printf("\n\t\tDo you again want to get services from us?\n");
    printf("\n\t\t1-> YES                   2<-NO'\n");
    printf("\t\t");
    scanf("%d",&option);
    }while(option==1);//a do while loop unless user wants to use some more services
}
