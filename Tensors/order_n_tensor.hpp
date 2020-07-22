#ifndef ordern_tensor_hpp
#define ordern_tensor_hpp

#include "tensor.hpp"

/* Implements an order-3 tensor. */

class MatrixTensorN : public Tensor
{
    private:
        vector<size_t> m_size;
        vector<vector<float>> m_values;

     public:
     MatrixTensorN(const vector<size_t> &_size)
     {
        resize(_size);
     }

     const vector<size_t> &size() const override
     {
        return m_size;
     }

    void resize(const vector<size_t> &dims) override
    {

    }

    virtual float read(const vector<size_t> &i) const override
    {

    }

    virtual void write(const vector<size_t> &i, float value) override
    {

    }
};

#endif
