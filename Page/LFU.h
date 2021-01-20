#ifndef LFU_H
#define LFU_H
#include"Page.h"
class LFU:public Page
{
    public:
        LFU();
        virtual ~LFU();
        void carry_out();
    protected:

    private:
};

#endif // LFU_H
