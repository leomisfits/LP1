#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std; struct Cloud {
        string name;
        int multiplier;
}; 
bool returnNum(char);
bool identify_pattern(string&,char);
int main(int argc, char const *argv[]) {
        string multiChar = "";
        int count = 0;
        string pattern = "";
	cout <<"teste";
        ifstream text("input.txt");
	stringstream buffer;
    	buffer << text.rdbuf();
    	string charArray(buffer.str());
    	charArray = charArray + '@';
        ofstream output;
        output.open("output.txt");
        Cloud object;

        while(charArray[count] != '@'){
            if(charArray[count] != '\n' and pattern != " :"){
                //para garantir que o objeto nao receba uma quebra de linha, e que nao receba o ultimo espaco
                object.name = object.name + charArray[count];
            }
            if(identify_pattern(pattern,charArray[count]) == true){
                //caso o padrao seja detectado significa que esta na hora de analisar o numero de vezes que a string deve ser impressa 
		        count++;
                while(returnNum(charArray[count]) == true){
                    multiChar = multiChar + charArray[count];
                    text >> charArray[count];
			        count++;
                }
		cout << "teste";
                object.multiplier = stoi(multiChar);
                //convertemos a string que vai ser o numero de vezes que sera impresso em inteiro, e passamos o valor para o multiplicador do objeto
		        object.name = object.name.substr(0, object.name.size()-1);
		        // para eliminar o ':' que sao do padrao do nome do objeto.
                while(object.multiplier > 0){
                    output << object.name;
                    object.multiplier--;
                }
                object.name = "";
                object.multiplier = 0;
                multiChar = "";
		        pattern = "";
		        //no final do if os valores sao resetados
            }//fi
	        count++;
        }
       output.close();
}

bool returnNum(char receiver){
        if (receiver == '0' or receiver == '1' or receiver == '2'
        or receiver == '3' or receiver == '4' or receiver == '5' or receiver == '6' or receiver == '7'
        or receiver == '8' or receiver == '9'){
                return true;
        }
        else
                return true;
}

bool identify_pattern(string& pattern, char receiver){
    if (receiver == ' ' or receiver == ':' or receiver == ':'){
        pattern = pattern + receiver;
    }
    if(pattern == "  "){
        pattern = " ";
    }
    if(pattern == " : ")
        return true;
    else
        return false;
}


