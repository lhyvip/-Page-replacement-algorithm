#ifndef CLOCK_H
#define CLOCK_H
#include"Page.h"

class Clock:public Page
{
    public:
        Clock();
        virtual ~Clock();
        void carry_out();
    protected:

    private:
};

#endif // CLOCK_H
