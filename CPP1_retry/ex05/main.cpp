#include "Karen.hpp"

int main(void)
{
    Karen karen;
    karen.complain("DEBUG");
    karen.complain("ERROR");
    karen.complain("INFO");
    karen.complain("WARNING");
    karen.complain("not_a_complaint_level");
}