#pragma once
#include <iomanip>
#include <iostream>

#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsSubScreen.h"
#include "enShowsOptions.h"

using namespace std;

class clsMainScreen : protected clsScreen {
   private:
    enum enMainMenuOptions {
        AnimesScreen = 1,
        MoviesScreen = 2,
        SeriesScreen = 3,
        Exit = 4
    };

    static short _ReadMainMenuOption() {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 4]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 4, "Enter Number between 1 to 4? ");
        return Choice;
    }

    static void _ShowAnimesScreen(enShowsOptions Animes) {
        clsSubScreen::ShowSubMenu(Animes);
    }

    static void _ShowMoviesScreen(enShowsOptions Movies) {
        clsSubScreen::ShowSubMenu(Movies);
    }

    static void _ShowSeriesScreen(enShowsOptions Series) {
        clsSubScreen::ShowSubMenu(Series);
    }

    static void _PerformMainMenuOption(enMainMenuOptions MainMenuOption) {
        switch (MainMenuOption) {
            case enMainMenuOptions::AnimesScreen: {
                system("cls");
                _ShowAnimesScreen(enShowsOptions::Animes);
                GoBackToMainMenu();
                break;
            }

            case enMainMenuOptions::MoviesScreen:
                system("cls");
                _ShowMoviesScreen(enShowsOptions::Movies);
                GoBackToMainMenu();
                break;

            case enMainMenuOptions::SeriesScreen:
                system("cls");
                _ShowSeriesScreen(enShowsOptions::Series);
                GoBackToMainMenu();
                break;

            case enMainMenuOptions::Exit:
                break;
        }
    }

   public:
    static void GoBackToMainMenu() {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menu...\n";

        system("pause>0");
        ShowMainMenu();
    }

    static void ShowMainMenu() {
        system("cls");
        _DrawScreenHeader("Shows Randomizer");

        cout << setw(37) << left << "" << "===========================================\n\n";
        cout << setw(37) << left << "" << "\t[1] Animes.\n\n";
        cout << setw(37) << left << "" << "\t[2] Movies.\n\n";
        cout << setw(37) << left << "" << "\t[3] Series.\n\n\n";
        cout << setw(37) << left << "" << "\t[4] Exit.\n\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformMainMenuOption((enMainMenuOptions)_ReadMainMenuOption());
    }
};
