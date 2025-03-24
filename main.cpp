#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<mutex>
#include<thread>
#include<chrono>
#include "Detection/detection.h"
#include "Prevention/prevention.h"
#include "Recovery/recovery.h"

using namespace std;


int main()
{
    ifstream inFile("input.txt");
    if(!inFile)
    {
        cerr<<"Error: Unable to open input file!\n";
        return 1;
    }

    int processes,  resources;
    inFile>>processes>>resources;

}