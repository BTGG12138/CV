#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<cctype>
#include"homework_4.hpp"
using std::cout;
using std::endl;
namespace ipb
{
    template<typename T=int>
    class named_vector
    {
    private:
        std::string name_;
        std::vector<T> vec_;
    public:
        named_vector()=default;
        named_vector(std::string name,std::vector<T> vec):
        name_(std::move(name)),vec_(std::move(vec)){}
        named_vector operator=(const named_vector& give)
        {
            if(this==&give)
            {
                return *this;
            }
            name_=give.name_;
            vec_=give.vec_;
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
            return vec_;
        }
        std::vector<T> vector()
        {
            return vec_;
        }
        int size()
        {
            return name_.size()+vec_.size();
        }
        bool empty()
        {
            if( name_.empty() and vec_.empty())
            {
                return true;
            }
            return false;
        }
        const size_t capacity() const
        {
            return vec_.capacity();
        }
        void resize(const size_t size)
        {
            vec_.resize(size);
        }
        void reserve(const size_t size)
        {
            vec_.reserve(size);
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
        for(size_t i=0;i<v.vector().size();i++)
        {
            v.vector()[i]=n;
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
            cout<<num<<" "<<endl;
        }
    }

    template<typename T=int>
    void toupper(named_vector<int>& v)
    {
        for(char& c:v.name())
        {
            c= static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
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
       std::rotate(v.vector().begin(),v.vector().begin()+n,v.vector().end());
    }

    template<typename T=int>
    void reverse(named_vector<int>& v)
    {
        std::reverse(v.vector().begin(),v.vector().end());
    }
}