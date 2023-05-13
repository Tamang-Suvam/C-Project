//AUM SRI SAI RAM
//The following contents contains the header file for different functions used
/*Done By:Suvam Tamang
 *Date:19/01/19
 *Regd. No:163244
 *A "MINI_ATM"
*/

//These are the declarations for the differnt colour to be used in the main program

#define Red "\033[0;31m"
#define BRed "\033[1;31m"	
#define Green "\033[0;32m"
#define BGreen "\033[1;32m"
#define Yellow "\033[0;33m"
#define BYellow "\033[01;33m"
#define Blue "\033[0;34m"
#define BBlue "\033[1;34m"
#define Magneta "\033[0;35m"
#define BMagneta "\033[1;35m"
#define Cyan "\033[0;36m"
#define BCyan "\033[1;36m"
#define Reset "\033[0m"


struct bank_details //Declaring the structure variable for storing all the bank details of a customer
{
    char name[30];
    int age;
    char gender;
    char address[100];
    char acc_no[15];
    char PIN[5];
    float balance;
}customer;

typedef struct bank_details bank_details;

struct details  //Declaring the structure variable for storing the date and time of transaction for a particular customer
{
    char acc_no[15];
    char pin[5];
    char name[30];
    int day;
    int month;
    int year;
    int sec;
    int min;
    int hour;
    float balance;
};

 typedef struct details date_time;

 void create_new_customer(FILE *f1);                                     //Header for registering the new customer
 void display(FILE *f1,char acc_no[],char pin[]);                        //Displays the customer details
 void deposit(FILE *f1,char acc_no[],char pin[],float balance);          //Depsit a certain amount in a certain customer account
 void withdraw(FILE *f1,char acc_no[],char pin[],float balance);         //WIthdraw amount from a certain customer
 char *pass_word(void);                                                  //echoing asterisk(*) as password
 void print_receipt_deposit(bank_details happy,float balance);           //Print receipt on deposit
 void print_receipt_withdrawl(bank_details happy,float balance);         //Print receipt on withdrawl
 void Modify(FILE *f1,char acc_no[],char pin[]);                         //Modify a particular customer details
 void balance_transfer(FILE *f1);                                        //Transfer balance in cash or from a registered acccount 
 void DATE(int *day,int *month,int *year);                               //Storing the current date of the system
 void TIME(int *sec,int *min,int *hour);                                 //Storing the current time of the system
 int workspace(float balance,char acc_no[],char pin[],bank_details temp);//Storing the transaction details of a customer
 void transaction_details(char acc_no[],char pin[]);                     //Printing the transaction details of a customer
 void change_pin(FILE *f1,char acc_no[],char pin[]);                     //Changing pin of the customer
 void fast_cash(FILE *f1,char acc_no[],char pin[]);                      //Provides fast cash to a user
