#ifndef RECOVERY_H
#define RECOVERY_H

#include <vector>
#include <fstream>

using namespace std;

class DeadlockRecovery {
public:
    void recover(vector<vector<int>>& allocation, vector<int>& available, ofstream& outFile);
};

#endif // RECOVERY_H
