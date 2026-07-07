template <typename T>
struct Node
{

    Node(const T& v,Node<T>* p = nullptr,Node<T>* n = nullptr)
    :  value(v),prev(p),next(n)
    {}

    T value;
    Node<T>* prev;
    Node<T>* next;
};
