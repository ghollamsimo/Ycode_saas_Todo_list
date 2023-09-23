#include <stdio.h>
#include <string.h>

struct Task {
    int  id;
    char title[50];
    char description[100];
    char deadline[11];  // Format: "YYYY-MM-DD"
    char status[30];    // "To do", "In progress", "Done"
};

// Bonus
struct Collaborator {
    int id;
    char firstName[50];
    char lastName[50];
    char email[100];
};



void menu(){
        printf("|===================|Todo List App|===================|\n");
        printf("|\t1. Ajouter une seule nouvelle tache           |\n");
        printf("|\t2. Ajouter plusieurs nouvelles taches         |\n");
        printf("|\t3. Afficher la liste de toutes les taches     |\n");
        printf("|\t4. Modifier une tache                         |\n");
        printf("|\t5. Supprimer une tache par identifiant        |\n");
        printf("|\t6. Rechercher les Taches                      |\n");
        printf("|\t7. Statistiques                               |\n");
        printf("|\t--------------Bonus -----------------              |\n");
        printf("|\t8.Ajouter des collaborateurs                           |\n");
        printf("|\t9. Quiter                                    |\n");
        printf("|=====================================================|\n \n");
        printf("Enter Your choice: ");
}
int isValidDeadline(const char deadline[]) {
    if (strlen(deadline) != 10) {
        return 0;
    }

    // Check the hyphens are in the correct positions
    if (deadline[4] != '-' || deadline[7] != '-') {
        return 0;
    }
}

int addSingleTask(struct Task tasks[], int count){
    struct Task newTask;

    newTask.id = count + 1;

    printf("Enter the title of the task: ");
    scanf(" %[^\n]", newTask.title);// i use [^\n] for newlines and spaces

    printf("Enter the description of the task: ");
    scanf(" %[^\n]", newTask.description);

    printf("Enter the deadline of the task (YYYY-MM-DD): ");
    scanf("%s", newTask.deadline);
    while(isValidDeadline(newTask.deadline) == 0){
        printf("Enter the deadline of the task (YYYY-MM-DD): ");
        scanf("%s", newTask.deadline);
    }

    printf("Enter the status of the task (To do/In progress/Done): ");
    scanf(" %[^\n]", newTask.status);

    tasks[count] = newTask;
    count++;

    printf("Task added successfully!\n");
    return count;
}

void displayTasks(struct Task tasks[], int count) {
    printf("\n--- All Tasks ---\n");
    for (int i = 0; i <count; i++) {
        printf("ID: %d\n", tasks[i].id);
        printf("Title: %s\n", tasks[i].title);
        printf("Description: %s\n", tasks[i].description);
        printf("Deadline: %s\n", tasks[i].deadline);
        printf("Status: %s\n", tasks[i].status);
        printf("\n");
    }
}

void displayCollaborators(struct Collaborator collaborator[], int count) {
    printf("\n--- All Collaborators ---\n");
    for (int i = 0; i <count; i++) {
        printf("ID: %d\n", collaborator[i].id);
        printf("LastName: %s\n", collaborator[i].lastName);
        printf("FirstName: %s\n", collaborator[i].firstName);
        printf("Email: %s\n", collaborator[i].email);
        printf("\n");
    }
}

int addMultipleTasks(struct Task tasks[], int count) {
    int numTasks;
    printf("How many tasks would you like to add? ");
    scanf("%d", &numTasks);

    for (int i = 0; i < numTasks; i++) {
        printf("Adding task %d:\n", i+1);
        count = addSingleTask(tasks, count);
    }
    return count;

}
//Tri par selection (je compare la case i avec la case i+1)
void sortTasksWithAlphabe(struct Task tasks[], int count) {
    struct Task temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(tasks[i].title, tasks[j].title) > 0) {
                temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
}

void displayMenu() {
    printf("\n|===========|Display Options|===========|\n");
    printf("|\t1. Afficher toutes les tâches         |\n");
    printf("|\t2. Trier par ordre alphabétique       |\n");
    printf("|\t3. Trier par deadline                 |\n");
    printf("|=======================================|\n \n");
    printf("Enter Your choice for display: ");
}

void modifyMenu() {
    printf("\n|===========|Modify Options|===========|\n");
    printf("|\t1. Modifier la description             |\n");
    printf("|\t2. Modifier le statut                   |\n");
    printf("|\t3. Modifier le deadline                 |\n");
    printf("|=======================================|\n \n");
    printf("Enter Your choice for modification: ");
}

void searchMenu() {
    printf("\n|===========|Search Options|===========|\n");
    printf("|\t1. Rechercher par Identifiant          |\n");
    printf("|\t2. Rechercher par Titre                |\n");
    printf("|=======================================|\n \n");
    printf("Enter Your choice for search: ");
}

