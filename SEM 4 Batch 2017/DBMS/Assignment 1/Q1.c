#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
    char name[30];
    int roll_no;
    float CGPA;
};

void writeData() {

    FILE *fp;
    fp = fopen("data.txt", "a");
    if(fp == NULL) {
        printf("The file couldn't open.\n");
        exit(1);
    }
    struct student newStudent;
    printf("Enter the details as directed below\n");
    printf("Name:\t");
    fflush(stdin);
    scanf("%[^\n]s", &newStudent.name);
    printf("Roll Number:\t");
    scanf("%d", &newStudent.roll_no);
    printf("CGPA:\t");
    scanf("%f", &newStudent.CGPA);
    fwrite(&newStudent, sizeof(struct student), 1, fp);
    if(fwrite != 0)
        printf("Contents written successfully\n");
    else
        printf("Error in writing file\n");
    fclose(fp);

}

void readData() {

    FILE *fp;
    fp = fopen("data.txt", "r");
    if(fp == NULL) {
        printf("The file couldn't open.");
        exit(1);
    }
    struct student newStudent;
    printf("Details of data are:\n");
    fflush(stdin);
    printf("ROLL NUMBER\tNAME\t\tCGPA\n");
    fread(&newStudent, sizeof(struct student), 1, fp);
    while(!feof(fp)){
        printf(" %d\t\t%s\t\t%.2f\n", newStudent.roll_no, newStudent.name, newStudent.CGPA);
        fread(&newStudent, sizeof(struct student), 1, fp);
    }
    fclose(fp);
}

void copyData() {
    FILE *fp, *temp;
    fp = fopen("data.txt","r");
    if(fp == NULL) {
        printf("The file couldn't open.");
        exit(1);
    }
    temp = fopen("copy.txt", "w");
    if(temp == NULL) {
        printf("The file couldn't open.");
        exit(1);
    }
    struct student newStudent;
    fflush(stdin);
    fread(&newStudent, sizeof(struct student), 1, fp);
    while(!feof(fp)){
        fwrite(&newStudent, sizeof(struct student), 1, temp);
        fread(&newStudent, sizeof(struct student), 1, fp);
    }
    printf("Work copied successfully\n");
    fclose(fp);
    fclose(temp);
}

void searchData() {
    FILE *fp;
    fp = fopen("data.txt","r+");
    if(fp == NULL) {
        printf("Unable to open the file\n");
        exit(0);
    }
    int match_roll;
    int flag = 0;
    printf("Enter the Roll Number of which data you want to search:\t");
    scanf("%d",&match_roll);
    struct student newStudent;
    fread(&newStudent, sizeof(struct student), 1, fp);
    while(!feof(fp)){
        if(newStudent.roll_no == match_roll) {
            printf("There exist a record of that roll number:\n");
            printf("Name:\t%s\tRoll Number:\t%d\tCGPA:\t%f\n", newStudent.name, newStudent.roll_no, newStudent.CGPA);
            flag = 1;
        }
        fread(&newStudent, sizeof(struct student), 1, fp);
    }
    if(flag == 0)
        printf("Sorry no record for such roll number.\n");
    fclose(fp);
}

void deleteData() {
    FILE *fr, *fw;
    fr = fopen("data.txt", "r");
    fw = fopen("temp.txt", "w");
    if(fr == NULL || fw == NULL) {
        printf("couldn't open file");
        exit(0);
    }
    int flag = 0;
    int match_roll;
    printf("Enter the roll number you want to remove:\t");
    scanf("%d", &match_roll);
    struct student newStudent;
    while(fread(&newStudent, sizeof(struct student), 1, fr)) {
        if(newStudent.roll_no != match_roll) {
            fwrite(&newStudent, sizeof(struct student), 1, fw);
        } else
            flag = 1;
    }
    fclose(fr);
    fclose(fw);
    fr = fopen("temp.txt", "r");
    fw = fopen("data.txt", "w");
    while(fread(&newStudent, sizeof(struct student), 1, fr)) {
        fwrite(&newStudent, sizeof(struct student), 1, fw);
    }
    if(flag == 0) {
        printf("No Such Roll Number Exist\n");
    } else {
        printf("Data correctly deleted\n");
    }
    fclose(fr);
    fclose(fw);
}

void displayData() {
    FILE *fp;
    fp = fopen("data.txt", "r");
    if(fp == NULL) {
        printf("The file couldn't open.");
        exit(1);
    }
    struct student newStudent;
    printf("Details of data are:\n");
    fflush(stdin);
    printf("ROLL NUMBER\tNAME\t\tCGPA\n");
    fread(&newStudent, sizeof(struct student), 1, fp);
    while(!feof(fp)){
        printf(" %d\t\t%s\t\t%.2f\n", newStudent.roll_no, newStudent.name, newStudent.CGPA);
        fread(&newStudent, sizeof(struct student), 1, fp);
    }
    fclose(fp);
}

int main()
{
    printf("===============FILE HANDLING IN C===============\n");
    int choice;
    while(1) {
        printf("\t++++++Choose any one of the below:+++++++\n");
        printf("\t\t1.Read Data from file. \n\t\t2.Write Data into file.\n\t\t3.Copy one file to another. \n\t\t4.Search a record by roll number. \n\t\t5.Delete record by roll number \n\t\t6.Exit\n\t\t\t");
        scanf("%d",&choice);
        printf("\t+++++++++++++++++++++++++++++++++++++++++\n");
        switch(choice)
        {
            case 1 : readData();
                     break;

            case 2 : writeData();
                     break;

            case 3 : copyData();
                     break;

            case 4 : searchData();
                     break;

            case 5 : displayData();
                     deleteData();
                     break;

            case 6:  exit(0);

            default: printf("Wrong choice entered\n");
                     break;
        }
    }
}
