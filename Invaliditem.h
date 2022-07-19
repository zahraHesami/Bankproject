#ifndef INVALIDITEM_H
#define INVALIDITEM_H


#include <string>
class Invaliditem
{
public:
    Invaliditem(std::string temp);
    std::  string get_error();
private:
    std:: string error;
};

#endif // INVALIDITEM_H
