#pragma once

#include <iostream>
#include <random>

#include "clsData.h"
#include "enShowsOptions.h"

using namespace std;

class clsLogic {
   private:
    static int RandomNumber(int from, int to) {
        static std::random_device rd;                   // Seed for the random number engine
        static std::mt19937 gen(rd());                  // Mersenne Twister engine
        std::uniform_int_distribution<> dis(from, to);  // Uniform distribution

        return dis(gen);  // Generate a random number within the range
    }

   public:
    static vector<clsAnime> LoadAnimesDataFromFile() {
        return clsData::LoadAnimesDataFromFile();
    }

    static void SaveNewAnime(vector<clsAnime> &vAnime) {
        clsData::SaveNewAnime(vAnime);
    }

    static vector<clsMovie> LoadMoviesDataFromFile() {
        return clsData::LoadMoviesDataFromFile();
    }

    static void SaveNewMovie(vector<clsMovie> &vMovie) {
        clsData::SaveNewMovie(vMovie);
    }

    static vector<clsSeries> LoadSeriesDataFromFile() {
        return clsData::LoadSeriesDataFromFile();
    }

    static void SaveNewSeries(vector<clsSeries> &vSeries) {
        clsData::SaveNewSeries(vSeries);
    }

    static string GetRandomAnimeTitle() {
        vector<clsAnime> vAnimes = LoadAnimesDataFromFile();

        if (vAnimes.empty()) {
            return "";
        }

        int randomIndex = RandomNumber(0, vAnimes.size() - 1);

        return vAnimes[randomIndex].GetTitle();
    }

    static string GetRandomMovieTitle() {
        vector<clsMovie> vMovies = LoadMoviesDataFromFile();

        if (vMovies.empty()) {
            return "";
        }

        int randomIndex = RandomNumber(0, vMovies.size() - 1);

        return vMovies[randomIndex].GetTitle();
    }

    static string GetRandomSeriesTitle() {
        vector<clsSeries> vSeries = LoadSeriesDataFromFile();

        if (vSeries.empty()) {
            return "";
        }

        int randomIndex = RandomNumber(0, vSeries.size() - 1);

        return vSeries[randomIndex].GetTitle();
    }
};
