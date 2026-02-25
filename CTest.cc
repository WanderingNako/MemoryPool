#include <cstdio>
#include "MemoryPool.hh"
 
class CTest
{
public:
                CTest() {
                    data1 = 3;
                    data2 = 4;
                }
                ~CTest() {}
    void*       operator new (size_t size);
    void        operator delete(void* pTest);
public:
 
    static      MemoryPool Pool;
    int         data1;
    int         data2;
};
 
void CTest::operator delete(void* pTest)
{  
    Pool.Free(pTest);  
}
 
 
void* CTest::operator new(size_t size)
{
    return (CTest*)Pool.Alloc();
}
 
MemoryPool CTest::Pool(sizeof(CTest));
 
int main()
{
    CTest* pTest = new CTest;
    printf("data1: %d\n", pTest->data1);
    printf("data2: %d\n", pTest->data2);
}