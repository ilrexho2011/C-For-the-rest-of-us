//
//  Homework Assignment #7: Binary and Bits
//
#include <iostream>
#include <string>

using namespace std;

int rotateLeft(int value, int amount) {
    // suggested four bit rotate left function
    const int OVERFLOW = 0b10000;
    while(amount > 0) {
        value = value << 1;
        if((value & OVERFLOW) == OVERFLOW) {
            value = value & 0b1111; // remove the overflow bit
            value = value | 0b0001; // set the rightmost bit
        }
        amount--;
    }
    return value;
}

int main()
{
    int inValvesOpen, outValvesOpen, pistonUp, cylinderFire;
    inValvesOpen = 0b0010;
    outValvesOpen = 0b0100;
    pistonUp = 0b1010;
    cylinderFire = 0b1000;
    for(int i = 0; i < 5; i++) {
        string d1 = "    1        2        3        4    ";
        string d2 = "   ___      ___      ___      ___   ";
        string d3 = " x|   |x  x|   |x  x|   |x  x|   |x ";
        string d4 = "  |   |    |   |    |   |    |   |  ";
        string d5 = "   ---      ---      ---      ---   ";
        string d6 = "    ?        ?        ?        ?    ";

        // Determining the current state of the cylinders
        for(int c = 0; c < 4; c++) {
            int offset = 9 * c;        // Shifting the string position
            char stateLabel = 'C';
            char inValve = 'x';
            char outValve = 'x';
            char upPiston = ' ';
            char downPiston = 'T';
            char chamber = ' ';

            // Setting the position mask
            int positionMask = 0b1000 >> c;

            // Updating the state of the cylinder
            if((inValvesOpen & positionMask) == positionMask) {
                inValve = 'o';
                stateLabel = 'I';
            }
            if((pistonUp & positionMask) == positionMask) {
                upPiston = 'T';
                downPiston = ' ';
                if((cylinderFire & positionMask) == positionMask) {
                    chamber = '*';
                    stateLabel = 'P';
                }
            }
            if((outValvesOpen & positionMask) == positionMask) {
                outValve = 'o';
                stateLabel = 'E';
            }

            // Updating the strings according to the cylinder state
            d3.at(1  + offset) = inValve;
            d3.at(3  + offset) = chamber;
            d3.at(4  + offset) = upPiston;
            d3.at(5  + offset) = chamber;
            d3.at(7  + offset) = outValve;
            d4.at(4  + offset) = downPiston;
            d6.at(4  + offset) = stateLabel;
        }

        // Displaying the updated strings
        cout << d1 << endl;
        cout << d2 << endl;
        cout << d3 << endl;
        cout << d4 << endl;
        cout << d5 << endl;
        cout << d6 << endl;
        cout << endl;
        cout << endl;

        // Calculating the number of bits required to shift left for the next state according to the cylinderFire variable
        int bitsToRotate = 0;
        if((cylinderFire & 0b0010) ==  cylinderFire) {
            bitsToRotate = 1;
        } else if((cylinderFire & 0b0001) ==  cylinderFire) {
            bitsToRotate = 3;
        } else {
            bitsToRotate = 2;
        }

        // Shifting the status variables for the next cylinders state
        inValvesOpen = rotateLeft(inValvesOpen, bitsToRotate);
        outValvesOpen = rotateLeft(outValvesOpen, bitsToRotate);
        pistonUp = rotateLeft(pistonUp, bitsToRotate);
        cylinderFire = rotateLeft(cylinderFire, bitsToRotate);
    }
    return 0;
}
