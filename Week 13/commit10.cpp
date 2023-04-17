#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>
using namespace std;

const int gridSize = 400;
const int doodlebugCount = 5;
const int antCount = 100;

const int originalTimeTillStarve = 3;
const int originalDoodleTimeTillBreed = 8;
const int originalAntTimeTillBreed = 3;

const char DOODLEBUG = 'X';
const char ANT = 'o';
const char EMPTY = '-';

class Organism{
    private:
        Organism** game;
        int orgID;
        int loc;
        int timeTillStarve;
        int timeTillBreed;
        bool movedThisRound = false;
    public:
        Organism() {
            setGame(nullptr);
            setOrgID(-1);
            setLoc(-1);
        };
        Organism(Organism** g, int pos) {
            setGame(g);
            setOrgID(-1);
            setLoc(pos);
        };

        virtual void move(Organism** g, int i) {};
        virtual void starve(Organism** g, int i) {};
        virtual void breed(Organism** g, int i) {};
        void setGame(Organism** val) {game = val;};
        void setOrgID(int val) {orgID = val;};
        void setLoc(int val) {loc = val;};
        void setTimeTillStarve(int val) {timeTillStarve = val;};
        void setTimeTillBreed(int val) {timeTillBreed = val;};
        int getTimeTillBreed() {return timeTillBreed;};
        int getTimeTillStarve() {return timeTillStarve;};
        void setMovedThisRound(bool val) {movedThisRound = val;};
        bool getMovedThisRound() {return movedThisRound;};

        Organism** getGame() {return game;};
        int getOrgID() {return orgID;};
        int getLoc() {return loc;};
        friend ostream& operator<<(ostream& os, const Organism& val) {
            os<< val.orgID;
            return os;
        }
};

class Doodlebug:public Organism {
    private:
    public:
        Doodlebug(Organism** g, int loc) {
            setGame(g);
            setOrgID(loc);
            setLoc(loc);
            setTimeTillStarve(originalTimeTillStarve);
            setTimeTillBreed(originalDoodleTimeTillBreed);
            setMovedThisRound(false);
        }
        void move(Organism** g, int i);
        void starve(Organism** g, int i);
        void breed(Organism** g, int i);
};

void Doodlebug::move(Organism** g, int i) {
    int sqrtGridSize = sqrt(gridSize);
    bool antNearby = false;
    // Check for ants in adjacent cells
    if (i >= sqrtGridSize && g[i - sqrtGridSize]->getOrgID() >= doodlebugCount && g[i - sqrtGridSize]->getOrgID() < doodlebugCount+antCount) { // up
        antNearby = true;
        setTimeTillStarve(originalTimeTillStarve);
        delete g[i - sqrtGridSize];
        g[i - sqrtGridSize] = new Organism(g, i - sqrtGridSize);
        swap(g[i], g[i - sqrtGridSize]);
        setMovedThisRound(true);
        return;
    } else if (i < gridSize - sqrtGridSize && g[i + sqrtGridSize]->getOrgID() >= doodlebugCount && g[i + sqrtGridSize]->getOrgID() < doodlebugCount+antCount) { // down
        antNearby = true;
        setTimeTillStarve(originalTimeTillStarve);
        delete g[i + sqrtGridSize];
        g[i + sqrtGridSize] = new Organism(g, i + sqrtGridSize);
        swap(g[i], g[i + sqrtGridSize]);
        setMovedThisRound(true);
        return;
    } else if (i % sqrtGridSize != 0 && g[i - 1]->getOrgID() >= doodlebugCount && g[i - 1]->getOrgID() < doodlebugCount+antCount) { // left
        antNearby = true;
        setTimeTillStarve(originalTimeTillStarve);
        delete g[i - 1];
        g[i - 1] = new Organism(g, i - 1);
        swap(g[i], g[i - 1]);
        setMovedThisRound(true);
        return;
    } else if ((i + 1) % sqrtGridSize != 0 && g[i + 1]->getOrgID() >= doodlebugCount && g[i + 1]->getOrgID() < doodlebugCount+antCount) { // right
        antNearby = true;
        setTimeTillStarve(originalTimeTillStarve);
        delete g[i + 1];
        g[i + 1] = new Organism(g, i + 1);
        swap(g[i], g[i + 1]);
        setMovedThisRound(true);
        return;
    }

    if (!antNearby) {
        int direction = rand() % 4;
        // Move in a random direction
        switch (direction) {
            case 0: // move up
                if (i >= sqrtGridSize && g[i - sqrtGridSize]->getOrgID() == -1) {
                    swap(g[i], g[i - sqrtGridSize]);
                    setTimeTillStarve(getTimeTillStarve() - 1);
                    setMovedThisRound(true);
                    return;
                }
                break;
            case 1: // move down
                if (i < gridSize - sqrtGridSize && g[i + sqrtGridSize]->getOrgID() == -1) {
                    swap(g[i], g[i + sqrtGridSize]);
                    setTimeTillStarve(getTimeTillStarve() - 1);
                    setMovedThisRound(true);
                    return;
                }
                break;
            case 2: // move left
                if (i % sqrtGridSize != 0 && g[i - 1]->getOrgID() == -1) {
                    swap(g[i], g[i - 1]);
                    setTimeTillStarve(getTimeTillStarve() - 1);
                    setMovedThisRound(true);
                    return;
                }
                break;
            case 3: // move right
                if((i + 1) % sqrtGridSize != 0 && g[i+1]->getOrgID() == -1) {
                    swap(getGame()[i], getGame()[i+1]);
                    setTimeTillStarve(getTimeTillStarve() - 1);
                    setMovedThisRound(true);
                }
            break;
        }
    }
    setTimeTillBreed(getTimeTillBreed() - 1);
};

