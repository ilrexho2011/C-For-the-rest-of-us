/*
 *----------------------------------------------------
 *      Homework Assignment #9: The String Class
 *----------------------------------------------------
*/

#include <iostream>
#include <string>

using namespace std;

string truncate(string str) {

    string retVal = str;
    int lastPos = retVal.length() - 1;

    bool found = true;

    while(found == true && lastPos >= 0) {
        if(retVal.substr(lastPos, 1) == " ") {
            retVal = retVal.erase(lastPos, 1);
        } else if(retVal.substr(0, 1) == " ") {
            retVal = retVal.erase(0, 1);
        } else {
            found = false;
        }
        lastPos = retVal.length() - 1;
    }
    return retVal;
}

int main()
{
    while(true) {
        cout << "Enter a track or 'q' to quit." << endl;
        string fullName = "";
        getline(cin, fullName);
        if(fullName == "q") {
            break;
        } else if (fullName.length() < 5){
            cout << "Please enter a track with more then five characters" << endl;
        } else {
            string artist = "";
            string title = "";
            size_t founded = fullName.find(":");
            if(founded != string::npos) {
                artist = truncate(fullName.substr(0, founded));
                title = truncate(fullName.substr(founded + 1, fullName.length() - founded));
            } else {
                founded = fullName.find("-");
                if(founded != string::npos) {
                    title = truncate(fullName.substr(0, founded - 1));
                    artist = truncate(fullName.substr(founded + 1, fullName.length() - founded - 1));
                } else {
                    int pos = -1;
                    founded = fullName.find("by");

                    // Continuous Looping until the last occurrence of 'by'
                    while(founded != string::npos) {
                        if(fullName.at(founded - 1) == ' ' && fullName.at(founded + 2) == ' ') {
                            pos = founded;
                        }
                        founded = fullName.find("by", founded + 2);
                    }
                    if(pos != -1) {
                        title = truncate(fullName.substr(0, pos - 1));
                        artist = truncate(fullName.substr(pos + 2, fullName.length() - pos - 1));
                    } else {                            // Teats all other options remained
                        cout << "Bad input" << endl;
                        title = "Empty";
                        artist = "Empty";
                    }
                }
            }
            cout << "TITLE: " << title << endl;
            cout << "ARTIST: " << artist << endl;
            cout << endl;
        }
    }
    return 0;
}
