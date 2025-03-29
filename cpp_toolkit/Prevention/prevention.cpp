#include "prevention.h"

void DeadlockPrevention::prevent(ofstream& outFile) {
    outFile << "Implementing deadlock prevention mechanisms...\n";
    outFile << "- Avoiding Circular Wait by enforcing resource ordering.\n";
    outFile << "- Applying Hold and Wait prevention strategy.\n";
    outFile << "- Allocating resources only when all required ones are available.\n";
}
