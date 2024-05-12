#include "arthmetic.h"
#include <iostream>

using namespace std;

template<class T>
Arthmetic<T>::Arthmetic(T a, T b) {
    this->a = a;
    this->b = b;
}

template<class T>
T Arthmetic<T>::add() {
    return a + b;
}

template<class T>
T Arthmetic<T>::sub() {
    return a - b;
}

template<class T>
Arthmetic<T>::~Arthmetic() {
    cout << "Object is destroyed" << endl;
}
