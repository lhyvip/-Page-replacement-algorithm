#ifndef LRU_H
#define LRU_H
#include"Page.h"

class LRU:public Page
{
    public:
        LRU();
        virtual ~LRU();
        void carry_out();
    protected:

    private:
};

#endif // LRU_H
