#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct ID3v1Tag {
    char title[31];
    char artist[31];
    char album[31];
    char year[5];
    char comment[31];
    char genre;
};

void readID3v1Tag(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cout << "Ошибка открытия файла." << endl;
        return;
    }
    
    file.seekg(-128, ios::end);
    
    char tag[4];
    file.read(tag, 3);
    tag[3] = '\0';
    if (strcmp(tag, "TAG") != 0) {
        cout << "Тег ID3v1 не найден в файле." << endl;
        return;
    }
    
    ID3v1Tag id3v1Tag;
    
    file.read(id3v1Tag.title, 30);
    file.read(id3v1Tag.artist, 30);
    file.read(id3v1Tag.album, 30);
    file.read(id3v1Tag.year, 4);
    file.read(id3v1Tag.comment, 30);
    file.read(&id3v1Tag.genre, 1);
    
    cout << "Альбом: " << id3v1Tag.album << endl;
    cout << "Исполнитель: " << id3v1Tag.artist << endl;
    cout << "Год: " << id3v1Tag.year << endl;
    
    file.close();
}

int main() {
    string filename = "example.mp3";
    readID3v1Tag(filename);
    
    return 0;
}