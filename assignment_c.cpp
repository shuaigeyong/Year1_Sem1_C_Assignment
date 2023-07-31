//Author : Tan Chin Yong , Tang Lit Xuan
//Date   : 7/2022-8/2022

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#pragma warning(disable:4996)

//Function Declaration
void login();
void viewmenu();
void vieworder();
void salesorder();
float disc(float x);
void receipt();
void summary();

//Declaration of variable and constant
#define DISCRATE1 15
#define DISCRATE2 10
#define DISCRATE3 5
const float PRICE_A = 69.00, PRICE_B = 70.00, PRICE_C = 55.50, PRICE_D = 58.00, PRICE_E = 65.00, PRICE_F = 89.00, PRICE_G = 73.50, PRICE_H = 80.00, PRICE_I = 50.00;
float discount, subtotal, alldiscount, totalsum, total;
float totalPria, totalPrib, totalPric, totalPrid, totalPrie, totalPrif, totalPrig, totalPrih, totalPrii;
int quantityBa, quantityBb, quantityBc, quantityBd, quantityBe, quantityBf, quantityBg, quantityBh, quantityBi;
int no = 1;     //Initialize no to 1, because the order no starts at 1
char typeOfBook;
char nextorder;
float sumba, sumbb, sumbc, sumbd, sumbe, sumbf, sumbg, sumbh, sumbi;
int sumqa, sumqb, sumqc, sumqd, sumqe, sumqf, sumqg, sumqh, sumqi;
int sumno;
char uname[50] = "a", cuname[50];
int pw, cpw, signup = 0;

int main() {
	//define the window size and color
	system("mode con cols=96 lines=43");
	system("color f0");  ////first letter set the background,second letter set the foreground

	//login page
	login();

	//if login successful signup will be 1 and uname,cname==0
	if (signup == 1 && strcmp(uname, cuname) == 0) {
		int u, l, t;
		t = 0;
		//display loading image
		for (u = 0; u <= 50; u++) {
			system("cls");
			l = 1;
			printf("\n\n\n\n");
			printf("\t                  U _____ u  _        ____   U  ___ u  __  __  U _____ u \n"
				"\t      __        __%c| ___%c|/ |%c|    U /%c___ | %c/ %c_ %c/U|' %c/ '|u%c| ___%c|/ \n"
				"\t      %c%c%c      /%c/ |  _| %cU | | u  %c| | u     | | | |%c| |%c/| |/ |  _|%c   \n"
				"\t      /%c %c /%c / /%c | |___  %c| |/__  | |/__.-,_| |_| | | |  | |  | |___   \n"
				"\t     U  %c V  V /  U|_____|  |_____|  %c____|%c_)-%c___/  |_|  |_|  |_____|  \n"
				"\t     .-,_%c /%c /_,-.<<   >>  //  %c%c  _// %c%c      %c%c   <<,-,,-.   <<   >>  \n"
				"\t      %c_)-'  '-(_/(__) (__)(_%c)(%c_)(__)(__)    (__)   (./  %c.) (__) (__) \n"
				, 92, 34, 34, 34, 92, 34, 92, 92, 92, 34, 92, 34, 92, 34, 34, 92, 92, 92, 34, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 34, 34, 92);
			printf("\n\n\n\n\n\n\n\n");
			printf("\t\t\t\t\tLoading...%d%c\n\t\t    ", t, 37);

			while (l <= u) {
				printf("%c", 22);
				l++;
			}
			printf("%c", 22);
			t += 2;
			Sleep(10);
		}
		Sleep(1000);
		system("cls");



		int op;
		do {

			//Display Logo
			system("cls");
			printf("ID :%s\n", uname);
			printf("\t     _   ____  ________  ______           _____           _                 \n"
				"\t    | | | |  %c/  |_   _| | ___ %c         /  ___|         | |                \n"
				"\t    | | | | .  . | | |   | |_/ /__  ___  %c `--. _   _ ___| |_ ___ _ __ ___  \n"
				"\t    | | | | |%c/| | | |   |  __/ _ %c/ __|  `--. %c | | / __| __/ _ %c '_ ` _ %c\n"
				"\t    | |_| | |  | | | |   | | | (_) %c__ %c /%c__/ / |_| %c__ %c ||  __/ | | | | |\n"
				"\t     %c___/%c_|  |_/ %c_/   %c_|  %c___/|___/ %c____/ %c__, |___/%c__%c___|_| |_| |_|\n"
				"\t                                                 __/ |                      \n"
				"\t                                                |___/     \n", 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92);


			op = 0;//avoid execute the last case again,so assign 0 to op.
			//printf("\nSelect an option ( 1 = View Menu, 2 = Sales Oder, 3 = Exit ): ");//main menu

			printf("\t\t\t\t---------------------------\n");
			printf("\t\t\t\t|      1. View Menu      |\n");
			printf("\t\t\t\t---------------------------\n");
			printf("\t\t\t\t|      2. Sales Order    |\n");
			printf("\t\t\t\t---------------------------\n");
			printf("\t\t\t\t|      3. Exit           |\n");
			printf("\t\t\t\t---------------------------\n");
			printf("Please Enter Your Option :");
			rewind(stdin);
			op = getche();
			op -= 48;
			rewind(stdin);
			switch (op) {
			case 1:
				viewmenu();
				break;
			case 2:
				vieworder();
				break;
			case 3:
				break;
			default:
				printf("\n\t\t\t\t\aINVALID INPUT,  PLEASE ENTER AGAIN\n\n");
				Sleep(1000);
				break;
			}
		} while (op != 3);
		system("cls");

		//display end page
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t\tU _____ u _   _    ____    \n"
			"\t\t\t\t%c| ___%c|/| %c |%c|  |  _%c%c   \n"
			"\t\t\t\t |  _|%c <|  %c| |>/| | | |  \n"
			"\t\t\t\t | |___ U| |%c  |uU| |_| |%c \n"
			"\t\t\t\t |_____| |_| %c_|  |____/ u \n"
			"\t\t\t\t <<   >> ||   \\\\,-.|||_    \n"
			"\t\t\t\t(__) (__)(_%c)  (_/(__)_)   \n\n", 92, 34, 92, 34, 34, 92, 34, 92, 92, 92, 92, 34);
		printf("\t\t\t%c THANKS FOR USING OUR UMT POS SYSTEM %c \n\n\n\t\t\t\t", 1, 1);
		system("pause");
		return 0;
	}
}

