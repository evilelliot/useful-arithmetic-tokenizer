#include "src/tokenizer.hpp"
#include <iostream>
#include <string>

int main(int argc, char *argv[]){
    std::string exp = "3 + 4.5";
    Tokenizer tk(exp);
    
    if(tk.is_valid()){
        tk.print_list();
    }
    return 0;
}