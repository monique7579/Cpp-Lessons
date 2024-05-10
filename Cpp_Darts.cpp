#include <iostream>
#include <cmath> //provides declarations and functions for mathematical operations.
#include<random>


using namespace std;


// Dart class
class Dart {
private:
    double angle;
    double strength;


public:
    // Constructor to initialize angle and strength
    Dart(double angle, double strength) : angle(angle), strength(strength) {}


    // Getter functions
    double getAngle() const { return angle; }
    double getStrength() const { return strength; }
};


// Dartboard class
class Dartboard {
private:
    static constexpr double idealAngle = 45.0; // Ideal angle in degrees
    static constexpr double idealStrength = 10.0; // Ideal strength


public:
    // Method to calculate the score of a given Dart
    int scoreDart(const Dart& dart) const {
        double angleDiff = abs(dart.getAngle() - idealAngle);
        double strengthDiff = abs(dart.getStrength() - idealStrength);


        // Calculate score based on angle and strength differences
        int score = static_cast<int>(100 - (angleDiff * 2 + strengthDiff));
        return max(score, 0); // Ensure score is non-negative
    }
};


int main() {
    // Instantiate Dartboard object
    Dartboard dartboard;


    // Sample dart throwing scenarios
    Dart dart1(45.0, 10.0); // Ideal shot
    Dart dart2(30.0, 8.0);  // Angle slightly off, strength slightly low
    Dart dart3(60.0, 12.0); // Angle off, strength high
    Dart dart4(70.0, 6.0);  // Angle off, strength low


    // Display scores for each dart
    cout << "Dart 1 Score: " << dartboard.scoreDart(dart1) << endl;
    cout << "Dart 2 Score: " << dartboard.scoreDart(dart2) << endl;
    cout << "Dart 3 Score: " << dartboard.scoreDart(dart3) << endl;
    cout << "Dart 4 Score: " << dartboard.scoreDart(dart4) << endl;


    return 0;
}
