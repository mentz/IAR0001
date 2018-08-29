#include <vector>
#include <cmath>

class Item {
private:
    vector<double> specs;
    sf::Color color;
public:
    Item(sf::Color color, vector<double> &specs){
        this -> color = color;
        this -> specs = specs;
    }
    double calcDist(Item *other){
        double dist = 0;
        for(int i = 0; i < specs.size(); i++){
            dist += pow(specs[i] - other -> specs[i], 2);
        }
        dist = sqrt(dist);
    }
    sf::Color getColor(){
        return this -> color;
    }
}
