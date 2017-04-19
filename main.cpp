/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2017 Conrad Hübler
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 * Simple test case for the finv functions
 */

#include "src/fisher_dist.h"

#include <iostream>

int main(int argc, char **argv) {
    double p = 0;
    double m = 0;
    double n = 0;
    std::cout << "p: "; 
    std::cin >> p;
    std::cout << std::endl <<  "enter df1: "; std::cin >> m;
    std::cout << std::endl <<  "enter df1: "; std::cin >> n;
    try{
    std::cout << "f value is " << finv(p,m,n) << std::endl;
    }
    catch (int result)
    {
        if(result == -1)
            std::cout << "x must lie between 0 and 1, sorry" << std::endl;
    }
    return 0;
}
