#include<iostream>
using namespace std;

int main(){
    int days, times;
    cout << "Enter number of days: ";
    cin >> days;
    cout << "Enter number of times per day: ";
    cin >> times;

    double** temperatures = new double* [days];
    for (int i=0; i< days; i++){
        temperatures[i] = new double[times];
    }

    cout << "Enter the temperatures: \n";
    for (int i=0; i< days; i++){
        for (int j=0; j< times; j++){
            cin >> temperatures[i][j];
        }
    }

    for (int i=0; i< days; i++){
        double dailyTotal = 0.0;
        for (int j=0; j< times; j++){
            dailyTotal += temperatures[i][j];
        }
        double dailyAvg = dailyTotal / times;
        cout << "Average temperature for day " << (i+1) << ": " << dailyAvg << endl;
    }

    int hottestDay = 0;
    double highestTemp = -100.0;
    for (int i=0 ; i< days ; i++){
        for (int j=0; j< times; j++){
            if (temperatures[i][j] > highestTemp){
                highestTemp = temperatures[i][j];
                hottestDay = i;
            }
        }
    }

    cout << "Hottest temperature recorded: " << highestTemp << " on day " << (hottestDay + 1) << endl;

    int coldestDay = 0;
    double lowestTemp = 100.0;

    for (int i=0 ; i< days ; i++){
        for (int j=0; j< times; j++){
            if (temperatures[i][j] < lowestTemp){
                lowestTemp = temperatures[i][j];
                coldestDay = i;
            }
        }
    }

    cout << "Coldest temperature recorded: " << lowestTemp << " on day " << (coldestDay + 1) << endl;

    for (int i=0; i< days; i++){
        delete[] temperatures[i];
    }
    delete[] temperatures;

    return 0;

}

