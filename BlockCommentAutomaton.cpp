#include "BlockCommentAutomaton.h"
void BlockCommentAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        inputRead = 1;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void BlockCommentAutomaton::S1(const std::string& input) {
    if(input[index] == '|')
    {
        inputRead++;
        index++;
        S2(input);
    }
    else
    {
        Serr();
    }
}

void BlockCommentAutomaton::S2(const std::string& input) {
    if(input[index] == '|')
    {
        inputRead++;
        index++;
        S3(input);
    }
    else if(input[index] != '|' &&  (unsigned int)index <= input.size()-1)
    {
        if(input[index] == '\n')
        {
            ++newLines;
        }
        inputRead++;
        index++;
        S2(input);
    }
    else if((unsigned int)index <= input.size()-1)
    {
        Serr();
    }
    else
    {
        Serr();
    }
}

void BlockCommentAutomaton::S3(const std::string& input) {
    if(input[index] == '#')
    {
        inputRead++;
        index++;
        S4(input);
    }
    else if(input[index] == '|')
    {
        inputRead++;
        index++;
        S3(input);
    }
    else if(input[index] != '|' && (unsigned int)index <= input.size()-1)
    {
        S2(input);
    }
    else
    {
        Serr();
    }
}

void BlockCommentAutomaton::S4(const std::string& input) {
    return;
}