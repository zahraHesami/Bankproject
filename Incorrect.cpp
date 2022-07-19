#include "Incorrect.h"
#include <string>
Incorrect::Incorrect(std::string temp)
{
    invalid= temp;
}
std::string Incorrect::show_invalid()
{
    return invalid;
}
