//AUM SRI SAI RAM
//The following contents contains the functions for different programs to be used in this project
//Done By:Suvam Tamang
//III B.Sc(Maths(Hons.))
//Regd. No:163244
 #include<stdio.h>
 #include<stdlib.h>
 #include<time.h>
 #include<string.h>
 #include<termios.h>
 #include"atm_header.h"

 //The following function is a self written GETCH funnction for implementation in this project
 
static struct termios old,new;
 
void initTermios(int echo)
{
  tcgetattr(0, &old); 
  new = old; 
  new.c_lflag &= ~ICANON; 
  new.c_lflag &= echo ? ECHO : ~ECHO; 
  tcsetattr(0, TCSANOW, &new); 
}
 
void resetTermios(void)
{
  tcsetattr(0, TCSANOW, &old);
}
 
char getch_(int echo)
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}
 
char getch(void)
{
  return getch_(0);
}
 /*****************************************************************************/
 //The following is a self written string compare function
 
int strcomp(char temp[],char check[])
{
  int i=0;
        
    while( temp[i]==check[i] && i<strlen(check))
    {
      i++;
    }
  if(i==strlen(check))  
      return 1;
  return 0;
}
/***********************************************************************************/
 //The following function gives the date of transaction by a customer
 
 void DATE(int *day,int *month,int *year)
{
   time_t now;
   time(&now);
   struct tm*local=localtime(&now);     //Accessing the local date of the system
   *day=local->tm_mday;                 //here day is in int format storing the date of the execution of the program 
   *month=local->tm_mon+1;              //month stores the month of execution of the program
   *year=local->tm_year+1900;           //year stores the date of execution of the program
   printf("\n\t\t%s~~Date of transaction:%02d:%02d:%02d\n%s",Green,*day,*month,*year,Reset);
}
/**********************************************************************************/
 //The following function is to print the time of transaction

  void TIME(int *sec,int *min,int *hours)
{
   time_t now;
   time(&now);
   struct tm*local=localtime(&now);
   *hours=local->tm_hour;
   *min=local->tm_min;
   *sec=local->tm_sec;
   if(*min>30)            
   {
       *hours=((*hours-6)%12)+1;
       *min-=60;
   }
   if(*hours<12)
   {
       printf("\n\t\t%s~~Time of transaction:%02d:%02d:%02d am\n%s",Green,*hours,*min+30,*sec,Reset);//Printing the time of execution of the program
   }
   else
   {
       printf("\n\t\t%s~~Time of transaction:%02d:%02d:%02d pm\n%s",Green,*hours,*min+30,*sec,Reset);//Printing the time of execution of the program

   }
}

