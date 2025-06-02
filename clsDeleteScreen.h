#pragma once

#include <iomanip>
#include <iostream>
#include <vector>

#include "clsAnime.h"
#include "clsInputValidate.h"
#include "clsLogic.h"
#include "clsScreen.h"
#include "enShowsOptions.h"

class clsDeleteScreen : protected clsScreen {
   private:
    static void _PrintAnime(clsAnime Anime) {
        cout << "\nAnime Info:";
        cout << "\n___________________\n";
        cout << "\nAnime Title    : " << Anime.GetTitle();
        cout << "\nAnime Status   : " << Anime.GetStringStatus();
        cout << "\n___________________\n";
    }

    static void _PrintMovie(clsMovie Movie) {
        cout << "\nMovie Info:";
        cout << "\n___________________\n";
        cout << "\nMovie Title      : " << Movie.GetTitle();
        cout << "\nMovie Duration   : " << Movie.GetDuration();
        cout << "\n___________________\n";
    }

    static void _PrintSeries(clsSeries Series) {
        cout << "\nSeries Info:";
        cout << "\n___________________\n";
        cout << "\nSeries Title     : " << Series.GetTitle();
        cout << "\nSeries Seasons   : " << Series.GetSeasons();
        cout << "\n___________________\n";
    }

    static void _ShowDeleteAnimeScreen() {
        _DrawScreenHeader("Delete Anime Screen");

        string AnimeName = "";

        cout << "\nPlease Enter Anime Name: ";
        AnimeName = clsInputValidate::ReadString();
        while (/*!clsAnime::isAnimeExist(AnimeName)*/false) {
            cout << "\nAnime was not found, please type the name correctly: ";
            AnimeName = clsInputValidate::ReadString();
        }

        // clsAnime Anime1 = clsAnime::find(AnimeName);
        // _PrintAnime(Anime1);

        cout << "\nAre you sure you want to delete this Anime y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y') {
            if (/*Anime1.Delete()*/true) {
                cout << "\nAnime Deleted Successfully :-)\n";
                // _PrintAnime(Anime1);
            } else {
                cout << "\nError Anime Was not Deleted\n";
            }
        }
    }

    static void _ShowDeleteMovieScreen() {
        _DrawScreenHeader("Delete Movie Screen");

        string MovieName = "";

        cout << "\nPlease Enter Movie Name: ";
        MovieName = clsInputValidate::ReadString();
        while (/*!clsMovie::isMovieExist(MovieName)*/false) {
            cout << "\nMovie was not found, please type the name correctly: ";
            MovieName = clsInputValidate::ReadString();
        }

        // clsMovie Movie1 = clsMovie::find(MovieName);
        // _PrintMovie(Movie1);

        cout << "\nAre you sure you want to delete this Movie y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y') {
            if (/*Movie1.Delete()*/true) {
                cout << "\nMovie Deleted Successfully :-)\n";
                // _PrintMovie(Movie1);
            } else {
                cout << "\nError Movie Was not Deleted\n";
            }
        }
    }

    static void _ShowDeleteSeriesScreen() {
        _DrawScreenHeader("Delete Series Screen");

        string SeriesName = "";

        cout << "\nPlease Enter Series Name: ";
        SeriesName = clsInputValidate::ReadString();
        while (/*!clsSeries::isSeriesExist(SeriesName)*/false) {
            cout << "\nSeries was not found, please type the name correctly: ";
            SeriesName = clsInputValidate::ReadString();
        }

        // clsSeries Series1 = clsSeries::find(SeriesName);
        // _PrintSeries(Series1);

        cout << "\nAre you sure you want to delete this Series y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y') {
            if (/*Series1.Delete()*/true) {
                cout << "\nSeries Deleted Successfully :-)\n";
                // _PrintSeries(Series1);
            } else {
                cout << "\nError Series Was not Deleted\n";
            }
        }
    }

   public:
    static void ShowDeleteShowScreen(enShowsOptions CurrentShowType) {
        switch (CurrentShowType) {
            case enShowsOptions::Animes:
                _ShowDeleteAnimeScreen();
                break;
            case enShowsOptions::Movies:
                _ShowDeleteMovieScreen();
                break;
            case enShowsOptions::Series:
                _ShowDeleteSeriesScreen();
                break;
        }
    }
};
