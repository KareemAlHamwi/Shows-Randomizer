#pragma once

#include <iomanip>
#include <iostream>

#include "clsLogic.h"
#include "clsScreen.h"
#include "enShowsOptions.h"

using namespace std;

class clsRandomScreen : protected clsScreen {
   private:
    static void _ShowRandomAnime() {
        _DrawScreenHeader("Random Anime");

        cout << setw(8) << left << "" << "\n\tAnd your Anime is .. " << endl;
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;

        string title = clsLogic::GetRandomAnimeTitle();
        if (title.empty()) {
            cout << "\n\t\t\t\tNo Animes Available In the System!\n"
                 << endl;

        } else {
            cout << setw(8) << left << "" << right << setw(50) << title;
        }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;
    }

    static void _ShowRandomMovie() {
        _DrawScreenHeader("Random Movie");

        cout << setw(8) << left << "" << "\n\tAnd your Movie is .. " << endl;
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;

        string title = clsLogic::GetRandomMovieTitle();
        if (title.empty()) {
            cout << "\n\t\t\t\tNo Movies Available In the System!\n"
                 << endl;

        } else {
            cout << setw(8) << left << "" << right << setw(50) << title;
        }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;
    }

    static void _ShowRandomSeries() {
        _DrawScreenHeader("Random Series");

        cout << setw(8) << left << "" << "\n\tAnd your Series is .. " << endl;
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;

        string title = clsLogic::GetRandomSeriesTitle();
        if (title.empty()) {
            cout << "\n\t\t\t\tNo Series Available In the System!\n"
                 << endl;

        } else {
            cout << setw(8) << left << "" << right << setw(50) << title;
        }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;
    }

   public:
    static void ShowRandomShow(enShowsOptions CurrentShowType) {
        switch (CurrentShowType) {
            case enShowsOptions::Animes:
                _ShowRandomAnime();
                break;
            case enShowsOptions::Movies:
                _ShowRandomMovie();
                break;
            case enShowsOptions::Series:
                _ShowRandomSeries();
                break;
        }
    }
};
