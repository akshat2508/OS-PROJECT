#include "detection.h"

DeadlockDetection::DeadlockDetection(int p, int r) : processes(p), resources(r) {
    allocation.resize(p, vector<int>(r));
    maxClaim.resize(p, vector<int>(r));
    need.resize(p, vector<int>(r));
    available.resize(r);
}