/*
1. first i get the id entered by the user (id task)
2. i use the loop for to find the task entred by the user (compare the id of tasks with the enreted one)
3. i print the information of the finded task
*/
void searchTasks(struct Task tasks[], int count) {
    int searchChoice, idToSearch;
    char titleToSearch[50];

    searchMenu();
    scanf("%d", &searchChoice);

    switch (searchChoice) {
        case 1: // Rechercher par Identifiant
            printf("Enter the ID to search: ");
            scanf("%d", &idToSearch);
            
            for (int i = 0; i < count; i++) {
                if (tasks[i].id == idToSearch) {
                    printf("\nTask Found:\n");
                    printf("ID: %d\n", tasks[i].id);
                    printf("Title: %s\n", tasks[i].title);
                    printf("Description: %s\n", tasks[i].description);
                    printf("Deadline: %s\n", tasks[i].deadline);
                    printf("Status: %s\n", tasks[i].status);
                    return;
                }
            }
            printf("Task with the given ID not found.\n");
            break;
            
        case 2: // Rechercher par Titre
            printf("Enter the title to search: ");
            scanf(" %[^\n]", titleToSearch);
            
            for (int i = 0; i < count; i++) {
                if (strcmp(tasks[i].title, titleToSearch) == 0) {
                    printf("\nTask Found:\n");
                    printf("ID: %d\n", tasks[i].id);
                    printf("Title: %s\n", tasks[i].title);
                    printf("Description: %s\n", tasks[i].description);
                    printf("Deadline: %s\n", tasks[i].deadline);
                    printf("Status: %s\n", tasks[i].status);
                    return;
                }
            }
            printf("Task with the given title not found.\n");
            break;
            
        default:
            printf("Invalid choice for search.\n");
    }
}
//TRI PAR SELECTION
void sortTasksByDeadline(struct Task tasks[], int count) {
    struct Task temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(tasks[i].deadline, tasks[j].deadline) > 0) {
                temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
}

void modifyTask(struct Task tasks[], int count) {
    int idToModify, modifyChoice;
    printf("Enter the ID of the task to modify: ");
    scanf("%d", &idToModify);

    // Trouver la tâche avec l'ID donné
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (tasks[i].id == idToModify) {
            found = 1;
            modifyMenu();
            scanf("%d", &modifyChoice);

            switch (modifyChoice) {
                case 1:  // Modifier la description
                    printf("Enter the new description: ");
                    scanf(" %[^\n]", tasks[i].description);
                    break;
                case 2:  // Modifier le statut
                    printf("Enter the new status: ");
                    scanf(" %[^\n]", tasks[i].status);
                    break;
                case 3:  // Modifier le deadline
                    printf("Enter the new deadline (YYYY-MM-DD): ");
                    scanf("%s", tasks[i].deadline);
                    break;
                default:
                    printf("Invalid choice for modification.\n");
            }
            printf("Task modified successfully!\n");
            break;
        }
    }

    if (found==0) {
        printf("Task with the given ID not found.\n");
    }
}

void displayStatistics(struct Task tasks[], int count) {
    int completedTasks = 0, incompleteTasks = 0;

    // Count the total number of tasks
    printf("Total number of tasks: %d\n", count);

    // Count completed and incomplete tasks
    for (int i = 0; i < count; i++) {
        if (strcmp(tasks[i].status, "Done") == 0) {
            completedTasks++;
        } else {
            incompleteTasks++;
        }
    }
    
    // Display the counts
    printf("Number of completed tasks: %d\n", completedTasks);
    printf("Number of incomplete tasks: %d\n", incompleteTasks);
}

int deleteTaskById(struct Task tasks[], int count, int id) {
    int index = -1;
    // Trouver l'index de la tâche avec l'ID donné
    for (int i = 0; i < count; i++) {
        if (tasks[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Task with the given ID not found.\n");
        return count;
    }

    // Déplacer toutes les tâches suivantes une position vers l'arrière
    for (int i = index; i < count - 1; i++) {
        tasks[i] = tasks[i + 1];
    }

    // Mettre à jour les ID des tâches restantes
    for (int i = index; i < count - 1; i++) {
        tasks[i].id = i + 1;
    }

    // Réduire le nombre de tâches
    count--;

    printf("Task deleted successfully!\n");
    return count;
}
//bonus
int createMultipleCollaborators(struct Collaborator collaborators[], int count) {
    int numCollaborators;
    printf("How many collaborators would you like to add? ");
    scanf("%d", &numCollaborators);

    for(int i = 0; i < numCollaborators; i++) {
        printf("Enter first name of collaborator %d: ", i+1);
        scanf("%s", collaborators[i].firstName);
        printf("Enter last name of collaborator %d: ", i+1);
        scanf("%s", collaborators[i].lastName);
        printf("Enter email of collaborator %d: ", i+1);
        scanf("%s", collaborators[i].email);

        printf("Collaborator added successfully!\n");
        count++;
    }
    return count;
}   

int main() {
    struct Task tasks[100];
    struct Collaborator collaborators[100];
    int taskCount = 0, collaboratorsCount = 0;
    int choice, displayChoice, idToDelete;

    while (1) {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                taskCount = addSingleTask(tasks, taskCount);
                break;
            case 2:
                taskCount = addMultipleTasks(tasks, taskCount);
                break;
            case 3:
                displayMenu();
                scanf("%d", &displayChoice);
                switch (displayChoice) {
                    case 1:
                        displayTasks(tasks, taskCount);
                        break;
                    case 2:
                        sortTasksWithAlphabe(tasks, taskCount);
                        displayTasks(tasks, taskCount);
                        break;
                    case 3:
                        sortTasksByDeadline(tasks, taskCount);
                        displayTasks(tasks, taskCount);
                        break;
                    default:
                        printf("Invalid choice for display.\n");
                }
                break;
            case 4:
                modifyTask(tasks, taskCount);
                break;

            case 5:
                printf("Enter the ID of the task to delete: ");
                scanf("%d", &idToDelete);
                taskCount = deleteTaskById(tasks, taskCount, idToDelete);
                displayTasks(tasks, taskCount);
                break;

            case 6:
                searchTasks(tasks, taskCount);
                break;

            case 7:
                displayStatistics(tasks, taskCount);
                break;
            case 8:
                collaboratorsCount = createMultipleCollaborators(collaborators, collaboratorsCount);
                displayCollaborators(collaborators, collaboratorsCount);
                break;
            case 9:
                printf("Have A Good Day");
                return 0;
        }
    }
}