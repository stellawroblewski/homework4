// this function takes the number of grid point per dimension and return an estimate of Pi using the dart board method

#include <iostream>
#include <math.h> 
using namespace std;



double gridpi(unsigned npoints)
{
    float divide = npoints;
    float iteration = (1/divide); //creates value for the difference in each grid point 
    double insideCount = 0; //initialize both counts to 0
    double outsideCount = 0;
    double yCoord = 0; //initialize both coords to 0
    double xCoord = 0;
    while (yCoord <= 1) { //go through all possible coordinate conbonations 
        while (xCoord <= 1) {
            double squares = hypot (xCoord, yCoord);
            if (squares < 1) { //if the addition of the squares are less than or equal to 1, the point is inside/on the circle
                insideCount += 1;
            }
            else {
                outsideCount += 1;
            }
            xCoord += iteration;
        }
        yCoord += iteration;
        xCoord = 0;
    }

    double piEstimate = ((insideCount / (outsideCount + insideCount)) * 4);
    return piEstimate;
}


int main()
{
    unsigned value;
    cin >> value;  //read in value for gridpi
    double estimate = gridpi(value); //call gridpi
    cout << estimate << endl; //return value

    return 0;   
}



