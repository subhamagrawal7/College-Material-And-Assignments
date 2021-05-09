#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int fill=-1; //Maintains the count of data that is filled
struct student{
int studentCode;
char name[20];
char address[40];
char mobile[20];
float marks;
float cgpa;
};
struct student s[100];
void insert();
void delete();
void search();
void traverse();
void update();
int main(){
	printf("Enter the number of operation you want to conduct:\n");
	printf("1) insert\n2) delete\n3) search\n4) traverse\n5) update\n6) exit\n\n");
	while(1){
		int ch;
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				insert();
				break;
			case 2:
				delete();
				break;
			case 3:
				search();
			break;
			case 4:
				traverse();
				break;
			case 5:
				update();
				break;
			case 6:
				exit(0);
			default:
				printf("Please select the correct choice.\n");
				break;
		
		}
	}
	return 0;
}
void insert()
{	
 int p,pos;
 printf("1) Append\n2) Insert at a specific position\n");
 printf("\nSelect your above preference: ");
 scanf("%d", &p);
 switch(p)
{
	case 1:
	if(fill==99)
	{
		printf("The list is filled, no more data can be inserted.\n");
	}
	else
	{
		printf("Enter the details to be inserted. \n");
		printf("Enter the name: ");
		scanf("%s", &s[fill+1].name);
		printf("Enter the Student code: ");
		
		scanf("%d", &s[fill+1].studentCode);
		if(s[fill+1].studentCode<1 || s[fill+1].studentCode>100)
		{
		printf("Incorrect Student code! Please enter a valid Student Code\n");
		break;
		}
		
		printf("Enter the Marks: ");
		scanf("%f", &s[fill+1].marks);
		if(s[fill+1].marks<0 || s[fill+1].marks>100)
		{
		printf("Invalid marks! Enter the correct marks\n");
		break;
		}
		
		printf("Enter Address: ");
		scanf("%s", &s[fill+1].address);
		printf("Enter Mobile Number in the format +91-{0-9}: ");
		scanf("%s", &s[fill+1].mobile);
		if(strlen(s[fill+1].mobile)!=14)
		{
		printf("Invalid Mobile No.! Enter the correct Mobile Number\n");
		break;
		}
		
		printf("Enter CGPA: ");
		scanf("%f", &s[fill+1].cgpa);
		if(s[fill+1].cgpa<0 || s[fill+1].cgpa>10)
		{
		printf("Invalid CGPA! Enter the correct CGPA\n");
		break;
		}
		
		printf("Your information is appended\n");
		fill++;
	}
	break;
	case 2:
	printf("Enter the index number where data is to be inserted: ");
	scanf("%d", &pos);
	if(pos<0 || pos>fill)
	{
	printf("Position Out of Range! Enter the correct Position\n");
	break;
	}else{
	int i;
	for(i=fill+1;i>pos;i--){
	s[i]=s[i-1];
	}
	printf("Enter the details to be inserted: \n");
	printf("Enter the name: ");
	scanf("%s", &s[pos].name);
	printf("Enter the Student code: ");
	scanf("%d", &s[pos].studentCode);
	if(s[pos].studentCode<1 || s[pos].studentCode>100)
	{
	printf("Incorrect Student code! Please enter a valid Student Code\n");
	break;
	}
	
	printf("Enter the Marks: ");
	scanf("%f", &s[pos].marks);
	if(s[pos].marks<0 || s[pos].marks>100)
	{
	printf("Invalid marks! Enter the correct marks\n");
	break;
	}
	
	printf("Enter Address: ");
	scanf("%s", &s[pos].address);
	printf("Enter Mobile Number in the format +91-{0-9}: ");
	scanf("%s", &s[pos].mobile);
	if(strlen(s[pos].mobile)!=14)
	{
	printf("Invalid Mobile No.! Enter the correct Mobile Number\n");
	break;
	}
	
	printf("Enter CGPA: ");
	scanf("%f", &s[pos].cgpa);
	
	if(s[pos].cgpa<0 || s[pos].cgpa>10)
	{
	printf("Invalid CGPA! Enter the correct CGPA\n");
	break;
	}
	
	printf("Your information is inserted.\n");
	fill++;
	}
	break;

}
}
void delete(){
	int roll,i;
	printf("Enter the student code which is to be deleted: ");
	scanf("%d",&roll);
	for(i=0;i<=fill;i++){
		if(roll==s[i].studentCode){
		break;
		}
	}
	if(i==fill+1){
		printf("Enter a valid roll number.\n");
	}else{
		for(;i<fill;i++){
			s[i]=s[i+1];
		}
		printf("The information has been deleted.\n");
		fill--;
	}
}
void search(){
	int roll,i;
	printf("Enter the student code which is to be searched: ");
	scanf("%d",&roll);
	for(i=0;i<=fill;i++){
		if(roll==s[i].studentCode){
			break;
		}
	}
	if(i==fill+1){
		printf("Enter a valid student code.\n");
	}else{
		printf("The marks are: %.2f\n",s[i].marks);
		printf("The address is: %s\n",s[i].address);
		printf("The cgpa is: %.2f\n",s[i].cgpa);
		printf("The mobile no. is: %s\n",s[i].mobile);
		printf("The name is: %s\n",s[i].name);
		printf("The student code is: %d\n",s[i].studentCode);
	}
}
void traverse(){
	int index,i;
	printf("Enter the index till where you want to traverse: ");
	scanf("%d",&index);
	if(index<0||index>fill){
		printf("Enter a valid index.\n");
	}else{
		for(i=0;i<=index;i++){
			printf("The marks are: %.2f\n",s[i].marks);
			printf("The address is: %s\n",s[i].address);
			printf("The cgpa is: %.2f\n",s[i].cgpa);
			printf("The mobile number is: %s\n",s[i].mobile);
			printf("The name is: %s\n",s[i].name);
			printf("The student code is: %d\n\n",s[i].studentCode);
		}
	}
}
void update()
{
	int code,i;
	printf("Enter the Student Code which is to be updated: ");
	scanf("%d", &code);
	for(i=0;i<fill; i++)
	{
		if(code==s[i].studentCode)
		{
			break;
		}
	}
	if(i==fill+1)
	{
		printf("Please enter a valid Student Code\n");
	}
	else
	{
		printf("\nEnter the information you want to update-\n");
		printf("1.Student code\n2.Address\n3.Name\n4.Marks\n5.CGPA\n6.Mobile No.\n7.All updated!\n");
		
		while(1){
			int c;
			printf("\nEnter the choice for updation: ");
			scanf("%d",&c);
			if(c==1){
				printf("Enter new student code: ");
				scanf("%d",&s[i].studentCode);
				if(s[i].studentCode<1 || s[i].studentCode>100) {
				printf("Incorrect Student code! Please enter a valid Student Code\n");
				
				}
			}
			else if(c==2){
				printf("Enter new address: ");
				scanf("%s",&s[i].address);
			}
			else if(c==3){
				printf("Enter name: ");
				scanf("%s",&s[i].name);
			}
			else if(c==4){
				printf("Enter new marks: ");
				scanf("%f",&s[i].marks);
				if(s[i].marks<0 || s[i].marks>100)
				
				{
				printf("Invalid marks! Enter the correct marks\n");
				
				}
			}
			else if(c==5)
			{
				printf("Enter new CGPA: ");
				scanf("%f",&s[i].cgpa);
				if(s[i].cgpa<0 || s[i].cgpa>10)
				{
					printf("Invalid CGPA! Enter the correct CGPA\n");
				}
			}
			
			else if(c==6)
			{
				printf("Enter new mobile number: ");
				scanf("%s",&s[i].mobile);
				
				if(strlen(s[i].mobile)!=14)
				{
				printf("Invalid Mobile No.! Enter the correct Mobile Number\n");
				}
			}
			else if(c==7){
				break;
			}
			else{
				printf("Enter a valid choice.\n");
			}
			}
		printf("The student details have been updated successfully!\n");
	}
}
