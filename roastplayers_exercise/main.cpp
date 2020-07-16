#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<int> jerseyNumber(5);
    vector<int> playerRating(5);
    string userOption;
    int i;
    for (i = 0; i < 5; i++) {
        cout << "Enter Jersey Number for player " << i + 1 << " (0-99)" << endl;
        cin >> jerseyNumber.at(i);
        cout << "Enter Rating for player " << i + 1 << " (1-9)" << endl;
        cin >> playerRating.at(i);

    }
    cout << "Menu Option" << endl;
    cout << "A. Output Roaster" << endl;
    cout << "B. Add Player" << endl;
    cout << "C. Delete Player" << endl;
    cout << "D. Update Player Rating " << endl;
    cout << "E. Output Player Above a Rating" << endl;
    cout << "F. Quit" << endl;

    cout << "Enter a letter for instruction" << endl;
    cin >> userOption;
    while (userOption != "F") {
        if (userOption == "A") {
            for (i = 0; i < playerRating.size(); i++) {
                cout << "Player number " << i + 1 << " has jersey number " << jerseyNumber.at(i)
                     << " with a rating of " << playerRating.at(i) << endl;
            }
        } else if (userOption == "B") {
            int newJerNum;
            int newPlaRat;
            cout << "Enter the new jersey number" << endl;
            cin >> newJerNum;
            jerseyNumber.push_back(newJerNum);
            cout << "Enter the new player rating" << endl;
            cin >> newPlaRat;
            playerRating.push_back(newPlaRat);
        } else if (userOption == "C") {
            cout << "Enter the jersey number to delete the player";
            int numDelete;
            int temp1;
            int temp2;
            cin >> numDelete;
            for (i = 0; i < playerRating.size(); i++) {
                if (numDelete == jerseyNumber.at(i)) {
                    for (int j = i; j < (playerRating.size() - 1); j++) {
                        temp1 = jerseyNumber.at(j);
                        jerseyNumber.at(j) = jerseyNumber.at(j + 1);
                        jerseyNumber.at(j + 1) = temp1;
                        temp2 = playerRating.at(j);
                        playerRating.at(j) = playerRating.at(j + 1);
                        playerRating.at(j + 1) = temp2;
                    }
                }
            }
            jerseyNumber.pop_back();
            playerRating.pop_back();
        } else if (userOption == "D") {
            int updateNum;
            bool isFound = false;
            cout << "Enter the jersey number of the player you want to update" << endl;
            cin >> updateNum;
            for (i = 0; i < playerRating.size(); i++) {
                if (jerseyNumber.at(i) == updateNum) {
                    isFound = true;
                    cout << "What is the new rating? " << endl;
                    int newRate;
                    cin >> newRate;
                    playerRating.at(i) = newRate;
                }
            }
            if (!isFound) {
                cout << "Player Not Found" << endl;
            }
        } else if (userOption == "E") {
            cout << "Enter a rating" << endl;
            int userStandard;
            cin >> userStandard;
            for (i = 0; i < jerseyNumber.size(); i++) {
                if (playerRating.at(i) > userStandard) {
                    cout << "Players qualify the condition is player with jersey number " << jerseyNumber.at(i)
                         << " and a rating of " << playerRating.at(i) << endl;
                }
            }
        } else {
            cout << "Invalid input. Try again.";
        }
        cout << "Enter another letter for instruction" << endl;

        cin >> userOption;
    }

    return 0;
}