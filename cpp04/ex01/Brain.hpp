#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class   Brain
{
    public:
        Brain();
        Brain(Brain &b);
        ~Brain();
        Brain       &operator=(Brain &b);
        std::string getIdea(int id) const;
        int         getId(void) const;
        void        setIdea(const std::string &str);
    private:
        std::string _ideas[100];
        int         _id;
};

#endif
