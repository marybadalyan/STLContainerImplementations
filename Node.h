template <typename T>
struct Node
{
    Node(const T& v,Node<T>* n = nullptr)
    : value(v), next(n) {}
  
    T value;
    Node<T>* next;
};
