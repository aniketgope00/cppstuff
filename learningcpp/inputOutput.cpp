#include <iostream>
#include <string>

int main(){

    int number = 0;
    std::cin >> number;
    printf("Your id is %d\n", number + 3);

    std::string myColor = "";
    std::cin >> myColor;
    std::cout << "My color is " << myColor << std::endl;
    
    return 0;
}