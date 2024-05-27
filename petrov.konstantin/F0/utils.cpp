#include "utils.hpp"
#include <memory>
#include <algorithm>
#include <functional>
#include <set>
#include <vector>

petrov::Node::Node(char nSym, size_t nFreq, str nCode):
  symbol(nSym),
  freq(nFreq),
  code(nCode)
{}
std::ostream& petrov::operator<<(std::ostream& out, const Node& node)
{
  std::ostream::sentry sentry(out);
  if (!sentry)
  {
    return out;
  }
  out.flush();
  return out << node.symbol << " : " << node.freq << " : " << node.code;
}
std::istream& petrov::operator>>(std::istream& in, Node& node)
{
  std::istream::sentry sentry(out);
  if (!sentry)
  {
    return in;
  }
}

bool petrov::compareNodes(const Node& lhs, const Node& rhs)
{
  bool mainCondition = (lhs.freq <= rhs.freq && lhs.symbol != rhs.symbol);
  bool zeroCondition = (lhs.symbol == 0) && (rhs.symbol == 0);
  bool notSameZeros = zeroCondition && (lhs.left != rhs.left);
  bool zeroCondWithSort = (lhs.freq <= rhs.freq) && notSameZeros;
  return mainCondition || zeroCondWithSort;
}
bool petrov::doesNodeHaveKey(const Node& node, char key)
{
  return node.symbol == key;
}
bool petrov::doesNodeHaveCode(const Node& node, const std::string& code)
{
  return node.code == code;
}
bool petrov::isEqual(const Node& n1, const Node& n2)
{
  return n1.symbol == n2.symbol && n1.freq == n2.freq;
}
void petrov::addToSet(setType& alph, char symbol)
{
  auto dPHKey = std::bind(&doesNodeHaveKey, std::placeholders::_1, symbol);
  auto element = std::find_if(alph.begin(), alph.end(), dPHKey);
  if (element != alph.end())
  {
    Node tmp = (*element);
    alph.erase(element);
    tmp.freq += 1;
    alph.insert(tmp);
  }
  else
  {
    alph.insert(Node(symbol));
  }
}