/************************************************************************************/
//Function which takes in the details of a new customer taking care of the fact that the customer account number should be unique
   void create_new_account(FILE *f1)
{
       bank_details tmp;
       int i,n,seed,flag=0;
       int p,temp=0;
       char acc_no[15],pin[5];
       char M;
       char Acc[15];
       char t;
       system("figlet Enter Details Below:");   //figlet command for enlarging the output
       printf("\n\t\t1.Your Full Name:\n");
       getchar();
       printf("\t\t");
       gets(customer.name);
       while(1)                                 //An infinite while loop to check the age unless the sensible input is given 
       {
       printf("\n\t\t2.Enter your Age(only in digits):\n");
       printf("\t\t");
       scanf("%d",&customer.age);
       if(customer.age<=0)                      //If the age is insensible negative input then the input is ignored and the user is prompted to re-enter
       {
           printf("\n\t\t%sInvlaid Input!!..Input Again\n%s",Red,Reset);
           continue;
       }
       else
       {
           break;
       }
       }
       while(1)                                 //An infinite while loop to check the correct gender input unless a snsible input is given
       {
       printf("\n\t\t3.Enter your gender(M/F)\n");
       printf("\t\t");
       getchar();
       scanf("%c",&customer.gender);
           if(customer.gender!='M' && customer.gender!='F') //only input as 'M' and 'F' is taken else is ignored and prompted to re-enter
           {
               printf("\n\t\t%sInvalid Input\n%s",Red,Reset);
           continue;
           }
           else
               break;
       }
       printf("\n\t\t4.Please Enter your full address\n");
       printf("\t\t");
       getchar();
       gets(customer.address);
             if(customer.gender=='M')
             {
                  printf("\n\t\t%sThe world of S.B.I welcomes you Mr.%s\n%s",Green,customer.name,Reset);
             }
             else
             {
                 printf("\n\t\t%sThe world of S.B.I welcomes you Miss.%s\n%s",Green,customer.name,Reset);
             }
             while(1)                                 //An infinite while loop to check the uniqueness of the account number
             {
                   printf("\n\t\tPlease input a suitable 14 digit account number for yourself:\n");
                   printf("\t\t");
                   gets(Acc);
                   flag=0;
                   if(strlen(Acc)!=14)                //When the input is not 14 digit long then it is ignored and the user prompted to re-enter
                   {
                       printf("\n\t\t%sInvalid account number!!!!...Try Again!.\n%s",Red,Reset);   //Checks whether the account number entered is 14 digit long or not
                       continue;                                                                   //If not then he is prompted to enter it once again
                   }
                   else
                   {
                   rewind(f1);                                                    
                   while(fread(&tmp,sizeof(tmp),1,f1))
                       
                       {
                       if(strcomp(tmp.acc_no,Acc))                                    //Checking whether the account number entered clashes with the previous user 
                          {                                                           //account number
                           printf("\n\t\t%sFor the betterment of the services for our customer later we strongly advice uniqueness of the account number!!...\n%s",Green,Reset);
                           printf("\n\t\t%sSo Please enter once again your unique 14 digit number different from above\n%s",Green,Reset);
                           flag=1;
                           break;
                          }
                       }
                   
                         if(flag==1)
                         {
                          rewind(f1);
                          continue;
                         }
                         else
                         {
                          strcpy(customer.acc_no,Acc);
                          temp=1;
                         }  
                   }
                   if(temp==1)
                   {
                   break;
                   }          
             }

       srand(time(NULL));
       p=(rand()%9000+1000);                                                        //Using rand() for generating 4 digit number as the customer's pin
       printf("\n\t\tThis is your PIN:%s%d\n%s",Yellow,p,Reset);
       printf("\n\t\t5.Please carefully input the same pin as displayed above\n");
       printf("\t\t");
       gets(customer.PIN);
       while(1)
       {
       printf("\n\t\t6.Please enter the starting balance for your account(MIN Rs.100)\n");
       printf("\t\t");
       scanf("%f",&customer.balance);
           if(customer.balance<100)              //An amount of less than Rs.100 is not taken
           {
           printf("\n\t\t%sAmount should be atleast Rs. 100\n%s",Red,Reset);
           printf("\n\t\t%sAgain re-enter the amount\n%s",Red,Reset);
           continue;
           }
           else 
           {
                  break;
           }
       }
       fwrite(&customer,sizeof(customer),1,f1);    //Writing the entire block of relevant data into the file "ALL_BANK_DETAILS.txt" for one customer
       printf("\n\t\t%sThank you!!.. for your kind co-operation\n%s",Green,Reset);
       printf("\n\t\t%sNow you are eligible to use our services 24*7\n%s",Green,Reset);
       fclose(f1);//Closing the file "ALL_BANK_DETAILS.txt"
}

/************************************************************************************************************/
 //This function displays the details of a customer as when his account number and pin is entered and found to be correct
   void display(FILE *f1,char acc_no[],char pin[])
{
    bank_details bank;
    while(fread(&bank,sizeof(bank),1,f1)==1)
     {
             if(strcmp(bank.acc_no,acc_no)==0 && strcmp(bank.PIN,pin)==0)     //Checking for the correct input account number and pin
             {
                 printf("%s",Cyan);
                 printf("\n\t\t--------------------------------------------------------");//Printingn the entire details of the customer
                 printf("\n\t\t|->Customer name:%s\n",bank.name);
                 printf("\n\t\t|->Age:%d\n",bank.age);
                 printf("\n\t\t|->Gender:%c\n",bank.gender);
                 printf("\n\t\t|->Address:%s\n",bank.address);
                 printf("\n\t\t|->Account Number:%s\n",bank.acc_no);
                 printf("\n\t\t|->PIN:%s\n",bank.PIN);
                 printf("\n\t\t|->Total Balance:%.2f%s",bank.balance,Cyan,Reset);
                 printf("\n\t\t--------------------------------------------------------");
                 printf("%s",Reset);
                 break;
           }
     }
    fclose(f1);//Closing the file 
}

