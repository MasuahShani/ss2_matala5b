#include "MagicalContainer.hpp"
using namespace ariel;

MagicalContainer:: MagicalContainer():real_arr(nullptr),  arr_p(nullptr),
p_size(0), real_size(0){}
MagicalContainer:: MagicalContainer(const MagicalContainer& mcl):real_arr(nullptr), arr_p(mcl.arr_p),
p_size(mcl.p_size),real_size(0){}
MagicalContainer:: ~MagicalContainer()
{
    delete[]arr_p;
    delete[]real_arr;
    
}
MagicalContainer& MagicalContainer:: operator=(const MagicalContainer& mcl)
{
    if(this==&mcl)
    {
        throw runtime_error("self assignment");
    }
    arr_p=mcl.arr_p;
    real_arr=mcl.real_arr;
    p_size=mcl.p_size;
    real_size=mcl.real_size;

    return *this;
}
MagicalContainer:: MagicalContainer(MagicalContainer&& mcl) noexcept:real_arr(mcl.real_arr), arr_p(mcl.arr_p),
p_size(mcl.p_size),real_size(mcl.real_size)
{
    mcl.arr_p=nullptr;
    mcl.real_arr=nullptr;
    mcl.p_size=0;
    mcl.real_size=0;
}
MagicalContainer& MagicalContainer:: operator=(MagicalContainer&& mcl) noexcept 
{

    if(this!=&mcl)
    {
        arr_p=mcl.arr_p;
        real_arr=mcl.real_arr;
        p_size=mcl.p_size;
        real_size=mcl.real_size;
    }
    return *this;
}

bool  isPrime(int num)
{
        if(num<=1)
    {
        return false;
    }

    if(num%2==0 && num!=2)
    {
        return false;
    }
    for (int i = 3; i <= sqrt(num); i+=2)
    {
        if(num%i==0 )
        {
            return false;
        }
    }
    return true;
}

void MagicalContainer:: addElement(const int& val)
{
    if(real_size==0)// we need to add the first one
    {
       real_arr = new int[1];
       real_arr[0]=val;
       real_size++;

        if(isPrime(val))// we need to add the first one
        {
            arr_p=new int [1];
            arr_p[0]=0;
            p_size++;
        }
    }
    
    else
    {
        if(isPrime(val))// we need to resize 
        {
            delete[] arr_p;
            arr_p=new int[static_cast<unsigned long>(p_size)+1];
            p_size++;
        }
        int* new_r=new int[static_cast<unsigned long>(real_size)+1];
    
        int i=0;
        int x=0;
        while (real_arr[i]<val && i<real_size)//copy until we find the place
        { 
            new_r[i]=real_arr[i];
            if(isPrime(new_r[i]))// put the index of the prime num in the arr
            {
                arr_p[x++]=i;
            }
            i++;

        }
        new_r[i]=val;// put the index of the item in the right place
        if(isPrime(new_r[i]))
        {
            arr_p[x++]=i;
        }
               
        while (i<real_size)
        {
            new_r[i+1]=real_arr[i];
            if(isPrime(new_r[i+1]))// put the index of the prime num in the arr
            {
                arr_p[x++]=i+1;
            }
            i++;
        }

        delete[]real_arr;
        real_arr=new_r;
        real_size++;
        
    

    }
    

          
    
    

}
void MagicalContainer:: removeElement(const int& val)
{
    if(real_size==0)
    {
        throw runtime_error("empty");
    }
    int i=0;
    while (i<real_size && real_arr[i]<val)
    {
        i++;
    }
    if(real_arr[i]==val)
    {
        int* new_r=new int[static_cast<unsigned long>(real_size)-1];
        for (int j = 0; j < i; j++)// copy until the item
        {
            new_r[j]=real_arr[j];
        }
        for (int j = i+1; j < real_size; j++)//copy the rest
        {
            new_r[j-1]=real_arr[j];
        }
        delete[]real_arr;
        real_arr=new_r;
        real_size--;

        if(isPrime(val))
        {
            int* new_p=new int[static_cast<unsigned long>(p_size)-1];
            int j = 0;
            while (arr_p[j]!=i)//until the index
            {
                new_p[j]=arr_p[j++]; 
            }
            j++;
            while (j<p_size)//the rest
            {
                new_p[j-1]=arr_p[j];
            }

            delete[]arr_p;
            arr_p=new_p;
            p_size--;
            
             
            
        }
            


    }
    else
    {
        throw runtime_error("there is no such val");

    }
    
    
        

}

int MagicalContainer:: size() const {return real_size;}






