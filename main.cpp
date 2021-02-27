#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream inputFile(argv[1], ios::in);
    ifstream emptyFile(argv[2], ios::in);
    if(!inputFile){
        printf("Error: cannot parse input file data from %s\n", argv[1]);
            exit(1);
    }else if(!emptyFile){
        printf("Error: cannot find file %s\n",argv[2]);
            exit(1);
    }
    inputFile.close();
    emptyFile.close();

   std::cout<<("(i) - Insert value"
               "\n(d) - Delete value"
               "\n(s) - Search value"
               "\n (n) - Print next iterator value"
               "\n(r) - Reset iterator"
               "\n(a) - Delete alternate nodes"
               "\n(m) - Merge two lists"
               "\n(t) - Intersection"
               "\n(p) - Print list"
               "\n(l) - Print length"
               "\n(q) - Quit program"
               );








































    return 0;
}
