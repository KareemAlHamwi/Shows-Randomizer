#pragma once

#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>

#include "clsAnime.h"
#include "clsMovie.h"
#include "clsSeries.h"
#include "clsString.h"

using namespace std;
namespace fs = std::filesystem;

class clsData {
   private:
    static string GetFilePath(const string& filename) {
        if (fs::exists(filename)) {
            return filename;
        }

        fs::path exePath = fs::current_path() / filename;
        if (fs::exists(exePath)) {
            return exePath.string();
        }

        fs::path dataPath = fs::current_path() / "Data" / filename;
        if (fs::exists(dataPath)) {
            return dataPath.string();
        }

        return filename;
    }

    static clsAnime _ConvertLineToAnimeObject(string Line, string Separator = "#//#") {
        vector<string> vAnimeData = clsString::split(Line, Separator);
        return clsAnime(vAnimeData[0], stoi(vAnimeData[1]));
    }

    static string _ConvertAnimeObjectToLine(clsAnime Anime, string Separator = "#//#") {
        return Anime.GetTitle() + Separator + to_string(Anime.GetStatus());
    }

    static clsMovie _ConvertLineToMovieObject(string Line, string Separator = "#//#") {
        vector<string> vMovieData = clsString::split(Line, Separator);
        return clsMovie(vMovieData[0], vMovieData[1]);
    }

    static string _ConvertMovieObjectToLine(clsMovie Movie, string Separator = "#//#") {
        return Movie.GetTitle() + Separator + Movie.GetDuration();
    }

    static clsSeries _ConvertLineToSeriesObject(string Line, string Separator = "#//#") {
        vector<string> vSeriesData = clsString::split(Line, Separator);
        return clsSeries(vSeriesData[0], vSeriesData[1]);
    }

    static string _ConvertSeriesObjectToLine(clsSeries Series, string Separator = "#//#") {
        return Series.GetTitle() + Separator + Series.GetSeasons();
    }

   public:
    static vector<clsAnime> LoadAnimesDataFromFile() {
        vector<clsAnime> vAnimes;
        string filePath = GetFilePath("Animes.txt");

        fstream MyFile(filePath, ios::in);
        if (MyFile.is_open()) {
            string Line;
            while (getline(MyFile, Line)) {
                vAnimes.push_back(_ConvertLineToAnimeObject(Line));
            }
            MyFile.close();
        } else {
            cerr << "Error: Could not open Animes file at " << filePath << endl;
        }

        return vAnimes;
    }

    static vector<clsMovie> LoadMoviesDataFromFile() {
        vector<clsMovie> vMovies;
        string filePath = GetFilePath("Movies.txt");

        fstream MyFile(filePath, ios::in);
        if (MyFile.is_open()) {
            string Line;
            while (getline(MyFile, Line)) {
                vMovies.push_back(_ConvertLineToMovieObject(Line));
            }
            MyFile.close();
        } else {
            cerr << "Error: Could not open Movies file at " << filePath << endl;
        }

        return vMovies;
    }

    static vector<clsSeries> LoadSeriesDataFromFile() {
        vector<clsSeries> vSeries;
        string filePath = GetFilePath("Series.txt");

        fstream MyFile(filePath, ios::in);
        if (MyFile.is_open()) {
            string Line;
            while (getline(MyFile, Line)) {
                vSeries.push_back(_ConvertLineToSeriesObject(Line));
            }
            MyFile.close();
        } else {
            cerr << "Error: Could not open Series file at " << filePath << endl;
        }

        return vSeries;
    }

    static void SaveNewAnime(const vector<clsAnime>& vAnime) {
        string filePath = GetFilePath("Animes.txt");
        fstream MyFile(filePath, ios::out);

        if (MyFile.is_open()) {
            for (const clsAnime& Anime : vAnime) {
                MyFile << _ConvertAnimeObjectToLine(Anime) << endl;
            }
            MyFile.close();
        } else {
            cerr << "Error: Could not save Animes file at " << filePath << endl;
        }
    }

    static void SaveNewMovie(const vector<clsMovie>& vMovie) {
        string filePath = GetFilePath("Movies.txt");
        fstream MyFile(filePath, ios::out);

        if (MyFile.is_open()) {
            for (const clsMovie& Movie : vMovie) {
                MyFile << _ConvertMovieObjectToLine(Movie) << endl;
            }
            MyFile.close();
        } else {
            cerr << "Error: Could not save Movies file at " << filePath << endl;
        }
    }

    static void SaveNewSeries(const vector<clsSeries>& vSeries) {
        string filePath = GetFilePath("Series.txt");
        fstream MyFile(filePath, ios::out);

        if (MyFile.is_open()) {
            for (const clsSeries& Series : vSeries) {
                MyFile << _ConvertSeriesObjectToLine(Series) << endl;
            }
            MyFile.close();
        } else {
            cerr << "Error: Could not save Series file at " << filePath << endl;
        }
    }
};
