#ifndef DATA_STRUCTURES_AND_ALGORITHMS_ARTHMETIC_H
#define DATA_STRUCTURES_AND_ALGORITHMS_ARTHMETIC_H

template<class T>
class Arthmetic {
    T a;
    T b;

public:
    Arthmetic(T a, T b);
    T add();
    T sub();
    ~Arthmetic();
};

#endif//DATA_STRUCTURES_AND_ALGORITHMS_ARTHMETIC_H
