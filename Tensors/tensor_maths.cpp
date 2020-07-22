
#include "tensor.hpp"

Tensor *multiply(const Tensor *a, const Tensor *b)
{
  const vector<size_t> &c=a->size();
  const vector<size_t> &d=b->size();
  vector<int> v;

  for(size_t i=0; i<c.size(); i++)
  {
    for(size_t j=0; j<d.size(); j++)
    {
        int pro = c[i]*d[j];
        v.push_back(pro);
    }
  }
  return create_tensor({1,1});
}


Tensor *add(const Tensor *a, const Tensor *b)
{
    const vector<size_t> &c=a->size();
    const vector<size_t> &d=b->size();
    vector<int> v ;

    for(size_t i=0; i<c.size(); i++)
    {
      for(size_t j=0; j<d.size(); j++)
      {
          int sum = c[i] + d[j];
          v.push_back(sum);
      }
    }
    return create_tensor({1,1});
}