/*********************************************************************************************************/
 //This function undertakes the action of deposition of a certain amount by a customer checking for his account number and pin
  void deposit(FILE *f1,char acc_no[],char pin[],float balance)
{
    char choice;
    int flag=0;
    bank_details temp;
    date_time dt;
    while(fread(&temp,sizeof(temp),1,f1)==1) //Is something there to read from the input file
    {
            if(strcmp(temp.acc_no,acc_no)==0 && strcmp(temp.PIN,pin)==0) //Checking for the account number and pin so that depositing can happen in the correct account
            {
                    fseek(f1,-sizeof(temp),1);
                    temp.balance+=balance;
                    fwrite(&temp,sizeof(temp),1,f1);
                    workspace(balance,acc_no,pin,temp);                         //The function which stores the transaction history of the customer depositing amount
                    printf("%s",Green);
                    printf("\n\t\tDo you want a receipt??..\n");                
                    printf("\n\t\ty->YES          NO<-n\n%s",Green,Reset);
                    printf("\t\t");
                    scanf("%c",&choice);
                    if(choice=='y')
                    {
                    print_receipt_deposit(temp,balance);     //calling printf receipt function when the user wants to display his current transactions details
                    }
                    flag=1;
                    break;
            }
    }
    if(flag)
    {
        printf("\n\t\t%sSuccessfully Deposited!!...\n%s",Green,Reset);
    }
    else
        printf("\n\t\t%sERROR OCCURED TRY AGAIN\n%s",BRed,Reset);
    fclose(f1);//closing the file
}
  
/**************************************************************************************************/
 //This unction basically does the action of withdrawl of the amount by the user
  void withdraw(FILE *f1,char acc_no[],char pin[],float balance)
{
    float amount1;
    char choice;
    int flag=0;
    bank_details happy;
    date_time dt;
    rewind(f1);
    while(fread(&happy,sizeof(happy),1,f1)==1)  //Whether there is something to read in the file
    {
        if(strcmp(happy.acc_no,acc_no)==0 && strcmp(happy.PIN,pin)==0) //Checking for the account number and the pin of the user
        {
                    if(happy.balance<balance)                           //Checking whether suffecient balance is there in his account or not
                    {
                        printf("\n\t\t%sSorry you do not have sufficient balance in your account\n%s",Red,Reset);
                        printf("\n\t\t%sTry Again\n%s",Red,Reset);
                    }
                    else
                    {
                        fseek(f1,-sizeof(happy),1);
                        happy.balance=happy.balance-balance;
                        fwrite(&happy,sizeof(happy),1,f1);
                        workspace(balance,acc_no,pin,happy);           //The function which stores the transaction history of customer withdrawing amount            
                        printf("\n\t\t%sDo you want a receipt??..\n%s",Green,Reset);
                        printf("\n\t\t%sy->YES          NO<-n\n%s",Green,Reset);
                        printf("\t\t");
                        scanf("%c",&choice);
                        if(choice=='y')
                        {
                                print_receipt_withdrawl(happy,balance);//callling the print_receipt_withdrawl function as when user wants his current transaction 
                        }                                              //details
                        flag=1;
                   }
        break;
        }
    }
    if(flag)
    {
        printf("\n\t\t%sTransaction Successfull!!...\n%s",Green,Reset);
    }
    else
    {
        printf("%sERROR OCCURED TRY AGAIN%s",Red,Reset);
    }
    fclose(f1);//closing the file
}

