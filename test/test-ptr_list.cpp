#include <stdio.h>
#include <boost/shared_ptr.hpp>

class A {
public:
    void print() {
        printf("class A print!\n");
    }
};

int main(int argc, char **argv) {
    boost::shared_ptr<A> a1(new A());
    a1->print();
}
