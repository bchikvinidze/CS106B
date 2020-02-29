/*
 * File: InverseGenetics.cpp
 * --------------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Inverse Genetics problem
 * on Assignment #3.
 * [TODO: extend the documentation]
 */

#include <iostream>
#include <string>
#include <fstream>
#include "set.h"
#include "map.h"
#include "console.h"
#include "simpio.h"
using namespace std;

/* Initializing constants */
const int CODON_LENGTH = 3;

/* Lists all RNA strads that could generate a protein recursively */
void listRNAStrandsFor(string protein, Map<char, Set<string> >& codons, string& soFar) {
	if(soFar.length() == protein.length() * CODON_LENGTH) {
		cout << soFar << endl;
	} else foreach(string codon in codons.get(protein[soFar.length()/CODON_LENGTH])) {
		listRNAStrandsFor(protein, codons, soFar + codon);
	}
}

/* Function: listAllRNAStrandsFor(string protein,
 *                                Map<char, Set<string> >& codons);
 * Usage: listAllRNAStrandsFor("PARTY", codons);
 * ==================================================================
 * Given a protein and a map from amino acid codes to the codons for
 * that code, lists all possible RNA strands that could generate
 * that protein. This is a wrapper function.
 */
void listAllRNAStrandsFor(string protein, Map<char, Set<string> >& codons){
	string soFar = "";
	listRNAStrandsFor(protein, codons, soFar);
}

/* Function: loadCodonMap();
 * Usage: Map<char, Lexicon> codonMap = loadCodonMap();
 * ==================================================================
 * Loads the codon mapping table from a file.
 */
Map<char, Set<string> > loadCodonMap();

int main() {
    Map<char, Set<string> > codons = loadCodonMap();
	string protein;
	do{
		protein = getLine("Enter protein: ");
	} while (protein.size() == 0);
	listAllRNAStrandsFor(protein, codons);
    return 0;
}

/* You do not need to change this function. */
Map<char, Set<string> > loadCodonMap() {
    ifstream input("codons.txt");
    Map<char, Set<string> > result;

    /* The current codon / protein combination. */
    string codon;
    char protein;

    /* Continuously pull data from the file until all data has been
     * read.
     */
    while (input >> codon >> protein) {
        result[protein] += codon;
    }

    return result;
}
