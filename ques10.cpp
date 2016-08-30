#include <iostream>
#include <string>
#include <fstream>
using namespace std; 
struct Cloud {
        string name;
        int multiplier;
}; 
int main(int argc, char const *argv[]) {
        int count = 0;
        string trash;
        ifstream text(argv[1]);
        ofstream output(argv[2]);
        Cloud object;
        while(not text.eof()){
            text >> object.name;
            text >> trash;
            text >> object.multiplier;
            while(object.multiplier > 0){
                output << object.name + " ";
                object.multiplier--;
            }
            object.name = "";
        }
        output.close();
}