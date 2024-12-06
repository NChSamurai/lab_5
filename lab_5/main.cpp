#include<iostream>
#include <vector>
#include<fstream>
#include<string>
#include"Files.h"
using namespace std;

int main()
{
    cout<<"Choose the method: \n -- 1 \n -- 2 \n -- 4 \n -- 5 \n -- 6\n ---";
    int choice;
    int l;
    cin >> choice;
    char *name = "f.txt";
    switch (choice)
    {
        //1 task
        case 1:{
            cout << "Enter the length -- ";
            while(!(cin>>l) or (l < 0))
            {
                cout<<"Wrong !! Enter again !\n";
                cin.clear();
                cin.ignore();
                cout<<"Enter int : ";
            }
        Files::fillFile(name, l);
        Files::multiplyComponents(name);
        Files::readBin(name);
        cout << "\n";
        Files::readBin("multiplyComponentsFile.bin");
            break;}

        //2 task
        case 2: {
            cout << "Enter the length -- ";
            while(!(cin>>l) or (l < 0))
            {
                cout<<"Wrong !! Enter again !\n";
                cin.clear();
                cin.ignore();
                cout<<"Enter int : ";
            }
            int n;
            cout << "Enter the n -- ";
            while(!(cin>>n) or (n < 0) or (n*n < l))
            {
                cout<<"Wrong !! Enter again !\n";
                cin.clear();
                cin.ignore();
                cout<<"Enter int : ";
            }
            Files::fillFile(name, l);
            vector<vector<int>> V = (Files::fillMatrix( name, n));
            Files::printMatrix(V);
            cout << "---------------" << "\n";
            vector<vector<int>> changedV =  Files::changeMatrix(V);
            Files::printMatrix(changedV);
            break;
        }
        //4 task
        case 4: {
            cout << "Enter the length -- ";
            while(!(cin>>l) or (l < 0))
            {
                cout<<"Wrong !! Enter again !\n";
                cin.clear();
                cin.ignore();
                cout<<"Enter int : ";
            }
            Files::fillFileTxt(name, l);
            Files::fillNewFileTxt(name);
            break;
        }
        //5 task
        case 5: {
            cout << "Enter the length -- ";
            while(!(cin>>l) or (l < 0))
            {
                cout<<"Wrong !! Enter again !\n";
                cin.clear();
                cin.ignore();
                cout<<"Enter int : ";
            }
            Files::fillFileTxt2(name, l);
            Files::fillNewFileTxt2(name);
            break;
        }
        //6 task
        case 6:{
            cout << "Enter the letter -- ";
            string s;
            while(!(cin>>s) or (s.size() > 1))
            {
                cout<<"Wrong !! Enter again !\n";
                cin.clear();
                cin.ignore();
                cout<<"Enter string : ";
            }
        Files::readTxt("text.txt", s);
        break;
        }
        default:
            cout<<"Wrong number or unfinished task";
    }
    return 0;
}