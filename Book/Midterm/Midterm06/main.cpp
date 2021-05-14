
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on April 26, 2021, 3:46 PM
 * Purpose: Print Problem 6 solutions
 */

#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    cout<<"See attached image for work:\n"
        <<"  2.875(base10) = 10.111(base2), 2.7(base8), 2.E(base16)\n"
        <<"  2.875(base10) to NASA format: 5C000002 \n\n"
        <<"  .1796875(base10) = .0010111(base2), .134(base8), .2E(base16)\n"
        <<"  .1796875(base10) to NASA format: 5C0000FE \n\n"
        <<"  -2.875(base10) = -10.111(base2), -2.7(base8), -2.E(base16)\n"
        <<"  -2.875(base10) to NASA format: A4000002 \n\n"
        <<"  -.1796875(base10) = -.0010111(base2), -.134(base8), -.2E(base16)\n"
        <<"  -.1796875(base10) to NASA format: A40000FE \n\n"
        <<"  59999901(NASA) = 1.4(base10)\n"
        <<"  59999902(NASA) = 2.8(base10)\n"
        <<"  A66667FE(NASA) = -.175(base10)\n";
    
    return 0;
}