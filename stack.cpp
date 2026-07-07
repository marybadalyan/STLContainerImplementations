#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

template <typename T>
class Stack
{
public:
    void push(const T& n){
        container.push_back(n);
    }
    void pop(){
        assert(!isEmpty());
        container.pop_back();
    }
    T top() const{

        assert(!isEmpty());
        return container.back();
    }
    int size() const{

        return container.size();
    }
    bool isEmpty() const{
        return container.empty();
    }

    void clear(){
        assert(!isEmpty());
        container.clear();
    }

    bool contains(const T& n) const{
        return std::find(container.begin(), container.end(), n) != container.end();
    }

    void print() const{
        for (const auto& elem :container){
            std::cout << elem << " ";
        }    
    }

private:
    std::vector<T> container;
};

int main()
{
    Stack<int> st;

    st.push(4);
    st.push(5);
    st.pop();
    st.push(45);
    st.push(85);
    st.print();
    st.contains(45);
    st.clear();
    st.size();
    st.print();
}
