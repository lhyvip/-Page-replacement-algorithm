#ifndef FIFO_H
#define FIFO_H
#include"Page.h"

class FIFO:public Page
{
    public:
        FIFO();
        virtual ~FIFO();
        void carry_out();
    protected:

    private:
};

#endif // FIFO_H
