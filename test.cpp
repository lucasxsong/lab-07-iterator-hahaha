#include "gtest/gtest.h"
#include "composite.h"
#include "iterator.h"

TEST(six, first){
	Base* one =  new Op(1);
	Base* two =  new Op(2);
	Base* three =  new Add(one,two);
	Base* six = new Mult(three,two);
	Base* root = new Root(six);
	Iterator* i = new PreorderIterator(root);
	i->first(); 
        EXPECT_EQ(6,i->current()->evaluate());
}
TEST(six, next){
	Base* one =  new Op(1);
	Base* two =  new Op(2);
	Base* three =  new Add(one,two);
	Base* six = new Mult(three,two);
	Base* root = new Root(six);
	Iterator* i = new PreorderIterator(root);
	i->first();
	i->next();
	EXPECT_EQ(3,i->current()->evaluate());
	i->next();
	EXPECT_EQ(1,i->current()->evaluate());
	i->next();
	EXPECT_EQ(2,i->current()->evaluate());
	i->next();
	EXPECT_EQ(2,i->current()->evaluate());
}
TEST(sqrFour, firstAndNext){
    Base* two =  new Op(2);
    Base* four = new Sqr(two);
    Base* root3 = new Root(four);
    Iterator* i = new PreorderIterator(root3);
	
	i->first();
	EXPECT_EQ(4,i->current()->evaluate());
	i->next();
	EXPECT_EQ(2,i->current()->evaluate());
}
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}



