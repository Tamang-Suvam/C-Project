      


                                                         A  MINI  AUTOMATED  TELLER  MACHINE
                                                        -------------------------------------
         
          1)NAME:A C Project which mimics the automated teller machine

          2)PURPOSE:The above project is a highly user friendly and interactive program which uses the concept of file handling in plenty 
                     thereby providing with all the features which an ATM would provide

          3)MEMBERS:Suvam Tamang;Regd.No:-163244

          4)HOW TO COMPILE:Use the command $make -f Makefile in order to compile the whole program.

          5)HOW TO RUN:The makefile command creates the executable file with the name "mini_atm".Thus the program can be run with the command $./mini_atm
 
          The above project basically allows a user to create a new account for himself if he is not registered before.During the course of this time he 
          is asked to enter his basic details eg, name,age,gender,full address,account number,starting balance.The account number must be entered such that
          it does not clash with the account number of the user already registered.So the program itself takes care of this and in case the account numbers 
          are found to be clashing then the customer is prompted to re-enter the account number.Thus the program works with each customer having their unique 
          account number.The four digit pin is given to the user which he must mandatorily know before undertaking any transactions.The user can deposit and 
          withdraw amount(if at all the asked amount is available in his account) as when necessary.He can also view his details only after giving his unique 
          account number and pin.If he wants he can modify his basic details(viz.,name,age,gender,address) at any time, only his account number,pin and balance
          cannot be changed under "Modify Customer Details".He also can as when necessary transfer money in cash into the account of the customer already registered
          or he can transfer amount to another registered customer from his own account.The user is also given the facility of fast cash if at all he has sufficient 
          amount in his account.Also changing PIN of any user has been made flexible.He can change his pin at any time.Lastly, the user can also view his last 
          transaction details(if he has done one)as when required.

          The file "ALL_TRANSACTION_DETAILS.txt" is been used by the functions(viz, create_new_account,deposit or withdraw money,get the details of a customer,
          Modify a customer details,balance_transfer,pin change and fast cash).Another file named "Transaction_details.txt" is used for writing the previous 
          transaction details of a customer.