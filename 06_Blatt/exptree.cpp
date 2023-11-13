#include "exptree.hpp"

namespace ExpTree {

double VarNode::evaluate(const Variable* vars, int numVars) const {
    for (int i = 0; i < numVars; ++i) {
        if (vars[i].name == variable->name) {
            return vars[i];
        }
    }
    // If the variable is not found, return 0.0 as a default value.
    return 0.0;
}

}
