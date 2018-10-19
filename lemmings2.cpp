#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {

    int n, b, sg, sb, power, fightN;

    vector<int> greenSurvivors, blueSurvivors;
    bool flag = false;
    //Podemos mudar o comparador do multiset para o fazer ordernar os elementos de forma ascendente. Mais conveniente para o nosso uso
    multiset<int, std::greater<int>> green, blue;

    multiset<int, std::greater<int>>::iterator greenFighter, blueFighter;
    

    cin >> n;

    while(n--) {

        cin >> b >> sg >> sb;

        green.clear();
        blue.clear();

        for(int i = 0; i < sg; i++) {
            cin >> power;
            green.insert(power);
        }
        for(int i = 0; i < sb; i++)  {
            cin >> power;
            blue.insert(power);
        }

        while(!green.empty() && !blue.empty()) {
            
            fightN = min(b, min((int)green.size(),(int)blue.size()));   

            greenSurvivors.clear();
            blueSurvivors.clear();

            while(fightN--) {
                greenFighter = green.begin();
                blueFighter  = blue.begin();

                int greenPower = *greenFighter;
                int bluePower  = *blueFighter;

                green.erase(greenFighter);
                blue.erase(blueFighter);

                if (greenPower > bluePower) {
                    greenSurvivors.push_back(greenPower-bluePower);
                }
                else if (bluePower > greenPower){
                    blueSurvivors.push_back(bluePower-greenPower);
                }
            }

            for(int x : greenSurvivors)
                green.insert(x);
            for(int x : blueSurvivors)
                blue.insert(x);

        }

        if (flag) cout << '\n';

        flag = true;

        if (green.empty() && blue.empty()) {
            cout << "green and blue died\n";
        }
        else if (green.empty() && !blue.empty()) {
            cout << "blue wins\n";
            for(int x : blue) {
                cout << x << endl;
            }
        } 
        else if (!green.empty() && blue.empty()) {
            cout << "green wins\n";
            for(int x : green) {
                cout << x << endl;
            }
        }
        
    }

    return 0;
}