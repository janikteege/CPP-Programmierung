#include <iostream>

struct node{
public:
    int value;
    node* _left;
    node* _right;
    node (int);
    node (const node& other);
    ~node () ;
};

class binarytree {
public:
    // CTor & DTor
    binarytree (int treeSize);
    ~binarytree();
    // extend tree
    binarytree operator+=(const node* rhs);
    void insert(int value);
    // tree operations
    int find(int index) const;
    // getter
    int size() const;
    void print() const;

private:
    void print(const node* current) const;
    node* root;
    int size;
};

int main() {
    binarytree t{35};
    std::cout << t.size() << std::endl;
    for(int i = 0; 1 < 10; i++) {
        int x = rand () % 100;
        t.insert(x);
        std::cout << x << " ";
        for(int i = 0; i < 6; i++) {
            t += new node{i};
        }
    }
    std:: cout << std::endl;
    t.print();
    for(int i = 0; i < 20; i++) {
        std::cout << t.find(i) << " ";
    }
}