#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class   Brain
{
    public:
        Brain();
        Brain(const Brain &b);
        ~Brain();
        Brain &operator=(const Brain &b);
        std::string getIdeas(void);
    private:
        std::string _ideas[100];
};

#endif