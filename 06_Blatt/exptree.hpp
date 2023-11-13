#include <string>

/* An expression is a sequence of operators and operands that specifies a computation.
 * It can be organised in form of a tree, where nodes are operators and leaves
 * are values or variables.
*/
namespace ExpTree {

// Stores the value of a named variable. 
// This class is used to subtitute values for the variables represented by the VarNodes
// in the expression tree.
class Variable
{
    public:
        // Constructs a variable with the given name.
        Variable(const char* _name) : name{_name} {}

        // Store the name as a std::string for easy comparison
        const std::string name;

        /// Assignment operator to set the value of the variable.
        Variable& operator=(double val) {
            value = val;
            return *this;
        }

        // Conversion operator to double to get the value.
        operator double() const {
            return value;
        }
    private:
        double value;
};


// The (abstract) base class of nodes the expression tree is built of.
class Node
{
    public:
        /**
         * This function calculates the value of the term the (sub)tree represents
         * with the current variable values. Something is missing though ...
         *
         * @param vars An array of Variables
         * @param numVars The length of vars.
         */
        virtual double evaluate(const Variable* vars, int numVars) const = 0;

        // Virtual destructor to allow proper destruction of derived classes.
        virtual ~Node() {}
};

// A base class for binary operators.
// TODO: Use this class to correctly delete subnodes on destruction.
class BinOpNode : public Node
{
    public:
        BinOpNode(Node* _left, Node* _right) : left{_left}, right{_right} {}
        // Destructor to delete the left and right subnodes.
        virtual ~BinOpNode() {
            delete left;
            delete right;
        }
    protected:
        Node* left = nullptr;
        Node* right = nullptr;
};

// Calculates the sum of the two operands.
class SumNode : public BinOpNode
{
    public:
        SumNode(Node* _left, Node* _right) : BinOpNode{_left, _right} {}

        double evaluate(const Variable* vars, int numVars) const override {
            return left->evaluate(vars, numVars) + right->evaluate(vars, numVars);
        }
};

// Calculates the product of the two operands.
class MulNode : public BinOpNode
{
    public:
        MulNode(Node* _left, Node* _right) : BinOpNode{_left, _right} {}

        double evaluate(const Variable* vars, int numVars) const override {
            return left->evaluate(vars, numVars) * right->evaluate(vars, numVars);
        }
};

// Represents a variable in the tree.
class VarNode : public Node
{
    public:
        VarNode(Variable* _variable) : variable{_variable} {}
        VarNode(const char* _variable) : variable{new Variable{_variable}} {}

        double evaluate(const Variable* vars, int numVars) const override;

        ~VarNode() {
            delete variable;
        }

    private:
        Variable* variable;
};

}; // namespace ExpTree
