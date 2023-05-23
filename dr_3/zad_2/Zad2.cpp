//
// Created by MILEN_PC on 23.5.2023 г..
//

#include "PriorityQueue.hpp"

int main(){
    PriorityQueue<char> queue(4);
    char a = 'A';
    char b = 'B';
    char c = 'C';
    char d = 'D';
    char e = 'E';
    queue.push('A', 0);
    queue.push(b, 3);
    queue.push(c, 2);
    queue.push(d, 2);
    queue.push(e, 1);
    //write a number variable


    std::cout << queue.peek() << std::endl; // B
    queue.pop();

    std::cout << queue.peek() << std::endl; // C
    queue.pop();

    std::cout << queue.peek() << std::endl; // D
    queue.pop();

    std::cout << queue.peek() << std::endl; // E
    queue.pop();

    std::cout << queue.peek() << std::endl; // A
    queue.pop();
    return 0;
}