/**********************************************************************************/
 //This function masks the 4-digit integer input as his pin by an asterisk(*)
 char* pass_word(void)
 {
    char *tmp;
    char str[20],c=' ';
    int i=0;
    while(i<=3)
    {
        str[i]=getch();       //This function does not echo the character as input but rather prints asterisk(*)
        c=str[i];
        if(c==13)
            break;
        else
            printf("*");
        i++;
    }
    str[i]='\0';
    tmp=calloc(4,sizeof(char));//allocating the space for the temporary string tmp;
    sscanf(str,"%s",tmp);      //writing the contents of "str" int "tmp"
    i=0;
    return tmp;//returning the string "tmp"
}
  
/**************************************************************************************/
 //Function to print the receipt after depositing certain amount
 void print_receipt_deposit(bank_details happy,float balance)
{
    int day,month,year,sec,min,hour;
    system("clear");
    printf("%s",Green);
    printf("\n\t\t~~THANKS  FOR  USING  OUR  SERVICES\n");
    printf("\n\t\t~~Name of the customer:%s\n",happy.name);
    printf("\n\t\t~~Account Number:%s\n",happy.acc_no);
    printf("\n\t\t~~Amount Deposited:%.2f\n",balance);
    printf("\n\t\t~~Total Amount:%.2f\n%s",happy.balance,Reset);
    DATE(&day,&month,&year);   //calling date function for storing date
    TIME(&sec,&min,&hour);     //calling time function for storing time
    printf("\n\t\t%sTHANKS!!... VISIT AGAIN!..\n%s",Magneta,Reset);
}

/*****************************************************************************************/
 //Function to print the receipt after withdrawl
 void print_receipt_withdrawl(bank_details happy, float balance)
{
    int day,month,year,sec,min,hour;
    system("clear");
    printf("%s",Green);
    printf("\n\t\t~~THANKS  FOR  USING  OUR  SERVICES\n");
    printf("\n\t\t~~Name of the customer:%s\n",happy.name);
    printf("\n\t\t~~Account Number:%s\n",happy.acc_no);
    printf("\n\t\t~~Amount Withdrawn:%.2f\n",balance);
    printf("\n\t\t~~Total Amount:%.2f\n%s",happy.balance,Reset);
    DATE(&day,&month,&year); //calling date function for storing date
    TIME(&sec,&min,&hour);//calling time function for storing time
    printf("\n\t\t%sTHANKS!!... VISIT AGAIN!..\n%s",Magneta,Reset);

 }

/******************************************************************************************/
 //Function which takes the task of modifying the details of a particular customer
  void Modify(FILE *f1,char acc_no[],char pin[])
{
    bank_details tmp;
    char Acc[15];
    char Pin[5];
    float balance;
    int flag=0;
    printf("\n\t\t%sYou can only change your basic information here\n%s",Red,Reset);
    rewind(f1);
    while(fread(&tmp,sizeof(tmp),1,f1)==1) //if anything is there to read from the file
        if(strcmp(tmp.acc_no,acc_no)==0 && strcmp(tmp.PIN,pin)==0)   //checking for the pin and the account number of the customer
        {
                    strcpy(Acc,tmp.acc_no);
                    strcpy(Pin,tmp.PIN);
                    balance=tmp.balance;
                    printf("\n\t\t~Enter the new details\n");
                    printf("\n\t\t~Name:\n");
                    printf("\t\t");
                    gets(customer.name);
                    printf("\n\t\t~Age:\n");
                    printf("\t\t");
                    scanf("%d",&customer.age);
                    printf("\n\t\t~Gender:\n");
                    getchar();
                    printf("\t\t");
                    scanf("%c",&customer.gender);
                    printf("\n\t\t~Customer Address:\n");
                    printf("\t\t");
                    getchar();
                    gets(customer.address);
                    customer.balance=balance;
                    strcpy(customer.acc_no,Acc);
                    strcpy(customer.PIN,Pin);
                    fseek(f1,-sizeof(customer),1);
                    fwrite(&customer,sizeof(customer),1,f1); //Writing the modifying contents into the file
                    flag=1;
                    break;
        }
    if(flag)
        printf("\n\t\t%sSuccessfully Modified\n%s",Green,Reset);
    else
        printf("\n\t\t%s Error occured Try Again\n%s",Red,Reset);
        fclose(f1);//closing the file
}

