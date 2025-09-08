#include<iostream>
#include<stdio.h>
#include<cmath>

using namespace std;
const float PI = 3.141592653589793;

bool ObOnWay( int tarX, int tarY, int obX, int obY){
    int cross = ( obX*obY - tarY*tarX);
    if (cross == 0 ) return false;

    if (obX < min(0,tarX) || obX > max(0, tarX)) return false;
    if (obY < min(0,tarY) || obY > max(0, tarY)) return false;

    return true;
}

float distCal( int corX, int corY){
    float distance;
    distance = sqrt(pow(corX, 2.0) + pow(corY, 2.0));

    return distance;
}

float angleCal( int corX, int corY){
    float angle_deg;
    angle_deg = atan2(corY, corX) * 180 /PI;

    return angle_deg;
}

int main (){
    int tarX;
    int tarY;
    int obX;
    int obY;
    int myX;
    int myY;
    float totalDist;
    float angleTurn;
    float distBeforeOb;
    float distAfterOb;

    cout << "input target coordenates: x , y" << endl;
    cin >> tarX >> tarY;
    cout << "input obstacle coordibnates: x, y" << endl;
    cin >> obX >> obY;


    if ( ObOnWay(tarX, tarY, obX,obY)){
        totalDist = distCal(tarX, tarY);
        distBeforeOb = distCal(obX, obY);
        angleTurn = angleCal(tarX,  tarY);

        cout << "Driving " << totalDist << " angle of arrival: " << angleTurn << endl;
        cout << "Obstacle encountered on distance: "<< distBeforeOb << endl; 

        myX = obX + 3; myY = obY;
        angleTurn = 90 - angleTurn;
        cout << "Turning " << angleTurn << " to overcome obstacle" << endl;
        
        int vX = tarX-myX; int vY = tarY-myY;
        distAfterOb = distCal(vX, vY);
        angleTurn = angleCal(vX, vY);
        cout << "Going " << distAfterOb << " , angle of arrival: " <<  angleTurn << endl;
    }else{
        angleTurn = angleCal(tarX,  tarY);
        totalDist = distCal(tarX, tarY);
        cout << "Obstacle is not on the way angle of arrival: " << angleTurn << ", distance: " << totalDist << endl;
    }

    return 0;
}