#pragma once

#include <iomanip>
#include <iostream>
#include <vector>

#include "clsAnime.h"
#include "clsInputValidate.h"
#include "clsLogic.h"
#include "clsScreen.h"
#include "enShowsOptions.h"

class clsAddNewScreen : protected clsScreen {
   private:
    static void _ReadAnimeInfo(clsAnime& Anime) {
        cout << "\nEnter Anime Title: ";
        Anime.SetTitle(clsInputValidate::ReadString());

        cout << "\nEnter Anime Status (Incomplete = 0 / Complete = 1): ";
        Anime.SetStatus(clsInputValidate::ReadIntNumber());
    }

    static void _PrintAnime(clsAnime Anime) {
        cout << "\nAnime Info:";
        cout << "\n___________________\n";
        cout << "\nAnime Title    : " << Anime.GetTitle();
        cout << "\nAnime Status   : " << Anime.GetStringStatus();
        cout << "\n___________________\n";
    }

    static void _ReadMovieInfo(clsMovie& Movie) {
        cout << "\nEnter Movie Title: ";
        Movie.SetTitle(clsInputValidate::ReadString());

        cout << "\nEnter Movie Duration: ";
        Movie.SetDuration(clsInputValidate::ReadString());
    }

    static void _PrintMovie(clsMovie Movie) {
        cout << "\nMovie Info:";
        cout << "\n___________________\n";
        cout << "\nMovie Title      : " << Movie.GetTitle();
        cout << "\nMovie Duration   : " << Movie.GetDuration();
        cout << "\n___________________\n";
    }

    static void _ReadSeriesInfo(clsSeries& Series) {
        cout << "\nEnter Series Title: ";
        Series.SetTitle(clsInputValidate::ReadString());

        cout << "\nEnter Series Number of Seasons: ";
        Series.SetSeasons(clsInputValidate::ReadString());
    }

    static void _PrintSeries(clsSeries Series) {
        cout << "\nSeries Info:";
        cout << "\n___________________\n";
        cout << "\nSeries Title     : " << Series.GetTitle();
        cout << "\nSeries Seasons   : " << Series.GetSeasons();
        cout << "\n___________________\n";
    }

    static void _ShowAddNewAnimeScreen() {
        _DrawScreenHeader("Add New Anime Screen");

        vector<clsAnime> vAnimes = clsLogic::LoadAnimesDataFromFile();
        clsAnime Anime;

        cout << "\nPlease Enter Anime Info:\n\n";
        _ReadAnimeInfo(Anime);

        vAnimes.push_back(Anime);

        clsLogic::SaveNewAnime(vAnimes);

        cout << "\n\n\nAnime Added Successfully :-)\n";
        _PrintAnime(Anime);
    }

    static void _ShowAddNewMovieScreen() {
        _DrawScreenHeader("Add New Movie Screen");

        vector<clsMovie> vMovies = clsLogic::LoadMoviesDataFromFile();
        clsMovie Movie;

        cout << "\nPlease Enter Movie Info:\n\n";
        _ReadMovieInfo(Movie);

        vMovies.push_back(Movie);

        clsLogic::SaveNewMovie(vMovies);

        cout << "\n\n\nMovie Added Successfully :-)\n";
        _PrintMovie(Movie);
    }

    static void _ShowAddNewSeriesScreen() {
        _DrawScreenHeader("Add New Series Screen");

        vector<clsSeries> vSeries = clsLogic::LoadSeriesDataFromFile();
        clsSeries Series;

        cout << "\nPlease Enter Series Info:\n\n";
        _ReadSeriesInfo(Series);

        vSeries.push_back(Series);

        clsLogic::SaveNewSeries(vSeries);

        cout << "\n\n\nSeries Added Successfully :-)\n";
        _PrintSeries(Series);
    }

   public:
    static void ShowAddNewShowScreen(enShowsOptions CurrentShowType) {
        switch (CurrentShowType) {
            case enShowsOptions::Animes:
                _ShowAddNewAnimeScreen();
                break;
            case enShowsOptions::Movies:
                _ShowAddNewMovieScreen();
                break;
            case enShowsOptions::Series:
                _ShowAddNewSeriesScreen();
                break;
        }
    }
};
