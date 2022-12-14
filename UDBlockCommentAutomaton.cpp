#include "UDBlockCommentAutomaton.h"
void UDBlockCommentAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        inputRead = 1;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void UDBlockCommentAutomaton::S1(const std::string& input) {
    if (input[index] == '|') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}

void UDBlockCommentAutomaton::S2(const std::string& input) {
    if(input[index] != '|' && (unsigned int)index <= input.size()-1 )
    {
        if(input[index] == '\n')
        {
            ++newLines;
        }
        inputRead++;
        index++;
        S2(input);
    }
    else if(input[index] == '|')
    {
        inputRead++;
        index++;
        S3(input);
    }
    else if((unsigned int)index >= input.size()-1)
    {
        //inputRead++;
        //index++;
        S4(input);
    }
    else {
        Serr();
    }
}

void UDBlockCommentAutomaton::S3(const std::string& input) {
    if((unsigned int)index <= input.size()-1 && input[index] != '|' && input[index] != '#') //FIXME : might have to switch it back.
    {
        if(input[index] == '\n')
        {
            ++newLines;
        }
        inputRead++;
        index++;
        S2(input);
    }
    else if(input[index] == '|')
    {
        inputRead++;
        index++;
        S3(input);
    }
    else if((unsigned int)index >= input.size()-1)
    {
        S4(input);
    }
    else if(input[index] == '#')
    {
        Serr();
    }
    else {
        Serr();
    }
}

void UDBlockCommentAutomaton::S4(const std::string& input){
    return;
}
