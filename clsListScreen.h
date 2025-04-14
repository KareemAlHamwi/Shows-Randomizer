#pragma once

#include <iomanip>
#include <iostream>
#include <vector>

#include "clsAnime.h"
#include "clsLogic.h"
#include "clsMovie.h"
#include "clsScreen.h"
#include "clsSeries.h"
#include "enShowsOptions.h"

using namespace std;

class clsListScreen : protected clsScreen {
   private:
    static void _PrintAnimeRecord(clsAnime Anime) {
        cout << setw(8) << left << "" << "| " << setw(50) << left << Anime.GetTitle();
        cout << "| " << setw(20) << left << Anime.GetStringStatus();
    }

    static void _PrintMovieRecord(clsMovie Movie) {
        cout << setw(8) << left << "" << "| " << setw(50) << left << Movie.GetTitle();
        cout << "| " << setw(20) << left << Movie.GetDuration();
    }

    static void _PrintSeriesRecord(clsSeries Series) {
        cout << setw(8) << left << "" << "| " << setw(50) << left << Series.GetTitle();
        cout << "| " << setw(20) << left << Series.GetSeasons();
    }

    static void _ShowAnimesList() {
        vector<clsAnime> vAnimes = clsLogic::LoadAnimesDataFromFile();

        _DrawScreenHeader("Animes List");

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;

        cout << setw(8) << left << "" << "| " << left << setw(50) << "Title";
        cout << "| " << left << setw(50) << "Status";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;

        if (vAnimes.size() == 0)
            cout << "\t\t\t\t\t\tNo Animes Available In the System!";
        else
            for (clsAnime Anime : vAnimes) {
                _PrintAnimeRecord(Anime);
                cout << "\n\n";
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;
    }

    static void _ShowMoviesList() {
        vector<clsMovie> vMovies = clsLogic::LoadMoviesDataFromFile();

        _DrawScreenHeader("Movies List");

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;

        cout << setw(8) << left << "" << "| " << left << setw(50) << "Title";
        cout << "| " << left << setw(50) << "Duration";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;

        if (vMovies.size() == 0)
            cout << "\t\t\t\t\t\tNo Movies Available In the System!";
        else
            for (clsMovie Movie : vMovies) {
                _PrintMovieRecord(Movie);
                cout << "\n\n";
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;
    }

    static void _ShowSeriesList() {
        vector <clsSeries> vSeries = clsLogic::LoadSeriesDataFromFile();

        _DrawScreenHeader("Animes List");

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;

        cout << setw(8) << left << "" << "| " << left << setw(50) << "Title";
        cout << "| " << left << setw(50) << "Seasons";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;

        if (vSeries.size() == 0)
            cout << "\t\t\t\t\t\tNo Series Available In the System!";
        else

            for (clsSeries Series : vSeries) {
                _PrintSeriesRecord(Series);
                cout << "\n\n";
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;
    }

   public:
    static void ShowList(enShowsOptions CurrentShowType) {
        switch (CurrentShowType) {
            case enShowsOptions::Animes:
                _ShowAnimesList();
                break;
                case enShowsOptions::Movies:
                _ShowMoviesList();
                break;
                case enShowsOptions::Series:
                _ShowSeriesList();
                break;
        }
    }
};
