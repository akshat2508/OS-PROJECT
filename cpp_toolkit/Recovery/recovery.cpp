#include "recovery.h"

void DeadlockRecovery::recover(vector<vector<int>>& allocation, vector<int>& available, ofstream& outFile) {
    outFile << "Recovering from deadlock...\n";
    outFile << "Terminating lowest priority process to release resources.\n";

    for (size_t i = 0; i < allocation.size(); i++) {
        for (size_t j = 0; j < allocation[i].size(); j++) {
            available[j] += allocation[i][j];
            allocation[i][j] = 0;
        }
        outFile << "Process P" << i << " terminated. Resources released.\n";
        break;
    }
}
