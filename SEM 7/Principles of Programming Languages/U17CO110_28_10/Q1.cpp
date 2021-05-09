
#include <bits/stdc++.h>

using namespace std;

class Publication {
public:
        string title;
        float price;

        void getData() {
                cout << "Enter Title: ";
                cin >> title;
                cout << "Enter Price: ";
                cin >> price;
        }
};

class Book : public Publication {
public:
        int pageCount;

        void getDataBook() {
                cout<<"**********ENTER BOOK DATA*****************\n";
                Publication::getData();
                cout << "Enter pageCount: ";
                cin >> pageCount;
        }

        void putData() {
                cout<<"*************BOOK DATA ENTERED************\n";
                cout << "Title :" << Publication::title << endl;
                cout << "Price :" << Publication::price << endl;
                cout << "PageCount: " << pageCount << endl;
        }
};

class Tape : public Publication {
public:
        int playingTime;

        void getDataTape() {
                cout<<"*********ENTER CASSETTE DATA**************\n";
                Publication::getData();
                cout << "Enter playingTime: " << endl;
                cin >> playingTime;
        }

        void putData() {
                cout<<"*******ENTERED CASSETTE DATA***************\n";
                cout << "Title :" << Publication::title << endl;
                cout << "Price :" << Publication::price << endl;
                cout << "PlayingTime: " << playingTime << endl;
        }
};

int main() {

        Book book;
        book.getDataBook();
        book.putData();

        Tape tape;
        tape.getDataTape();
        tape.putData();
        return 0;
}
