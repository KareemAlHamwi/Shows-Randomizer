#pragma once

#include <iostream>

using namespace std;

class clsAnime {
   private:
    string _Title;
    enum enStatus { Incomplete = 0, Complete = 1 };
    enStatus _Status;

   public:

    clsAnime() {};

    clsAnime(string Title, int Status) {
        this->_Title = Title;
        this->_Status = (enStatus) Status;
    }

    string GetTitle() {
        return _Title;
    }

    enStatus GetStatus() {
        return _Status;
    }

    string GetStringStatus() {
        return (_Status == 0) ? "Incomplete" : "Complete";
    }

    void SetTitle(string Title) {
        this->_Title = Title;
    }

    void SetStatus(int Status) {
        this->_Status = (enStatus) Status;
    }
};
