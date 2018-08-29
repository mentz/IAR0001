#include <vector>
#include <cmath>

class Item {
private:
    vector<double> caracteristicas;
    sf::Color color;
public:
    Item();
    double calcDist(Item &other){
        double dist = 0;
        for(int i = 0; i < caracteristicas.size(); i++){
            dist += pow(caracteristicas[i] - other.caracteristicas[i], 2);
        }
        dist = sqrt(dist);
    }
}
