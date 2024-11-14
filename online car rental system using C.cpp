#include <stdio.h>
#include <string.h>
#include<time.h>
struct Car 
{
	char brand[20],model[20],customername[20],customerid[20];
	float price,rentAmount;
	int availability,day,month,year,no,numberOfDays,numofdays,penalty,carindex;
};
struct Car c,cars[10],rental,returnDate,r; 
int days() 
{
	int numberOfDays = 0;
	while (1) 
	{
		if (rental.day == returnDate.day && rental.month == returnDate.month && rental.year == returnDate.year)
		break;
		numberOfDays++;
		rental.day++;
		if (rental.day > 31) 
		{
			rental.day = 1;
			rental.month++;
		}
		if (rental.month > 12) 
		{
			rental.month = 1;
			rental.year++;
		}
	}
	return(numberOfDays);
}
void display()
{
	strcpy(cars[1].brand, "Toyota");
	strcpy(cars[1].model, "\tCamry\t");
	cars[1].price = 1500.0;
	cars[1].no=1;
	cars[1].availability = 1;

	strcpy(cars[2].brand, "Honda");
	strcpy(cars[2].model, "\tCivic\t");
	cars[2].price = 1450.0;
	cars[2].no=2;
	cars[2].availability = 1;

	strcpy(cars[3].brand, "Tesla");
	strcpy(cars[3].model, "\tModel 3\t");
	cars[3].price = 17500.0;
	cars[3].no=3;
	cars[3].availability = 1;

	strcpy(cars[4].brand, "BMW");
	strcpy(cars[4].model, "\t3 Series");
	cars[4].price = 16000.0;
	cars[4].no=4;
	cars[4].availability = 1;

	strcpy(cars[5].brand, "Mercedes-Benz");
	strcpy(cars[5].model, "C-Class\t");
	cars[5].price = 16500.0;
	cars[5].no=5;
	cars[5].availability = 1;
	printf("Available Cars:\n");
	printf("No\tBrand\t\tModel\t\tRent per day\n");
	for(int i = 0; i <=5; i++) 
	{
		if(cars[i].availability) 
		{
			printf("%d\t%s\t%s\t(Rs.%.2f)\n",cars[i].no,cars[i].brand,cars[i].model,cars[i].price);
		}
	}
}
void car_rent()
{
	int carIndex;
	display();
	printf("Enter the Index Number of the car that you would like to rent: ");
	scanf("%d",&carIndex);
	printf("Lets check whether the car is available or not\n");
	if(cars[carIndex].availability) 
	{
		cars[carIndex].availability = 0;
		printf("Car is available\n\n");
		printf("Enter Customer Name:");
		scanf("%s",c.customername);
		printf("Enter Customer ID:");
		scanf("%s",c.customerid);
		printf("Enter the date on which you are renting the car (dd mm yyyy): ");
		scanf("%d %d %d", &rental.day, &rental.month, &rental.year);
		printf("Enter the date on which you will return the car (dd mm yyyy): ");
		scanf("%d %d %d", &returnDate.day, &returnDate.month, &returnDate.year);
		c.numberOfDays = days(rental, returnDate);
		c.rentAmount = cars[carIndex].price *c.numberOfDays;
		printf("\nWARNING: If any damage is done to the car then you are entirely responsible. The car has to be returned in its initial condition.\n");
		printf("\nDetails:\n");
		printf("NAME:\t%s\nID:\t%s\nCAR RENTED:\t%s %s\nNUMBER OF DAYS:\t%d\nRENT:\t%.2f\n",c.customername,c.customerid,cars[carIndex].brand, cars[carIndex].model,c.numberOfDays,c.rentAmount);
	} 
	else 
	{
		printf("Sorry, that car is not available.\n");
	}
	r.carindex=carIndex;
}
void car_return()
{
	char id[13];
	int flag=0,i,j,carno,a=0;
	printf("\nWelcome back dear customer \n");
	printf("Please enter your ID\n");
	scanf("%s",id);
	for(i=0;i<10;i++)
	{
		if(strcmp(c.customerid,id)==0)
		{
			flag=1;
			printf("\nHELLO %s\n",c.customername);
			display();
			printf("For confirmation please enter the Index Number of the car that you had rented: ");
	scanf("%d",&carno);
	if(r.carindex==carno)
		{
			a=1;
			printf("Confirmed!!\n");
			printf("For confirmation please enter the date on which you took the car and the date on which you are returning the date in(dd mm yyyy)format.\n");
			scanf("%d %d %d", &rental.day, &rental.month, &rental.year);
			scanf("%d %d %d", &returnDate.day, &returnDate.month, &returnDate.year);
			c.numofdays=days(rental, returnDate);
			if(c.numofdays>c.numberOfDays)
			{
				c.penalty=cars[carno].price*(c.numofdays-c.numberOfDays)+500;
				c.rentAmount+=c.penalty;
			}
			printf("No. of days delayed:%d\n",c.numofdays-c.numberOfDays);
			printf("Penalty:%d\n",c.penalty);
			printf("Total Amount:%f \n",c.rentAmount);
			printf("\n\n");
			break;
		}
		if(a==0)
		{
			printf("Wrong choice! Please enter the correct number\n");
		}
		break;
		}
	}
	if(flag==0)
	{
		printf("Customer not found\n");
	}
}
int main() 
{
	int p=0,ch;
	while(1)
	{
		printf("\nHELLO!!\nEnter 1 to Continue\n");
		scanf("%d",&p);
		if(p==1)
		{
			printf("\aHI!! Are you here to take the car service or return back the car?Enter\n1.Want to rent a Car.\n2.Want to return the car.\n");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:car_rent();
					break;
				case 2:car_return();
					break;
				default:printf("Wrong choice!! Try again.\n");
			}
		}
		else
		printf("\nBYE!!Today's work is over\n");
	}
}
