//
// Created by B-ZONE on 05.12.2024.
//

#ifndef LAB_5_FILES_H
#define LAB_5_FILES_H
#include<iostream>
#include<fstream>
#include<string>
#include <vector>
using namespace std;

class Files {


public:
    Files();

    static void printMatrix(vector<vector<int>>);

    static void fillFile(char* filename, int length);

    static void fillFileTxt(char* filename, int length);

    static void fillFileTxt2(char* filename, int length);

    static void fillNewFileTxt2(char* name);

    static void fillNewFileTxt(char* filename);

    static void readTxt(char* filename, string last);

    static void multiplyComponents(char* name);

    static void readBin(char* name);

    static vector<vector<int>> changeMatrix(vector<vector<int>> matrix);

    static vector<vector<int>> fillMatrix(char* name, int n);
};


#endif //LAB_5_FILES_H
