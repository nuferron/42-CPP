template <typename T> Array<T>::Array(): _total(0)
{
    this->_array = NULL;
}

template <typename T> Array<T>::Array(unsigned int n): _total(n)
{
    this->_array = new T[n];
}

template <typename T> Array<T>::Array(const Array &a): _total(a._total)
{
    this->_array = new T[this->_total];
    for (int i = 0; i < this->_total; i++)
        this->_array[i] = a._array[i];
}

template <typename T> Array<T>::~Array()
{
    delete [] this->_array;
}

template <typename T> Array<T> &Array<T>::operator=(const Array &a)
{
    if (this->_array)
        delete [] this->array;
    this->_total = a._total;
    this->_array = new T[this->_total];
    for (int i = 0; i < this->_total; i++)
        this->_array[i] = a._array[i];
}

template <typename T> T &Array<T>::operator[](unsigned int id) const
{
    return (this->_array[id]);
}

template <typename T> unsigned int    Array<T>::size(void) const
{
    return (this->_total);
}