#include <iostream>
#include <string>
#include <vector>
#include <random>
 
using namespace std;
int NUM_SAMPLES = 1000;
 
 
int main()
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::normal_distribution<double> distr(50, 26); // define the range

    // TODO: Initialize empty vector here 
    vector <double> vec;

    // TODO: Print size of vector below
    cout << "size of vector before loop: " << vec.size() << endl;
 
    // Sample from the distribution and fill the vector with numbers
    for(int i = 0; i< NUM_SAMPLES; i++)
    {     
        // TODO: FILL IN HERE
        // Sample a value from the distribution and add the value to the vector
        // hint: use distr(gen) to sample from the distribution.
        vec.push_back(distr(gen));
    }

    // TODO: PRINT SIZE OF VECTOR BELOW
    cout << "size of vector after loop: " << vec.size() << endl;
  
    // To store mean and variance as running average
    double avg = 0;
    double var = 0;
 
    // To store mean and variance values of the previous iteration
    double oldAvg, oldVar;
 
    for(int j=0;j<NUM_SAMPLES;j++)
    {
        // For the first number, mean = number and variance
        if((j+1)==1)
        {
            // TODO: Initialize avg value
            avg = **FILL IN HERE**; 
            oldAvg = avg;
            oldVar = 0;
        } else { 
            // TODO: Compute the new average and variance using the recurrence relations provided
            //avg = oldAvg+ (**FILL IN HERE** - oldAvg)/(j+1);
            //var = oldVar + (**FILL IN HERE** - oldAvg)*( **FILL IN HERE** - avg);
 
            // Assign mean and variance values to be used in the next iteration
            oldAvg=avg;
            oldVar=var;
          
            // Print sampled number, running mean and running variance values
            // for every 2 iterations upto 30 iterations, and for every 50 iterations afterwards
            if(j%50==0 ||(j<30 && j%2==0))
            {
                cout <<"Sampled number: " <<j << endl;
                cout <<"Mean: " << avg << endl;
                cout <<"Variance: " << var/j << endl;
                cout << endl;
            }
        }
    }
 
    return 0;
}
