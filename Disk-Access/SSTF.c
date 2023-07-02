#include <stdio.h>
#include <stdlib.h>

#define MAX 200

void sstf(int arr[], int head, int size)
{
    int total_movement = 0;
    int visited[MAX] = {0};
    int current = head;
    
    for (int i = 0; i < size; i++) {
        int shortest_distance = __INT_MAX__;
        int selected = -1;
        for (int j = 0; j < size; j++) {
            if (!visited[j]) {
                int distance = abs(current - arr[j]);
                if (distance < shortest_distance) {
                    shortest_distance = distance;
                    selected = j;
                }
            }
        }
        visited[selected] = 1;
        total_movement += shortest_distance;
        current = arr[selected];
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
    
    sstf(arr, head, n);
    
    return 0;
}
