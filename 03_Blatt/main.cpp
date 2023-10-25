#include "utils.hpp"

#include <iostream>
#include <string>
#include <limits>

constexpr auto max_size = std::numeric_limits<std::streamsize>::max();

// probably should go into utils.hpp
template <typename T>
class ArrayList {
private:
    T* array;
    int size{};
    int capacity{};

    // increase capacity of underlying array to new size
    void reserve(int newSize) {
        if (newSize > this->capacity) {
            T* newArray = new T[newSize];
            // copy content to new array
            for (int i = 0; i < this->size; i++) {
                newArray[i] = this->array[i];
            }
            // delete memory at our pointer,
            // because after the next line it becomes unreachable
            delete[] this->array;
            this->array = newArray;
            this->capacity = newSize;
        }
    }

        
    public:
        ArrayList(){
            constexpr int initialSize = 8;
            this->array = new T[initialSize];
            for (int i = 0; i < initialSize; i++)
            {
                this->array[i] = 0;
            }
            this->capacity = initialSize;
            this->size = 0;
        }
        T* getArray() {
            return this->array;
        }
        void pushBack(T element) {
            if (this->size >= this->capacity) {
                this->reserve((this->capacity*3) / 2 + 1);
            }
            this->array[this->size] = element;
            this->size++;
        }
        void popBack() {
            if (this->size > 0) {
                this->size--;
            }
        }
        T getAt(int index){
            if (index < 0 || index >= this->size) {
                // IDK
                return 0;
            }
            return this->array[index];
        }
        void setAt(int index, T element) {
            if (index < 0 || index >= this->size) {
                return;
            }
            this->array[index] = element;
        }
        void insert(int index, T element){
            if (index < 0 || index > size) {
                // IDK
                return;
            }
            if (this->size >= this->capacity) {
                this->reserve((this->capacity * 3) / 2 + 1);
            }
            // shift elements from back 1 by 1
            for (int i = this->size; i > index; i--) {
                this->array[i] = this->array[i - 1];
            }
            this->array[index] = element;
            this->size++;
        }
        // display info of ArrayList
        void print(){
            std::cout << "Array at " << this->array << "\n";
            std::cout << "Capacity " << this->capacity << "\n";
            std::cout << "Size " << this->size << "\n";
            std::cout << "[";
            if (this->size > 0) {
                for (int i = 0; i < this->size - 1; i++)
                {
                    std::cout << this->array[i] << ", ";
                }
                std::cout << this->array[(this->size)-1];
            }
            std::cout << "]\n";
            
        }
        bool isPerm() {
            return isPermutation(this->array, this->size);
        }
        bool isSortedWith(int* perm) {
            return isSorted(this->array, this->size, perm);
        }
        ~ArrayList(){
            delete[] this->array;
        }
};


/* done:
 *      * read doubles from cin and put them into an array until something that
 *        is not a number is entered. (std::cin.fail() is true)
 *      * increase the array's size if necessary
 *      * reset cin (see clear() and ignore())
 *      * read in the same amount of integers
 *      * implement functions in utils.cpp
 *      * test given input with isPermutation() and isSorted()
 *      * clean up all dynamically allocated memory
 */
int main(int, char**) 
{
    auto* list = new ArrayList<double>(); // muss wahrscheinlich nicht auf den heap
    auto* permutation = new ArrayList<int>(); // muss wahrscheinlich nicht auf den heap
    int count = 0;
    std::cout << "Gib deine Zahlen ein: \n";
    while(true) {
        double inputNumber = 0.0;

        std::cin >> inputNumber;
        if (std::cin.fail()) {
            std::cin.clear(); // unset fail-bit
            // std::cin.ignore(max_size, '\n'); // skip bad input for manual input
            std::cin.ignore(max_size, ' '); // skip bad input for testing input
            break;
        }
        count++;
        list->pushBack(inputNumber);
    }
    std::cout << "Gib deine Permutation ein: \n";
    while(count > 0)
    {
        std::cout << count << ": ";
        int inputNumber = 0;
        std::cin >> inputNumber;
        if (std::cin.fail()) {
            std::cin.clear(); // unset fail-bit
            //std::cin.ignore(max_size, '\n'); // skip bad input for manual input
            std::cin.ignore(max_size, ' '); // skip bad input for testing input
            break;
        }
        permutation->pushBack(inputNumber);
        count--;
    }
    list->print();
    permutation->print();
    std::cout << "Permutation? " << permutation->isPerm() << "\n";
    std::cout << "Sorted? " << list->isSortedWith(permutation->getArray()) << "\n";
    delete list;
    delete permutation;
}