void Doodlebug::starve(Organism** g, int i) {
    delete[] g[i];
    g[i] = new Organism(g, i);
}

void Doodlebug::breed(Organism** g, int i) {
    int sqrtGridSize = sqrt(gridSize);
    setTimeTillBreed(originalDoodleTimeTillBreed);
    if (i >= sqrtGridSize && g[i - sqrtGridSize]->getOrgID() == -1) { // up
        delete[] g[i - sqrtGridSize];
        g[i - sqrtGridSize] = new Doodlebug(g, i);
    } else if (i < gridSize - sqrtGridSize && g[i + sqrtGridSize]->getOrgID() == -1) { // down
        delete[] g[i + sqrtGridSize];
        g[i + sqrtGridSize] = new Doodlebug(g, i);
    } else if (i % sqrtGridSize != 0 && g[i - 1]->getOrgID() == -1) { // left
        delete[] g[i - 1];
        g[i - 1] = new Doodlebug(g, i);
    } else if ((i + 1) % sqrtGridSize != 0 && g[i + 1]->getOrgID() == -1) { // right
        delete[] g[i + 1];
        g[i + 1] = new Doodlebug(g, i);
    }
}

class Ant:public Organism {
    private:
    public:
        Ant(Organism** g, int loc) {
            setGame(g);
            setOrgID(loc);
            setLoc(loc);
            setTimeTillBreed(originalAntTimeTillBreed);
            setMovedThisRound(false);
        }
        void move(Organism** g, int i);
        void starve(Organism**g, int i) {};
        void breed(Organism** g, int i);
};

void Ant::move(Organism** g, int i) {
    int sqrtGridSize = sqrt(gridSize);
    int direction = rand() % 4;
    switch(direction) {
        case 0: // move up
            if(i + 1 > sqrtGridSize && getGame()[i-sqrtGridSize]->getOrgID() == -1) {
                swap(getGame()[i], getGame()[i-sqrtGridSize]);
                setMovedThisRound(true);
            }
        break;
        case 1: // move down
            if(i + 1 < gridSize-sqrtGridSize && getGame()[i+sqrtGridSize]->getOrgID() == -1) {
                swap(getGame()[i], getGame()[i+sqrtGridSize]);
                setMovedThisRound(true);
            }
        break;
        case 2: // move left
            if(i % 20 != 0 && getGame()[i-1]->getOrgID() == -1) {
                swap(getGame()[i], getGame()[i-1]);
                setMovedThisRound(true);
            }
        break;
        case 3: // move right
            if((i + 1) % 20 != 0 && getGame()[i+1]->getOrgID() == -1) {
                swap(getGame()[i], getGame()[i+1]);
                setMovedThisRound(true);
            }
        break;
    }
    setTimeTillBreed(getTimeTillBreed() - 1);
};

