#ifndef DETECTION_H
#define DETECTION_H

#include <iostream>
#include <vector>
#include <queue>
#include <mutex>

using namespace std;

class DeadlockDetection {
private:
    int processes, resources;
    vector<vector<int>> allocation, maxClaim, need;
    vector<int> available;
    mutex mtx;

    bool isSafe();

public:
    DeadlockDetection(int p, int r);
    void input();
    bool detectDeadlock();
    vector<vector<int>>& getAllocation();
    vector<int>& getAvailable();
};

#endif
