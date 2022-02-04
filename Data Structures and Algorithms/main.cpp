//
//  main.cpp
//  Data Structures and Algorithms
//
//  Created by Dario Mazhara on 2/4/22.
//

#include <iostream>
#include "StackUsingVectors.cpp"


class Object {
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    //Probably the easiest implementation of a stack
    Stack<int> stack;
    
    cout << stack.empty() << endl;
    stack.push(4);
    stack.push(34);
    stack.push(76);
    stack.push(44);
    stack.push(0);
    cout << stack.empty() << endl;
    
    cout << stack.top() << endl;
    
    stack.pop();
    
    cout << stack.top() << endl;
    
    
    
    Stack<Object*> stack2;
    
    stack2.push(new Object());
    
    cout << stack2.top() << endl; //lol well it works
    
    cout << stack.size() << endl;
    
    cout << stack2.size() << endl;
    return 0;
}
