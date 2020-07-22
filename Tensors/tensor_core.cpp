
#include "tensor.hpp"

#include "matrix_tensor.hpp"

#include "order_3_tensor.hpp"

 // #include "order_n_tensor.hpp"

bool is_scalar(const Tensor *x)
{
    const vector<size_t> &d=x->size();
    for(size_t i=0; i<d.size(); i++)
    {
        if(d[i]>1)
        {
            return false;
        }
    }
    return true;
}

bool is_vector(const Tensor *x)
{
    const vector<size_t> &d=x->size();
    for(size_t i=0; i<d.size(); i++)
    {
        if(d[i]==1)
        {
            return true;
        }
    }
    return false;
}

size_t order(const Tensor *x)
{
    const vector<size_t> &d=x->size();
    int len=0;
    for(size_t i=0; i<d.size(); i++)
    {
        if(d[i]>1 || d[i]==1)
        {
            len++;
        }
    }
    return len;
}

size_t volume(const vector<size_t> &dims)
{
    int total = 0;
    MatrixTensor obj1;
    MatrixTensor3 obj2;
    //MatrixTensorN obj3;
    vector<size_t> i;
    if(dims.size()==2)
    {
        for(size_t index=0; index<dims.size(); index++)
        {
            assert(dims[index]>0);
            i.push_back(index);
            int temp = obj1.read(i);
            if(temp>0)
            {
                total++;
            }
        }
    }
    else if(dims.size()==3)
    {
        for(size_t index=0; index<dims.size(); index++)
        {
            assert(dims[index]>0);
            i.push_back(index);
            int temp = obj2.read(i);
            if(temp>0)
            {
                total++;
            }
        }
    }
    /*
    else
    {
        for(size_t index=0; index<dims.size(); index++)
        {
            assert(dims[index]>0);
            i.push_back(index);
            int temp = obj3.read(i);
            if(temp>0)
            {
                total++;
            }
        }
    }
    */


    return total;
}

size_t index_to_offset(const vector<size_t> &size, const vector<size_t> &index, bool allow_broadcast)
{
    int offset=0;
    int prev_length=1;

    for(int i=0; i<size.size(); i++)
    {
        size_t dim_length=size[i];
        size_t dim_offset=0;

        // Handle the various kinds of implicit extension and broadcasting
        if(i < index.size())
        {
            dim_offset=index[i];
            if( dim_offset >= dim_length)
            {
                assert(allow_broadcast);
                dim_offset=0;
            }
        }

        offset = offset * prev_length + dim_offset;
        prev_length=dim_length;
    }
    for(int i=size.size(); i<index.size(); i++)
    {
        assert(index[i]==0 || allow_broadcast);
    }
    return offset;
}


vector<size_t> offset_to_index(const vector<size_t> &size, int offset)
{
    vector<size_t> res(size.size(), 0);

    for(int i=0;i<size.size();i++)
    {
        ;
    }
    return res;
}

void first_index(const vector<size_t> &size, vector<size_t> &index)
{
    index.resize(size.size(), 0);
}

bool next_index(const vector<size_t> &size, vector<size_t> &index)
{
    bool carry=true;
    for(int i=0; i<size.size(); i++)
    {
        if(carry)
        {
            if(index[i]+1 < size[i])
            {
                index[i] += 1;
                carry=false;
            }
            else
            {
                index[i] = 0;
            }
        }
    }
    return !carry;
}


Tensor *create_tensor(const std::vector<size_t> &size)
{
    // We do not support order-0 or order-1 for simplicity
    assert(size.size() >= 2);

    if(size.size() == 2)
    {
        return new MatrixTensor(size);
    }
    else
    {
        if(size.size()==3)
        {
          return new MatrixTensor3(size);
        }
        /*
        else if(size.size() > 3)
        {
          return new MatrixTensorN(size);
        }*/
        assert(false);
    }
}
