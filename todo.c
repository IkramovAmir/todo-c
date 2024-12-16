#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Task strukturasini yaratamiz
typedef struct
{
    char title[128]; // Vazifaning nomi
    char description[512];
    int status; // 1 - "Bajarilgan", 0 - "Bajarilmagan"
} Task;

Task tasks[100]; // Vazifalar ro'yxati
int count = 0;   // Hozirgi vazifalar soni

// add_task - Yangi vazifa qo'shish
void add_task()
{
    printf("Enter task title: ");
    getchar(); // for clear enter
    fgets(tasks[count].title, sizeof(tasks[count].title), stdin);

    // printf("\n");

    printf("Enter Task Description: ");
    fgets(tasks[count].description, sizeof(tasks[count].description), stdin);

    tasks[count].status = 0;
    count++;

    printf("Task added successfully!\n\n");
};

// list_all_tasks - Barcha vazifalarni ro'yxatini ko'rsatish
void list_all_tasks()
{
    if (count == 0)
    {
        printf("No tasks available!!!\n\n");
        return;
    }

    printf("ID   | Title        | Description            |  Status\n");
    printf("----------------------------------------------------------\n");

    for (int i = 0; i < count; i++)
    {
        printf("%-5d|  %-10s  |  %-25s  |  %s\n", i + 1, strtok(tasks[i].title, "\n"), strtok(tasks[i].description, "\n"), tasks[i].status == 1 ? "Done" : "Not Done");
    }
};

// get_task_by_id - Vazifani ID bo'yicha ko'rsatish
void get_task_by_id()
{
    int id;
    printf("Enter task ID to get: ");
    scanf("%d", &id);
    getchar();
    printf("\n");

    id--;

    printf("Title: %-10s\n", tasks[id].title);
    printf("Description: %-10s\n", tasks[id].description);
    printf("Status: %-10s\n", tasks[id].status == 1 ? "Done" : "Not Done!");
    printf("\n");
};

// delete_task_by_id - Vazifani ID bo'yicha o'chirish
void delete_task_by_id()
{
    int id;

    printf("Enter task ID to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > count)
    {
        printf("Invalid ID!!!");
        return;
    }
    id--;
    for (int i = id; i < count - 1; i++)
    {
        tasks[i] = tasks[i + 1];
    }

    count--;
    printf("Task deleted successfully!");
    printf("\n");
};

// mark_task_completed - Vazifani "Completed" deb belgilash
void mark_task_completed()
{
    int id;

    printf("If you complete any task, pls enter ID of that task: ");
    scanf("%d", &id);
    
    id--;
    tasks[id].status = 1;
    printf("Task marked as completed!");
};

// mark_task_incomplete - Vazifani "Incomplete" deb belgilash
void mark_task_incomplete()
{
    int id;

    printf("If you incompleted yet any task, pls enter ID of that task: ");
    scanf("%d", &id);

    id--;
    tasks[id].status = 0;
    printf("Task marked as incompleted!");
};

// show_menu - Foydalanuvchiga menyuni ko'rsatish
// void exit_program(void){
//     retu
// };

int main()
{
    int n;

    while (1)
    {
        printf("To-Do List Menu:\n");
        printf("\n 1. Add Task\n 2. List Tasks\n 3. Get Task by ID\n 4. Delete Task\n 5. Mark Task as Completed\n 6. Mark Task as Incompleted\n 7. Exit\n Enter your choice: ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            add_task();
            break;
        case 2:
            list_all_tasks();
            break;
        case 3:
            get_task_by_id();
            break;
        case 4:
            delete_task_by_id();
            break;
        case 5:
            mark_task_completed();
            break;
        case 6:
           mark_task_incomplete();
           break;
        case 7:
           printf("You are exited program!!!");
           return 0;
        
        }
    }
    return 0;
}