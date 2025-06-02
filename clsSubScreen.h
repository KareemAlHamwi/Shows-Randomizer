#pragma once
#include <iomanip>
#include <iostream>

#include "clsAddNewScreen.h"
#include "clsInputValidate.h"
#include "clsListScreen.h"
#include "clsRandomScreen.h"
#include "clsScreen.h"
#include "enShowsOptions.h"
#include "clsDeleteScreen.h"

using namespace std;

class clsSubScreen : protected clsScreen {
   private:
    enum enSubMenuOptions {
        List = 1,
        Random = 2,
        AddNew = 3,
        Delete = 4,
        Exit = 5
    };

    static short _ReadSubMenuOption() {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }

    static void _GoBackToSubMenu(enShowsOptions ShowsTypeOption) {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menu...\n";
        system("pause>0");

        ShowSubMenu(ShowsTypeOption);
    }

    static void _ShowListScreen(enShowsOptions ShowsTypeOption) {
        clsListScreen::ShowList(ShowsTypeOption);
    }

    static void _ShowRandomShowScreen(enShowsOptions ShowsTypeOption) {
        clsRandomScreen::ShowRandomShow(ShowsTypeOption);
    }

    static void _ShowAddNewScreen(enShowsOptions ShowsTypeOption) {
        clsAddNewScreen::ShowAddNewShowScreen(ShowsTypeOption);
    }

    static void _ShowDeleteScreen(enShowsOptions ShowsTypeOption) {
        clsDeleteScreen::ShowDeleteShowScreen(ShowsTypeOption);
    }

    static void _PerformSubMenuOption(enSubMenuOptions MainMenuOption, enShowsOptions ShowsTypeOption) {
        switch (MainMenuOption) {
            case enSubMenuOptions::List: {
                system("cls");
                _ShowListScreen(ShowsTypeOption);
                _GoBackToSubMenu(ShowsTypeOption);
                break;
            }

            case enSubMenuOptions::Random:
                system("cls");
                _ShowRandomShowScreen(ShowsTypeOption);
                _GoBackToSubMenu(ShowsTypeOption);
                break;

            case enSubMenuOptions::AddNew:
                system("cls");
                _ShowAddNewScreen(ShowsTypeOption);
                _GoBackToSubMenu(ShowsTypeOption);
                break;
                
                case enSubMenuOptions::Delete:
                system("cls");
                _ShowDeleteScreen(ShowsTypeOption);
                _GoBackToSubMenu(ShowsTypeOption);

            case enSubMenuOptions::Exit:
                break;
        }
    }

    static void _ShowAnimesSubMenu() {
        system("cls");
        _DrawScreenHeader("Animes Randomizer");

        cout << setw(37) << left << "" << "===========================================\n\n";
        cout << setw(37) << left << "" << "\t[1] Show Animes List.\n\n";
        cout << setw(37) << left << "" << "\t[2] Get Random Anime.\n\n";
        cout << setw(37) << left << "" << "\t[3] Add New Anime.\n\n";
        cout << setw(37) << left << "" << "\t[4] Delete an Anime.\n\n\n";
        cout << setw(37) << left << "" << "\t[5] Exit.\n\n";
        cout << setw(37) << left << "" << "===========================================\n";
    }

    static void _ShowMoviesSubMenu() {
        system("cls");
        _DrawScreenHeader("Movies Randomizer");

        cout << setw(37) << left << "" << "===========================================\n\n";
        cout << setw(37) << left << "" << "\t[1] Show Movies List.\n\n";
        cout << setw(37) << left << "" << "\t[2] Get Random Movie.\n\n";
        cout << setw(37) << left << "" << "\t[3] Add New Movie.\n\n";
        cout << setw(37) << left << "" << "\t[4] Delete a Movie.\n\n\n";
        cout << setw(37) << left << "" << "\t[5] Exit.\n\n";
        cout << setw(37) << left << "" << "===========================================\n";
    }

    static void _ShowSeriesSubMenu() {
        system("cls");
        _DrawScreenHeader("Series Randomizer");

        cout << setw(37) << left << "" << "===========================================\n\n";
        cout << setw(37) << left << "" << "\t[1] Show Series List.\n\n";
        cout << setw(37) << left << "" << "\t[2] Get Random Series.\n\n";
        cout << setw(37) << left << "" << "\t[3] Add New Series.\n\n";
        cout << setw(37) << left << "" << "\t[4] Delete a Series.\n\n\n";
        cout << setw(37) << left << "" << "\t[5] Exit.\n\n";
        cout << setw(37) << left << "" << "===========================================\n";
    }

   public:
    static void ShowSubMenu(enShowsOptions CurrentShowType) {
        switch (CurrentShowType) {
            case enShowsOptions::Animes:
                _ShowAnimesSubMenu();
                break;
            case enShowsOptions::Movies:
                _ShowMoviesSubMenu();
                break;
            case enShowsOptions::Series:
                _ShowSeriesSubMenu();
                break;
        }

        _PerformSubMenuOption((enSubMenuOptions)_ReadSubMenuOption(), CurrentShowType);
    }
};
