#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int available[MAX_RESOURCES];
int maximum[MAX_PROCESSES][MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
bool finish[MAX_PROCESSES];

int n_processes;
int n_resources;

bool is_safe() {
    int work[MAX_RESOURCES];
    for (int i = 0; i < n_resources; i++) {
        work[i] = available[i];
    }

    bool found;
    int count = 0;
    int safe_seq[MAX_PROCESSES];

    while (count < n_processes) {
        found = false;
        for (int i = 0; i < n_processes; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < n_resources; j++) {
                    if (need[i][j] > work[j])
                        break;
                }

                if (j == n_resources) {
                    for (int k = 0; k < n_resources; k++) {
                        work[k] += allocation[i][k];
                    }
                    finish[i] = true;
                    found = true;
                    safe_seq[count] = i;
                    count++;
                }
            }
        }

        if (!found)
            break;
    }

    if (count == n_processes) {
        printf("The system is in a safe state.\n");
        printf("Safe sequence: ");
        for (int i = 0; i < n_processes; i++) {
            printf("%d ", safe_seq[i]);
        }
        printf("\n");
        return true;
    } else {
        printf("System is not in safe state.\n");
        return false;
    }
}

int main() {
    printf("Enter the number of processes: ");
    scanf("%d", &n_processes);
    printf("Enter the number of resources: ");
    scanf("%d", &n_resources);

    printf("\nEnter the available resources: ");
    for (int i = 0; i < n_resources; i++) {
        scanf("%d", &available[i]);
    }

    printf("\nEnter the maximum resources for each process:\n");
    for (int i = 0; i < n_processes; i++) {
        printf("Process %d: ", i);
        for (int j = 0; j < n_resources; j++) {
            scanf("%d", &maximum[i][j]);
        }
    }

    printf("\nEnter the allocated resources for each process:\n");
    for (int i = 0; i < n_processes; i++) {
        printf("Process %d: ", i);
        for (int j = 0; j < n_resources; j++) {
            scanf("%d", &allocation[i][j]);
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
        finish[i] = false;
    }

    is_safe();

    return 0;
}
