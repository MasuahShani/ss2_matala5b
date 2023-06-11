#pragma once
#include <math.h>
#include <stdexcept>
#include <iostream>
using namespace std;

namespace ariel{
  

    
	

	class MagicalContainer
	{
	private:
        int* real_arr; 
        int* arr_p;//for index of prime numbers
        int real_size;
        int p_size;
	public:
		MagicalContainer();
		MagicalContainer(const MagicalContainer& mcl);
		~MagicalContainer();
		MagicalContainer& operator=(const MagicalContainer& mcl);
		MagicalContainer(MagicalContainer&& mcl) noexcept;
		MagicalContainer & operator=(MagicalContainer&& mcl) noexcept ;

		void addElement(const int& val);
		void removeElement(const int& val);

		int size() const;
       



		class AscendingIterator {

		private:
            int* p_arr;
            int* real_arr;
            int* r_size;
            int pointer;

		public:

			AscendingIterator(MagicalContainer &mcl)
				:p_arr(mcl.arr_p),real_arr(mcl.real_arr),r_size(&mcl.real_size),pointer(0) {}

            ~AscendingIterator(){}
            AscendingIterator(const AscendingIterator& itr):p_arr(itr.p_arr),real_arr(itr.real_arr),r_size(itr.r_size),pointer(itr.pointer){}
            AscendingIterator& operator=(const AscendingIterator& mcl)
            {
                 if(this==&mcl)
                {
                    return *this;
                }
                if(real_arr!=mcl.real_arr)
                {
                    throw runtime_error("not the same container");
                }
                pointer=mcl.pointer;
                return *this;
            }
            AscendingIterator(AscendingIterator&& itr) noexcept:p_arr(itr.p_arr),real_arr(itr.real_arr),r_size(itr.r_size),pointer(itr.pointer){}
            AscendingIterator & operator=(AscendingIterator&& mcl) noexcept
            {
                if(this==&mcl)
                {
                    return *this;
                }
                if(real_arr!=mcl.real_arr)
                {
                    return *this;
                }
                pointer=mcl.pointer;
                return *this;
            }			
            int& operator*() const {
				if (pointer == *r_size) {
					throw runtime_error("Dereferencing iterator pointing to an empty container");
				}
				return real_arr[pointer];
			}

			// ++i;
			AscendingIterator& operator++() 
			{
                if(pointer==(*r_size))
                {
                    throw runtime_error("done");

                }
                pointer++;
				return *this;
			}

			bool operator==(const AscendingIterator& rhs) const {
                if(real_arr !=rhs.real_arr)
                {
                    throw runtime_error("not the same container");
                }
               
				return pointer == rhs.pointer;
			}

			bool operator!=(const AscendingIterator& rhs) const {
                if(real_arr !=rhs.real_arr)
                {
                    throw runtime_error("not the same container");
                }
				return pointer != rhs.pointer;
			}

			bool operator>(const AscendingIterator& rhs) const {
                if(real_arr !=rhs.real_arr)
                {
                    throw runtime_error("not the same container");
                }

               return pointer>rhs.pointer;
			}

			bool operator<(const AscendingIterator& rhs) const {
                if(real_arr !=rhs.real_arr)
                {
                    throw runtime_error("not the same container");
                }

				return pointer<rhs.pointer;
			}

			AscendingIterator begin() const
            {
                AscendingIterator itr(*this);
                itr.pointer=0;
                return itr;
            }
			AscendingIterator end() const
            {
                AscendingIterator itr(*this);
                itr.pointer=*r_size;
                return itr;
            }
			
		};

        
        
        
        
		
		class SideCrossIterator {

		private:
            int* p_arr;
            int* real_arr;
            int* r_size;
            int pointer;
            int wich_side;
           

		public:

			SideCrossIterator(MagicalContainer &mcl):p_arr(mcl.arr_p),real_arr(mcl.real_arr),r_size(&mcl.real_size),pointer(0),wich_side(1) 
            {
                if(*r_size==0)
                {
                    pointer=-1;
                }
            }
            ~SideCrossIterator(){}
            SideCrossIterator(const SideCrossIterator& itr):p_arr(itr.p_arr),real_arr(itr.real_arr),r_size(itr.r_size),pointer(itr.pointer),wich_side(itr.wich_side){}
            SideCrossIterator& operator=(const SideCrossIterator& mcl)
            {
                 if(this==&mcl)
                {
                    return *this;
                }
                if(real_arr!=mcl.real_arr)
                {
                    throw runtime_error("not the same container");
                }
                pointer=mcl.pointer;
                wich_side=mcl.wich_side;

                return *this;
            }
            SideCrossIterator(SideCrossIterator&& itr) noexcept:p_arr(itr.p_arr),real_arr(itr.real_arr),r_size(itr.r_size),pointer(itr.pointer),wich_side(itr.wich_side){}
            SideCrossIterator & operator=(SideCrossIterator&& mcl) noexcept
            {
                if(this==&mcl)
                {
                    return *this;
                }
                if(real_arr!=mcl.real_arr)
                {
                    return *this;
                }
                pointer=mcl.pointer;
                wich_side=mcl.wich_side;
                return *this;
            }			
            int& operator*() const {
				if (pointer == -1) {
					throw runtime_error("the itr point on nuthing");
				}
				return real_arr[pointer];
			}
			// ++i;
			SideCrossIterator& operator++()
			{
                
                if(pointer==-1)
                {
                    throw runtime_error("done");

                }
                if(pointer==(*r_size)/2)//the end
                {
                    pointer=-1;

                }
                else if(wich_side==1)
                {
                    pointer=*r_size-pointer-1;
                    wich_side=2;

                }
                else if (wich_side==2)
                {
                    pointer=*r_size -pointer;
                    wich_side=1;
                }
              

                return *this;
               
			}
            bool operator==(const SideCrossIterator& rhs) const {
                if(real_arr !=rhs.real_arr)
                {
                    throw runtime_error("not the same container");
                }

				return pointer == rhs.pointer;
			}
            bool operator!=(const SideCrossIterator& rhs) const {
                if(real_arr !=rhs.real_arr)
                {
                    throw runtime_error("not the same container");
                }

				return pointer != rhs.pointer;
			}

