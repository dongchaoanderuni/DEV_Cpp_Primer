#ifndef __TOKEN_H__
#define __TOKEN_H__

#include <string>

using std::string;

class Token
{
public:
    Token():tok(INT), varInt(0) {}
    Token(const Token& t):tok(t.tok) {copyUnion(t);} 
    ~Token() {if(STR == tok)  varString.~string();}

    Token& operator=(const Token&);
    Token& operator=(const std::string&);
    Token& operator=(char);
    Token& operator=(int);
    Token& operator=(double);

    Token(Token&& other);
    Token& operator=(Token &&);

private:
    enum {INT, CHAR, DBL, STR} tok;
    union 
    {
        char        varChar;
        int         varInt;
        double      varDouble;
        std::string varString;
    };

    void copyUnion(const Token&);

};

Token::Token(Token &&other)
{
    switch(other.tok)
    {
        case Token::INT:
        {
            varInt = other.varInt;
            break;
        }
        case Token::CHAR:
        {
            varChar = other.varChar;
            break;
        }
        case Token::DBL:
        {
            varDouble = other.varDouble;
            break;
        }
        case Token::STR:
        {
            new(&varString) string(other.varString);
            other.varString.~string();
            break;
        }
        default:
        {
            std::cout << "Error.\n" << std::endl;
        }
    }
    
    other.tok = INT;
    other.varInt = 0;
}

Token& Token::operator=(Token&& other)
{
    if(this != &other)
    {
        tok = other.tok;
        switch(other.tok)
        {
            case Token::INT:
            {
                varInt = other.varInt;
                break;
            }
            case Token::CHAR:
            {
                varChar = other.varChar;
                break;
            }
            case Token::DBL:
            {
                varDouble = other.varDouble;
                break;
            }
            case Token::STR:
            {
                new(&varString) string(other.varString);
                other.varString.~string();
                break;
            }
            default:
            {
                std::cout << "Error.\n" << std::endl;
            }
        }
        other.tok = INT;
        other.varInt = 0;
    }

    return *this;
}

Token& Token::operator=(int i)
{
    if(STR == tok)
    {
        varString.~string();
    }

    varInt = i;
    tok = INT;

    return *this;
}

Token& Token::operator=(char c)
{
    if(STR == tok)
    {
        varString.~string();
    }

    varChar = c;
    tok = CHAR;

    return *this;
}

Token& Token::operator=(double d)
{
    if(STR == tok)
    {
        varString.~string();
    }

    varDouble = d;
    tok = DBL;

    return *this;
}

Token& Token::operator=(const std::string &s)
{
    if(STR == tok)
    {
        varString = s;
    }
    else
    {
        new(&varString) string(s);
    }
    tok = STR;

    return *this;
}

Token& Token::operator=(const Token& t)
{
    if((STR == tok)&&(STR != t.tok))
    {
        varString.~string();
    }

    if((STR == tok)&&(STR == t.tok))
    {
        varString = t.varString;
    }
    else
    {
        copyUnion(t);
    }

    tok = t.tok;
    
    return *this;
}

inline void Token::copyUnion(const Token& t)
{
    switch(t.tok)
    {
        case Token::INT:
        {
            varInt = t.varInt;
            break;
        }
        case Token::CHAR:
        {
            varChar = t.varChar;
            break;
        }
        case Token::DBL:
        {
            varDouble = t.varDouble;
            break;
        }
        case Token::STR:
        {
            new(&varString) string(t.varString);
            break;
        }
        default:
        {
            std::cout << "Error.\n" << std::endl;
        }
    }
}

#endif