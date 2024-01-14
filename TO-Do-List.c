#include <stdio.h>
#include <stdlib.h>

// Structure to represent a task
struct Task {
    char description[100];
    int isCompleted;
};

// Function to add a new task
// void addTask(struct Task tasks[], int *taskCount) {
//     // Implementation to add a new task
// }
void addTask(struct Task tasks[], int *taskCount) {
    if (*taskCount < 100) {
        printf("Enter task description: ");
        scanf(" %[^\n]", tasks[*taskCount].description);
        tasks[*taskCount].isCompleted = 0;  // Initialize as not completed
        (*taskCount)++;
        printf("Task added successfully!\n");
    } else {
        printf("Task list is full. Cannot add more tasks.\n");
    }
}


// Function to display all tasks
// void displayTasks(struct Task tasks[], int taskCount) {
//     // Implementation to display all tasks
// }
void displayTasks(struct Task tasks[], int taskCount) {
    if (taskCount == 0) {
        printf("No tasks to display.\n");
    } else {
        printf("===== To-Do List =====\n");
        for (int i = 0; i < taskCount; i++) {
            printf("%d. %s - %s\n", i + 1, tasks[i].description, tasks[i].isCompleted ? "Completed" : "Not Completed");
        }
        printf("=======================\n");
    }
}


// Function to mark a task as completed
// void markTaskCompleted(struct Task tasks[], int taskCount) {
//     // Implementation to mark a task as completed
// }
void markTaskCompleted(struct Task tasks[], int taskCount) {
    if (taskCount == 0) {
        printf("No tasks to mark as completed.\n");
    } else {
        printf("Enter the task number to mark as completed: ");
        int taskNumber;
        scanf("%d", &taskNumber);

        if (taskNumber >= 1 && taskNumber <= taskCount) {
            tasks[taskNumber - 1].isCompleted = 1;
            printf("Task marked as completed!\n");
        } else {
            printf("Invalid task number. Please try again.\n");
        }
    }
}


// Function to save tasks to a file
// void saveTasksToFile(struct Task tasks[], int taskCount, const char *filename) {
//     // Implementation to save tasks to a file
// }
void saveTasksToFile(struct Task tasks[], int taskCount, const char *filename) {
    FILE *file = fopen(filename, "w");

    if (file != NULL) {
        for (int i = 0; i < taskCount; i++) {
            fprintf(file, "%s %d\n", tasks[i].description, tasks[i].isCompleted);
        }
        fclose(file);
        printf("Tasks saved to %s\n", filename);
    } else {
        printf("Error opening file for writing.\n");
    }
}


// Function to load tasks from a file
// void loadTasksFromFile(struct Task tasks[], int *taskCount, const char *filename) {
//     // Implementation to load tasks from a file
// }
#include <stdio.h>

void loadTasksFromFile(struct Task tasks[], int *taskCount, const char *filename) {
    FILE *file = fopen(filename, "r");

    if (file != NULL) {
        while (fscanf(file, " %[^\n] %d", tasks[*taskCount].description, &tasks[*taskCount].isCompleted) != EOF) {
            (*taskCount)++;
            if (*taskCount >= 100) {
                break;  // Avoid exceeding the maximum number of tasks
            }
        }
        fclose(file);
        printf("Tasks loaded from %s\n", filename);
    } else {
        printf("File not found. Starting with an empty task list.\n");
    }
}


//==========================   Main Method =======================================
int main() {
    struct Task tasks[100];  // Assuming a maximum of 100 tasks
    int taskCount = 0;

    // Load tasks from a file (if any)
    loadTasksFromFile(tasks, &taskCount, "tasks.txt");

    int choice;
    do {
        // Display menu
        printf("\n===== To-Do List Application =====\n");
        printf("1. Add Task\n");
        printf("2. Display Tasks\n");
        printf("3. Mark Task as Completed\n");
        printf("4. Save and Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Process user choice
        switch (choice) {
            case 1:
                addTask(tasks, &taskCount);
                break;
            case 2:
                displayTasks(tasks, taskCount);
                break;
            case 3:
                markTaskCompleted(tasks, taskCount);
                break;
            case 4:
                // Save tasks to a file and exit
                saveTasksToFile(tasks, taskCount, "tasks.txt");
                printf("Tasks saved. Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
