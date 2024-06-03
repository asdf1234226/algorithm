#include <cstdlib> // for rand() and srand()
#include<iostream>
#include <ctime>   // for time()
using namespace std;

// Helper function to generate a random number between 0 and max_seconds.
int random_seconds(int max_seconds) {
    return rand() % (max_seconds + 1);
}

int main(){
    //srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < 100; i++)
    {
        int ttl = random_seconds(180);
        //cout << ttl << " ";
        if (ttl>180)
        {
            cout << "large";
        }        
    }
    return 0;
}