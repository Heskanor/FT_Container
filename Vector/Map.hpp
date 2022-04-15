
//Map implementation
using namespace std;
template <typename K, typename V>
class mapClass
{
    private:
        pair<K, V> *arr;
        int size;
        int capacity;
        void resize(int newCapacity);
    public:
        mapClass();
        mapClass(int capacity);
        mapClass(const mapClass<K, V> &m);
        ~mapClass();
        int getSize();
        int getCapacity();
        void insert(K key, V value);
        void remove(K key);
        V& find(K key);
        mapClass<K, V>& operator=(const mapClass<K, V> &m);
        void print();
};
template <typename K, typename V>
mapClass<K, V>::mapClass()
{
    arr = NULL;
    size = 0;
    capacity = 0;
}
template <typename K, typename V>
mapClass<K, V>::mapClass(int capacity)
{
    arr = new pair<K, V>[capacity];
    size = 0;
    this->capacity = capacity;
}
template <typename K, typename V>
mapClass<K, V>::mapClass(const mapClass<K, V> &m)
{
    arr = new pair<K, V>[m.capacity];
    size = m.size;
    capacity = m.capacity;
    for(int i = 0; i < size; i++)
        arr[i] = m.arr[i];
}
template <typename K, typename V>
mapClass<K, V>::~mapClass()
{
    delete[] arr;
}
template <typename K, typename V>
int mapClass<K, V>::getSize()
{
    return size;
}
template <typename K, typename V>
int mapClass<K, V>::getCapacity()
{
    return capacity;
}
template <typename K, typename V>
void mapClass<K, V>::insert(K key, V value)
{
    if(size == capacity)
        resize(capacity * 2);
    arr[size++] = pair<K, V>(key, value);
}
template <typename K, typename V>
void mapClass<K, V>::remove(K key)
{
    if(size == 0)
        return;
    for(int i = 0; i < size; i++)
    {
        if(arr[i].first == key)
        {
            for(int j = i; j < size - 1; j++)
                arr[j] = arr[j + 1];
            size--;
            break;
        }
    }
}
template <typename K, typename V>
V& mapClass<K, V>::find(K key)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i].first == key)
            return arr[i].second;
    }
    return arr[0].second;
}
template <typename K, typename V>
mapClass<K, V>& mapClass<K, V>::operator=(const mapClass<K, V> &m)
{
    if(this == &m)
        return *this;
    delete[] arr;
    arr = new pair<K, V>[m.capacity];
    size = m.size;
    capacity = m.capacity;
    for(int i = 0; i < size; i++)
        arr[i] = m.arr[i];
    return *this;
}
template <typename K, typename V>
void mapClass<K, V>::resize(int newCapacity)
{
    pair<K, V> *newArr = new pair<K, V>[newCapacity];
    for(int i = 0; i < size; i++)
        newArr[i] = arr[i];
    delete[] arr;
    arr = newArr;
    capacity = newCapacity;
}
template <typename K, typename V>
void mapClass<K, V>::print()
{
    for(int i = 0; i < size; i++)
        cout << arr[i].first << " " << arr[i].second << endl;
}

