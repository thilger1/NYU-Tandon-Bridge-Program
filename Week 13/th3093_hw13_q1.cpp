#include <algorithm>
#include <random>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//20x20 grid, 5 dooglebugs, 100 ants
//all doodlebugs move before ants do
//after 3 moves, ants reproduce to available space
//after 8 moves, doodlebugs reproduce to available space

const char DOODLEBUG = 'X';
const char ANT = 'o';
const char SPACE = '-';
const int GRID_SIZE = 400;
vector<char> grid;

class Organism {
protected:
    //1 - north, 2 - south, 3 - east, 4 - west
    int possible_moves[4] = {1, 2, 3, 4};
    int Space;
    int Life;
public:
    //pass optional parameter to move it in direction of ant to eat?
    void move() {
        vector <int> possible_moves;
        for (int i = 0; i < 4; i++)
            possible_moves.push_back(i);
        random_shuffle(possible_moves.begin(), possible_moves.end());
        int move = possible_moves[0];
        //north (1)

        checkGrid(move, this.Space)
        if (move == 1 && Space > 19) {
            if (checkGrid(Space - 20))
                Space -= 20;
        }
        //east (2)
        if (move == 2 && Space % 10 != 0) {
            if (checkGrid(Space + 1))
                Space += 1;
        }
        //south (3)
        if (move == 3 && Space < 379) {
            if (checkGrid(Space + 20))
                Space += 20;
        }
        //west (4)
        if (move == 4 && Space % 10 != 1) {
            if (checkGrid(Space - 1))
                Space -= 1;
        }
    }

    int getLife() const {
        return Life;
    }
    void setLife(int life) {
        Life = life;
    }

    //breed();
    //need to modify breed for bugs
    //constructor
    Organism(int space) {
        Space = space;
        Life = 0;
    };
    //

};

class Doodlebug: public Organism {
private:
    char Shape = 'X';
public:
    friend Doodlebug operator ++(Doodlebug& bug) {
        int life = bug.getLife();
        life += 1;
        if (life == 8) {
            //breed();
            life = 0;
        }
        bug.setLife(life);
        return bug;
    }

    void breed() {
        if(checkGrid) {
            //random space
            //duplicate, call constructor
        }
    }
};

class Ant: public Organism {
private:
    char Shape = 'o';
    //increment life every round, 
    int Life = 0;
public:
    Ant breed() {

    }
    friend Ant operator ++(Ant& bug) {
        int life = bug.getLife();
        life += 1;
        if (life == 3) {
            //breed();
            life = 0;
        }
        bug.setLife(life);
        return bug;
    }
};

bool checkGrid(int index) {
    if (grid[index] == '-')
        return true;
    else
        return false;
}

void printGrid(vector <char> vect) {
    int counter = 0;
    for (int i = 0; i < GRID_SIZE; i++) {
        if (counter == 20) {
            cout<<endl;
            counter = 0;
        }
        cout<<vect[i]<<' ';
        counter++;
    }
}

void startSim() {
    vector<int> random_nums;
    for (int i = 0; i < GRID_SIZE; i++) {
        grid.push_back('-');
        random_nums.push_back(i);
    }
    
    srand(time(0));
    random_shuffle(random_nums.begin(), random_nums.end());
    for (int i = 0; i < 6; i++) {
        grid[random_nums[i]] = 'X';
    }

    for (int i = 5; i < 105; i++) {
        grid[random_nums[i]] = 'o';
    }
    printGrid(grid);
    
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