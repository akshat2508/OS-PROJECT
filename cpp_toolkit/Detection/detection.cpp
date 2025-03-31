#include "detection.h"

DeadlockDetection::DeadlockDetection(int p, int r) : processes(p), resources(r) {
    allocation.resize(p, vector<int>(r));
    maxClaim.resize(p, vector<int>(r));
    need.resize(p, vector<int>(r));
    available.resize(r);
}

void DeadlockDetection::inputFromFile(ifstream& inFile) {
    lock_guard<mutex> lock(mtx);
    
    for (int i = 0; i < processes; i++)
        for (int j = 0; j < resources; j++)
            inFile >> allocation[i][j];

    for (int i = 0; i < processes; i++)
        for (int j = 0; j < resources; j++)
            inFile >> maxClaim[i][j];

    for (int j = 0; j < resources; j++)
        inFile >> available[j];

    for (int i = 0; i < processes; i++)
        for (int j = 0; j < resources; j++)
            need[i][j] = maxClaim[i][j] - allocation[i][j];
}

bool DeadlockDetection::isSafe(ofstream& outFile) {
    vector<bool> finish(processes, false); // Track finished processes
    vector<int> work = available; // Work vector representing available resources
    vector<int> safeSequence; // Track safe sequence
    int count = 0;

    while (count < processes) {
        bool found = false;

        for (int i = 0; i < processes; i++) {
            if (!finish[i]) { 
                bool canAllocate = true;

                // Check if resources are available
                for (int j = 0; j < resources; j++) {
                    if (need[i][j] > work[j]) {
                        canAllocate = false;
                        break;
                    }
                }

                if (canAllocate) {
                    // Allocate resources & mark process as completed
                    for (int j = 0; j < resources; j++)
                        work[j] += allocation[i][j];

                    finish[i] = true;
                    safeSequence.push_back(i);
                    found = true;
                    count++;
                }
            }
        }

        if (!found) { // If no process was allocated, system is in an unsafe state
            outFile << "System is in an UNSAFE state! Deadlock possible.\n";
            return false;
        }
    }

    // If all processes are executed, print safe sequence
    outFile << "System is in a SAFE state.\nSafe sequence: ";
    for (int i = 0; i < safeSequence.size(); i++) {
        outFile << "P" << safeSequence[i];
        if (i < safeSequence.size() - 1) outFile << " -> ";
    }
    outFile << endl;

    return true;
}