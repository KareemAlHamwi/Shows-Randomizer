#pragma once
#include <iostream>
using namespace std;

class clsMovie {
   private:
    string _Title;
    string _Duration;

   public:
    clsMovie() {};

    clsMovie(string Title, string Duration) {
        this->_Title = Title;
        this->_Duration = Duration;
    }

    string GetTitle() {
        return _Title;
    }

    string GetDuration() {
        return _Duration;
    }

    void SetTitle(string Title) {
        this->_Title = Title;
    }

    void SetDuration(string Duration) {
        this->_Duration = Duration;
    }
};
