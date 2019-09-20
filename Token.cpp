#include "Token.h"

using namespace std;

Token::Token(TokenType inTokenType, stack <char> tokenFromScanner, int lineNum)
{
    this->token = tokenFromScanner;
    this->tokenType = inTokenType;
    this->lineNumOcurringOn = lineNum;
}
string Token::tokenToString()
{
    // cout << "debug tokenToString~13";
    string tempToken = "";
    string stringToken = "";
    char tempTop;
    
    stack <char> temp = this->token; //save the token array so that it isnt destroyed in the process
    
    while(!this->token.empty())
    {
        // cout << "debug TTSwhile22";
        tempTop = this->token.top();
        stringToken = tempTop + stringToken;
        token.pop();
    }
    
    this->token = temp; //reload the token array to what it was
    // cout << "debug TTSB4 return";
    return stringToken;
    
}
string Token::tokenTypeToString(/*TokenType tokenType, stack <char> token, int lineNum*/)
{
    switch(this->tokenType)
    {
        case COMMA:
        {
            // cout << "com-";
            return "COMMA"; 
            break;
        }
        case PERIOD:
        {
            // cout << "per-";
            return "PERIOD"; 
            break;
        }
        case Q_MARK:
        {
            return "Q_MARK"; 
            break;
        }
        case LEFT_PAREN:
        {
            return "LEFT_PAREN"; 
            break;
        }
        case RIGHT_PAREN:
        {
            return "RIGHT_PAREN"; 
            break;
        }
        case COLON:
        {
            return "COLON"; 
            break;
        }
        case COLON_DASH:
        {
            return "COLON_DASH"; 
            break;
        }
        case MULTIPLY:
        {
            return "MULTIPLY"; 
            break;
        }
        case ADD:
        {
            // cout << "add-";
            return "ADD"; 
            break;
        }
        case SCHEMES:
        {
            return "SCHEMES"; 
            break;
        }
        case FACTS:
        {
            return "FACTS"; 
            break;
        }case RULES:
        {
            return "RULES"; 
            break;
        }
        case QUERIES:
        {
            return "QUERIES"; 
            break;
        }
        case ID:
        {
            return "ID"; 
            break;
        }
        case STRING:
        {
            return "STRING"; 
            break;
        }
        case COMMENT:
        {
            return "COMMENT"; 
            break;
        }
        case UNDEFINED:
        {
            // cout << "und-";
            return "UNDEFINED"; 
            break;
        }
        case EndOf:
        {
            return "EOF"; 
            break;
        }
    }
    return "Error";
}
string Token::toString(/*TokenType tokenType, stack <char> token, int lineNum*/)
{
    string tokenLine = "(" + tokenTypeToString(/*tokenType*/) + ",\"" + tokenToString() + "\"," + to_string(this->lineNumOcurringOn) + ")";
    return tokenLine;
}