/*
 * File: UniversalHealthCoverage.cpp
 * ----------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the UniversalHealthCoverage problem
 * on Assignment #3.
 * [TODO: extend the documentation]
 */
#include <iostream>
#include <string>
#include "set.h"
#include "vector.h"
#include "console.h"
#include "simpio.h"
#include "map.h"
using namespace std;

/* Takes a hospital for consideration to further check whether it will be involved 
	as one of the hospitals in the answer */
void considerHospital(Set<string>& cities, Vector< Set<string> >& locations,
                              Vector< Set<string> >& result, Set<string>& hospital, int i) {
	foreach(string city in hospital) {
		cities.remove(city);
	}
	result.add(hospital);
	locations.remove(i);
}

/* Checks if the city is covered by any of the chosen hospitals*/
bool cityCovered(string city, Vector< Set<string> >& result) {
	for(int i = 0; i < result.size(); i++) {
		if(result[i].contains(city)) return true;
	}
	return false;
}

/* This function reverses the considerHospital() function. This means that 
	the hospital in discussion was not included in the answer */
void unConsiderHospital(Set<string>& cities, Vector< Set<string> >& locations,
                              Vector< Set<string> >& result, Set<string>& hospital) {
	result.remove(result.size() - 1);
	locations.insert(0, hospital);
	foreach(string city in hospital){ 
		if(!cityCovered(city, result)) 
			cities.add(city); 
	}
}

/* Function: canOfferUniversalCoverage(Set<string>& cities,
 *                                     Vector< Set<string> >& locations,
 *                                     int numHospitals,
 *                                     Vector< Set<string> >& result);
 * Usage: if (canOfferUniversalCoverage(cities, locations, 4, result)
 * ==================================================================
 * Given a set of cities, a list of what cities various hospitals can
 * cover, and a number of hospitals, returns whether or not it's
 * possible to provide coverage to all cities with the given number of
 * hospitals.  If so, one specific way to do this is handed back in the
 * result parameter. This is a wrapper function for the canCover function.
 */
bool canOfferUniversalCoverage(Set<string>& cities, Vector< Set<string> >& locations,
                               int numHospitals, Vector< Set<string> >& result){ // yvelas vasheneb :((
	if(cities.isEmpty()) return true;
	if(numHospitals <= 0) return false;
	numHospitals--;
	bool res = false;
	for(int i = 0; i < locations.size(); i++) {
		Set<string> hospital = locations[i];
		considerHospital(cities, locations, result, hospital, i);
		res = canOfferUniversalCoverage(cities, locations, numHospitals, result);
		if(res) return true;
		unConsiderHospital(cities, locations, result, hospital);
	}
	return res;
}


int main() {
	/* example which was also given in the assignment PDF file */
	Set<string> cities;
	for(char ch = 'A'; ch <= 'F'; ch++) {
		cities.add(string() + ch);
	}
	Vector< Set<string> > locations;
	Set<string> h1, h2, h3, h4, h5;
	h1.add("A");
	h1.add("B");
	h1.add("C");

	h2.add("A");
	h2.add("C");
	h2.add("D");

	h3.add("B");
	h3.add("F");

	h4.add("C");
	h4.add("E");
	h4.add("F");

	h5.add("A");
	h5.add("B");
	h5.add("C");
	h5.add("D");

	locations.add(h1);
	locations.add(h2);
	locations.add(h3);
	locations.add(h4);
	locations.add(h5);

	int numHospitals = 4;
	Vector< Set<string> > result;
	cout << canOfferUniversalCoverage(cities, locations, numHospitals, result) << endl;
	if(result.size() != 0) cout << result.toString() << endl;
    return 0;
}
