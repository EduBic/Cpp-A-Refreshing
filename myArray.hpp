
template <typename T>
class MyArray {

public:

    // MyArray() {}

    MyArray(int length) {
        _length = length;

        _array = new T[length];
    }

    bool add(T elem, int index) {
        if (index > _length - 1) {
            return false;
        }

        _array[index] = elem;

        return true;
    }

    // Safe method
    T get(int index, T ifFailReturn) const {
        if (index > _length -1) {
            return ifFailReturn;
        }

        return _array[index];
    }

    // Unsafe method
    T get(int index) const {
        return _array[index];
    }

    int size() const {
        return _length;
    }

private:

    int _length;
    T* _array;

};