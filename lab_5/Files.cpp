//
// Created by B-ZONE on 05.12.2024.
//
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#include "Files.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sstream>


void Files::readBin(char* name){
    ifstream fileStream4;
    fileStream4.open(name, ios::binary);

    fileStream4.seekg(0, ios::end);
    streamsize fileSize = fileStream4.tellg(); // Получение размера файла
    fileStream4.seekg(0, ios::beg); // Возврат указателя в начало файла
    size_t elementCount = fileSize / sizeof(int);

    int a1;
    for (size_t i = 0; i < elementCount; ++i){
        fileStream4.read(reinterpret_cast<char*>(&a1), sizeof(a1));
        cout << a1 << " ";}
    fileStream4.close();
}

void Files::printMatrix(vector<vector<int>> matrix){
    int x = matrix.size();
    for (int i = 0; i < x; ++i){
        for (int j = 0; j < x; ++j){
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

}



Files::Files(){}

void Files::fillFile(char* name, int length){
    fstream fileStream3(name, ios::out | ios::binary);

    srand(static_cast<unsigned int>(std::time(nullptr)));


    for (size_t i = 0; i < length; ++i) {
        int randomNumber = std::rand() % 201 - 100;
        fileStream3.write(reinterpret_cast<const char*>(&randomNumber), sizeof(randomNumber));
    }
    fileStream3.close();
}

void Files::multiplyComponents(char* name){
    ifstream fileStream;
    fileStream.open(name, ios::binary);

    if (fileStream){
        ofstream fileStream2("multiplyComponentsFile.bin", ios::out | ios::binary);
        int a;
        int b;

        fileStream.seekg(0, std::ios::end);
        streamsize fileSize = fileStream.tellg();
        fileStream.seekg(0, std::ios::beg);
        size_t Count = fileSize / sizeof(int);

        fileStream.read(reinterpret_cast<char*>(&b), sizeof(b));

        for (size_t i = 0; i < Count - 1; ++i){
        fileStream.read(reinterpret_cast<char*>(&a), sizeof(a));
        int c = a * b;
        fileStream2.write(reinterpret_cast<const char*>(&c), sizeof(c));
            b = a;}
        fileStream.close();
        fileStream2.close();
    }
    else
        cout << "Wrong file name";
}

vector<vector<int>> Files::fillMatrix(char* name, int n) {
    vector<vector<int>> matrix;
    vector<int> fileData;

    ifstream fileStream;
    fileStream.open(name, ios::binary);

    fileStream.seekg(0, ios::end);
    streamsize fileSize = fileStream.tellg(); // Получение размера файла
    fileStream.seekg(0, ios::beg); // Возврат указателя в начало файла
    size_t elementCount = fileSize / sizeof(int);

    int a1;
    for (size_t i = 0; i < n * n; ++i) {
        if (i < elementCount) {
            fileStream.read(reinterpret_cast<char *>(&a1), sizeof(a1));
            fileData.push_back(a1);
        } else
            fileData.push_back(0);
    }

    for (int i = 0; i < n; i++) {
        vector<int> line;
        for (int j = 0; j < n; j++) {
            line.push_back(fileData[j + i * n]);

        }

        matrix.push_back(line);
    }
    return matrix;
}

vector<vector<int>> Files::changeMatrix(vector<vector<int>> matrix){
    int s = matrix.size();
    for (int x = 0; x < s; ++x) {
        int minn = matrix[x][x];
        int maxx = matrix[x][x];
        int x1;


        for (int i = 0; i < s; i++) {
            if (matrix[i][x] < minn) {
                minn = matrix[i][x];
                x1 = i;
            }
        }
        for (int j = 0; j < s; j++) {
            if (matrix[x][j] > maxx){
                maxx = matrix[x][j];

            }
        }
        matrix[x1][x] = maxx;
    }
    return matrix;



}
void Files::fillFileTxt(char* name, int length){
    ofstream fileStream3(name );

    srand(static_cast<unsigned int>(std::time(nullptr)));


    for (size_t i = 0; i < length; ++i) {
        int randomNumber = rand() % 201 - 100;
        fileStream3 << randomNumber << "\n";
    }

    fileStream3.close();
}

void Files::fillNewFileTxt(char* name){
    ifstream fileStream;
    fileStream.open(name);
    ofstream fileStream2("new_f.txt");

    int a;
    while(fileStream >> a){
        int c = a + 1;
        fileStream2 << c << "\n";
    }

    fileStream.close();
    fileStream2.close();
}

void Files::fillFileTxt2(char* name, int length){
    ofstream fileStream3(name );

    srand(static_cast<unsigned int>(std::time(nullptr)));


    for (size_t i = 0; i < length; ++i) {
        for (size_t i = 0; i < length; ++i) {
        int randomNumber = rand() % 201 - 100;
        fileStream3 << randomNumber << " ";}
        fileStream3 << "\n";
    }

    fileStream3.close();
}

void Files::fillNewFileTxt2(char* name) {
    ifstream fileStream;
    fileStream.open(name);
    ofstream fileStream2("new_f.txt");

    string a;
    while (getline(fileStream, a)) {
        istringstream iss(a);
        int c;
        iss >> c;
        int firstC = c;
        iss >> c;
        int minC = c ;
        while (iss >> c) {
            if (c < minC){
                minC = c;}
        }
        fileStream2 << (firstC + minC) << "\n";

    }
    fileStream.close();
    fileStream2.close();
}

void Files::readTxt(char* name, string last){
    ifstream fileStream;
    fileStream.open(name);
    ofstream fileStream2("new_f.txt");

    string a;
    while (getline(fileStream, a)) {
        string lastL;
        lastL = a.back();
        if (lastL == last){
            fileStream2 << a << "\n";
        }

    }
    fileStream.close();
    fileStream2.close();
}
