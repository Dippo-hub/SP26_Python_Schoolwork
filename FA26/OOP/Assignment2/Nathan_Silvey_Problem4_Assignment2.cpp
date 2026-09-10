#include <iostream>
#include <random>
#include <ctime>

bool search_points(const short pointsArr[], int target, int size = 12) {
    for(int i=0;i<size;i++) {
        if (pointsArr[i] == target)
            return true;
        else 
            return false;
    }
    return false;
}

void play_craps() {
    srand(time(0));

    int score, d1, d2, round=0;
    short points[12];
    bool playing = true;

    while (playing) {
        round++;
        d1 = random() % 6 + 1;
        d2 = random() % 6 + 1;

        score = d1 + d2;
        std::cout << "Round " << round << std::endl << "Rolled: " << score << std::endl;
        if (round == 1) {
            if (score == 2 || score == 3 || score == 12) {
                std::cout << "You Lose" << std::endl;
                playing = false;
            } else if (score == 7 || score == 11) {
                std::cout << "You win!" << std::endl;
                playing = false;
            } else {
                points[round-1] = score;
            }
        } else {

            if (score == 7) {
                std::cout << "You lose!" << std::endl;
                playing = false;
            } else if (search_points(points, score)) {
                std::cout << "You win!" << std::endl;
                playing = false;
            } else {
                points[round-1] = score;
            }
        }
    }
}

int main (void) {
    short t;
    while(t++<20) {
        play_craps();
    }
}