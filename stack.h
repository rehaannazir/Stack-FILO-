#ifndef REHAN_NAZIR_BSDSF24A042_PUCIT_EDU_PK
#define REHAN_NAZIR_BSDSF24A042_PUCIT_EDU_PK

template <typename T>

class Stack
{
    T *data;
    int capacity;
    int top;

public:
    Stack(int);
    Stack(const Stack &);
    void push(int);
    T pop();
    bool is_empty();
    bool is_full();
    int get_top();
    T stack_top();
    Stack &operator=(const Stack &);
    ~Stack();
};

#endif