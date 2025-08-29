#include <stdio.h>

// Structure to represent a job
struct Job {
    char id;     // Job ID
    int deadline; // Deadline of job
    int profit;  // Profit of job
};

// Function to sort the jobs based on profit
void sortByProfit(struct Job jobs[], int n) {
int i,j;
    for ( i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (jobs[j].profit < jobs[j + 1].profit) {
                struct Job temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }
}

// Function to find the maximum deadline from the given jobs
int findMaxDeadline(struct Job jobs[], int n) {
    int max = -1;
    int i;
    for ( i = 0; i < n; i++) {
        if (jobs[i].deadline > max) {
            max = jobs[i].deadline;
        }
    }
    return max;
}

// Function to schedule jobs and calculate maximum profit
int jobSequencing(struct Job jobs[], int n, char sequence[]) {
    // Sort jobs based on profit
    sortByProfit(jobs, n);

    // Find the maximum deadline
    int maxDeadline = findMaxDeadline(jobs, n);

    // Array to keep track of slot availability
    int slot[maxDeadline];
    int i;
    for (i = 0; i < maxDeadline; i++) {
        slot[i] = -1; // -1 indicates slot is free
    }

    // Schedule jobs
    int totalProfit = 0;
    int j;
    for (i = 0; i < n; i++) {
        for (j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slot[j] == -1) {
                sequence[j] = jobs[i].id;
                slot[j] = i;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    return totalProfit;
}

// Driver code
int main() {
    int n,i;
    printf("Name:-Rohit kumar\nEnrollment no.:-0827CS221232\nTopic:-Code to implement job sequencing with deadlines.:\n");
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    struct Job jobs[n];
    for (i = 0; i < n; i++) {
        printf("Enter details for job %d (ID, deadline, profit): ", i + 1);
        scanf(" %c %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }

    char sequence[100]; // Assuming maximum deadline is 100
    int totalProfit = jobSequencing(jobs, n, sequence);

    // Display the sequence of jobs
    printf("Sequence of jobs: ");
    for (i = 0; i < n; i++) {
        if (sequence[i] != '\0') {
            printf("%c ", sequence[i]);
        }
    }
    printf("\n");

    // Display the total profit
    printf("Total profit: %d\n", totalProfit);

    return 0;
}