//Define the login page function
void login() {
	//variable that use to exit login page
	int exit = 0;
	do {
		system("cls");
		printf("\t      =================================================================\n");
		printf("\t                         WELCOME TO UMT POS SYSTEM                    \n");
		printf("\t                                                                       \n");
		printf("\t                                                                       \n");
		printf("\t      =======================  LOGIN SYSTEM  ==========================\n");
		printf("\t      |1.SignUp                                                       |\n");
		printf("\t      |2.Login                                                        |\n");
		printf("\t      |0.Exit                                                         |\n");
		printf("\t      =================================================================\n\n");
		printf("Please Enter Your Option:");
		int op;
		scanf("%d", &op);

		rewind(stdin);
		switch (op) {
		case 1:
			//sign up username and password
			system("cls");
			printf("\t      =================================================================\n");
			printf("\t                         WELCOME TO UMT POS SYSTEM                    \n");
			printf("\t                                                                      \n");
			printf("\t                                                                      \n");
			printf("\t      =======================  LOGIN SYSTEM  ==========================\n");
			printf("\t      |1.SignUp                                                       |\n");
			printf("\t      |2.Login                                                        |\n");
			printf("\t      |0.Exit                                                         |\n");
			printf("\t      =================================================================\n\n\n");
			printf("\t                                  SIGN UP\n");
			printf("===============================================================================================\n");
			printf("Please Enter Your ");
			printf("\n\n\t	Username : ");
			scanf("%[^\n]", uname);
			rewind(stdin);
			printf("\n\t        Password : ");
			scanf("%d", &pw);
			rewind(stdin);
			printf("\n   Confirm your password : ");
			scanf("%d", &cpw);
			rewind(stdin);
			if (pw != cpw) {
				printf("\n\t                Password Does Not Match,Please Try Again\n\n");
				pw = 0;
				cpw = 0;
				Sleep(1000);
				break;
			}
			else {
				system("cls");
				printf("\t      =================================================================\n");
				printf("\t                         WELCOME TO UMT POS SYSTEM                    \n");
				printf("\t                                                                       \n");
				printf("\t                                                                       \n");
				printf("\t      =======================  LOGIN SYSTEM  ==========================\n");
				printf("\t      |1.SignUp                                                       |\n");
				printf("\t      |2.Login                                                        |\n");
				printf("\t      |0.Exit                                                         |\n");
				printf("\t      =================================================================\n\n");
				printf("\n\n\n\n\n\n\t                         SUCESSFULLY REGISTERED!\n");
				Sleep(1000);
				break;
			}
		case 2:
			system("cls");
			printf("\t      =================================================================\n");
			printf("\t                         WELCOME TO UMT POS SYSTEM                    \n");
			printf("\t                                                                      \n");
			printf("\t                                                                      \n");
			printf("\t      =======================  LOGIN SYSTEM  ==========================\n");
			printf("\t      |1.SignUp                                                       |\n");
			printf("\t      |2.Login                                                        |\n");
			printf("\t      |0.Exit                                                         |\n");
			printf("\t      =================================================================\n\n\n");
			printf("\t                                   LOGIN\n");
			printf("===============================================================================================\n");
			printf("Please Enter Your ");
			printf("\n\n\t	Username : ");
			scanf("%[^\n]", cuname);
			rewind(stdin);
			printf("\n\t        Password : ");
			scanf("%d", &cpw);
			rewind(stdin);
			//check the username and password correct or not 
			if (strcmp(cuname, uname) == 0 && pw == cpw) {
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\n\t                              LOG IN SUCCESSFUL\n");
				printf("\n\t                               Hi %s\n\n", uname);
				printf("                                  Welcome to UMT POS SYSTEM");
				signup = 1;
				Sleep(1800);
				break;
			}
			else {
				if (strcmp(cuname, uname) != 0) {
					printf("\t                           USER DOES NOT EXIST\n\n");
					Sleep(1000);
					break;
				}
				if (pw != cpw) {
					printf("\n\t                       Wrong Password,Please try again\n");
					Sleep(1000);
					break;
				}
			}
		case 0:
			exit = 1;
			signup = 0;
			printf("\n\t                       THANKS FOR USING OUR SYSTEM\n\n");
			Sleep(1000);
			break;
		default:
			printf("\n\t\t\t\t\aINVALID INPUT,  PLEASE ENTER AGAIN\n\n");
			Sleep(1000);
			break;
		}
	} while (exit != 1 && signup != 1);
}

