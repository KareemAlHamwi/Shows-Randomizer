#pragma once

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>

#include "clsAnime.h"
#include "clsDate.h"
#include "clsLogic.h"

using namespace std;

class clsScreen {
   public:

    static void _DrawScreenHeader(string Title) {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t\t   " << Title;

        cout << "\n\t\t\t\t\t______________________________________\n\n"
             << "\n\t\t\t\t\tDate: " << clsDate::dateToString(clsDate()) << "\n\n";
    }
};
