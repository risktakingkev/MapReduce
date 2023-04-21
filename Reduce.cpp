/*

Humberto Dominguez
Professor Scott Roueche
CSE 687- Object Oriented Design
Syracuse University
Phase 1 - Reduce Header
4/20/2023

This class was created in part of creating the MapReduce code for Phase 1 for
CSE 687. The Reduce class's primary purpose is to consolidate all of the data that has been gather thus far.

Since this is the cpp portion of the class, this will define how and where the the member and methods will be 
used.  
*/

//libraries that will be used in this class
#include "Reduce.h"



//Constructor. Creation of the class
Reduce::Reduce() {

}

//Constructor with one arguement. Creation of the class
Reduce::Reduce(string outputDirectoryLocation) : outputDir{outputDirectoryLocation}
{}

//Constructor. Creation of the class
Reduce::~Reduce() {

}


//reduce method. Iterators through the vector and sums up all of the occurences
bool Reduce::reduce (string word, std::vector<int> occurences){
    int sizeOfOccurence = occurences.size(); // returns an integer value for the size of the vector
    int totalOccurences = 0; // variable to store the total amount of time a word was used

    //for loop used to iterate through each element of the vector
    for (auto & timesUsed : occurences){
        totalOccurences += timesUsed; //each time through the loop, we are recording how many times the word was said
    }


    return true;
}


bool Reduce::export(string key, int reducedValue){

    string consolidatedKeyAndValue = outputDir+key+".txt"; //Creates a text doc with the key and the amount of times it was used
    ofstream file(consolidatedKeyAndValue); //creates a text file in the specified location
    file << key << " " << reducedValue; //writes the key and the value pair
    file.close(); //closes the doc

    string successFile = outputDir+key+"_SUCCESS.txt"; //Creates a txt file for the success notification
    ofstream file2(successFile); //creates a text file in the specified location
    file.close(); //closes the doc

    return 1;
}


void Reduce::setoutputDir(){
    	cout << "Please type in the Directory that you would like the files to be save in.: "; //asking the user which directory they would like their file to be saved in
        cin >> outputDir;
}

string Reduce::getoutputDir(){
    return outputDir;
}