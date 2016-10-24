//Ashena Gorgan Mohammadi, 610394128

/* This is called kill game. The game is as this:
 * n people are sitted round. Starting from the first player and moving forward
 * for with the number of intervals, a player is killed each time. The person
 * who remains alive is the winner. This game is implemented with a link array.
 */

#include <iostream>

using namespace std;

string killGame(string name[], int n, int interval){
    int next[n];
    for(int i = 0; i < n - 1; i++)
        next[i] = i + 1;
    next[n - 1] = 0;
    int remainers = n, i = 0, j = n - 1;
    while(remainers != 1){
        cout << i << " " << next[i] << endl;
        for(int k = 0; k < interval; k++){
            i = j;
            j = next[j];
        }
        next[i] = next[j];
        j = i;
        remainers--;
    }
    return name[i];
}

int main(){
    int n, interval;
    cout << "Enter number of players:" << endl;
    cin >> n;
    string name[n];
    cout << "Enter name of players:" << endl;
    for(int i = 0; i < n; i++)
        cin >> name[i];
    cout << "Enter the kill interval:" << endl;
    cin >> interval;
    string winner = killGame(name, n, interval);
    cout << "the winner is " << winner << endl;
    return 0;
}