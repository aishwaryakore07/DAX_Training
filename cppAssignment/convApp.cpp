#include<iostream>
// #include<unistd.h>
// #include <getopt.h>
// #include <boost/algorithm/string/trim.hpp>
#include<bits/stdc++.h>
#include <algorithm>
#include <fstream>
#include <string>
#include <getopt.h>

#define no_argument 0
#define required_argument 1 
#define optional_argument 2
using namespace std;

class convApp{
    public:
    vector<vector<string>> inputMatrix;

    string removeSpaces(string str)
    {
        str.erase(remove(str.begin(), str.end(), ' '), str.end());
        return str;
    }

    void pushVec(string s[]){
        int k=0;
        for (int i = 0; i < 1; i++)
        {
            vector<string> v;
            for (int j = 0; j < 9; j++) {
                s[k] = removeSpaces(s[k]);
                v.push_back(s[k++]);
            }
            inputMatrix.push_back(v);
        }
    }

    void readFileOperation(string fileName){
        string myText;

        ifstream MyReadFile(fileName);
        string tempArray[45];
        while(getline (MyReadFile, myText)){
            cout << myText<<endl;
            string temp;
            string tempArray[9];
            int k=0;
            temp = myText.substr(0,15);
            tempArray[k++] = temp;

            temp = myText.substr(14,15);
            tempArray[k++] = temp;

            temp = myText.substr(29,15);
            tempArray[k++] = temp;

            temp = myText.substr(44,10);
            tempArray[k++] = temp;

            temp = myText.substr(54,5);
            tempArray[k++] = temp;

            temp = myText.substr(59,20);
            tempArray[k++] = temp;

            temp = myText.substr(79,15);
            tempArray[k++] = temp;

            temp = myText.substr(94,15);
            tempArray[k++] = temp;

            temp = myText.substr(109,7);
            tempArray[k++] = temp;

            pushVec(tempArray);
            
        }
        // envelopeFormat(inputMatrix);
        // for (int i = 0; i < inputMatrix.size(); i++)
        //     {
        //         for (int j = 0; j < inputMatrix[i].size(); j++)
        //         {
        //             cout << inputMatrix[i][j] ;
        //         }    
        //         cout << endl;
        //     }
    }

    void envelopeFormat(vector<vector<string>> inputMatrix){
        fstream fstream_ob;
        fstream_ob.open("envelopeFormatOutput.txt", ios::app);
        for(int i=0;i<5;i++){
            fstream_ob << inputMatrix[i][0] << " ";
            fstream_ob << inputMatrix[i][1] << endl;
            fstream_ob << inputMatrix[i][4] << " ";
            fstream_ob << inputMatrix[i][5] << endl;
            fstream_ob << inputMatrix[i][6] << "," << " " << inputMatrix[i][7] << " " << inputMatrix[i][8]<<"\n\n";
        }
        fstream_ob.close();
    }

    void fixedFormat(){
        fstream fstream_ob;
        fstream_ob.open("fixedFormatOutput.txt", ios::app);
        for(int i=0;i<5;i++){
            fstream_ob << inputMatrix[i][1] << " " << inputMatrix[i][0] << "\t\t" <<  inputMatrix[i][4] << " " << inputMatrix[i][5] << "\t\t" << inputMatrix[i][6] << ", " << inputMatrix[i][7] << " " << inputMatrix[i][8] << "\n\n";
        }
        fstream_ob.close();
    }

    void csvFormat(){
        fstream fstream_ob;
        fstream_ob.open("csvFormatOutput.txt", ios::app);
        for(int i=0;i<5;i++){
            fstream_ob << "\"" << inputMatrix[i][1] << " " << inputMatrix[i][0] << "\"" << "," << "\"" << inputMatrix[i][4] << " " << inputMatrix[i][5] << "\"" << "," <<  "\"" << inputMatrix[i][6] << "," << " " << inputMatrix[i][7] << " "  << inputMatrix[i][8] << "\"" << "\n\n";
        }
        fstream_ob.close();
    }
};
int main(int argc, char *argv[]){
    
    convApp ca;
    const struct option longopts[] =
    {
        {"input_file", required_argument, 0, 'i'},
        {"output_format", required_argument, 0, 'f'},
        {0,0,0,0},
    };
    int index;
    int iarg=0;
    string hello = "hello";
    opterr=1; 
    string inputFile, outputFormat;
    while(iarg != -1)
    {
        iarg = getopt_long(argc, argv, "i:f:", longopts, &index);

        switch (iarg)
        {
            case 'i':
            // cout << "The input file is: " << optarg << endl;
            inputFile = optarg;
            // ca.readFileOperation(optarg);
            break;

            case 'f':
            // cout << "Output file is: " << optarg << endl;
            outputFormat = optarg;
            break;

      }
    }
    cout<<"input file: "<< inputFile<<endl;;
    cout<<"output format: "<<outputFormat<<endl;
    switch(inputFile){
        case 'envelope':
            

    }

//     convApp ca;
//     ca.readFileOperation();
//     ca.envelopeFormat();
//     ca.fixedFormat();
//     ca.csvFormat();
}
    