			bool operator>(const SideCrossIterator& rhs) const {
                if(real_arr !=rhs.real_arr)
                {
                    throw runtime_error("not the same container");
                }
                int num1=abs((*r_size)/2 - pointer);
                int num2=abs((*r_size)/2 - rhs.pointer);

                if(num1==num2)
                {                
                    if((*r_size)%2==0)
                    {
                        return pointer<rhs.pointer;
                    }
                    
                    return pointer>rhs.pointer;
                    
                }
				return num1<num2;
			}

			bool operator<(const SideCrossIterator& rhs) const {
				return !(*this>rhs)&&(*this!=rhs);
			}

			SideCrossIterator begin()  
            {
                SideCrossIterator itr(*this);
                itr.pointer=0;
                return itr;
            }
			SideCrossIterator end()  
            {
                SideCrossIterator itr(*this);
                itr.pointer=-1;
                return itr;
            }
			
		};
		class PrimeIterator {

		private:
            int* p_arr;
            int* real_arr;
            int* r_size;
            int pointer;
			int* p_size;

		public:

			PrimeIterator(MagicalContainer &mcl):p_arr(mcl.arr_p),real_arr(mcl.real_arr),r_size(&mcl.real_size),pointer(0),p_size(&mcl.p_size) {}
            ~PrimeIterator(){}
            PrimeIterator(const PrimeIterator& itr):p_arr(itr.p_arr),real_arr(itr.real_arr),r_size(itr.r_size),pointer(itr.pointer),p_size(itr.p_size){}
            PrimeIterator& operator=(const PrimeIterator& mcl)
            {
                 if(this==&mcl)
                {
                    return *this;
                }
                if(real_arr!=mcl.real_arr)
                {
                    throw runtime_error("not the same container");
                }
                pointer=mcl.pointer;
                return *this;
            }
            PrimeIterator(PrimeIterator&& itr) noexcept:p_arr(itr.p_arr),real_arr(itr.real_arr),r_size(itr.r_size),pointer(itr.pointer),p_size(itr.p_size){}
            PrimeIterator & operator=(PrimeIterator&& mcl) noexcept
            {
                if(this==&mcl)
                {
                    return *this;
                }
                if(real_arr!=mcl.real_arr)
                {
                    return *this;
                }
                pointer=mcl.pointer;
                return *this;
            }			


			// ++i;
			PrimeIterator& operator++() 
			{
                if(pointer==(*p_size))
                {
                    throw runtime_error("done");

                }
                pointer++;
				return *this;
			}
			int& operator*() const  
            {
                if (pointer == *p_size) {
					throw runtime_error("Dereferencing iterator pointing to an empty container");
				}
				return real_arr[p_arr[pointer]];//the item in the index that we have in the arr of the primes indexs
				
			}

			

			PrimeIterator begin() 
            {
                PrimeIterator itr(*this);
                itr.pointer=0;
                return itr;
            }
			PrimeIterator end() 
            {
                PrimeIterator itr(*this);
                itr.pointer=*p_size;
                return itr;
            }
            bool operator==(const PrimeIterator& rhs) const {
                if(real_arr !=rhs.real_arr)
                {
                    throw runtime_error("not the same container");
                }
               
				return pointer == rhs.pointer;
			}
            bool operator!=(const PrimeIterator& rhs) const {
                if(real_arr !=rhs.real_arr)
                {
                    throw runtime_error("not the same container");
                }

				return pointer != rhs.pointer;
			}
            bool operator<(const PrimeIterator& rhs) const {
                if(real_arr !=rhs.real_arr)
                {
                    throw runtime_error("not the same container");
                }

				return pointer<rhs.pointer;
			}
            bool operator>(const PrimeIterator& rhs) const {
                if(real_arr !=rhs.real_arr)
                {
                    throw runtime_error("not the same container");
                }

				return pointer>rhs.pointer;
			}
			
		};
	};
}



