#include<vector>
#include<iostream>
using std::cout;
using std::endl;
using vector = ipb::named_vector<int>;
namespace ipb
{
    template<typename T=int>
    class named_vector
    {
    private:
        std::string name_;
        std::vector<T> data_;
    public:
        Vector(std::string name,std::vector<T> data):
        name_(name),data_(data){};
        std::string name()const
        {
            return name_;
        }
        std::vector<T> vector()const
        {
            return data_;
        }
    };

    template<typename T=int>
    T accumulate(const vector& v)
    {
        T count=0;
        for(T num:v.vector())
        {
            count+=num;
        }
        return count;
    }

    template<typename T=int>
    int count(const vector& v,const T& n)
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
    bool all_even(const vector& v)
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
    void clamp(vector& v,const T& l,const T& r)
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
    void fill(vector& v,const T& n)
    {
        for(T num:v.vector())
        {
            num=n;
        }
    }

    template<typename T=int>
    bool find(const vector& v,const T& n)
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
    void print(const vector& v)
    {
        for(T num:v.vector())
        {
            cout<<num<<" ";
        }
    }

    template<typename T=int>
    void toupper(vector& v)
    {
        for(char cha:v.name())
        {
            cha=std::toupper(cha);
        }
    }

    template<typename T=int>
    void sort(vector& v)
    {
        
    }

    template<typename T=int>
    void rotate(vector& v,const int& n)
    {
        
    }

    template<typename T=int>
    void reverse(vector& v)
    {
        
    }
}