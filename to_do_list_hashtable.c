#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char description[100];
    int occupied;
} Task;

Task table[100];
int table_size;

void initializeTable() {
    for (int i = 0; i < table_size; i++) {
        table[i].occupied = 0;
    }
}

int hashFunction(int id) {
    return id % table_size;
}

void insertTask(int id, char* description) {
    int index = hashFunction(id);
    int originalIndex = index;
    int count = 0;

    while (table[index].occupied == 1 && count < table_size) {
        if (table[index].id == id) {
            printf("Task with this ID already exists!\n");
            return;
        }
        index = (index + 1) % table_size;
        count++;
    }

    if (count == table_size) {
        printf("Table is full!\n");
        return;
    }

    table[index].id = id;
    strcpy(table[index].description, description);
    table[index].occupied = 1;
    printf("Task added!\n");
}


void deleteTask(int id) {
    int index = hashFunction(id);
    int count = 0;

    while (count < table_size) {
        if (table[index].occupied == 1 && table[index].id == id) {
            table[index].occupied = -1; // Mark as deleted
            printf("Task deleted!\n");
            return;
        }
        if (table[index].occupied == 0) break; // Stop if we find an empty spot
        index = (index + 1) % table_size;
        count++;
    }

    printf("Task not found!\n");
}

// Display all tasks
void displayTasks() {
    int found = 0;
    for (int i = 0; i < table_size; i++) {
        if (table[i].occupied == 1) {
            printf("Task %d: %s\n", table[i].id, table[i].description);
            found = 1;
        }
    }
    if (!found) {
        printf("No tasks to display.\n");
    }
}

int main() {
    int choice, id;
    char description[100];

    do {
        printf("Enter table size (1 - 100): ");
        scanf("%d", &table_size);
    } while (table_size < 1 || table_size > 100);

    initializeTable();

    while (1) {
        printf("\n1. Add Task\n2. Delete Task\n3. Display Tasks\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        getchar(); 

        if (choice == 4) {
            printf("Exiting...\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                getchar(); 
                printf("Enter description: ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = 0;
                insertTask(id, description);
                break;
            case 2:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                deleteTask(id);
                break;
            case 3:
                displayTasks();
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

  
         
    
