#include"simple_hash_table.h"
using namespace std;
int main()
{
    sx::HashTable<int, int> h1;
    h1.insert(1, 1);
    cout << h1.find(1) << endl;
    cout << h1.erase(1);
    cout << endl;
    cout << h1.find(1) << endl;
    cout << h1.erase(1);
    //h1.insert(1, 1);
    //h1.insert(11, 11);
    //h1.insert(11, 11);
    //h1.insert(3, 3);
    //h1.insert(4, 4);
    //h1.insert(5, 5);
    //h1.insert(6, 6);
    //h1.insert(7, 7);
    //h1.insert(8, 8);
    //h1.insert(9, 9);
    //h1.insert(10, 10);
    //std::cout << h1.find(1) << endl;
    //std::cout << h1.find(3) << endl;
    //std::cout << h1.find(5) << endl;
    //std::cout << h1.find(7) << endl;
    //std::cout << h1.find(9) << endl;
    //std::cout << h1.find(11) << endl;
    //std::cout << h1.find(15) << endl;
    //cout << endl;
 /*   h1.erase(1);
    h1.erase(3);
    h1.erase(5);

    std::cout << h1.find(1) << endl;
    std::cout << h1.find(3) << endl;
    std::cout << h1.find(5) << endl;
    std::cout << h1.find(7) << endl;
    std::cout << h1.find(9) << endl;
    std::cout << h1.find(11) << endl;
    std::cout << h1.find(15) << endl;*/
    return 0;
}