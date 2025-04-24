#include<iostream>
#include<algorithm>
using namespace std;

struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
    bool isCompleted = false; // New field to mark completion
};

void findSJF(Process proc[], int n) {
    int completed = 0, currentTime = 0;

    while (completed != n) {
        int idx = -1;
        int minBurst = 9999;

        for (int i = 0; i < n; i++) {
            if (!proc[i].isCompleted && proc[i].arrivalTime <= currentTime) {
                if (proc[i].burstTime < minBurst) {
                    minBurst = proc[i].burstTime;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            proc[idx].completionTime = currentTime + proc[idx].burstTime;
            proc[idx].turnaroundTime = proc[idx].completionTime - proc[idx].arrivalTime;
            proc[idx].waitingTime = proc[idx].turnaroundTime - proc[idx].burstTime;
            proc[idx].isCompleted = true;
            currentTime = proc[idx].completionTime;
            completed++;
        } else {
            currentTime++; // CPU is idle
        }
    }
}

void displayProcessDetails(Process proc[], int n) {
    cout << "\nPID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n";
    for (int i = 0; i < n; i++) {
        cout << proc[i].pid << "\t" << proc[i].arrivalTime << "\t"
             << proc[i].burstTime << "\t" << proc[i].completionTime << "\t\t"
             << proc[i].turnaroundTime << "\t\t" << proc[i].waitingTime << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    Process proc[n];

    cout << "Enter Process Details (PID ArrivalTime BurstTime):\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << ": ";
        cin >> proc[i].pid >> proc[i].arrivalTime >> proc[i].burstTime;
    }

    findSJF(proc, n);
    displayProcessDetails(proc, n);

    return 0;
}  











// #include <iostream>
// using namespace std;

// struct Process{
//     int pid;
//     int arrivaltime;
//     int bursttime;
//     int completiontime;
//     int turnaroundtime;
//     int waitingtime;
// };

// void findSJF( Process proc[],int n){
//     int remainingtime[n];
//     for (int i = 0; i < n; i++)
//     {
//         remainingtime[i]=proc[i].bursttime;
//     }  
//     int currenttime=0;
//     int complete=0;
//     int shortest=0;
//     int minburst=9999;
//     while(complete<n){
//         minburst=9999;

//     }
// }


// int main(){
//     int n=5;
//     Process proc[n];
//     cout<<"Enter Process details (ID, Arrival, Burst)"<< endl;
//     for (int i = 0; i < n ; i++)
//     {
//         cout<<"Enter Process"<< i+1<< endl;
//         cin>> proc[i].pid>> proc[i].arrivaltime>> proc[i].bursttime;
//     }
//     findSJF(proc,n);
//     displayProcessdetails(proc,n);
// }