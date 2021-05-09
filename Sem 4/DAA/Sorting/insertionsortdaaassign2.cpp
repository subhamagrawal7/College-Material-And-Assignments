#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node * next;
};
void sortedInsert(struct Node **, struct Node *);
void deleteList(Node** head_ref)
{
    Node* current = *head_ref;
    Node* next;
    while (current != NULL) 
    {
        next = current->next;
        free(current);
        current = next;
    }
    *head_ref = NULL;
}
 
void insertionSort(struct Node **head_ref)
{
	struct Node *sorted = NULL;
	struct Node *current = *head_ref;
	while (current != NULL)
	{
		struct Node *next = current->next;
		sortedInsert(&sorted, current);
		current = next;
	}
	*head_ref = sorted;
}

void sortedInsert(struct Node **head_ref, struct Node *new_node)
{
	struct Node * current;
	if (*head_ref == NULL || (*head_ref)->data >= new_node->data)
	{
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
	else
	{
		current = *head_ref;
		while (current->next != NULL && current->next->data < new_node->data)
		{
			current = current->next;
		}

		new_node->next = current->next;
		current->next = new_node;
	}
}

void insert(struct Node **head, int data)
{
	struct Node *newnode = new Node;
	newnode->data = data;
	newnode->next = *head;
	*head = newnode;
}
int main()
{
	struct Node *a = NULL;
	int count = 0, i = 0, j = 0, tp, ch=1, c,z,flag=1;
	char b[100];
	FILE * fp;
		do {
		switch (ch)
		{
			case 1:
				fp = fopen("File 1sort.txt", "r");
				if (fp == NULL)
				{
					printf("file not found");
				}

				while (fscanf(fp, "%s\n", &b) == 1)
				{
					c = atoi(b);
					insert(&a, c);
				}
				printf("----------\nFILE 1 BEST CASE\n-----------");
				fclose(fp);
				break;
			case 2:
				fp = fopen("File 1.txt", "r");
				if (fp == NULL)
				{
					printf("file not found");
				}

				while (fscanf(fp, "%s\n", &b) == 1)
				{
					c = atoi(b);
					insert(&a, c);
				}

				printf("----------\nFILE 1 AVERAGE CASE\n-----------");
				fclose(fp);
				break;
			case 3:
				fp = fopen("File 1best.txt", "r");
				if (fp == NULL)
				{
					printf("file not found");
				}

				while (fscanf(fp, "%s\n", &b) == 1)
				{
					c = atoi(b);
					insert(&a, c);
				}

				printf("----------\nFILE 1 WORST CASE\n-----------");
				fclose(fp);
				break;
			case 4:
				fp = fopen("File 2sort.txt", "r");
				if (fp == NULL)
				{
					printf("file not found");
				}

				while (fscanf(fp, "%s\n", &b) == 1)
				{
					c = atoi(b);
					insert(&a, c);
				}

				printf("----------\nFILE 2 BEST CASE\n-----------");
				fclose(fp);
				break;
			case 5:
				fp = fopen("File 2.txt", "r");
				if (fp == NULL)
				{
					printf("file not found");
				}

				while (fscanf(fp, "%s\n", &b) == 1)
				{
					c = atoi(b);
					insert(&a, c);
				}

				printf("----------\nFILE 2 AVERAGE CASE\n-----------");
				fclose(fp);
				break;
			case 6:
				fp = fopen("File 2best.txt", "r");
				if (fp == NULL)
				{
					printf("file not found");
				}

				while (fscanf(fp, "%s\n", &b) == 1)
				{
					c = atoi(b);
					insert(&a, c);
				}

				printf("----------\nFILE 2 WORST CASE\n-----------");
				fclose(fp);
				break;
			case 7:
				fp = fopen("File 3sort.txt", "r");
				if (fp == NULL)
				{
					printf("file not found");
				}

				while (fscanf(fp, "%s\n", &b) == 1)
				{
					c = atoi(b);
				   insert(&a, c);
				}

				printf("----------\nFILE 3 BEST CASE\n-----------");
				fclose(fp);
				break;
			case 8:
				fp = fopen("File 3.txt", "r");
				if (fp == NULL)
				{
					printf("file not found");
				}

				while (fscanf(fp, "%s\n", &b) == 1)
				{
					c = atoi(b);
					insert(&a, c);
				}

				printf("----------\nFILE 3 AVERAGE CASE\n-----------");
				fclose(fp);
				break;
			case 9:
				fp = fopen("File 3best.txt", "r");
				if (fp == NULL)
				{
					printf("file not found");
				}

				while (fscanf(fp, "%s\n", &b) == 1)
				{
					c = atoi(b);
					insert(&a, c);
				}

				printf("----------\nFILE 3 WORST CASE\n-----------");
				fclose(fp);
				break;
			case 10:
				fp = fopen("File 4sort.txt", "r");
				if (fp == NULL)
				{
					printf("file not found");
				}

				while (fscanf(fp, "%s\n", &b) == 1)
				{
					c = atoi(b);
					insert(&a, c);
				}

				printf("----------\nFILE 4 BEST CASE\n-----------");
				fclose(fp);
				break;
			case 11:
				fp = fopen("File 4.txt", "r");
				if (fp == NULL)
				{
					printf("file not found");
				}

				while (fscanf(fp, "%s\n", &b) == 1)
				{
					c = atoi(b);
					insert(&a, c);
				}

				printf("----------\nFILE 4 AVERAGE CASE\n-----------");
				fclose(fp);
				break;
			case 12:
				fp = fopen("File 4best.txt", "r");
				if (fp == NULL)
				{
					printf("file not found");
				}

				while (fscanf(fp, "%s\n", &b) == 1)
				{
					c = atoi(b);
					insert(&a, c);
				}

				printf("----------\nFILE 4 WORST CASE\n-----------");
				fclose(fp);
				break;
			case 13:
				fp = fopen("File 5sortre.txt", "r");
				if (fp == NULL)
				{
					printf("file not found");
				}

				while (fscanf(fp, "%s\n", &b) == 1)
				{
					c = atoi(b);
					insert(&a, c);
				}

				printf("----------\nFILE 5 BEST CASE\n-----------");
				fclose(fp);
				break;
			case 14:
				fp = fopen("File 5.txt", "r");
				if (fp == NULL)
				{
					printf("file not found");
				}

				while (fscanf(fp, "%s\n", &b) == 1)
				{
					c = atoi(b);
					insert(&a, c);
				}

				printf("----------\nFILE 5 AVERAGE CASE\n-----------");
				fclose(fp);
				break;
			case 15:
				fp = fopen("File 5bestre.txt", "r");
				if (fp == NULL)
				{
					printf("file not found");
				}

				while (fscanf(fp, "%s\n", &b) == 1)
				{
					c = atoi(b);
					insert(&a, c);
				}

				printf("----------\nFILE 5 WORST CASE\n-----------");
				fclose(fp);
				break;
			case 16:
				fp = fopen("File 6asc.txt", "r");
				if (fp == NULL)
				{
					printf("file not found");
				}

				while (fscanf(fp, "%s\n", &b) == 1)
				{
					c = atoi(b);
					insert(&a, c);
				}

				printf("----------\nFILE 6 BEST CASE\n-----------");
				fclose(fp);
				break;
			case 17:
				fp = fopen("File 6.txt", "r");
				if (fp == NULL)
				{
					printf("file not found");
				}

				while (fscanf(fp, "%s\n", &b) == 1)
				{
					c = atoi(b);
					insert(&a, c);
				}

				printf("----------\nFILE 6 AVERAGE CASE\n-----------");
				fclose(fp);
				break;
			case 18:
				fp = fopen("File 6desc.txt", "r");
				if (fp == NULL)
				{
					printf("file not found");
				}

				while (fscanf(fp, "%s\n", &b) == 1)
				{
					c = atoi(b);
				    insert(&a, c);
				}

				printf("----------\nFILE 6 WORST CASE\n-----------");
				fclose(fp);
				break;
			case 19:
				fp = fopen("File 7sort.txt", "r");
				if (fp == NULL)
				{
					printf("file not found");
				}

				while (fscanf(fp, "%s\n", &b) == 1)
				{
					c = atoi(b);
					insert(&a, c);
				}

				printf("----------\nFILE 7 BEST CASE\n-----------");
				fclose(fp);
				break;
			case 20:
				fp = fopen("File 7.txt", "r");
				if (fp == NULL)
				{
					printf("file not found");
				}

				while (fscanf(fp, "%s\n", &b) == 1)
				{
					c = atoi(b);
					insert(&a, c);
				}

				printf("----------\nFILE 7 AVERAGE CASE\n-----------");
				fclose(fp);
				break;
			case 21:
				fp = fopen("File 7best.txt", "r");
				if (fp == NULL)
				{
					printf("file not found");
				}

				while (fscanf(fp, "%s\n", &b) == 1)
				{
					c = atoi(b);
					insert(&a, c);
				}

				printf("----------\nFILE 7 WORST CASE\n-----------");
				fclose(fp);
				break;
			case 22:
				fp = fopen("File 8sort.txt", "r");
				if (fp == NULL)
				{
					printf("file not found");
				}

				while (fscanf(fp, "%s\n", &b) == 1)
				{
					c = atoi(b);
					insert(&a, c);
				}

				printf("----------\nFILE 8 BEST CASE\n-----------");
				fclose(fp);
				break;
			case 23:
				fp = fopen("File 8.txt", "r");
				if (fp == NULL)
				{
					printf("file not found");
				}

				while (fscanf(fp, "%s\n", &b) == 1)
				{
					c = atoi(b);
					insert(&a, c);
				}

				printf("----------\nFILE 8 AVERAGE CASE\n-----------");
				fclose(fp);
				break;
			case 24:
				fp = fopen("File 8best.txt", "r");
				if (fp == NULL)
				{
					printf("file not found");
				}

				while (fscanf(fp, "%s\n", &b) == 1)
				{
					c = atoi(b);
					insert(&a, c);
				}

				printf("----------\nFILE 8 WORST CASE\n-----------");
				fclose(fp);
				break;
			case 25:
				fp = fopen("File 9sort.txt", "r");
				if (fp == NULL)
				{
					printf("file not found");
				}

				while (fscanf(fp, "%s\n", &b) == 1)
				{
					c = atoi(b);
					insert(&a, c);
				}

				printf("----------\nFILE 9 BEST CASE\n-----------");
				fclose(fp);
				break;
			case 26:
				fp = fopen("File 9.txt", "r");
				if (fp == NULL)
				{
					printf("file not found");
				}

				while (fscanf(fp, "%s\n", &b) == 1)
				{
					c = atoi(b);
					insert(&a, c);
				}

				printf("----------\nFILE 9 AVERAGE CASE\n-----------");
				fclose(fp);
				break;
			case 27:
				fp = fopen("File 9best.txt", "r");
				if (fp == NULL)
				{
					printf("file not found");
				}

				while (fscanf(fp, "%s\n", &b) == 1)
				{
					c = atoi(b);
					insert(&a, c);
				}

				printf("----------\nFILE 9 WORST CASE\n-----------");
				fclose(fp);
				break;
			case 28:
				fp = fopen("File 10.txt", "r");
				if (fp == NULL)
				{
					printf("file not found");
				}

				while (fscanf(fp, "%s\n", &b) == 1)
				{
					c = atoi(b);
					insert(&a, c);
				}

				printf("----------\nFILE 10 avg CASE\n-----------");
				fclose(fp);
				break;
		}
		clock_t t=0;
		t = clock();
		insertionSort(&a);
		t = clock() - t;
		double time_taken = ((double) t) / CLOCKS_PER_SEC;
		printf("\ninsertion sort took %f seconds to execute \n", time_taken);
		t=0;
		deleteList(&a);
		ch++;
		}while(ch != 28);
        return 0;
	}
