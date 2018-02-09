#include <iostream>
#include <ctime>
#include "highway.h"

using namespace std;

unsigned int Highway::max_K = 0;
double Highway::Percent = 0;
unsigned int Highway::NSegs = 0;

int main(int argc, char * argv[])
{
    unsigned int N;
    srand(time(NULL));
    if(argc == 5)
    {
        N = atoi(argv[1]);
        Highway::NSegs = atoi(argv[2]);
        Highway::max_K = atoi(argv[3]);
        Highway::Percent = atof(argv[4]);
        if(Highway::Percent > 1.0)
        {
            cout << "Na dwthei timh mikroterh tou 1, gia to orisma Percent!" << endl;
            return 1;
        }
    }
    else
    {
        cout << "Na dwthei to katallhlo plhthos orismatwn!" << endl;
        return 1;
    }
    Highway AttikiOdos;
    for (unsigned int i = 0; i < N; i++) { AttikiOdos.operate(); }
    return 0;
}