/************************************************************************************************/

//Function for performing different kinds of balance transfer transactions
//The user can do this either by using cash or can do it from his own account
 void balance_transfer(FILE *f1)
{
    bank_details tmp;
    float amount;
    int flag=0;
    int option;
    char ACC_NO[15];
    char ACC_NO2[15];
    char *pin;
    bank_details help;
    float amt;
    printf("\n\t\tThis is a Balance Transfer Window\n");
    printf("\n\t\t%s1-> CASH TRANSACTION                 2<- ACCOUNT TO ACCOUNT TRANSACTION\n%s",Yellow,Reset);
    printf("\t\t");
    scanf("%d",&option);
    switch(option)
    {
        case 1:                                                              //transferring amount using a raw cash into alraedy registered user's account
               printf("\n\t\tEnter the account number of the customer\n");
               getchar();
               printf("\t\t");
               gets(ACC_NO);
               while(1)
               {
                   printf("\n\t\tEnter the cash\n\t\t");
                   scanf("%f",&amt);
                   if(amt<=0) //Ignoring insensible input
                   {
                       printf("\n\t\t%sSorry You cannot transfer..Try Again\n%s",Red,Reset);
                       continue;
                   }
                   else
                       break;
               }
                rewind(f1);                                                     //Rewinding the file pointer
                while(fread(&help,sizeof(help),1,f1)==1)
                { 
                   if(strcomp(help.acc_no,ACC_NO))
                   {
                        workspace(amt,ACC_NO,pin,help);
                        fseek(f1,-sizeof(help),1);
                        help.balance+=amt;
                        fwrite(&help,sizeof(help),1,f1);
                        flag=1;
                        break;
                   }
                }
                break;
        case 2:                                                              //transferring amount from your own account
                printf("\n\t\tEnter your account number\n");
                printf("\t\t");
                getchar();
                gets(ACC_NO);
                printf("\n\t\tEnter your PIN\n");
                printf("\t\t");
                pin=pass_word();
                printf("\n\t\tNow enter the account number of the customer into whose account you would like to transfer the amount\n");
                printf("\t\t");
                gets(ACC_NO2);
                while(1)
                {
                   printf("\n\t\tEnter the amount\n");
                   printf("\t\t");
                   scanf("%f",&amt);
                   if(amt<=0)  //Ignoring insensible account number
                   {
                       printf("\n\t\t%sSorry You cannot transfer..Try Again\n%s",Red,Reset);
                       continue;
                   }
                   else
                       break;
                }
                rewind(f1);
                while(fread(&help,sizeof(help),1,f1)==1)
                {
                if(strcmp(help.acc_no,ACC_NO)==0 && strcmp(help.PIN,pin)==0)
                  {
                      if(help.balance<=0 && help.balance<amt)//ignoring insensible inputs
                      {
                          printf("\n\t\t%sSorry NO sufficient amount in your account\n%s",Red,Reset);
                          exit(1);
                      }
                        workspace(amt,ACC_NO,pin,help);
                        fseek(f1,-sizeof(help),1);
                        help.balance-=amt;
                        fwrite(&help,sizeof(help),1,f1);
                        break;
                  }
                }
                rewind(f1);
                while(fread(&tmp,sizeof(tmp),1,f1)==1)
                {
                    if(strcmp(tmp.acc_no,ACC_NO2)==0)
                        {
                           workspace(amt,ACC_NO2,pin,tmp); //Calling the function for storing date and time of transaction
                           fseek(f1,-sizeof(tmp),1);
                           tmp.balance+=amt;
                           fwrite(&tmp,sizeof(tmp),1,f1);
                           flag=1;
                           break;
                        }
                }
                if(flag)
                {
                  printf("\n\t\t%sTransaction successfull!!..\n%s",Green,Reset);
                }
               else
                  printf("\n\t\t%sTransaction Unsuccessfull!!..\n%s",Red,Reset);
                break;
        default:
                printf("\n\t\t%sInvalid Input!!...\n%s",Red,Reset);
                break;
    }
    if(flag)
    {
        printf("\n\t\t%sTransaction Successfull%s\n",Green,Reset);
    }
    else
    {
        printf("\n\t\t%sERROR OCCURED%s",Red,Reset);
    }
    fclose(f1);//closing the file
 }

