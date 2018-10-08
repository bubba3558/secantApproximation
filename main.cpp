#include <iostream>
#include "Polynomial.h"
#include <vector>
#include <stdlib.h>
using namespace std;

int main(int argc, char* argv[])
{
    vector<double> vect;
    if (argc<6){
        std::cout<<"podaj przynajmniej 6 liczb "<<std::endl<<"zakres, przyblizenie, ilos powtorzen, an, an-1,..., a1,a0"<<std::endl;
        return 1;
    }
    double bottom = atof(argv[1]); //cnvert strings to correct types
    double top = atof(argv[2]);
    double approx = atof(argv[3]);
    double loopsNo = atoi(argv[4]);
    for(int i=argc-1 ; i > 4; --i )
        vect.push_back( atof(argv[i] ));
    Polynomial func1(vect);
    func1.printRootFromRange(bottom, top, approx, loopsNo);

    return 0;
}
