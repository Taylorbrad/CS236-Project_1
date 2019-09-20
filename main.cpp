//main.cpp
#include <iostream> //cin/cout
#include <fstream> //read/write files
#include <cctype> //isspace, isalpha, isalnum
#include <stack>
#include "Scanner.h"
// #include "Scanner.cpp"
#include "Token.h"
// #include "Token.cpp"

using namespace std;

int main(int, char* argv[])
{
    Scanner myFunScanner = Scanner(argv[1]);
    myFunScanner.tokenize();
    // string fileText = "";
    // string inBetween = "";
    /*int lineNum = 0;
    string fileName = argv[1];
    ifstream inFile;
    inFile.open(fileName);
    stack <char> dummyScanner;*/
    
    /*if(!inFile)
    {
        cout << "Unable to read file";
        return 0;
    }
    char test;*/
    
    //count the first line if it is a newline character
    // test = ;
    /*if (inFile.peek() == '\n')
        {
            lineNum += 1;
            cout << lineNum;
        }*/
        
    // for (int x=1000; x > -5; x = x - 1)
    /*while (test != 's')
    {
        test = inFile.get();
        cout << test;
        
        if (test == '\n')
        {
            lineNum += 1;
            cout << lineNum;
        }
        else if (isalpha(test))
        {
            dummyScanner.push(test);
        }
        if (inFile.peek() == EOF)
        {
            cout << "--End of File--\n\n";
            return 0;
        }
    }
    Token testToken = Token(dummyScanner, 2);*/
    // cout << "debug main60";
    
    /*cout << "\nGood news! : ";
    cout << "\"" << testToken.tokenToString() << "\"" << endl;
    cout << testToken.tokenTypeToString(QUERIES) << endl;
    cout << testToken.toString();*/
    // while (inFile >> inBetween)
    // {
    // }
    // inFile.close();
    return 0;
}