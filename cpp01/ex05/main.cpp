#include "Harl.hpp"

int main(void)
{
    Harl    msg;

    msg.complain("ERROR");
    msg.complain("");
    msg.complain((void *)0);
    msg.complain(NULL);
    msg.complain("WARNING");
    msg.complain("INFO");
}