/******************************************************************************************************/
//Function to print the Transaction history of a customer
 void workspace2(float balance,char acc_no,char pin,bank_details temp)
{
    int day,month,year,sec,min,hour;
    time_t now;
    time(&now);
    struct tm*local=localtime(&now);
    date_time happy;
    char acc[15];
    char Pin[5];
    FILE *f2;
        f2=fopen("/home/suvam/PROJECT_2018-19(163244)/Data/Transaction_details.txt","a");
        if(f2==NULL)
        {
        printf("\n\t\t%sCan't open file\n%s",Red,Reset);
        exit(1);
        }
          day=local->tm_mday;
          month=local->tm_mon+1;
          year=local->tm_year+1900;
          happy.day=day;
          happy.month=month;
          happy.year=year;
          hour=local->tm_hour;
          min=local->tm_min;
          sec=local->tm_sec;
          if(min<30)
          {
             hour=((hour-6)%12)+1;
             min-=60;
          }
          happy.hour=hour;
          happy.min=min;
          happy.sec=sec;
          strcpy(happy.name,temp.name);
          strcpy(happy.acc_no,temp.acc_no);
          happy.balance=balance;
          strcpy(happy.pin,temp.PIN);
          fwrite(&happy,sizeof(happy),1,f2);
          fclose(f2);
}
 
 /*************************************************************************************************************/
 int  workspace(float balance,char acc_no[],char pin[],bank_details temp)
{
    int day,month,year,sec,min,hour;
    time_t now;
    time(&now);
    struct tm*local=localtime(&now);
    date_time happy;
    char acc[15];
    char Pin[5];
    FILE *fp;
         fp=fopen("/home/suvam/PROJECT_2018-19(163244)/Data/Transaction_details.txt","r+");
         if(fp==NULL)
         {
         printf("\n\t\t%sCan't open file\n%s",Red,Reset);
         exit(1);
         }
          day=local->tm_mday;
          month=local->tm_mon+1;
          year=local->tm_year+1900;
          happy.day=day;
          happy.month=month;
          happy.year=year;
          hour=local->tm_hour;
          min=local->tm_min;
          sec=local->tm_sec;
          if(min>30)
          {
             hour-=1;
             min+=60;
          }
          happy.hour=hour;
          happy.min=min;
          happy.sec=sec;
          strcpy(happy.name,temp.name);
          strcpy(happy.acc_no,temp.acc_no);
          happy.balance=balance;
          strcpy(happy.pin,temp.PIN);
          if(ftell(fp)==0)
          {
            fwrite(&happy,sizeof(happy),1,fp);
            fclose(fp);
            return 0;
          }
          while(fread(&happy,sizeof(happy),1,fp)==1);
          rewind(fp);
          while(fread(&happy,sizeof(happy),1,fp)==1)
          {
            if(strcmp(happy.acc_no,acc_no)==0 && strcmp(happy.pin,pin)==0)
            {
              happy.day=day;
              happy.month=month;
              happy.year=year;
              happy.hour=hour;
              happy.min=min;
              happy.sec=sec;
              strcpy(happy.name,temp.name);
              strcpy(happy.acc_no,temp.acc_no);
              happy.balance=balance;
              strcpy(happy.pin,temp.PIN);
              fseek(fp,-sizeof(happy),1);
              fwrite(&happy,sizeof(happy),1,fp);
              fclose(fp);
              return 0;
            }
          }
  fclose(fp);
  workspace2(balance,acc_no,pin,temp);//calling this function in order to open the file "Transaction_details.txt" as opened above in append mode
  return 0;
}

