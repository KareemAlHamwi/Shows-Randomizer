#include <iostream>
#include "clsMainScreen.h"
using namespace std;

int main() {
    srand(time(NULL));
    clsMainScreen::ShowMainMenu();

    system("pause");
    return 0;
}
