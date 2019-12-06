#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
int i,j;
int choice;
menu();
createacc();
delay(int);
lists();
remov();
view();
end();
transact();
float Interest(float ,float ,int );
struct date {
	int month,day,year;

};
struct {

	struct date withdraw;
	struct date deposit;
	int no,pin,age,phone;
	char name[20],address[40],type[15];
	float amt;
	struct date dob;

} create,upd,check,rem,transaction;

main() {
	  printf("\n\t\t  ******************Hello!*******************\n");
    printf("\t\t**********Welcome to Banking System************\n\n");
 printf("\n\n\t\t1.ADMIN LOGIN\n\t\t2.COSTUMER LOGIN\n\n\t\tEnter your choice:");
 scanf("%d",&choice);
 	system("cls");
	switch(choice) {
		   case 1:
			adminlogin();
			break;
		   case 2:
			costumerlogin();
			break;
            default:
            end();	
 	
	
	
	
}}
costumerlogin()
{
    int choice,t=0;
	FILE *old,*newrec;
	old=fopen("record.dat","r");
	newrec=fopen("new.dat","w");
//z:
	printf("Enter the account number:");
	scanf("%d",&transaction.no);
		printf("Enter the account PIN:");
		scanf("%d",&transaction.pin);
	while (fscanf(old,"%d %d %s %d/%d/%d %d %s %d %s %f %d/%d/%d",&create.no,&create.pin,create.name,&create.dob.month,&create.dob.day,&create.dob.year,&create.age,create.address,&create.phone,create.type,&create.amt,&create.deposit.month,&create.deposit.day,&create.deposit.year)!=EOF) {

		if(create.no==transaction.no && create.pin==transaction.pin) {
			t=1;
			if(strcmp(create.type,"fixed1")==0||strcmp(create.type,"fixed2")==0||strcmp(create.type,"fixed3")==0) {
				printf("\n\nYOU CANNOT WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
				                   
					fprintf(newrec,"%d %d %s %d/%d/%d %d %s %d %s %f %d/%d/%d\n",create.no,create.pin,create.name,create.dob.month,create.dob.day,create.dob.year,create.age,create.address,create.phone,create.type,create.amt,create.deposit.month,create.deposit.day,create.deposit.year);
			getch(); printf("enter any key to continue....");    ///	delay(1000000000);
				system("cls");
				menu();
				
                   }
                   else{
	
				printf("Enter the amount you want to withdraw:RS ");
				scanf("%f",&transaction.amt);
				if(transaction.amt<create.amt){
				create.amt-=transaction.amt;
				fprintf(newrec,"%d %d %s %d/%d/%d %d %s %d %s %f %d/%d/%d\n",create.no,create.pin,create.name,create.dob.month,create.dob.day,create.dob.year,create.age,create.address,create.phone,create.type,create.amt,create.deposit.month,create.deposit.day,create.deposit.year);
				printf("\n\nWithdrawn successfully!");
					printf("\n\tYOUR REMAINING BALANCE IS:%f",create.amt);
				
				}
				else{
				printf("+++You don't have enough money+++\n");
        printf("Please contact to your Bank Customer Services\n");
        printf("****Your Balance is:RS%.2f\n\n",create.amt );
			
				break; }
			}

		} else {              
				fprintf(newrec,"%d %d %s %d/%d/%d %d %s %d %s %f %d/%d/%d\n",create.no,create.pin,create.name,create.dob.month,create.dob.day,create.dob.year,create.age,create.address,create.phone,create.type,create.amt,create.deposit.month,create.deposit.day,create.deposit.year);
		printf("\n\t\tINVALID ACCOUNT NUMBER AND PIN "); break;
		//goto z;
		}
	}
	fclose(old);
	fclose(newrec);
	remove("record.dat");
	rename("new.dat","record.dat");
	if(t!=1) {
		printf("\n\nRecord not found!!");
		
u:
		printf("\n\n\nEnter 0 to try again and 1 to exit:");
		scanf("%d",&choice);
		system("cls");
		if (choice==0)
			costumerlogin();
		else if (choice==1)
			end();
		else {
			printf("\nInvalid!");
			goto u;
		}

	} else {
		printf("\n--------------Take your receipt!!!------------------\n");
    printf("-----Thank you for using ATM Banking Machine!!!-----\n");
		printf("\nEnter 0 try again and 1 to exit:");
		scanf("%d",&choice);
		system("cls");
		if (choice==0)
			costumerlogin();
		else
			end();
	}

}

	/*	while (fscanf(ptr,"%d %d %s %d/%d/%d %d %s %f %s %d %d/%d/%d",&create.no,create.pin,create.name,&create.dob.month,&create.dob.day,&create.dob.year,&create.age,create.address,&create.phone,create.type,&create.amt,&create.deposit.month,&create.deposit.day,&create.deposit.year)!=EOF) {
			if(create.no==check.no && create.pin==check.pin ) {
				system("cls");
				t=1;


			}
		}
	 else if (choice==2) {
		printf("Enter the name:");
		scanf("%s",&check.name);
		while (fscanf(ptr,"%d %d %s %d/%d/%d %d %s %f %s %d %d/%d/%d",&create.no,create.pin,create.name,&create.dob.month,&create.dob.day,&create.dob.year,&create.age,create.address,&create.phone,create.type,&create.amt,&create.deposit.month,&create.deposit.day,&create.deposit.year)!=EOF) {
			if(strcmp(create.name,check.name)==0 && create.pin==check.pin) {
				system("cls");
				t=1;
	
			}
		}
	}


	fclose(ptr);
	if(t!=1) {
		system("cls");
		printf("\nRecord not found!!");
see_invalid:
		printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
		scanf("%d",&choice);
		system("cls");
		if (choice==1)
			menu();
		else if (choice==2)
			end();
		else if(choice==0)
			view();
		else {
			system("cls");
			printf("\nInvalid!");
			goto see_invalid;
		}
	} else {
		printf("\nEnter 1 to go to the main menu and 0 to exit:");
		scanf("%d",&choice);
	}
	if (choice==1) {
		system("cls");
		menu();
	}

	else {

		system("cls");
		end();
	}

}

}*/
adminlogin()
{
	char pass[10],password[10]="KHI12345";
	char user[10],username[10]="FAST";
	int i=0;
	printf("\n\n\t\tEnter the user name:");
	scanf("%s",user);
	printf("\n\n\t\tEnter the password:");
	scanf("%s",pass);
	if ( strcmp(user,username)==0  && strcmp(pass,password)==0) {
		printf("\n\nPassword Match!\nLOADING");
		for(i=0; i<=6; i++) {
			delay(1000000);
			printf(".");
		}
		system("cls");
		menu();
	} else {
		printf("\n\n\t\tWrong user name and password!! ");
p:
		printf("\nEnter 1 to try again and 0 to exit:");
		scanf("%d",&choice);
		if (choice==1) {

			system("cls");
			main();
		}

		else if (choice==0) {
			system("cls");
			end();
		} else {
			printf("\nInvalid!");
			delay(1000000000);
			system("cls");
			goto p;
		}

	}
}
	


menu() {
	int choice;
	system("cls");
	system("color 9");
	printf("\n\n\t\t\t\t<<FAST BANK LTD.>>");
	printf("\n\n\t\t\tCUSTOMER ACCOUNT MANAGEMENT SYSTEM");
	printf("\n\n\n\t\t\t WELCOME TO THE MAIN MENU ");
	printf("\n\n\t\t1.Create new account\n\t\t2.Check the details of existing account\n\t\t3.For transactions\n\t\t4.Update information of existing account\n\t\t5.Removing existing account\n\t\t6.View customer's list\n\t\t7.Exit\n\n\n\n\n\t\t Enter your choice:");
	scanf("%d",&choice);

	system("cls");
	switch(choice) {
		case 1:
			createacc();
			break;
		case 2:
			view();
			break;
		case 3:
			transact();
			break;
		case 4:
			edit();
			break;
		case 5:
			remov();
			break;
		case 6:
			lists();
			break;
		case 7:
			end();
			break;

	}



}
delay(int x) {
	static int i=2,k;
	if(x==i)
		return;
	else {
		i=i-(i/2);
		delay(i);
	}
}

createacc()

{
	int choice;
	FILE *ptr;

	ptr=fopen("record.dat","a+");
e:
	system("cls");
	printf("\t\t\t ADD NEW ACCOUNT  ");
	printf("\n\n\nEnter today's date(mm/dd/yyyy):");
	scanf("%d/%d/%d",&create.deposit.month,&create.deposit.day,&create.deposit.year);
	printf("\nEnter the account number:");
	scanf("%d",&check.no);
                     
	while(fscanf(ptr,"%d %d %s %d/%d/%d %d %s %d %s %f %d/%d/%d\n",&create.no,&create.pin,create.name,&create.dob.month,&create.dob.day,&create.dob.year,&create.age,create.address,&create.phone,create.type,&create.amt,&create.deposit.month,&create.deposit.day,&create.deposit.year)!=EOF) {
		if (check.no==create.no) {
			printf("Account no. already in use!");
			delay(1000000000);
			goto e;

		}
	}
	create.no=check.no;
    printf("\nEnter the account PIN:");
	scanf("%d",&create.pin);
	printf("\nEnter the name:");
	scanf("%s",create.name);
	printf("\nEnter the date of birth(mm/dd/yyyy):");
	scanf("%d/%d/%d",&create.dob.month,&create.dob.day,&create.dob.year);
	printf("\nEnter the age:");
	scanf("%d",&create.age);
	printf("\nEnter the address:");
	scanf("%s",create.address);
	printf("\nEnter the phone number: ");
	scanf("%d",&create.phone);
	printf("\nEnter the amount to deposit:RS");
	scanf("%f",&create.amt);
	printf("\nType of account:\n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\t#Fixed3(for 3 years)\n\n\tEnter your choice:");
	scanf("%s",create.type);
                
	fprintf(ptr,"%d %d %s %d/%d/%d %d %s %d %s %f %d/%d/%d\n",create.no,create.pin,create.name,create.dob.month,create.dob.day,create.dob.year,create.age,create.address,create.phone,create.type,create.amt,create.deposit.month,create.deposit.day,create.deposit.year);


	fclose(ptr);
	printf("\nAccount created successfully!");
q:
	printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
	scanf("%d",&choice);
	system("cls");
	if (choice==1)
		menu();
	else if(choice==0)
		end();
	else {
		printf("\nInvalid!");
		goto q;
	}
}
lists() {
	FILE *view;
	view=fopen("record.dat","r");
	int t=0;
	system("cls");
	printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");
                     
	while(fscanf(view,"%d %d %s %d/%d/%d %d %s %d %s %f %d/%d/%d",&create.no,&create.pin,create.name,&create.dob.month,&create.dob.day,&create.dob.year,&create.age,create.address,&create.phone,create.type,&create.amt,&create.deposit.month,&create.deposit.day,&create.deposit.year)!=EOF) {
		printf("\n%d\t %s\t\t\t%s\t\t%d",create.no,create.name,create.address,create.phone);
		t++;
	}

	fclose(view);
	if (t==0) {
		system("cls");
		printf("\nNO RECORDS!!\n");
	}

i:
	printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
	scanf("%d",&choice);
	system("cls");
	if (choice==1)
		menu();
	else if(choice==0)
		end();
	else {
		printf("\nInvalid!");
		goto i;
	}
}
edit() {
	int choice,t=0;
	FILE *old,*newrec;
	old=fopen("record.dat","r");
	newrec=fopen("new.dat","w");

	printf("\nEnter the account no. of the customer whose info you want to update:");
    scanf("%d",&upd.no); 
	while(fscanf(old,"%d %d %s %d/%d/%d %d %s %d %s %f %d/%d/%d",&create.no,&create.pin,create.name,&create.dob.month,&create.dob.day,&create.dob.year,&create.age,create.address,&create.phone,create.type,&create.amt,&create.deposit.month,&create.deposit.day,&create.deposit.year)!=EOF) {
		if (create.no==upd.no) {
			t=1;
			printf("\nWhich information do you want to update?\n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone):");
			scanf("%d",&choice);
			system("cls");
			if(choice==1) {
				printf("Enter the new address:");
	scanf("%s",upd.address);   
				fprintf(newrec,"%d %d %s %d/%d/%d %d %s %d %s %f %d/%d/%d\n",create.no,create.pin,create.name,create.dob.month,create.dob.day,create.dob.year,create.age,upd.address,create.phone,create.type,create.amt,create.deposit.month,create.deposit.day,create.deposit.year);
				system("cls");
				printf("Changes saved!");
			} else if(choice==2) {
				printf("Enter the new phone number:");
	scanf("%f",&upd.phone);    
				fprintf(newrec,"%d %d %s %d/%d/%d %d %s %d %s %f %d/%d/%d\n",create.no,create.pin,create.name,create.dob.month,create.dob.day,create.dob.year,create.age,create.address,upd.phone,create.type,create.amt,create.deposit.month,create.deposit.day,create.deposit.year);
				system("cls");
				printf("Changes saved!");
			}

		} else             
			fprintf(newrec,"%d %d %s %d/%d/%d %d %s %d %s %f %d/%d/%d\n",create.no,create.pin,create.name,create.dob.month,create.dob.day,create.dob.year,create.age,create.address,create.phone,create.type,create.amt,create.deposit.month,create.deposit.day,create.deposit.year);
	}
	fclose(old);
	fclose(newrec);
	remove("record.dat");
	rename("new.dat","record.dat");

	if(t!=1) {
		system("cls");
		printf("\nRecord not found!!");
m:
		printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
		scanf("%d",&choice);
		system("cls");
		if (choice==1)

			menu();
		else if (choice==2)
			end();
		else if(choice==0)
			edit();
		else {
			printf("\nInvalid!");
			goto m;
		}
	} else {
		printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
		scanf("%d",&choice);
		system("cls");
		if (choice==1)
			menu();
		else
			end();
	}
}

transact() {
	int choice,t=0;
	FILE *old,*newrec;
	old=fopen("record.dat","r");
	newrec=fopen("new.dat","w");

	printf("Enter the account no. of the customer:");
scanf("%d",&transaction.no); 
	        while (fscanf(old,"%d %d %s %d/%d/%d %d %s %d %s %f %d/%d/%d",&create.no,&create.pin,create.name,&create.dob.month,&create.dob.day,&create.dob.year,&create.age,create.address,&create.phone,create.type,&create.amt,&create.deposit.month,&create.deposit.day,&create.deposit.year)!=EOF) 
			  {

		if(create.no==transaction.no) {
			t=1;
			if(strcmp(create.type,"fixed1")==0||strcmp(create.type,"fixed2")==0||strcmp(create.type,"fixed3")==0) {
				printf("\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
				delay(1000000000);
				system("cls");
				menu();

			}
			printf("\n\nDo you want to\n1.Deposit\n2.Withdraw\n\nEnter your choice:");
			scanf("%d",&choice);
			if (choice==1) {
				printf("Enter the amount you want to deposit:RS ");
				scanf("%f",&transaction.amt);
			
				create.amt+=transaction.amt;
				               
				fprintf(newrec,"%d %d %s %d/%d/%d %d %s %d %s %f %d/%d/%d\n",create.no,create.pin,create.name,create.dob.month,create.dob.day,create.dob.year,create.age,create.address,create.phone,create.type,create.amt,create.deposit.month,create.deposit.day,create.deposit.year);
				printf("\n\nDeposited successfully!");
				printf("\n\tYOUR UPDATED BALANCE IS:%f",create.amt);
				break;
			 }
			else {
				printf("Enter the amount you want to withdraw:RS ");
				scanf("%f",&transaction.amt);
					if(transaction.amt<create.amt){
			
				create.amt-=transaction.amt;
				              
				fprintf(newrec,"%d %d %s %d/%d/%d %d %s %d %s %f %d/%d/%d\n",create.no,create.pin,create.name,create.dob.month,create.dob.day,create.dob.year,create.age,create.address,create.phone,create.type,create.amt,create.deposit.month,create.deposit.day,create.deposit.year);
				printf("\n\nWithdrawn successfully!");
					printf("\n\tYOUR REMAINING BALANCE IS:%f",create.amt);
					break;
			}  
			else {
			printf("\n\tINVALID AMMOUNT\n\tYOUR BALANCE IS:%f",create.amt);	} }
		}

		else            
			fprintf(newrec,"%d %d %s %d/%d/%d %d %s %d %s %f %d/%d/%d\n",create.no,create.pin,create.name,create.dob.month,create.dob.day,create.dob.year,create.age,create.address,create.phone,create.type,create.amt,create.deposit.month,create.deposit.day,create.deposit.year);
		
}
	fclose(old);
	fclose(newrec);
	remove("record.dat");
	rename("new.dat","record.dat");
	if(t!=1) {
		printf("\n\nRecord not found!!");
s:
		printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
		scanf("%d",&choice);
		system("cls");
		if (choice==0)
			transact();
		else if (choice==1)
			menu();
		else if (choice==2)
			end();
		else {
			printf("\nInvalid!");
			goto s;
		}

	} else {
		printf("\nEnter 1 to go to the main menu and 0 to exit:");
		scanf("%d",&choice);
		system("cls");
		if (choice==1)
			menu();
		else
			end();
	}

}
remov() {
	FILE *old,*newrec;
	int t=0;
	old=fopen("record.dat","r");
	newrec=fopen("new.dat","w");
	printf("Enter the account no. of the customer you want to delete:");
	scanf("%d",&rem.no);
	                   
	while (fscanf(old,"%d %d %s %d/%d/%d %d %s %d %s %f %d/%d/%d",&create.no,&create.pin,create.name,&create.dob.month,&create.dob.day,&create.dob.year,&create.age,create.address,&create.phone,create.type,&create.amt,&create.deposit.month,&create.deposit.day,&create.deposit.year)!=EOF) {
		if(create.no!=rem.no)
			fprintf(newrec,"%d %d %s %d/%d/%d %d %s %d %s %f %d/%d/%d\n",create.no,create.pin,create.name,create.dob.month,create.dob.day,create.dob.year,create.age,create.address,create.phone,create.type,create.amt,create.deposit.month,create.deposit.day,create.deposit.year);

		else {
			t++;
			printf("\nRecord deleted successfully!\n");
		}
	}
	fclose(old);
	fclose(newrec);
	remove("record.dat");
	rename("new.dat","record.dat");
	if(t==0) {
		printf("\nRecord not found!!");
v:
		printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
		scanf("%d",&choice);

		if (choice==1)
			menu();
		else if (choice==2)
			end();
		else if(choice==0)
			remov();
		else {
			printf("\nInvalid!");
			goto v;
		}
	} else {
		printf("\nEnter 1 to go to the main menu and 0 to exit:");
		scanf("%d",&choice);
		system("cls");
		if (choice==1)
			menu();
		else
			end();
	}

}

view() {
	FILE *ptr;
	int t=0,rate;
	int choice;
	float time;
	float intrst;
	ptr=fopen("record.dat","r");
	printf("Do you want to check by\n1.Account no\n2.Name\nEnter your choice:");
	scanf("%d",&choice);
	if (choice==1) {
		printf("Enter the account number:");
		scanf("%d",&check.no);
                    
		while (fscanf(ptr,"%d %d %s %d/%d/%d %d %s %d %s %f %d/%d/%d",&create.no,&create.pin,create.name,&create.dob.month,&create.dob.day,&create.dob.year,&create.age,create.address,&create.phone,create.type,&create.amt,&create.deposit.month,&create.deposit.day,&create.deposit.year)!=EOF) {
			if(create.no==check.no) {
				system("cls");
				t=1;

				printf("\nAccount NO.:%d\nName:%s\nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nPhone number:%d \nType Of Account:%s \nAmount deposited:RS %.2f \nDate Of Deposit:%d/%d/%d\n\n",create.no,create.name,create.dob.month,create.dob.day,create.dob.year,create.age,create.address,create.phone,create.type,create.amt,create.deposit.month,create.deposit.day,create.deposit.year);
				if(strcmp(create.type,"fixed1")==0) {
					time=1.0;
					rate=9;
					intrst=Interest(time,create.amt,rate);
					printf("\n\nYou will get RS%.2f as interest on %d/%d/%d",intrst,create.deposit.month,create.deposit.day,create.deposit.year+1);
				} else if(strcmp(create.type,"fixed2")==0) {
					time=2.0;
					rate=11;
					intrst=Interest(time,create.amt,rate);
					printf("\n\nYou will get RS.%.2f as interest on %d/%d/%d",intrst,create.deposit.month,create.deposit.day,create.deposit.year+2);

				} else if(strcmp(create.type,"fixed3")==0) {
					time=3.0;
					rate=13;
					intrst=Interest(time,create.amt,rate);
					printf("\n\nYou will get RS.%.2f as interest on %d/%d/%d",intrst,create.deposit.month,create.deposit.day,create.deposit.year+3);

				} else if(strcmp(create.type,"saving")==0) {
					time=(1.0/12.0);
					rate=8;
					intrst=Interest(time,create.amt,rate);
					printf("\n\nYou will get RS.%.2f as interest on %d of every month",intrst,create.deposit.day);

				} else if(strcmp(create.type,"current")==0) {

					printf("\n\nYou will get no interest");

				}

			}
		}
	} else if (choice==2) {
		printf("Enter the name:");
		scanf("%s",&check.name);
		                 
		while (fscanf(ptr,"%d %d %s %d/%d/%d %d %s %d %s %f %d/%d/%d",&create.no,&create.pin,create.name,&create.dob.month,&create.dob.day,&create.dob.year,&create.age,create.address,&create.phone,create.type,&create.amt,&create.deposit.month,&create.deposit.day,&create.deposit.year)!=EOF) {
			if(strcmp(create.name,check.name)==0) {
				system("cls");
				t=1;
				printf("\nAccount No.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nPhone number:%d \nType Of Account:%s \nAmount deposited:RS%.2f \nDate Of Deposit:%d/%d/%d\n\n",create.no,create.name,create.dob.month,create.dob.day,create.dob.year,create.age,create.address,create.phone,
				       create.type,create.amt,create.deposit.month,create.deposit.day,create.deposit.year);
				if(strcmp(create.type,"fixed1")==0) {
					time=1.0;
					rate=9;
					intrst=Interest(time,create.amt,rate);
					printf("\n\nYou will get RS.%.2f as interest on %d/%d/%d",intrst,create.deposit.month,create.deposit.day,create.deposit.year+1);
				} else if(strcmp(create.type,"fixed2")==0) {
					time=2.0;
					rate=11;
					intrst=Interest(time,create.amt,rate);
					printf("\n\nYou will get RS.%.2f as interest on %d/%d/%d",intrst,create.deposit.month,create.deposit.day,create.deposit.year+2);

				} else if(strcmp(create.type,"fixed3")==0) {
					time=3.0;
					rate=13;
					intrst=Interest(time,create.amt,rate);
					printf("\n\nYou will get RS.%.2f as interest on %d/%d/%d",intrst,create.deposit.month,create.deposit.day,create.deposit.year+3);

				} else if(strcmp(create.type,"saving")==0) {
					time=(1.0/12.0);
					rate=8;
					intrst=Interest(time,create.amt,rate);
					printf("\n\nYou will get RS.%.2f as Interest on %d of every month",intrst,create.deposit.day);

				} else if(strcmp(create.type,"current")==0) {

					printf("\n\nYou will get no Interest");

				}

			}
		}
	}


	fclose(ptr);
	if(t!=1) {
		system("cls");
		printf("\nRecord not found!!");
l:
		printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
		scanf("%d",&choice);
		system("cls");
		if (choice==1)
			menu();
		else if (choice==2)
			end();
		else if(choice==0)
			view();
		else {
			system("cls");
			printf("\nInvalid!");
			goto l;
		}
	} else {
		printf("\nEnter 1 to go to the main menu and 0 to exit:");
		scanf("%d",&choice);
	}
	if (choice==1) {
		system("cls");
		menu();
	}

	else {

		system("cls");
		end();
	}

}

float Interest(float am,float time,int rate) {
	float i;
	i=(time*am*rate)/100;
	return i;

}
end() {
	main();
}



