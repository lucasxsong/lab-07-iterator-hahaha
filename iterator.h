#ifndef __ITERATOR_H__
#define __ITERATOR_H__
#include <stack>
using namespace std;
#include "composite.h"
class Iterator {
    protected:
        Base* self_ptr;
        Base* current_ptr;
        Visitor* v;
    public:
        Iterator(Base* ptr);
        Iterator(const Iterator & obj){
            
        }
        /* Sets up the iterator to start at the beginning of traversal */
        virtual void first() = 0;
        
        /* Move onto the next element */
        virtual void next() = 0;

        /* Returns if you have finished iterating through all elements */
        virtual bool is_done() = 0;
        Base* self(){
            return self_ptr;
        }
        /* Return the element the iterator is currently at */
        virtual Base* current() = 0;
        Visitor* returnVisitor() {
            return v;
        }
};
/**
 * The OperatorIterator will be used to iterate over 
 * composite nodes with two children. This means it's
 * first will initialize to the left child, and its next
 * will cycle from left child (which is where it is set 
 * to start), to right child, then to NULL.**/
class OperatorIterator : public Iterator {
    public:
        OperatorIterator(Base* ptr);//{ self_ptr = ptr; current_ptr = NULL; }

        void first(){
            current_ptr=self_ptr->get_left();
        }
        void next(){
            if(current_ptr==self_ptr->get_left())
                current_ptr=self_ptr->get_right();
            else if (current_ptr==self_ptr->get_right())
                current_ptr= NULL;
        }
        bool is_done(){
            if(current_ptr==NULL)
                return true;
            return false;
        }
        Base* current(){
            return  current_ptr;
        }
        
};
/**The UnaryIterator will be used to iterate 
 * over composite nodes with one child (only
 * Sqr in our case). This means it's first will
 * initialize to the only child (which has been 
 * redeclared in the composite class as the left child, 
 * with Unary having no right child to make for an 
 * easier interface, and next will cycle from child
 * (which is where it is set to start) to NULL.**/
class UnaryIterator : public Iterator {
    public:
        UnaryIterator(Base* ptr);
        void first(){
            current_ptr=self_ptr->get_left();
        }
        void next(){
            if(current_ptr==self_ptr->get_left())
                current_ptr=NULL;
        }
        bool is_done(){
            if(current_ptr==NULL)
                return true;
            return false;
        }
        Base* current(){
            return current_ptr;
        }
};
/**The NullIterator is used to iterate
 * over leaf nodes. Since leaf nodes 
 * have no children, the NullIterators is_done()
 * will always return true and its current will 
 * always return NULL. The first() and next() 
 * functions don't need to do anything.**/
class NullIterator : public Iterator {
    public:
        NullIterator(Base* ptr);
        void first(){};
        void next(){};
        bool is_done(){
            //cout<<8<<endl;
            return true;
        }
        Base* current(){
            return NULL;
        }
};

class PreorderIterator : public Iterator {
    private:
        stack<Base*> bases;
    protected:
        stack<Iterator*> iterators;
    public:
        PreorderIterator(Base* ptr);

        void first();
        void next();
        bool is_done();
        Base* current();
};

#endif //__ITERATOR_H__