void Ant::breed(Organism** g, int i) {
    int sqrtGridSize = sqrt(gridSize);
    setTimeTillBreed(originalAntTimeTillBreed);
    if (i >= sqrtGridSize && g[i - sqrtGridSize]->getOrgID() == -1) { // up
        delete[] g[i - sqrtGridSize];
        g[i - sqrtGridSize] = new Ant(g, i);
    } else if (i < gridSize - sqrtGridSize && g[i + sqrtGridSize]->getOrgID() == -1) { // down
        delete[] g[i + sqrtGridSize];
        g[i + sqrtGridSize] = new Ant(g, i);
    } else if (i % sqrtGridSize != 0 && g[i - 1]->getOrgID() == -1) { // left
        delete[] g[i - 1];
        g[i - 1] = new Ant(g, i);
    } else if ((i + 1) % sqrtGridSize != 0 && g[i + 1]->getOrgID() == -1) { // right
        delete[] g[i + 1];
        g[i + 1] = new Ant(g, i);
    }
}

class Game {
    friend class Organism;
    friend class Doodlebug;
    friend class Ant;

    private:
    Organism** game;
    int timeCount = 0;
    public:
    Game();
    void play();
    void moveOrgs();
    void gameOver();
    void display();
    void setTimeCount(int val) {timeCount = val;}; 
    Organism** getGame() {return game;};
};

Game::Game() {
    game = new Organism*[gridSize];
    for (int i = 0; i < gridSize; i++) {
        if (i < doodlebugCount) {
            Doodlebug* orgPtr = new Doodlebug(game, i);
            game[i] = orgPtr;
        } else if (i < doodlebugCount+antCount) {
            Ant* orgPtr = new Ant(game, i);
            game[i] = orgPtr;
        } else {
            Organism* orgPtr = new Organism(game, i);
            game[i] = orgPtr;
        }
    }
    srand(time(nullptr));
    for(int i = 0; i < gridSize; i++) {
        int new_i = rand() % gridSize;
        swap(game[i], game[new_i]);
    }
};

void Game::moveOrgs() {
    Organism** copyGame = new Organism*[gridSize];
    for(int i = 0; i < gridSize; i++) {
        copyGame[i] = game[i];
    }
    for(int i = 0; i < gridSize; i++) {
        if (getGame()[i]->getOrgID() >= 0 && getGame()[i]->getOrgID() < doodlebugCount && copyGame[i]->getOrgID() == getGame()[i]->getOrgID() && getGame()[i]->getMovedThisRound()==false) { // moving doodlebugs
            getGame()[i]->move(getGame(), i);
        }
    }
    for(int i = 0; i < gridSize; i++) {
        if (getGame()[i]->getOrgID() >= doodlebugCount && getGame()[i]->getOrgID() < doodlebugCount+antCount && copyGame[i]->getOrgID() == getGame()[i]->getOrgID() && getGame()[i]->getMovedThisRound()==false) { // moving ants
            getGame()[i]->move(getGame(), i);
        }
    }
    delete[] copyGame;

    for(int i = 0; i < gridSize; i++) {
        if (getGame()[i]->getTimeTillBreed() <= 0) {
            getGame()[i]->breed(getGame(), i);
        }
        if (getGame()[i]->getTimeTillStarve() <= 0) {
            getGame()[i]->starve(getGame(), i);
        }
    }
    timeCount++;
    for(int i = 0; i < gridSize; i++) {
        getGame()[i]->setMovedThisRound(false);
    }
};

void Game::gameOver() {
    for(int i = 0; i < gridSize; i++) {
        delete game[i];
    }
    delete[] game;
};


void Game::display() {
    int countOfAnts = 0;
    int countOfDoodles = 0;
    int sqrtGridSize = sqrt(gridSize);
    cout<<"World at time "<<timeCount<<":"<<endl<<endl;
    for(int i = 0; i < gridSize; i++) {
        if (i % sqrtGridSize == 0) {
            cout<<endl;
        }
        if (game[i]->getOrgID() >= 0 && game[i]->getOrgID() < doodlebugCount) {
            cout<<DOODLEBUG<<' ';
            countOfDoodles++;
        } else if (game[i]->getOrgID() >= doodlebugCount && game[i]->getOrgID() < doodlebugCount+antCount) {
            cout<<ANT<<' ';
            countOfAnts++;
        } else {cout<<EMPTY<<' ';};
    }
    cout<<endl<<endl<<"Press ENTER to continue"<<endl;
    cout<<countOfAnts<<" ";
    cout<<countOfDoodles<<endl;
}

int main() {
    Game grid;
    int input;
    for(int i = 0; true; i++) {
        grid.display();
        grid.moveOrgs();
        cin.ignore();
    }
}