#include <stdio.h>
#include <stdlib.h>

#define MAX 200

void c_scan(int arr[], int head, int size)
{
    int total_movement = 0;
    int current = head;
    int start_index = 0;
    int i;
    
    // Sort the request queue in ascending order
    for (i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    // Find the index at which the head starts moving towards the end of the disk
    for (i = 0; i < size; i++) {
        if (arr[i] > head) {
            start_index = i;
            break;
        }
    }
    
    // Traverse the request queue in the direction of the head movement
    for (i = start_index; i < size; i++) {
        total_movement += abs(current - arr[i]);
        current = arr[i];
    }
    
    // If the last request is not at the end of the disk, move to the end of the disk
    if (arr[size-1] != 199) {
        total_movement += abs(current - 199);
        current = 199;
    }
    
    // Move to the beginning of the disk
    total_movement += 199;
    current = 0;
    
    // Traverse the request queue in the direction of the head movement again
    for (i = 0; i < start_index; i++) {
        total_movement += abs(current - arr[i]);
        current = arr[i];
    }
    
    printf("Total head movement = %d\n", total_movement);
}

int main()
{
    int n, head, arr[MAX];
    
    printf("Enter the size of the request queue: ");
    scanf("%d", &n);
    
    printf("Enter the initial position of the disk head: ");
    scanf("%d", &head);
    
    printf("Enter the request queue: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    c_scan(arr, head, n);
    
    return 0;
}
