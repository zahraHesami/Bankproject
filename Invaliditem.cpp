#include "Invaliditem.h"
#include <iostream>

Invaliditem::Invaliditem(std::string temp)
{
  error=temp;
}
std::string Invaliditem::get_error()
{
    return error;
}
