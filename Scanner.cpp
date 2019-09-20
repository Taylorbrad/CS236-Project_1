#include "Scanner.h"
#include "Token.h"
#include <cctype>
using namespace std;

Scanner::Scanner(string fileName)
{
    this->fileName = fileName;
}
void Scanner::tokenize()
{
    int lineNum = 1;
    int badCreateFlag = 0;
    int tempTrackerDebug = 0;
    ifstream inFile;
    ofstream outFile;
    char currentChar;
    stack <char> currentTokenStack;
    stack <char> emptyStack;
    stack <Token> allTokensInFile;
    TokenType tokenType;
    
    // currentChar = inFile.peek();
    // char test = currentChar;
    // currentChar = test;
    inFile.open(this->fileName);
    
    if(!inFile)
    {
        cout << "Unable to read file";
        return;
    }
    /*count the first line if it is a newline character*/
    // if (inFile.peek() == '\n')
    // {
    //     lineNum += 1;
    //     cout << lineNum;
    // }
    
    while (inFile.peek() != EOF) //you gotta get all the tokens in this while statement
    {
        while(isspace(inFile.peek())) //Whenever the scanner encounters whitespace, iterate out until there is no more white space
        {
            if (inFile.peek() == '\n')
            {
                lineNum += 1;
            }
            inFile.get();
        }
        badCreateFlag = 0;
        currentTokenStack = emptyStack; //Empty the stack to fill it with another token
        
        currentChar = inFile.get(); //get the next character
        
        
        switch (currentChar/*any token*/) //you gotta create the full token in this switch statement
        {
            case ',': //if current character is one of the single character tokens, create the token object and move to the next token in file. Otherwise, keep scanning
                if (currentChar == ',')
                tokenType = COMMA;
                
            case '.':
                if (currentChar == '.')
                tokenType = PERIOD;
                
            case '?':
                if (currentChar == '?')
                tokenType = Q_MARK;
                
            case '(':
                if (currentChar == '(')
                tokenType = LEFT_PAREN;
                
            case ')':
                if (currentChar == ')')
                tokenType = RIGHT_PAREN;
                
            case ':':
                if (currentChar == ':')
                tokenType = COLON;
                
            case '*':
                if (currentChar == '*')
                tokenType = MULTIPLY;
                
            case '+':
                if (currentChar == '+')
                tokenType = ADD;
            {
                badCreateFlag = 1;
                currentTokenStack.push(currentChar);
            }
            break; 
            
            // case '\n':          //Whitespace cases
                // cout << "we did it";
            case '\t':
            case ' ':
                // tempTrackerDebug += 1;
                // cout << "-" << tempTrackerDebug;
                //in this case, somehow do not create a token at all
            break;
            // case isalpha(currentChar);
            // break; //Break for multiple character tokens
            default:
                tempTrackerDebug += 1;
                cout << "+" << tempTrackerDebug;
                    // cout << "newlineees";
                badCreateFlag = 1;
                tokenType = UNDEFINED;
                currentTokenStack.push(currentChar);
            break;
        }
        if (badCreateFlag == 1)
        {
            // cout << "should get here tbh, but only 1 times";
            Token currentToken = Token(tokenType, currentTokenStack, lineNum); //Create the token object from the data collected
            allTokensInFile.push(currentToken); //push that token to the stack
            // cout << allTokensInFile.size();
        }
        
    }
    
    inFile.close(); //Close the input file
    
    outFile.open("out_file_test.txt"); //Open the output file
    
    if (!outFile.is_open())
    {
        cout << "There was an issue trying to create the output text file :/\n";
        return;
    }
    
    while (!allTokensInFile.empty())
    {//this is currently backwards
        // cout << "write here, but 1";
        Token writeToken = allTokensInFile.top();
        outFile << writeToken.toString() << endl;
        allTokensInFile.pop();
    }
    outFile.close();
    
    // for (int x=1000; x > -5; x = x - 1)
    // {
    //     test = inFile.get();
        
    //     if (test == '\n')
    //     {
    //         lineNum += 1;
    //         cout << lineNum;
    //     }
        
    //     if (inFile.peek() == EOF)
    //     {
    //         return 0;
    //     }
    // }
    
}


