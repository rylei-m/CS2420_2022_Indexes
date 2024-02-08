#include <iostream>
#include <string>
//using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::string;
template <typename T>
class SafeArray{
public:
  SafeArray(const unsigned int capacity);
  ~SafeArray();
  void insert(const unsigned int index, const T& item);
  T get(const unsigned int index) const;
private:
  unsigned int capacity{ 0 };
  T* arr{nullptr};
};
template <typename T>
SafeArray<T>::SafeArray(const unsigned int capacity){
  this->capacity = capacity;
  this->arr = new T[capacity];
}
template <typename T>
SafeArray<T>::~SafeArray() {
  delete[] this->arr;
}
template <typename T>
void SafeArray<T>::insert(const unsigned int index, const T& item){
  if (index >= capacity)
  {
    cout << "The index was out of bounds" << endl;
    return;
  }
  arr[index] = item;
}
template <typename T>
T SafeArray<T>::get(const unsigned int index) const{
  if (index >= capacity)
  {
    cout << "The index was out of bounds" << endl;
    throw 1;
  }
  return arr[index];
}
int main() {
 SafeArray<int> mySafeArray(10);
 mySafeArray.insert(0, 13);
 mySafeArray.insert(1, 50);
 mySafeArray.insert(2, 77);
 
cout << "The data at index 1 is " << mySafeArray.get(0) << endl;
 cout << "The data at index 2 is " << mySafeArray.get(1) << endl;
 cout << "The data at index 3 is " << mySafeArray.get(2) << endl;
  
  SafeArray<string> myStringArray(5);
 myStringArray.insert(0, "Hello") ;
 myStringArray.insert(1,"there");
 myStringArray.insert(2, "x");
  
 cout << "The data at index 1 is " << myStringArray.get(0) << endl;
 cout << "The data at index 2 is " << myStringArray.get(1) << endl;
 cout << "The data at index 3 is " << myStringArray.get(2) << endl;
}