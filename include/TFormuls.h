#ifndef TFORMULS_H
#define TFORMULS_H

#include <iostream>
#include "cmath"
#include "TStack.h"


int priority(char a) {
  int tmp = 0;
  if (a == '^')
    tmp = 3;
  else if (a == '*' || a == '/')
    tmp = 2;
  else  if (a == '+' || a == '-')
    tmp = 1;
  return tmp;
}
class TFormuls
{
private:
  std::string infix;
  std::string postfix;
  TStack<char> operand;
  TStack<int> tmp;
public:
  TFormuls(const std::string& infixforms);
  void Process();
  bool CheckFormuls();
  double Calculate();

  std::string GetPostfix();
};

TFormuls::TFormuls(const std::string &infixforms)
{
  infix = infixforms;
}

void TFormuls::Process()
{

  for (int i = 0; i < infix.length(); i++) {
    char c = infix[i];

    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
      postfix += c;

    else if (c == '(')
      operand.Push('(');

    else if (c == ')') {
      while (operand.Top() != '(') {
        postfix += operand.Top();
        operand.Pop();
      }
      operand.Pop();
    }

    else {
      while (!operand.Empty()
             && priority(infix[i]) <= priority(operand.Top())) {
        postfix += operand.Top();
        operand.Pop();
      }
      operand.Push(c);
    }
  }
  while (!operand.Empty()) {
    postfix += operand.Top();
    operand.Pop();
  }
}
bool TFormuls::CheckFormuls()
{
  TStack<bool> stack;
  for (const char& elem : infix)
  {
    if (elem == '(')
    {
      stack.Push(true);
      continue;
    }
    if (elem == ')')
    {
      if (stack.Empty())
        return false;
      stack.Pop();
      continue;
    }
  }
  if (!stack.Empty())
    return false;
  return true;
}
double TFormuls::Calculate()
{
  for (char element : postfix)
  {
    if(element >= '0' && element <= '9')
    {
      tmp.Push(element- '0');
    }
    else
    {
      int x = tmp.Top();
      tmp.Pop();
      int y = tmp.Top();
      tmp.Pop();
      if(element == '+')
      {
        tmp.Push(y+x);
      }
      if(element == '-')
      {
        tmp.Push(y-x);
      }
      if(element == '*')
      {
        tmp.Push(y*x);
      }
      if(element == '/')
      {
        tmp.Push(y/x);
      }
      if(element == '^')
      {
        tmp.Push(pow(y,x));
      }
    }
  }
  return tmp.Top();
}

std::string TFormuls::GetPostfix()
{
  return (postfix);
}
#endif
