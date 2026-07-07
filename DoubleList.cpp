#include <iostream>
#include "DoubleNode.h"
#include <cassert>

template <typename T>
class DList
{
public:
    DList():m_size(0){
        m_head = nullptr;
    }
    ~DList(){
        //clear();
    }
    void push(const T& value){
        Node<T>* tmp = new Node<T>(value);
        if(m_head != nullptr){
            m_head->prev = tmp;
            tmp->next = m_head;
        }
        m_head = tmp;
        ++m_size;
    }
    void pop(){
        assert(!isEmpty());
        Node<T>* tmp = m_head;
        if(tmp->next != nullptr){
            m_head = tmp->next;
            m_head->prev = nullptr;
        }
        else 
        {
            m_head = nullptr;
        }
        delete tmp;
        --m_size;
    }
    T top() const{
        assert(!isEmpty());

        return m_head->value;
    }
    bool isEmpty() const{
        return m_size == 0;
    }
    void clear(){
        while(!isEmpty()){
            pop();
        }
    }
    bool contains(const T& value) const{
        Node<T>* tmp = m_head;
        while(tmp != nullptr){
            if(tmp->value == value) return true;
            
            tmp = tmp->next;
        }
        return false;
    }
    int size() const{
        return m_size;
    }
    void print() const{
        Node<T>* tmp = m_head;
        while(tmp != nullptr){
            std::cout << tmp->value << " ";
            tmp = tmp->next;
        }
    }
private:
    Node<T>* m_head;
    int m_size;
};

int main(){

    DList<int> obj;

    obj.push(4);
    obj.push(8); 
    obj.push(6);
    obj.pop();
    obj.push(5);
    obj.push(8);
    obj.push(6);
    obj.pop();
    obj.push(5);
    obj.push(52);
    obj.print();
    obj.top();
    obj.contains(45);
    obj.clear();
    obj.print();
}
