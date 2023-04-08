#include <algorithm>
#include <chrono>
#include <random>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//20x20 grid, 5 dooglebugs, 100 ants

const char DOODLEBUG = 'X';
const char ANT = 'o';
const char SPACE = '-';
const int GRID_SIZE = 400;


void startSim() {
    vector<int> random_nums;
    vector<char> grid;
    for (int i = 0; i < GRID_SIZE; i++) {
        grid.push_back('-');
        random_nums.push_back(i);
    }
    
    srand(time(0));
    random_shuffle(random_nums.begin(), random_nums.end());
    for (int i = 0; i < 5; i++) {
        grid[random_nums[i]] = 'X';
    }

    for (int i = 4; i < 105; i++) {
        grid[random_nums[i]] = 'o';
    }
    int counter = 0;
    for (int i = 0; i < GRID_SIZE; i++) {
        if (counter == 20) {
            cout<<endl;
            counter = 0;
        }
        cout<<grid[i]<<' ';
        counter++;
    }
}

//intialize grid
    //20x20 2-dimensional array
    //choose random spaces for 5 dbs
    //choose random spaces for 100 ants
    //intialize grid based on spaces for ants and dbs

    //5 doodlebugs
        //Organism class
            //doodlebug class
    //100 ants
        //Organism class
            //ant class

//Organism class
    //movement
    //

//time step
    //increment step #
    //move ants & dbs
    //check for eating
    //check for breeding
    //check for starvation
/*int doodleBug() {

    //initialize grid
        //
}*/


int main() {
    startSim();
    return 0;
}