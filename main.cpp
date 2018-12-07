#include <iostream>
#include <vector>
#include "composite.h"
#include "iterator.h"
#include "visitor.h"
using namespace std;

int main() {

	Op* op3 = new Op(3);
	Op* op4 = new Op(4);
	Op* op2 = new Op(2);
	Add* add = new Add(op3, op4);
	Sqr* sqr = new Sqr(op2);
	Sub* sub = new Sub(add, sqr);
	Root* root = new Root(sub);

    PrintVisitor s;
	cout << "PreOrder Iteration:" << endl;
	PreorderIterator* pre_itr = new PreorderIterator(root);
	for(pre_itr->first(); !pre_itr->is_done(); pre_itr->next()) {
		pre_itr->current()->accept(&s);
	}
    
    s.execute();
    
};