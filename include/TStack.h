#ifndef TSTACK_H
#define TSTACK_H

#include <iostream>

template<class T>
class TStack
{
private:
  struct Node
  {
    T data;
    Node* next;
  };
  Node* vertex;
public:
  TStack() : vertex (nullptr) {}
  ~TStack();
  bool Empty() const;
  void Push(const T& perm);
  const T& Top() const;
  void Pop();
};
template <class T>
TStack<T>::~TStack()
{
  while(!Empty())
  {
    this->Pop();
  }
}
template <class T>
bool TStack<T>::Empty() const
{
  return ( vertex == nullptr );
}
template <class T>
void TStack<T>::Push(const T& perm)
{
  Node* nnode = new Node;
  nnode->data = perm;
  nnode->next = vertex;
  vertex = nnode;
}
template <class T>
const T &TStack<T>::Top() const
{
  if (Empty()){
    throw std::range_error("stack empty");
  }
  return vertex->data;
}
template <class T>
void TStack<T>::Pop()
{
  if (Empty())
  {
    throw std::range_error("stack empty");
  }
  vertex = vertex->next;
}
#endif
