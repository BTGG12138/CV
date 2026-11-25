#include<vector>
#include<iostream>
#include<algorithm>
using std::cout;
using std::endl;
namespace ipb
{
    template<typename T=int>
    class named_vector
    {
    private:
        std::string name_;
        std::vector<T> data_;
    public:
        named_vector()=default;
        named_vector(std::string name,std::vector<T> data):
        name_(std::move(name)),data_(std::move(data)){};
        named_vector operator=(const named_vector& give)
        {
            if(this==&give)
            {
                return *this;
            }
            name_=give.name_;
            data_=give.data_;
            return *this;
        }
        const std::string name()const
        {
            return name_;
        }
        std::string name()
        {
            return name_;
        }
        const std::vector<T> vector()const
        {
            return data_;
        }
        std::vector<T> vector()
        {
            return data_;
        }
        int size()
        {
            return name_.size()+data_.size();
        }
        bool empty()
        {
            if( name_.empty() and data_.empty())
            {
                return true;
            }
            return false;
        }
        const size_t capacity() const
        {
            return data_.capacity();
        }
        void resize(size_t size)
        {
            data_.resize(size);
        }
        void reserve(size_t size)
        {
            data_.reserve(size);
        }
    };

    template<typename T=int>
    T accumulate(const named_vector<int>& v)
    {
        T count=0;
        for(T num:v.vector())
        {
            count+=num;
        }
        return count;
    }

    template<typename T=int>
    int count(const named_vector<int>& v,const T& n)
    {
        int cnt=0;
        for(T num:v.vector())
        {
            if(num==n)
            {
                cnt+=1;
            }
        }
        return cnt;
    }

    template<typename T=int>
    bool all_even(const named_vector<int>& v)
    {
        bool even=true;
        for(T num:v.vector())
        {
            if(num%2==1)
            {
                even=false;
            }
        }
        return even;
    }

    template<typename T=int>
    void clamp(named_vector<int>& v,const T& l,const T& r)
    {
        for(T num:v.vector())
        {
            if(num<l)
            {
                num=l;
            }
            else if(num>r)
            {
                num=r;
            }
        }
    }

    template<typename T=int>
    void fill(named_vector<int>& v,const T& n)
    {
        for(T num:v.vector())
        {
            num=n;
        }
    }

    template<typename T=int>
    bool find(const named_vector<int>& v,const T& n)
    {
        bool find=false;
        for(T num:v.vector())
        {
            if(num==n)
            {
                find=true;
            }
        } 
        return find;
    }

    template<typename T=int>
    void print(const named_vector<int>& v)
    {
        for(T num:v.vector())
        {
            cout<<num<<" ";
        }
    }

    template<typename T=int>
    void toupper(named_vector<int>& v)
    {
        for(char& cha:v.name())
        {
            cha = static_cast<char>(std::toupper(static_cast<unsigned char>(cha)));
        }
    }

    template<typename T=int>
    void sort(named_vector<int>& v)
    {
        sort(v.vector().begin(),v.vector().end());
    }

    template<typename T=int>
    void rotate(named_vector<int>& v,const int& n)
    {
        
    }

    template<typename T=int>
    void reverse(named_vector<int>& v)
    {

    }
}