#include <iostream>
#include <random>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>

struct dice {
    int sides = 0;
    int multiplier = 0;
};
enum dicetype : int {d4, d6, d8, d10, d12, d20};
struct roll {
    std::vector<dice> dices;
};

//"-d 4x5 20x3 12x6 10x2 /";
int main(int argc, char* argv[])
{
    std::vector<roll> rolls;
    for (int i = 0; i < argc; i++) {
        if (std::string(argv[i]) == "-d") {
            roll d;
            while ((argv[++i][0]) != '/') {
                std::stringstream val;
                val << std::string(argv[i]);
                std::string tempstr;


                while (std::getline(val, tempstr)) {
                    dice a;
                    std::stringstream dicess;
                    dicess << tempstr;
                    std::getline(dicess, tempstr, 'x');
                    int sides = std::stoi(tempstr);
                    std::getline(dicess, tempstr);
                    int multiplier = std::stoi(tempstr);
                    a.sides = sides;
                    a.multiplier = multiplier;
                    if (multiplier && sides)
                        d.dices.push_back(a);
                }
            }
            rolls.push_back(d);
        }
    }

    const int DICE_COUNT[6]{ 2,3,6,12,24,48 };
    std::vector<int*> results;
    
    for (int n = 0; n < 6; n++) {
        const int ROLL_COUNT = 100'000;
        std::default_random_engine randy(time(NULL));
        std::uniform_int_distribution<int> dice(1, 6);
        int *result = (int*)malloc(sizeof(int) * DICE_COUNT[n]*7);
        if (result == NULL) {
            exit(-1);
        }
        for (int i = 0; i < DICE_COUNT[n]*7; i++) {
            result[i] = 0;
        }
        for (int i = 0; i < ROLL_COUNT; i++) {
            int sum = 0;
            for (int i = 0; i < DICE_COUNT[n]; i++) {
                sum += dice(randy);
            }
            result[sum]++;
        }
        for (int i = DICE_COUNT[n]; i <= DICE_COUNT[n] * 7 - DICE_COUNT[n]; i++) {
            std::cout << std::fixed << std::setprecision(10) << std::setw(4) << std::left
                << i << ":\t" << double(result[i]) / ROLL_COUNT * 100 << '\n';
        }
        results.push_back(result);
    }
    return 0;
}
