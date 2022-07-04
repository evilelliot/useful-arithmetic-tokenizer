#ifndef TOKENIZER_HPP
#define TOKENJIZER_HPP

#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
class Tokenizer{
    private:
        struct _token{
        std::string _type; 
        float       _number;
        char        _operator;
        int         _col_pos;

        _token(std::string _t, float _n, char _o, int _c){
            this->_number   = _n;
            this->_type     = _t;
            this->_operator = _o;
            this->_col_pos  = _c;
        }
        _token(){}
    };  
    std::vector<_token> _tokens_list;
    int p_init = 0;
    int p_clos = 0;
    public:
    Tokenizer(std::string exp){
        
        int pos    = 0;
        float num  = 0; 
        std::string token; 
        std::istringstream tokens_stream(exp); 
        
        _token aux;

        while(tokens_stream >> token){
            if(token.size() == 1 && is_operator(token[0])){
                aux = {"OPERATOR", NULL, token[0], pos};
            }else if(token.size() == 1 && token[0] == '(' || token[0] == ')'){
                token[0] == '(' ? p_init++ : p_clos++; 
                aux = {token[0] == '(' ? "RIGHT_PARENTHESIS" : "LEFT_PARENTHESIS", NULL, token[0], pos};
            }else{
                std::istringstream numbers_stream(token);
                if(numbers_stream >> num){
                    aux = {(is_float(num) ? "FLOAT_NUMBER" : "INTEGER"), num, NULL, pos};                
                }
            }
            _tokens_list.push_back(aux);
            pos++;
        }
        // std::cout << (p_init == p_clos ? "Expresión valida." : "Expresión invalida.") << std::endl;
    }

    // Static methods
    static bool is_float(float number){
        return (number != (int)number ? true : false);
    }
    static bool is_operator(char c){
        switch(c){
            case '+':
            case '-':
            case '*':
            case '/':
                return true;
            break;
            default:
                return false;
            break;
        }
    }
    bool is_valid(){
        int error_count = 0;
        int i = 0;
        bool flag, _flag;
        std::for_each(_tokens_list.begin(), _tokens_list.end(), [&](_token item){
            if(i <= _tokens_list.size()){
                if(_tokens_list[i]._type == _tokens_list[i+1]._type){
                    if(_tokens_list[i]._type == "OPERATOR"){
                        error_count++;
                        flag = false;
                        std::cout << "| \033[1;31mError (\033[1;36m" << error_count << "\033[0m\033[1;31m)\033[0m: \033[0m\n|\033[1;33m Invalid use of operators\033[0m, there cannot be two arithmetic operators in a row in the same expression. Expected [num operator num] or similar." << std::endl
                                  << "| Found at column (" << _tokens_list[i]._col_pos << ") with '" << _tokens_list[i]._operator << "' as operator and '" 
                                  << _tokens_list[i++]._operator << "' as the next operator." << std::endl;
                                  std::cout << "________________________________________________________________________________________________________________________________________________" << std::endl;
                    }else if(_tokens_list[i]._type == "INTEGER" || _tokens_list[i]._type == "FLOAT_NUMBER"){
                        error_count++;
                        flag = false;
                        std::cout << "| \033[1;31mError (\033[1;36m" << error_count << "\033[0m\033[1;31m)\033[0m: \033[0m\n|\033[1;33m Invalid use of numbers\033[0m, there cannot be two numbers in a row in the same expression. Expected [num operator num] or similar." << std::endl
                                  << "| Found at column (" << _tokens_list[i]._col_pos << ") with '" << _tokens_list[i]._number << "' as type ["<< _tokens_list[i]._type << "] and '" << _tokens_list[i++]._number
                                  << "' as the next data type ["<< _tokens_list[i++]._type << "]" << std::endl;
                                  std::cout << "________________________________________________________________________________________________________________________________________________" << std::endl;
                    }
                }
            }
            i++;
        });
        if(p_init != p_clos){
            error_count++;
            std::cout << "| \033[1;31mError (\033[1;36m" << error_count << "\033[0m\033[1;31m)\033[0m: \033[0m\n| \033[1;33mInvalid use of parenthesis\033[0m, expected to close a set of parentheses." << std::endl
            << "| Example of use \033[1;32m( 5 + 5 ) + ( 2.6 )\033[0m." << std::endl;
            std::cout << "________________________________________________________________________________________________________________________________________________" << std::endl;
        }
        return (flag && _flag);
    }
    void print_list(){
        std::cout << _tokens_list.size() << std::endl;
        std::for_each(_tokens_list.begin(), _tokens_list.end(), [&](_token item){
            if(item._type == "FLOAT_NUMBER" || item._type == "INTEGER"){
                std::cout << "Type: " << item._type << std::endl;
                std::cout << "Number: " << item._number << std::endl;
                std::cout << "Col: " << item._col_pos << std::endl;
                std::cout << "___________________" << std::endl;
            }else if(item._type == "OPERATOR"){
                std::cout << "Type: " << item._type << std::endl;
                std::cout << "Operator: " << item._operator << std::endl;
                std::cout << "Col: " << item._col_pos << std::endl;
                std::cout << "___________________" << std::endl;
            }else if(item._type == "RIGHT_PARENTHESIS" || item._type == "LEFT_PARENTHESIS"){
                std::cout << "Type: " << item._type << std::endl;
                std::cout << "Parenthesis: " << item._operator << std::endl;
                std::cout << "Col: " << item._col_pos << std::endl;
                std::cout << "___________________" << std::endl;
            }
        });
    }
};

#endif