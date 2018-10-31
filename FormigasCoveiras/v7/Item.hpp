#include <vector>
#include <cmath>

#define ABS(a) ((a>0)?a:(-a))

class Item {
private:
    std::vector<double> specs;
    sf::Color color;
public:
    Item(sf::Color color, std::vector<double> &specs){
        this -> color = color;
        this -> specs = specs;
    }
    double calcDist(Item *other){
        double dist = 0;
        for(int i = 0; i < specs.size(); i++){
            dist += pow(specs[i] - other -> specs[i], 2);
            // dist += ABS(specs[i] - other -> specs[i]);
            // ^ não funciona sozinho
        }
        dist = sqrt(dist);
        return dist;
    }
    sf::Color getColor(){
        return this -> color;
    }
};