//Define submenu functions
void viewmenu() {
	int close = 0;
	do {
		system("cls");
		printf("ID :%s\n", uname);
		printf("\n\t\t\t                  MENU\n");
		printf("\t\t\t  ---------------------------------------\n");
		printf("\t\t\t  |1 = Software Development Programming |\n");
		printf("\t\t\t  |2 = Web Programming                  |\n");
		printf("\t\t\t  |3 = Mobile Programming               |\n");
		printf("\t\t\t  |0 = Exit                             |\n");
		printf("\t\t\t  ---------------------------------------\n");
		printf("\n\n\t Please select a field to view: ");


		int select;
		select = getche();
		select -= 48;
		switch (select) {
		case 1:
			system("cls");
			printf("ID :%s\n\n", uname);
			printf("\n\t\t  ------------------------------------------------------------\n");
			printf("\t\t  |Software Development Programming                          |\n");
			printf("\t\t  ------------------------------------------------------------\n");
			printf("\t\t  |A = Beginning with Programming Logic and Design    RM%.2f|\n", PRICE_A);
			printf("\t\t  |B = C Programming                                  RM%.2f|\n", PRICE_B);
			printf("\t\t  |C = Programming Fundamentals                       RM%.2f|\n", PRICE_C);
			printf("\t\t  ------------------------------------------------------------\n");
			printf("\t\t  Your input : %d\n\n", select);
			printf("\t\t       Press any key to return to the previous page\n\n\n");
			system("pause");
			break;
		case 2:
			system("cls");
			printf("ID :%s\n\n", uname);
			printf("\n\t\t  -------------------------------------------------------------\n");
			printf("\t\t  |Web Programming                                            |\n");
			printf("\t\t  -------------------------------------------------------------\n");
			printf("\t\t  |D = HTML and CSS Design                             RM%.2f|\n", PRICE_D);
			printf("\t\t  |E = Web Programming                                 RM%.2f|\n", PRICE_E);
			printf("\t\t  |F = ASP.NET Programming                             RM%.2f|\n", PRICE_F);
			printf("\t\t  -------------------------------------------------------------\n");
			printf("\t\t  Your input : %d\n\n", select);
			printf("\t\t       Press any key to return to the previous page\n\n\n");
			system("pause");
			break;
		case 3:
			system("cls");
			printf("ID :%s\n\n", uname);
			printf("\n\t\t  ------------------------------------------------------------\n");
			printf("\t\t  |Mobile Programming                                        |\n");
			printf("\t\t  ------------------------------------------------------------\n");
			printf("\t\t  |G = Mobile Design and Programming                  RM%.2f|\n", PRICE_G);
			printf("\t\t  |H = Building Mobile App                            RM%.2f|\n", PRICE_H);
			printf("\t\t  |I = Android Programming                            RM%.2f|\n", PRICE_I);
			printf("\t\t  ------------------------------------------------------------\n");
			printf("\t\t  Your input : %d\n\n", select);
			printf("\t\t       Press any key to return to the previous page\n\n\n");
			system("pause");
			break;
		case 0:
			system("cls");
			close = 1;
			break;
		default:
			printf("\n\t\t\t\t\aINVALID INPUT,  PLEASE ENTER AGAIN\n\n");
			Sleep(1000);
		}
	} while (close != 1);
}
//Define order function
void vieworder() {
	do {
		salesorder();
		receipt();
	} while (nextorder == 'Y');
	summary();
}
//Define order function
void salesorder() {

	printf("\nSales Order No : %d\n", no);

	do {
		int i;
		rewind(stdin);
		system("cls");
		printf("ID :%s\n", uname);
		printf("\t\t    ------------------------------------------------------\n");
		printf("\t\t    |Sales Order No : %d                                  |\n", no);
		printf("\t\t    |----------------------------------------------------|\n");
		printf("\t\t    |Book A x%5d    Book D x%5d    Book G x%5d     |\n", quantityBa, quantityBd, quantityBg);
		printf("\t\t    |Book B x%5d    Book E x%5d    Book H x%5d     |\n", quantityBb, quantityBe, quantityBh);
		printf("\t\t    |Book C x%5d    Book F x%5d    Book I x%5d     |\n", quantityBc, quantityBf, quantityBi);
		printf("\t\t    ------------------------------------------------------\n");
		printf("Please Enter The Book Type (X to Exit):\t");
		rewind(stdin);

		typeOfBook = getche();
		printf("\n");

		switch (typeOfBook)
		{
		case 'A':
		case'a':
			quantityBa = 0;
			rewind(stdin);
			printf("                             Quantity : ");
			scanf("%d", &quantityBa);
			totalPria = quantityBa * PRICE_A;
			break;
		case 'B':
		case'b':
			quantityBb = 0;
			rewind(stdin);
			printf("                             Quantity : ");
			scanf("%d", &quantityBb);
			totalPrib = quantityBb * PRICE_B;
			break;
		case 'C':
		case'c':
			quantityBc = 0;
			rewind(stdin);
			printf("                             Quantity : ");
			scanf("%d", &quantityBc);
			totalPric = quantityBc * PRICE_C;
			break;
		case 'D':
		case'd':
			quantityBd = 0;
			rewind(stdin);
			printf("                             Quantity : ");
			scanf("%d", &quantityBd);
			totalPrid = quantityBd * PRICE_D;
			break;
		case 'E':
		case'e':
			quantityBe = 0;
			rewind(stdin);
			printf("                             Quantity : ");
			scanf("%d", &quantityBe);
			totalPrie = quantityBe * PRICE_E;
			break;
		case'F':
		case'f':
			quantityBf = 0;
			rewind(stdin);
			printf("                             Quantity : ");
			scanf("%d", &quantityBf);
			totalPrif = quantityBf * PRICE_F;
			break;
		case'G':
		case'g':
			quantityBg = 0;
			rewind(stdin);
			printf("                             Quantity : ");
			scanf("%d", &quantityBg);
			totalPrig = quantityBg * PRICE_G;
			break;
		case'H':
		case'h':
			quantityBh = 0;
			rewind(stdin);
			printf("                             Quantity : ");
			scanf("%d", &quantityBh);
			totalPrih = quantityBh * PRICE_H;
			break;
		case'I':
		case'i':
			quantityBi = 0;
			rewind(stdin);
			printf("                             Quantity : ");
			scanf("%d", &quantityBi);
			totalPrii = quantityBi * PRICE_I;
			break;
		case'X':
		case'x':
			typeOfBook = 'X';
			nextorder = 'N';
			break;
		default:
			printf("\n\t\t\t\t\aINVALID INPUT,  PLEASE ENTER AGAIN\n\n");
			Sleep(1000);
			break;
		}
	} while (typeOfBook != 'X');
}
//Define receipt functions
void receipt() {
	char confirm;
	//if quantity more than 0, will ask if the user confirm the order
	if (quantityBa != 0 || quantityBb != 0 || quantityBc != 0 || quantityBd != 0 || quantityBe != 0 || quantityBf != 0 || quantityBg != 0 || quantityBh != 0 || quantityBi != 0) {

		do {
			printf("\n\t\tConfirm the order ? (Y=yes N=no) : ");
			rewind(stdin);
			//auto change the word to uppercase
			confirm = toupper(getchar());
			if (confirm != 'Y' && confirm != 'N')
				printf("\n\t\t\t\t\aINVALID INPUT,  PLEASE ENTER AGAIN\n\n");
		} while (confirm != 'Y' && confirm != 'N');
		switch (confirm) {
		case'Y':


			//printf("ID :%s\n", uname);
			printf("\n\t\t                         ORDER LIST");
			printf("\n\t\t    -----------------------------------------------------\n");
			printf("\t\t    =====================================================\n");
			if (quantityBa != 0) {
				printf("\t\t     Book A x %3d @ RM%6.2f          =      RM%10.2f \n", quantityBa, PRICE_A, totalPria);
				sumba = sumba + totalPria;
				sumqa = sumqa + quantityBa;
			}
			if (quantityBb != 0) {
				printf("\t\t     Book B x %3d @ RM%6.2f          =      RM%10.2f \n", quantityBb, PRICE_B, totalPrib);
				sumbb = sumbb + totalPrib;
				sumqb = sumqb + quantityBb;
			}
			if (quantityBc != 0) {
				printf("\t\t     Book C x %3d @ RM%6.2f          =      RM%10.2f \n", quantityBc, PRICE_C, totalPric);
				sumbc = sumbc + totalPric;
				sumqc = sumqc + quantityBc;
			}
			if (quantityBd != 0) {
				printf("\t\t     Book D x %3d @ RM%6.2f          =      RM%10.2f \n", quantityBd, PRICE_D, totalPrid);
				sumbd = sumbd + totalPrid;
				sumqd = sumqd + quantityBd;
			}
			if (quantityBe != 0) {
				printf("\t\t     Book E x %3d @ RM%6.2f          =      RM%10.2f \n", quantityBe, PRICE_E, totalPrie);
				sumbe = sumbe + totalPrie;
				sumqe = sumqe + quantityBe;
			}
			if (quantityBf != 0) {
				printf("\t\t     Book F x %3d @ RM%6.2f          =      RM%10.2f \n", quantityBf, PRICE_F, totalPrif);
				sumbf = sumbf + totalPrif;
				sumqf = sumqf + quantityBf;
			}
			if (quantityBg != 0) {
				printf("\t\t     Book G x %3d @ RM%6.2f          =      RM%10.2f \n", quantityBg, PRICE_G, totalPrig);
				sumbg = sumbg + totalPrig;
				sumqg = sumqg + quantityBg;
			}
			if (quantityBh != 0) {
				printf("\t\t     Book H x %3d @ RM%6.2f          =      RM%10.2f \n", quantityBh, PRICE_H, totalPrih);
				sumbh = sumbh + totalPrih;
				sumqh = sumqh + quantityBh;
			}
			if (quantityBi != 0) {
				printf("\t\t     Book I x %3d @ RM%6.2f          =      RM%10.2f \n", quantityBi, PRICE_I, totalPrii);
				sumbi = sumbi + totalPrii;
				sumqi = sumqi + quantityBi;
			}
			subtotal = totalPria + totalPrib + totalPric + totalPrid + totalPrie + totalPrif + totalPrig + totalPrih + totalPrii;

			printf("\t\t    =====================================================\n");
			printf("\t\t     Subtotal                        =      RM%10.2f \n", subtotal);
			discount = disc(subtotal);
			printf("\t\t     Discount                        =      RM%10.2f \n", discount);
			printf("\t\t    =====================================================\n");
			//calculate total price of order
			total = subtotal - discount;
			printf("\t\t     Total to pay                    =      RM%10.2f \n", total);
			printf("\t\t    =====================================================\n\n");

			alldiscount += discount;
			totalsum += total;
			totalPria = 0, totalPrib = 0, totalPric = 0, totalPrid = 0, totalPrie = 0, totalPrif = 0, totalPrig = 0, totalPrih = 0, totalPrii = 0;
			quantityBa = 0, quantityBb = 0, quantityBc = 0, quantityBd = 0, quantityBe = 0, quantityBf = 0, quantityBg = 0, quantityBh = 0, quantityBi = 0;
			subtotal = 0;
			sumno = no;
			no++;
			do {
				printf("Do you still want to continue ordering?(Y=yes N=no) : ");
				rewind(stdin);
				nextorder = toupper(getchar());
				rewind(stdin);

				if (nextorder != 'Y' && nextorder != 'N')
					printf("\n\t\t\t\t\aINVALID INPUT,  PLEASE ENTER AGAIN\n\n");

			} while (nextorder != 'Y' && nextorder != 'N');

			break;
		case 'N':
			quantityBa = 0, quantityBb = 0, quantityBc = 0, quantityBd = 0, quantityBe = 0, quantityBf = 0, quantityBg = 0, quantityBh = 0, quantityBi = 0;
			break;
		default:
			printf("\n\t\t\t\t\aINVALID INPUT,  PLEASE ENTER AGAIN\n\n");
			break;
		}
	}
}
//Define summary function
void summary() {
	int sumquantity = sumqa + sumqb + sumqc + sumqd + sumqe + sumqf + sumqg + sumqh + sumqi;
	float sumprice = sumba + sumbb + sumbc + sumbd + sumbe + sumbf + sumbg + sumbh + sumbi;
	//if user has ordered, show summary, if not have any order will not show the summary
	if (sumqa != 0 || sumqb != 0 || sumqc != 0 || sumqd != 0 || sumqe != 0 || sumqf != 0 || sumqg != 0 || sumqh != 0 || sumqi != 0) {
		system("cls");
		printf("ID :%s\n", uname);
		printf("\n\n\t\t\t       DAILY SALES ORDER SUMMARY REPORT\n");
		printf("\t\t\t       --------------------------------\n\n");
		printf("\t\t  Total Number of Sales Order = %d\n\n", sumno);
		printf("\t\t  ===========================================================\n");
		printf("\t\t   Book         Quantity Sold Sales                   Amount\n");
		printf("\t\t  ===========================================================\n");
		if (sumqa != 0)
			printf("\t\t   A                    %3d                      %10.2f \n", sumqa, sumba);
		if (sumqb != 0)
			printf("\t\t   B                    %3d                      %10.2f \n", sumqb, sumbb);
		if (sumqc != 0)
			printf("\t\t   C                    %3d                      %10.2f \n", sumqc, sumbc);
		if (sumqd != 0)
			printf("\t\t   D                    %3d                      %10.2f \n", sumqd, sumbd);
		if (sumqe != 0)
			printf("\t\t   E                    %3d                      %10.2f \n", sumqe, sumbe);
		if (sumqf != 0)
			printf("\t\t   F                    %3d                      %10.2f \n", sumqf, sumbf);
		if (sumqg != 0)
			printf("\t\t   G                    %3d                      %10.2f \n", sumqg, sumbg);
		if (sumqh != 0)
			printf("\t\t   H                    %3d                      %10.2f \n", sumqh, sumbh);
		if (sumqi != 0)
			printf("\t\t   I                    %3d                      %10.2f \n", sumqi, sumbi);

		printf("\t\t  ===========================================================\n");
		printf("\t\t   TOTAL                %3d                      %10.2f \n", sumquantity, sumprice);
		printf("\t\t   TOTAL DISCOUNT                                %10.2f \n", alldiscount);
		printf("\t\t  ===========================================================\n");
		printf("\t\t   TOTAL CHARGES                                 %10.2f \n", totalsum);
		printf("\t\t  ===========================================================\n\n\n");
		printf("\t\t\t\tTHANK YOU %s, HAVE A NICE DAY!!\n\n", uname);
		system("pause");
	}
}
//Define the discount function
float disc(float x) {
	if (x >= 500)
		return x * DISCRATE1 / 100;
	else if (x >= 300)
		return x * DISCRATE2 / 100;
	else if (x >= 200)
		return x * DISCRATE3 / 100;
	else
		return 0;
}
