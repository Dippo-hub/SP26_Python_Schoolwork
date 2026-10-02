#include <iostream>
#include <string>
using std::string;
using namespace std;


class Spaceship {
    private:
        int x, y, angle;
        string pos; // "{X: x, Y: y, Direction: direction}"
        string direction;

    public:

        Spaceship () {
            x=0;
            y=0;
            angle=0;
            direction = "up";
        }
        Spaceship (const string &path) {
            x=0;
            y=0;
            angle = 0;

            for(short i=0; i<path.size();i++) {
                if (path.at(i) == 'R') //char is R turns right
                    angle += 90;
                else if (path.at(i) == 'L') //char is L turns left
                    angle -= 90;
                else { //char is A advances in direction
                    angle = (angle % 360 + 360) % 360; //normalize angle between 0-359
                    switch(angle) {
                        case 0: y--; break;
                        case 90: x++; break;
                        case 180: y++; break;
                        case 270: x--; break;
                        default: break;
                    }
                }
                    
            }
        }
        
        string getPos() {
            angle = (angle % 360 + 360) % 360;
            switch(angle) {
                case 0: direction = "up"; break;
                case 90: direction = "right"; break;
                case 180: direction = "down"; break;
                case 270: direction = "left"; break;
                default: direction = "unknown"; break;
            }

            pos = "Position: {X: " + std::to_string(x) + ", Y: " + std::to_string(y) + ", Direction: " + direction + "}";

            return pos;
        }
};

int main()
{
Spaceship astrochuckler;
std::cout << astrochuckler.getPos() << std::endl;
Spaceship lunacycle("RAALALL");
std::cout << lunacycle.getPos() << std::endl;
Spaceship quirkonaut("AAAARAARLAAAARAAARRAAAALLLA");
std::cout << quirkonaut.getPos() << std::endl;
Spaceship zanyverse("");
std::cout << zanyverse.getPos() << std::endl;
Spaceship cosmocomedy("LAAA");
std::cout << cosmocomedy.getPos() << std::endl;
return 0;
}