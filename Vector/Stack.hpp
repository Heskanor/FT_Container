//Stack implementation
using namespace std;
template <typename T>
class stackClass
{
    private:
        T *arr;
        int size;
        int capacity;
        void resize(int newCapacity);
    public:
        stackClass();
        stackClass(int capacity);
        stackClass(const stackClass<T> &s);
        ~stackClass();
        int getSize();
        int getCapacity();
        void push(T element);
        void pop();
        T& top();
        stackClass<T>& operator=(const stackClass<T> &s);
        void print();
};
template <typename T>
stackClass<T>::stackClass()
{
    arr = NULL;
    size = 0;
    capacity = 0;
}
template <typename T>
stackClass<T>::stackClass(int capacity)
{
    arr = new T[capacity];
    size = 0;
    this->capacity = capacity;
}
template <typename T>
stackClass<T>::stackClass(const stackClass<T> &s)
{
    arr = new T[s.capacity];
    size = s.size;
    capacity = s.capacity;
    for(int i = 0; i < size; i++)
        arr[i] = s.arr[i];
}
template <typename T>
stackClass<T>::~stackClass()
{
    delete[] arr;
}
template <typename T>
int stackClass<T>::getSize()
{
    return size;
}
template <typename T>
int stackClass<T>::getCapacity()
{
    return capacity;
}
template <typename T>
void stackClass<T>::push(T element)
{
    if(size == capacity)
        resize(capacity * 2);
    arr[size++] = element;
}
template <typename T>
void stackClass<T>::pop()
{
    if(size == 0)
        return;
    size--;
}
template <typename T>
T& stackClass<T>::top()
{
    return arr[size - 1];
}
template <typename T>
stackClass<T>& stackClass<T>::operator=(const stackClass<T> &s)
{
    if(this == &s)
        return *this;
    delete[] arr;
    arr = new T[s.capacity];
    size = s.size;
    capacity = s.capacity;
    for(int i = 0; i < size; i++)
        arr[i] = s.arr[i];
    return *this;
}
template <typename T>
void stackClass<T>::resize(int newCapacity)
{
    T *newArr = new T[newCapacity];
    for(int i = 0; i < size; i++)
        newArr[i] = arr[i];
    delete[] arr;
    arr = newArr;
    capacity = newCapacity;
}
template <typename T>
void stackClass<T>::print()
{
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
//Queue implementation
template <typename T>
class queueClass
{
    private:
        T *arr;
        int size;
        int capacity;
        void resize(int newCapacity);
    public:
        queueClass();
        queueClass(int capacity);
        queueClass(const queueClass<T> &q);
        ~queueClass();
        int getSize();
        int getCapacity();
        void enqueue(T element);
        void dequeue();
        T& front();
        queueClass<T>& operator=(const queueClass<T> &q);
        void print();
};
template <typename T>
queueClass<T>::queueClass()
{
    arr = NULL;
    size = 0;
    capacity = 0;
}
template <typename T>
queueClass<T>::queueClass(int capacity)
{
    arr = new T[capacity];
    size = 0;
    this->capacity = capacity;
}
template <typename T>
queueClass<T>::queueClass(const queueClass<T> &q)
{
    arr = new T[q.capacity];
    size = q.size;
    capacity = q.capacity;
    for(int i = 0; i < size; i++)
        arr[i] = q.arr[i];
}
template <typename T>
queueClass<T>::~queueClass()
{
    delete[] arr;
}
template <typename T>
int queueClass<T>::getSize()
{
    return size;
}
template <typename T>
int queueClass<T>::getCapacity()
{
    return capacity;
}
template <typename T>
void queueClass<T>::enqueue(T element)
{
    if(size == capacity)
        resize(capacity * 2);
    arr[size++] = element;
}
template <typename T>
void queueClass<T>::dequeue()
{
    if(size == 0)
        return;
    size--;
}
template <typename T>
T& queueClass<T>::front()
{
    return arr[0];
}
template <typename T>
queueClass<T>& queueClass<T>::operator=(const queueClass<T> &q)
{
    if(this == &q)
        return *this;
    delete[] arr;
    arr = new T[q.capacity];
    size = q.size;
    capacity = q.capacity;
    for(int i = 0; i < size; i++)
        arr[i] = q.arr[i];
    return *this;
}
template <typename T>
void queueClass<T>::resize(int newCapacity)
{
    T *newArr = new T[newCapacity];
    for(int i = 0; i < size; i++)
        newArr[i] = arr[i];
    delete[] arr;
    arr = newArr;
    capacity = newCapacity;
}
template <typename T>
void queueClass<T>::print()
{
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}