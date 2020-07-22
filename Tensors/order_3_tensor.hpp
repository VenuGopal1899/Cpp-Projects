#ifndef order3_tensor_hpp
#define order3_tensor_hpp

#include "tensor.hpp"

/* Implements an order-3 tensor. */
class MatrixTensor3 : public Tensor
{
    private:
        vector<size_t> m_size;
        vector<vector<vector<float>>> m_values;

     public:
     MatrixTensor3(const vector<size_t> &_size)
     {
        resize(_size);
     }

     const vector<size_t> &size() const override
     {
        return m_size;
     }

    void resize(const vector<size_t> &dims) override
    {
        assert(dims.size()==3);
        assert(dims[0]>0);
        assert(dims[1]>0);
        assert(dims[2]>0);
        int i,j;

        m_values.resize(dims[0], vector<vector<float>>());

        for(i=0; i<dims[0]; i++)
        {
            for(j=0;j<dims[1];j++)
            {
                m_values[i][j].resize(dims[2], 0.0f);
            }
            m_values[i][j].resize(dims[1], 0.0f);
        }
        m_size=dims;
    }

    virtual float read(const vector<size_t> &i) const override
    {
        int i0=0, i1=0, i2=0;
        if(m_size[0]>0 && m_size[0]!=1)
        {
            assert(i[0]<m_size[0]);
            i0=i[0];
        }
        if(m_size[1]>1 && m_size[1]!=1)
        {
            assert(i[1]<m_size[1]);
            i1=i[1];
        }
        if(m_size[2]>1 && m_size[2]!=1)
        {
            assert(i[2]<m_size[2]);
            i2=i[2];
        }
        assert(i0<m_size[0]);
        assert(i1<m_size[1]);
        assert(i2<m_size[2]);
        return m_values[i0][i1][i2];
    }

    virtual void write(const vector<size_t> &i, float value) override
    {
        size_t i0=0, i1=0, i2=0;
        if(i.size() > 0){
            i0=i[0];
        }
        if(i.size() > 1){
            i1=i[1];
        }
        if(i.size() > 2){
            i2=i[2];
        }
        assert(i0<m_size[0]);
        assert(i1<m_size[1]);
        assert(i2<m_size[2]);
        m_values[i0][i1][i2]=value;
    }
};

#endif
