#pragma once
#include <iostream>
using namespace std;

class clsSeries {
   private:
    string _Title;
    string _Seasons;

   public:
    clsSeries() {};

    clsSeries(string Title, string Seasons) {
        this->_Title = Title;
        this->_Seasons = Seasons;
    }

    string GetTitle() {
        return _Title;
    }

    string GetSeasons() {
        return _Seasons;
    }

    void SetTitle(string Title) {
        this->_Title = Title;
    }

    void SetSeasons(string Seasons) {
        this->_Seasons = Seasons;
    }
};
