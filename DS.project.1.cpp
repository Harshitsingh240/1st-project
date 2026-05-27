#include<stdio.h>
#include<stdlib.h>

#define SIZE 50

typedef struct
{
    int id;
    char pName[20];
    int priority;
    float BT;
} Process;

int count = 0;

/* ADD PROCESS */
void Add(Process table[], int n)
{
    if(count >= SIZE)
    {
        printf("Process table is full\n");
        return;
    }

    printf("\nEnter process-%d details\n", count + 1);

    printf("Enter PID : ");
    scanf("%d", &table[count].id);

    printf("Enter Process Name : ");
    scanf("%s", table[count].pName);

    printf("Enter Priority : ");
    scanf("%d", &table[count].priority);

    printf("Enter Burst Time : ");
    scanf("%f", &table[count].BT);

    count++;
}

/* DISPLAY */
void Display(Process table[], int n)
{
    int i;

    if(count == 0)
    {
        printf("No records found\n");
        return;
    }

    printf("\n----- PROCESS DETAILS -----\n");

    for(i = 0; i < count; i++)
    {
        printf("\nProcess-%d\n", i + 1);
        printf("PID       : %d\n", table[i].id);
        printf("PName     : %s\n", table[i].pName);
        printf("Priority  : %d\n", table[i].priority);
        printf("BT        : %.2f\n", table[i].BT);
    }
}

/* BUBBLE SORT BY PRIORITY */
void BubbleSortByPriority(Process table[], int n)
{
    int i, j;
    Process temp;

    for(i = 0; i < count - 1; i++)
    {
        for(j = 0; j < count - i - 1; j++)
        {
            if(table[j].priority > table[j + 1].priority)
            {
                temp = table[j];
                table[j] = table[j + 1];
                table[j + 1] = temp;
            }
        }
    }

    printf("Processes sorted by Priority\n");
}

/* INSERTION SORT BY PID */
void InsertionSortByPid(Process table[], int n)
{
    int i, j;
    Process key;

    for(i = 1; i < count; i++)
    {
        key = table[i];
        j = i - 1;

        while(j >= 0 && table[j].id > key.id)
        {
            table[j + 1] = table[j];
            j--;
        }

        table[j + 1] = key;
    }

    printf("Processes sorted by PID\n");
}

/* SHELL SORT BY BT */
void shellSortByBT(Process table[], int n)
{
    int gap, i, j;
    Process temp;

    for(gap = count / 2; gap > 0; gap = gap / 2)
    {
        for(i = gap; i < count; i++)
        {
            temp = table[i];

            for(j = i; j >= gap && table[j - gap].BT > temp.BT; j -= gap)
            {
                table[j] = table[j - gap];
            }

            table[j] = temp;
        }
    }

    printf("Processes sorted by Burst Time\n");
}

/* LINEAR SEARCH BY PID */
void linearSearchByPid(Process table[], int n)
{
    int pid, i, found = 0;

    printf("Enter PID to search : ");
    scanf("%d", &pid);

    for(i = 0; i < count; i++)
    {
        if(table[i].id == pid)
        {
            printf("\nProcess Found\n");
            printf("PID       : %d\n", table[i].id);
            printf("PName     : %s\n", table[i].pName);
            printf("Priority  : %d\n", table[i].priority);
            printf("BT        : %.2f\n", table[i].BT);

            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("Process not found\n");
    }
}

/* BINARY SEARCH BY PID */
void BinarySearchByPid(Process table[], int n)
{
    int pid;
    int low = 0;
    int high = count - 1;
    int mid;
    int found = 0;

    printf("Enter PID to search : ");
    scanf("%d", &pid);

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(table[mid].id == pid)
        {
            printf("\nProcess Found\n");
            printf("PID       : %d\n", table[mid].id);
            printf("PName     : %s\n", table[mid].pName);
            printf("Priority  : %d\n", table[mid].priority);
            printf("BT        : %.2f\n", table[mid].BT);

            found = 1;
            break;
        }
        else if(table[mid].id < pid)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if(found == 0)
    {
        printf("Process not found\n");
    }
}

/* MAIN FUNCTION */
int main()
{
    Process table[SIZE];
    int choice;

    while(1)
    {
        printf("\n========= MENU =========\n");
        printf("1. Add\n");
        printf("2. Display\n");
        printf("3. Bubble Sort By Priority\n");
        printf("4. Insertion Sort By PID\n");
        printf("5. Shell Sort By BT\n");
        printf("6. Linear Search By PID\n");
        printf("7. Binary Search By PID\n");
        printf("8. Exit\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                Add(table, SIZE);
                break;

            case 2:
                Display(table, SIZE);
                break;

            case 3:
                BubbleSortByPriority(table, SIZE);
                break;

            case 4:
                InsertionSortByPid(table, SIZE);
                break;

            case 5:
                shellSortByBT(table, SIZE);
                break;

            case 6:
                linearSearchByPid(table, SIZE);
                break;

            case 7:
                printf("First sort by PID using option 4\n");
                BinarySearchByPid(table, SIZE);
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