/***************************************************************************************************/
//Function to diaplay the transation details of a customer
 void transaction_details(char acc_no[],char pin[])
{
    date_time happy;
    int flag=0;
    FILE *fp;
    fp=fopen("/home/suvam/PROJECT_2018-19(163244)/Data/Transaction_details.txt","r");
    if(fp==NULL)
    {
        printf("\n\t\t%sCan't open file\n%s",Red,Reset);
        exit(1);
    }
    while(fread(&happy,sizeof(happy),1,fp)==1)
    {
        if(strcmp(happy.acc_no,acc_no)==0 && strcmp(happy.pin,pin)==0)
    {
        flag=1;
        printf("\n\t\tName of the customer->%s%s%s\n",Green,happy.name,Reset);//printing the details of a customer along with the date and time of transactiion
        printf("\n\t\tAccount Number->%s%s%s\n",Green,happy.acc_no,Reset);
        printf("\n\t\tAmount of transaction->%s%.2f%s\n",Green,happy.balance,Reset);
        printf("\n\t\tLast Date of transaction->%s%d:%d:%d\n%s",Green,happy.day,happy.month,happy.year,Reset);
        if(happy.min>30)
        {
           happy.hour=((happy.hour-6)%12)+1;
           happy.min-=60;
        }
        if(happy.hour<12)
        {
         printf("\n\t\tLast Time of transaction->%s%02d:%02d:%02d am%s\n",Green,happy.hour,(happy.min+30),happy.sec,Reset);
        }
        else
        {
        printf("\n\t\tLast Time of transaction->%s%02d:%02d:%02d pm%s\n",Green,happy.hour,(happy.min+26),happy.sec,Reset);
        }
       break;
    }
    }
    if(flag==0)
    {
        printf("\n\t\t%sNo customer Transactions found with this account number and pin\n%s",Red,Reset);
        exit(1);
    }
    fclose(fp);
}

/*****************************************************************************************************************************/
 //Function to modify the pin of the customer
 void change_pin(FILE *f1,char acc_no[],char pin[])
{
    bank_details temp;
    char *Pin,*help;
    int flag;
    while(fread(&temp,sizeof(temp),1,f1)==1)
    {
        if(strcomp(temp.acc_no,acc_no) && strcomp(temp.PIN,pin))
         {
            while(1)
            {
            printf("\n\t\tEnter the new PIN you would like to change to\n");
            printf("\t\t");
            Pin=pass_word();  //User entering new password
            printf("\n\t\tEnter once again\n");
            printf("\t\t");
            help=pass_word();  //Once again he is asked in order to verify his earlier input
            if(strcomp(Pin,help)!=1)
            {
                printf("\n\t\t%sUnidentical Inputs Try Again\n%s",Red,Reset);
                continue;
            }
            else
                break;
            }
            strcpy(temp.PIN,Pin);
            fseek(f1,-sizeof(temp),1);
            fwrite(&temp,sizeof(temp),1,f1);//PIN changed successfully
            flag=1;
            break;
        }
    }
    if(flag)
        printf("\n\t\t%sSuccessfully Modified\n%s",Green,Reset);
    else
        printf("\n\t\t%sERROR!..\n%s",Red,Reset);
    fclose(f1);//Closing the file
}

