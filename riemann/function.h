template<typename T> inline T func(T x) {
    return x*x*x + x*x;
}

template<typename T> inline T antiderivative(T x) {
    return x*x*x*x / 4 + x*x*x / 3;
}

template<typename T> inline T integral(T xmin, T xmax) {
    return antiderivative<T>(xmax) - antiderivative<T>(xmin);
}

const float xmin = -5;
const float xmax = +5;

const float ymin = func(xmin);  // for Monte-Carlo
const float ymax = func(xmax); 