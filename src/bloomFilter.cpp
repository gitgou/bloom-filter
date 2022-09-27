#include<bitset>
#include<iostream>
#include<functional>
#include<bitset>
using namespace std;
class BloomFilter{
    // @param1 hashFunc: 哈希函数对象
    // @param2 k: k 个哈希函数   
    // @param3 m: 数组大小
    BloomFilter(function<unsigned int(char*, unsigned int)> hashFunc, size_t k, size_t m)
    :_k(k)
    //,_m(m)
    {
    }
    //初始化哈希函数
    bool initialize(){

    }
    //添加元素
    bool add(){

    }
    //移除函数 
    bool remove(){

    }

    bool isExist(){

    }

private:
    function<unsigned int(char*, unsigned int)> _HashFunc;
    const size_t _k;
    //const size_t _m;
    bitset<1000> _bitArray;    
};

int main(){

}