/**************************************************************************************/
 //Function providing fast cash for a customer
 void fast_cash(FILE *f1,char acc_no[],char pin[])
{
    bank_details temp;
    int choice,flag=0,option=1;
    float balance;
    do
    {
    printf("                          >>>>>>> FAST CASH <<<<<<<         \n");//printing fast cash menu
    printf("\n\t\t[1]-> Rs.10,000                                    Rs. 5,000 <-[2]\n");
    printf("\n\t\t[3]-> Rs.2,500                                     Rs. 1,000 <-[4]\n");
    printf("\t\t");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
               while(fread(&temp,sizeof(temp),1,f1))
               {
                   if(strcomp(temp.acc_no,acc_no) && strcomp(temp.PIN,pin))
                   {
                       if(temp.balance<10000)//Checking for the available balance in the customer's account
                       {
                           printf("\n\t\t%sSorry!!.. Insufficient Balance in your account\n%s",Red,Reset);
                           flag=0;
                       }
                       else
                       {
                         fseek(f1,-sizeof(temp),1);
                         temp.balance-=10000;
                         fwrite(&temp,sizeof(temp),1,f1);
                         balance=10000;
                         workspace(balance,acc_no,pin,temp);           //The function which stores the transaction history of customer withdrawing amount            
                         flag=1;
                       }
                   }
                   break;
               }
                       if(flag)
                       {
                         printf("\n\t\tTransaction Successfull\n");
                         printf("\n\t\tRemaining balance:%.2f",temp.balance);
                       }
                       else
                         printf("\n\t\tUnsuccessfull Transaction\n");
               break;
        case 2:
               while(fread(&temp,sizeof(temp),1,f1))
               {
                   if(strcomp(temp.acc_no,acc_no) && strcomp(temp.PIN,pin))
                   {
                       if(temp.balance<5000)//Checking for the available balance in the customer's account
                       {
                           printf("\n\t\t%sSorry!!.. Insufficient Balance in your account\n%s",Red,Reset);
                           flag=0;
                       }
                       else
                       {
                       temp.balance-=5000;
                       fseek(f1,-sizeof(temp),1);
                       fwrite(&temp,sizeof(temp),1,f1);
                       balance=5000;
                       workspace(balance,acc_no,pin,temp);           //The function which stores the transaction history of customer withdrawing amount            
                       flag=1;
                       }
                   }
                   break;
               }
                       if(flag)
                       {
                         printf("\n\t\tTransaction Successfull\n");
                         printf("\n\t\tRemaining balance:%.2f",temp.balance);
                       }
                       else
                         printf("\n\t\tUnsuccessfull Transaction\n");
               break;
        case 3:
               while(fread(&temp,sizeof(temp),1,f1))
               {
                   if(strcomp(temp.acc_no,acc_no) && strcomp(temp.PIN,pin))
                   {
                       if(temp.balance<2500)//Checking for the available balance in the customer's account
                       {
                           printf("\n\t\t%sSorry!!.. Insufficient Balance in your account\n%s",Red,Reset);
                           flag=0;
                       }
                       else
                       {
                       temp.balance-=2500;
                       fseek(f1,-sizeof(temp),1);
                       fwrite(&temp,sizeof(temp),1,f1);
                       balance=2500;
                       workspace(balance,acc_no,pin,temp);           //The function which stores the transaction history of customer withdrawing amount            
                       flag=1;
                       }
                   }
                   break;
               }
                       if(flag)
                       {
                         printf("\n\t\tTransaction Successfull\n");
                         printf("\n\t\tRemaining balance:%.2f",temp.balance);
                       }
                       else
                         printf("\n\t\tUnsuccessfull Transaction\n");
               break;
        case 4:
               while(fread(&temp,sizeof(temp),1,f1))
               {
                   if(strcomp(temp.acc_no,acc_no) && strcomp(temp.PIN,pin))
                   {
                       if(temp.balance<1000)//Checking for the available balance in the customer's account
                       {
                           printf("\n\t\t%sSorry!!.. Insufficient Balance in your account\n%s",Red,Reset);
                           flag=0;
                       }
                       else
                       {
                       temp.balance-=1000;
                       fseek(f1,-sizeof(temp),1);
                       fwrite(&temp,sizeof(temp),1,f1);
                       balance=1000;
                       workspace(balance,acc_no,pin,temp);           //The function which stores the transaction history of customer withdrawing amount            
                       flag=1;
                       }
                   }
                   break;
               }
                       if(flag)
                       {
                        printf("\n\t\tTransaction Successfull\n");
                        printf("\n\t\tRemaining balance:%.2f",temp.balance);
                       }
                       else
                       printf("\n\t\tUnsuccessfull Transaction\n");
                   break;
        default:
               printf("\n\t\t%sInvalid Entry!!!...\n%s",Red,Reset);
               break;
     }
    printf("\n\t\tPress 1 to continue else press any key to exit\n");
    scanf("%d",&option);
    }while(option==1);
     fclose(f1);//Closing the file
}
 /*********END OF THE PROJECT*********/
 /*********SAIRAM*********/

