

#include <iostream>
#include <fstream>

using namespace std;

string _heroName = "Error";
int _heroAtk = 0;
int _heroDef = 0;
int _heroHp = 0;

string _goblinOneName = "Error";
int _gOneAtk = 0;
int _gOneDef = 0;
int _gOneHp = 0;

string _goblinTwoName = "Error";
int _gTwoAtk = 0;
int _gTwoDef = 0;
int _gTwoHp = 0;

// what: parse the following
// Kurt 10 5 100
// Goblin 6 3 40
// Goblin 5 5 50
void ParseIn () {
    // input file stream
    ifstream inFile("saveTrial.in");

    inFile >> _heroName;
    inFile >> _heroAtk >> _heroDef >> _heroHp;

    inFile >> _goblinOneName;
    inFile >> _gOneAtk >> _gOneDef >> _gOneHp;

    inFile >> _goblinTwoName;
    inFile >> _gTwoAtk >> _gTwoDef >> _gTwoHp;

    inFile.close();

    cout << _heroName;
    cout << ";atk->" << _heroAtk;
    cout << ";def->" << _heroDef;
    cout << ";hp->" << _heroHp;
    cout << endl;
}

string HeroAttack() {
    int curDmg = 0;
    string meg = "";
    char dmgChar = 'E';

    curDmg = _heroAtk - _gOneDef;
    _gOneHp -= curDmg;

    meg += _heroName + " attacks " + _goblinOneName + " for ";
    dmgChar = curDmg + '0';

    meg += dmgChar;
    meg += " dmg.";

    meg += "\n";

    curDmg = _heroAtk - _gTwoDef;
    _gTwoHp -= curDmg;

    meg += _heroName + " attacks " + _goblinTwoName + " for ";
    dmgChar = curDmg + '0';

    meg += dmgChar;
    meg += " dmg.";

    meg += "\n";

    // cout << meg << endl;
    return meg;
}

void WriteOut () {
    string messageSolo = "Error";

    // output file stream
    ofstream outFile("saveTrial.out");

    for (int i = 0; i < 3; i++) {
        messageSolo = HeroAttack();
        outFile << i << "->" << messageSolo << endl;
    }

    outFile.close();
}

int main () {
    ParseIn();
    WriteOut();

    return 0;
}
