#include <stdio.h>
#include <limits.h>

struct process {
    int process_id, arrival_time, burst_time, priority, waiting_time, turnaround_time, completion_time, response_time;
    int remaining_time;
};

// Prototipet e funksioneve qe definohen me poshte
void getProcessData(struct process p[], int n);
void executeProcesses(struct process p[], int n, float *WaitingTime, float *TurnAroundTime, float *CompletionTime);
void printProcessData(struct process p[], int n);
void printAverages(float WaitingTime, float TurnAroundTime, float CompletionTime, int n);

int main() {
    int n;
    float WaitingTime = 0, TurnAroundTime = 0, CompletionTime = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process p[n];

    getProcessData(p, n);
    executeProcesses(p, n, &WaitingTime, &TurnAroundTime, &CompletionTime);
    printProcessData(p, n);
    printAverages(WaitingTime, TurnAroundTime, CompletionTime, n);

    return 0;
}

// Funksioni i cili i kerkon te dhenat nga useri
void getProcessData(struct process p[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter priority for process %d: ", i + 1);
        scanf("%d", &p[i].priority);
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &p[i].arrival_time);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &p[i].burst_time);
        p[i].process_id = i + 1;
        p[i].waiting_time = 0;
        p[i].turnaround_time = 0;
        p[i].remaining_time = p[i].burst_time;
    }
}

// Funksioni qe ben ekzekutimin e proceseve ne baze te prioritetit te tyre duke marre parasysh edhe vetine preemptive
void executeProcesses(struct process p[], int n, float *WaitingTime, float *TurnAroundTime, float *CompletionTime) {
    int current_time = 0, completed = 0;

    while (completed != n) {
        int highest_priority = INT_MAX;
        int selected_process = -1;

        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time <= current_time && p[i].remaining_time > 0 && p[i].priority < highest_priority) {
                highest_priority = p[i].priority;
                selected_process = i;
            }
        }

        if (selected_process == -1) {
            current_time++;
            continue;
        }

        p[selected_process].remaining_time--;

        if (p[selected_process].remaining_time == 0) {
            p[selected_process].completion_time = current_time + 1;
            p[selected_process].turnaround_time = p[selected_process].completion_time - p[selected_process].arrival_time;
            p[selected_process].waiting_time = p[selected_process].turnaround_time - p[selected_process].burst_time;
            *CompletionTime += p[selected_process].completion_time;
            *TurnAroundTime += p[selected_process].turnaround_time;
            *WaitingTime += p[selected_process].waiting_time;
            completed++;
        }

        current_time++;
    }
}

// Funksioni i cili printon te dhenat
void printProcessData(struct process p[], int n) {
    printf("\nProcess ID\tPriority\tArrival Time\tBurst Time\tCompletion Time\t\tWaiting Time\t\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n", p[i].process_id, p[i].priority, p[i].arrival_time, p[i].burst_time,
            p[i].completion_time, p[i].waiting_time, p[i].turnaround_time);
    }
}

// Funksioni i cili printon mesataret e llogaritura
void printAverages(float WaitingTime, float TurnAroundTime, float CompletionTime, int n) {
    printf("Average waiting time is: %f\n", (WaitingTime / n));
    printf("Average turnaround time is: %f\n", (TurnAroundTime / n));
    printf("Average Completion time is: %f\n", (CompletionTime / n));
}