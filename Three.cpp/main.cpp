//
//  main.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 26/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include <iostream>
#include <chrono>
#include <glm/glm.hpp>
#include <gtest/gtest.h>

using namespace std;


void test2(glm::vec2& vec) {
    vec = glm::vec2(1.0, 1.0);
}

void test1(glm::vec2 vec) {
    vec = glm::vec2(1.0, 1.0);
}

int main(int argc, char **argv) {

    auto start = chrono::high_resolution_clock::now();
    
    for( int i = 0; i < 100000; i++ ) {
        glm::vec2 vector(0.0, 5.0);
        test1( vector );
    }
    
    auto end = chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count() << " ns" << std::endl;
    
    
    start = chrono::high_resolution_clock::now();
    
    for( int i = 0; i < 100000; i++ ) {
        test1( glm::vec2(0.0, 5.0) );
    }
    
    end = chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count() << " ns" << std::endl;
    

    
    
    start = chrono::high_resolution_clock::now();
    
    for( int i = 0; i < 100000; i++ ) {
        glm::vec2 vector(0.0, 5.0);
        test2( vector );
    }
    
    end = chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count() << " ns" << std::endl;
        return 0;
}
