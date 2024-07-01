#include <cstdio>
#include <iostream>

void printWithPuts(){
    puts("printing with puts");
}

void printwithCout(){
    std::cout << "printing with cout" << std::endl;
}

int main(){
    printWithPuts();
    printwithCout();
    return 0;
}