#include "iterator.h"
Iterator::Iterator(Base* ptr){
    this->self_ptr = ptr; current_ptr = NULL; 
}

OperatorIterator::OperatorIterator(Base* ptr): Iterator(ptr){ 
    self_ptr = ptr; current_ptr = NULL; 
    
}

NullIterator::NullIterator(Base* ptr): Iterator(ptr){ 
    self_ptr = ptr; current_ptr = NULL; 
    
}

UnaryIterator::UnaryIterator(Base* ptr): Iterator(ptr){ 
    self_ptr = ptr; current_ptr = NULL; 
    
}
PreorderIterator::PreorderIterator(Base* ptr): Iterator(ptr){ 
    self_ptr = ptr; current_ptr = NULL; 
    
}
void PreorderIterator::first() {
    // Empty the stack (just in case we had something leftover from another run)
    // Create an iterator for the Base* that we built the iterator for
    // Initialize that iterator and push it onto the stack
    while (!iterators.empty()){
        iterators.pop();
    }
    //make current ptr the ROOT. 
    iterators.push(self_ptr->get_left()->create_iterator());
    
    bases.push(iterators.top()->current());
    
}

void PreorderIterator::next() {
    // Create an iterator for the item on the top of the stack
    // Initialize the iterator and push it onto the stack
    // As long as the top iterator on the stack is_done(), pop 
    //it off the stack and then advance whatever iterator is now on top of the stack
    
    if(iterators.empty()){
        return;
    }
    
    Iterator* root = iterators.top();
    Iterator* root2;
    Base* selfCopy = iterators.top()->self();
    if(selfCopy->get_right()!=NULL)
        root2= new OperatorIterator(selfCopy);
    else if (selfCopy->get_left()!=NULL)
        root2= new UnaryIterator(selfCopy);
    else
        root2 = new NullIterator(selfCopy);
    
    
    //cout<<iterators.top()->self()->evaluate()<<endl;
    //cout<<"size: "<<iterators.size()<<endl;
    iterators.pop();
    bases.pop();
    //cout<<"size: "<<iterators.size()<<endl;
    root2->first();
    root2->next();
    root->first();
    
    if(!root2->is_done() &&!root->is_done()){
        //cout<<"two child "<<root2->current()->evaluate()<<endl;
        iterators.push(root2->current()->create_iterator());
        //iterators.top()->next();
        //bases.push(iterators.top()->current());
        //cout<<"here"<<iterators.top()->self()->evaluate()<<endl;
        iterators.push(root->current()->create_iterator());
        //iterators.top()->first();
        //bases.push(iterators.top()->current());
        //cout<<"here"<<iterators.top()->self()->evaluate()<<endl;
        return;
        
    }
    if(!root->is_done()){
        //cout<<"one child"<<endl;
        iterators.push(root->current()->create_iterator());
        //iterators.top()->first();
        //bases.push(iterators.top()->current());
    }
    //cout<<7<<endl;
    //cout<<"size: "<<iterators.size()<<endl;
}

bool PreorderIterator::is_done() {
    // Return true if there are no more elements on the stack to iterate
    if(iterators.size()==0)
        return true;
    return false;
}

Base* PreorderIterator::current() {
    // Return the current for the top iterator in the stack
    if(iterators.empty())
        return NULL;
        
    return iterators.top()->self();
    
}
