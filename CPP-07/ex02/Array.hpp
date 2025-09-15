#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array {
    private:

    public:
        Array(void);
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array(void);
};

#endif