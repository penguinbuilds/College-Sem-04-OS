#include <stdio.h>
#include <stdlib.h>

#define MAX 200

void fcfs(int arr[], int head, int size)
{
    int total_movement = 0;
    int current = head;
    
    for (int i = 0; i < size; i++) {
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
    
    fcfs(arr, head, n);
    
    return 0;
}
