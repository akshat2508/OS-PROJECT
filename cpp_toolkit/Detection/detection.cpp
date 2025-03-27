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
