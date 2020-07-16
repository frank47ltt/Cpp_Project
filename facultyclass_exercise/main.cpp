#include <iostream>
#include "Faculty.h"
using namespace std;

int main() {
    Faculty prof;
    Faculty prof1;
    Faculty prof2("Selina", "1234556", "Math", "Elementary");
    prof.setName("Frank Liu");
    prof.setID("06571806");
    prof.setDepartment("Computer Science");
    prof.setDegree("Doctoral");

    cout << prof1.getID() << endl;
    cout << prof2.getID() << endl;
    return 0;
}

