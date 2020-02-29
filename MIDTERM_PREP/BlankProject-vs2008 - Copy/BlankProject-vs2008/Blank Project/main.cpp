/*
 * File: main.cpp
 * --------------
 * This is a blank C++ source file.
 */

#include <iostream>
#include "console.h"
#include <string>
#include "simpio.h"
#include "stack.h"
#include "queue.h"
#include "vector.h"
#include "map.h"
#include "set.h"
#include "grid.h"
#include "tokenscanner.h"
#include "random.h"
#include "lexicon.h"
#include <math.h>
using namespace std;
#include <fstream>






















//
//struct Domino {
// int leftDots;
// int rightDots;
//};
//
//void rotateDomino(Domino& domino){
//	int temp = domino.rightDots;
//	domino.rightDots = domino.leftDots;
//	domino.leftDots = temp;
//}
//
//bool formsChain(Vector<Domino> &dominos, int s){
//	if(dominos.isEmpty()) 
//		return true;
//	for( int i = 0; i < dominos.size(); i++){
//		Domino nextDomino = dominos[i];
//		Vector<Domino> rest = dominos;
//		rest.remove(i);
//		if(s == -1 || nextDomino.leftDots == s){ 
//			if(formsChain(rest, nextDomino.rightDots))
//				return true;
//		}
//		if(s == -1 || nextDomino.rightDots == s){
//			if(formsChain(rest, nextDomino.leftDots)){
//				return true;
//			}
//		}
//	}
//	return false;
//}
//
//bool formsDominoChain(Vector<Domino> &dominos){
//	int s = -1;
//	return formsChain(dominos, s);
//}
//
//int main(){
//	Domino d1;
//	Domino d2;
//	Domino d3;
//	Domino d4;
//	Domino d5;
//	d1.leftDots = 1;
//	d1.rightDots = 4;
//	d2.leftDots = 1;
//	d2.rightDots = 6;
//	d3.leftDots = 2;
//	d3.rightDots = 6;
//	d4.leftDots = 3;
//	d4.rightDots = 4;
//	d5.leftDots = 4;
//	d5.rightDots = 4;
//	Vector<Domino> dominos;
//	dominos.add(d1);
//	dominos.add(d2);
//	dominos.add(d3);
//	dominos.add(d4);
//	dominos.add(d5);
//	cout << formsDominoChain(dominos) << endl;
//	return 0;
//}
//

//
////
////int raiseIntToPower(int n, int k){
////	if( k == 0 )
////		return 1;
////	if( k == 1 )
////		return n;
////	if(k%2 == 0)
////		return raiseIntToPower(n, k/2) * raiseIntToPower(n, k/2);
////	if(k%2 == 1)
////		return raiseIntToPower(n, k/2) * raiseIntToPower(n, k/2) * n;
////}
//
//int main(){
//	cout << raiseIntToPower(2,4) << endl; // 16
//	cout << raiseIntToPower(3,3) << endl; // 27
//	return 0;
//}
//
//















//
//void rotate(Queue<char> &q, int k){
//	for(int i = 0; i < k; i++){
//		char next = q.dequeue();
//		q.enqueue(next);
//	}
//}
//
//void roll(Stack<char> &s, int n, int k){ // vushveb ro n da k orive aranegatiuria da n araa s.size()-ze meti.
//	Queue<char> q;
//	for(int i = 0; i < n; i++){
//		q.enqueue(s.pop());
//	}
//	cout << q.toString() << endl;
//	cout << s.toString() << endl;
//	rotate(q, k);
//	Stack<char> newS;
//	for(int i = 0; i < n; i++)
//		newS.push(q.dequeue());
//	for(int i = 0; i < n; i++)
//		s.push(newS.pop());
//	cout << s.toString() << endl;
//}
//
//int main(){
//	Stack<char> s;
//	s.push('a');
//	s.push('b');
//	s.push('c');
//	s.push('d');
//	roll(s, 3, 2);
//	return 0;
//}
















//bool canFrogEatFly(int frogPos, int flyPos, Vector<int>& jumpSizes, Set<int>& lilypads) {//	if(frogPos == flyPos)//		return true;//	for(int i = 0; i < jumpSizes.size(); i++){//		int jump = jumpSizes[i];//		jumpSizes.remove(i);//		if(lilypads.contains(frogPos + jump)){//			if(canFrogEatFly(frogPos + jump, flyPos, jumpSizes, lilypads))//				return true;//		} else if(lilypads.contains(frogPos-jump)){//			if(canFrogEatFly(frogPos-jump,flyPos,jumpSizes,lilypads)){//				return true;//			}//		} else {////		}//		jumpSizes.add(jump);//	}//	return false;//}////
//int main() {
//	Vector<int> jumpSizes;
//	jumpSizes.add(2);
//	jumpSizes.add(4);
//
//	Set<int> lilypads;
//	lilypads.add(1);
//	lilypads.add(4);
//	lilypads.add(6);
//	lilypads.add(7);
//	lilypads.add(9);
//	cout << canFrogEatFly(1, 7, jumpSizes, lilypads) << endl;
//	return 0;
//}

//Vector<string> balancedStringsOfLength(int n){
//	Vector<string> result;
//	if(n == 0)
//		result += "";
//		return result;
//	for(int i = 0; i < n, i++) {
//		foreach(string one in balanced(i)){
//			foreach(string two in balanced(n-i-1)){
//				result += "(" + one ")" + two;
//			}
//		}
//	}
//	return result;
//}
//
//int main(){
//	cout << balancedStringsOfLength(1).toString() << endl;
//	return 0;
//}


//Set<string> allPetsMatching(Map<string, Set<string> >& adjectiveMap, Vector<string>& requirements, Set<string>& pets, Set<string> &notchosen){
//	if(requirements.isEmpty() || pets.isEmpty())
//		return pets;
//	foreach(string dog in pets){
//		for(int i = 0; i < requirements.size(); i++){
//			if(!adjectiveMap[dog].contains(requirements[i])){
//				notchosen.add(dog);
//			}
//		}
//	}
//	return pets - notchosen;
//}
//
//Set<string> allPetsMatching(Map<string, Set<string> >& adjectiveMap, Vector<string>& requirements){
//	Set<string> pets;
//	foreach(string dog in adjectiveMap){
//		pets.add(dog);
//	}
//	cout << pets.toString() << endl;
//	Set<string> chosen;
//	return allPetsMatching(adjectiveMap, requirements, pets, chosen);	
//}
//
//int main(){
//	Vector<string> req;
//	req.add("a");
//	req.add("b");
//	Map<string, Set<string> > adjectiveMap;
//	Set<string> pet1;
//	pet1.add("a");
//	pet1.add("b");
//	Set<string> pet2;
//	pet2.add("a");
//	Set<string> pet3;
//	adjectiveMap.put("1 ", pet1);
//	adjectiveMap.put("2 ", pet2);
//	adjectiveMap.put("3 ", pet3);
//	cout << allPetsMatching(adjectiveMap, req).toString() << endl; 
//	return 0;
//}



















//string integerToString2(int n){
//	if(n >= 0 && n <= 9)
//		return string() + char('0' + n);
//	return integerToString(n/10) + char('0'+(n%10));
//}
//
//int stringToInteger2(string str){
//	if(str.size() == 1)
//		return str[0]-'0';
//	return int(10*stringToInteger(str.substr(0,str.length()-1))) + (str[str.length()-1]-'0');
//}
//
//int main(){
//	int n = getInteger();
//	string str = integerToString2(n);
//	cout << str << endl;
//	cout << stringToInteger2(str) << endl;
//	return 0;
//}

//string replaceAll(string s, char from, char to, string newS){
//	if(s.length()==0)
//		return newS;
//	char first = s[0];
//	if(first != from){
//		newS += first;
//	} else {
//		newS += to;
//	}
//	return replaceAll(s.substr(1), from, to, newS);
//}
//
//int main(){
//	cout << replaceAll("banana", 'a', 'o', "") << endl;
//	return 0;
//}

//void rec(string number, Lexicon &lex, Map<int, string> &map, string cur){
//	if(number.size() == 0 && lex.contains(cur)){
//		cout << cur << endl;
//	} else if (number.size() != 0){
//		int nextInt = number[0] - '0';
//		for(int i = 0; i < map[nextInt].size(); i++){
//			char nextChar = map[nextInt][i];
//			cur += nextChar;
//			if(lex.containsPrefix(cur)){
//				rec(number.substr(1), lex, map, cur);
//			}
//			cur = cur.substr(0, cur.size()-1);
//		}
//	}	
//}
//
//int main(){
//	Lexicon lex("EnglishWords.dat");
//	string cur = "";
//	string k2 = "abc";
//string k3 = "def";
//string k4 = "ghi";
//string k5 = "jkl";
//string k6 = "mno";
//string k7 = "pqrs";
//string k8 = "tuv";
//string k9 = "wxyz";
//Map<int,string> map;
//map.put(2, k2);
//map.put(3, k3);
//map.put(4, k4);
//map.put(5, k5);
//map.put(6, k6);
//map.put(7, k7);
//map.put(8, k8);
//map.put(9, k9);
//	rec("7874464",lex,map,cur);
//	return 0;
//}
//













//bool areHappyTogether(string& p1, string& p2){
//  if(p1[0] == p2[0])
//	  return true;
//  return false;
//}
//
//bool canSplitMerrily(Set<string>& people, int teamSize,Vector<Set<string>>& teams, int peopleSize){
//	if(teams.size() == int(peopleSize/teamSize)) {// davushvat ro yvela chavsvit teamshi
//		for(int i = 0; i < teams.size(); i++){
//			if(teams[i].size() != teamSize)
//				return false;
//		}
//		return true;
//	}
//	foreach(string person in people){
//		Set<string> peopleCopy = people;
//		peopleCopy.remove(person); 
//		if(teams.size() == 0){
//			Set<string> team;
//			team.add(person);
//			teams.add(team);
//			if(canSplitMerrily(peopleCopy, teamSize, teams, peopleSize))
//						return true;
//		} else if(teams[teams.size()-1].size() != teamSize) {// tuki tavisufali adgilia jgufshi
//			Set<string> team = teams[teams.size()-1]; // bolos chamatebuli;
//			bool canAdd = true;
//			foreach(string person2 in team){
//				if(!areHappyTogether(person, person2)){
//					canAdd = false;
//				} 
//			}
//			if(canAdd){
//				team.add(person);
//				teams.remove(teams.size()-1);
//				teams.add(team);
//				if(canSplitMerrily(peopleCopy, teamSize, teams, peopleSize))
//					return true;
//			}
//		} else { // shemdegi team unda chavamatot
//			Set<string> team;
//			team.add(person);
//			teams.add(team);
//			if(canSplitMerrily(peopleCopy, teamSize, teams, peopleSize))
//						return true;
//		}
//		
//	}
//	return false;
//}
//
//int main(){
//	Set<string> people;
//	people.add("adam");
//	people.add("eve");
//	people.add("evangelina");
//	people.add("keith"); //ais gamo return false iqneba. ro wavshalo - true
//	people.add("alex");
//	int teamsize = 2;
//	Vector<Set<string>> teams;
//	int s = people.size();
//	cout << canSplitMerrily(people, teamsize, teams, s) << endl;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
////void listPossiblePaymentsRec(int total, const Set<string>& people, const Map<string, int>& payments) {
////	/* Base case: if there's one person left, they have to pay the whole bill. */
////	if (people.size() == 1) {
////		Map<string, int> finalPayments = payments;
////		finalPayments[people.first()] = total;
////		cout << finalPayments << endl;
////	}
//// /* Recursive case: The first person has to pay some amount between 0 and the
//// * total amount. Try all of those possibilities.
//// */
////	 else {
////		for (int payment = 0; payment <= total; payment++) {
////			Map<string, int> updatedPayments = payments;
////			updatedPayments[people.first()] = payment;
////			listPossiblePaymentsRec(total – payment, people – people.first(),
////						 updatedPayments);
////		}
////	}
////	/*if(people.size() == 1){
////		Map<string, int> newPayments = payments;
//		newPayments[people.first()] = total;
//		cout << newPayments.toString() << endl;
//	} else {
//		for(int i = 0; i < total; i++){
//			Map<string, int> newPayments = payments;
//			newPayments[people.first()] = i;
//			Set<string> rest = people;
//			string deadPerson = rest.first();
//			rest.remove(deadPerson);
//			wrapper(total-i,rest,newPayments);
//		}
//	}*/
//}
//
//void listPossiblePayments(int total, const Set<string>& people) {
// listPossiblePaymentsRec(total, people, {});
//}
//
//int main(){
//	Set<string> people;
//	people.add("a");
//	people.add("b");
//	people.add("c");
//	listPossiblePayments(4,people);
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
////bool isShrinkable(const string& word, const Lexicon& english,
////				  Vector<string>& shrinkingSequence)	{
////	if (!english.contains(word)) return false;
////	Queue<Vector<string> > q;
////	shrinkingSequence.add(word);
////	q.enqueue(shrinkingSequence);
////	Set<string> used;
////	used.add(word);
////	while(!q.isEmpty()){
////		Vector<string> newVec = q.dequeue();
////		string consider = newVec[newVec.size()-1];
////		if(consider.size() == 1){
////			shrinkingSequence = newVec;
////			return true;
////		}
////		for(int i = 0; i < consider.size(); i++){
////			string next = consider.substr(0,i) + consider.substr(i+1);
////			if(english.contains(next) && !used.contains(next)){
////				used.add(next);
////				Vector<string> nextSequence = newVec;
////				nextSequence += next;
////				q.enqueue(nextSequence);
////			}
////		}
////	}
////	return false;
////}
////
////
////int main(){
////	cout << "welcome." << endl;
////	Vector<string> seq;
////	Lexicon lex("EnglishWords.dat");
////	if(isShrinkable("startling",lex,seq))
////		cout << seq.toString() << endl;
////	return 0;
////}
//
//
//
//
//
//
//
//
//
//
////void getEn(string digits, Set<string>& words, Lexicon& lex, Map<int, char>& map, string cur){
////	if(digits.size() == 0){
////		if(lex.contains(cur))
////			words.add(cur);
////	} else {
////		int nextChar = digits[0]-'0';
////		cur += map.get(nextChar);
////		if(lex.containsPrefix(cur)){
////			getEn(digits.substr(1),words,lex,map,cur);
////		}
////		if(digits.size() >= 2){
////			nextChar = (digits[0]-'0')*10+(digits[1]-'0');
////			cur = cur.substr(0,cur.size()-1);
////			cur+= map.get(nextChar);
////			if(lex.containsPrefix(cur)){
////				getEn(digits.substr(2),words,lex,map,cur);
////			}
////		}	
////	}
////}
////
////void getAllEncryption(string digits, Set<string>& words, Lexicon& lex){
////	Map<int, char> map;
////	for(int i = 1; i <= 26; i++){
////		map.put(i, 'a'+i-1);
////	}
////	string cur = "";
////	getEn(digits, words, lex, map, cur);	
////}
////
////int main(){
////	string digits = getLine(" : ");
////	Set<string> words;
////	Lexicon lexicon("EnglishWords.dat");
////	getAllEncryption(digits, words, lexicon);
////	cout << words.toString() << endl;
////	return 0;
////}
////
//////struct node{
//////	string str;
//////	int count;
//////}
//////
//////int findMin(Queue<string>& q, dst, node c){
//////	
//////}
//////
//////int minPath(string src, string dst){//min raodenoba gacvlebis romlitac miigeba dst scr-dan. abcdef
////	int result = -1;
////	Queue<dist> q;
////	node first;
////	first.str = node;
////	first.count = 0;
////	q.enqueue(first);
////	while(!q.isEmpty()){
////		node next = q.dequeue();
////		if(next.count == dst){
////				return next.count;	
////		}
////		for(int i = 0; i < next.str.size()-3; i++){
////			string nextWord = next.str.substr(0, i) +
////				next.str.substr(i+2,2) +
////					next.str.substr(i,2) + 
////						next.str.substr(i+4); // axali sityva vipovet
////			node second;
////			second.str = nextWord;
////			second.count = next.count+1;
////			q.enqueue(second);
////		}
////	}
////	return result;
////}
//
//
////
////enum position{
////	cross = 1,
////	neither = 0,
////	nought = -1
////};
////
////struct boardT {
////	Grid<position> grid;
////	position currentPlayer;
////};
////
////bool isGameOver(boardT &board, position &result){
////	bool result;
////	for(int i = 0; i < 3; i++){
////		for(int j = 0; j < 3; j++){
////			if(board.grid[i][j] == neither){
////				result == neither;
////				return false;
////			}
////		}	
////	}
////
////	return true;
////}
////
////int main(){
////
////	return 0;
////}
////
//////int main(){
////	Grid<bool> gr(4,4);
////	gr[0][0] = true;
////	gr[0][3] = true;
////	gr[2][1] = true;
////	gr[3][0] = true;
////	gr[1][2] = true;
////	gr[2][2]=true;
////	gr[1][1] = true;
////	gr[3][3]=true;
////	Vector<int> vector;
////	cout << hamilton(gr, vector) << endl;
////	return 0;
////}	
////
//////bool isConnected(Grid<bool> &gr, Vector<int> &v, int last){
//////	for(int i = 0; i < v.size(); i++){
//////		if(gr[v[i]][last] == false)
////			return false;
////	}
////	return true;
////}
////
////bool izqliq(Grid<bool> &gr, Vector<int> &v){
////	if(v.size() == 0)
////		return true;
////	int last = v[v.size()-1];
////	if(isConnected(gr, v, last)){
////		v.remove(v.size()-1);
////		bool result = izqliq(gr, v);
////	}
//	v.add(last);
//}
//
//bool existss(Grid<bool> &gr, int n, Vector<int> &s, int a){
//	if(s.size() == n)
//		return true;
//	if(a >= gr.nCols)
//		return false;
//	s.add(a);
//	if(izqliq(gr,s)) {
//		if(existss(gr,n,s,1+a))
//			return true;
//		if(existss(gr,n,s,2+a))
//			return true;
//	} else {
//		s.remove(s.size()-1);
//		a=a+1;
//		s.add(a);
//		return existss(gr,n,s,a);
//	}
//}
//
//bool exists(Grid<bool> &gr, int n){
//	Vector<int> selected;
//	int a = 0;
//	return existss(gr, n, selected, a);
//}
//
//int maxqliq(Grid<bool> &gr, Vector<int> &s, int max){
//	if(s.size() > gr.nCols)
//		return max;
//	max = s.size();
//	int lastIndex = 0;
//	if(s.size() != 0){
//		lastIndex = s[s.size()-1]+1; // ganxilulebi ro agar gadavamowmot.
//	}
//	for(int i = lastIndex; i < gr.nCols; i++){
//		s.add(i);
//		if(izqliq(gr, s)){
//			int newMax = maxqliq(gr,s, max);
//			if(newMax > max)
//				max = newMax;
//		}else{
//			
//		}
//		s.remove(s.size()-1);
//		
//	}
//	return max;
//}
//
//int maxqliqW(Grid<bool> &gr){
//	Vector<int> s;
//	int a = 0;
//	return maxqliq(gr, s, a);
//}
//
//int main(){
//	Grid<bool> gr(4,4);
//	gr[0][0] = true;
//	gr[0][3] = true;
//	gr[2][1] = true;
//	gr[3][0] = true;
//	gr[1][2] = true;
//	gr[2][2]=true;
//	gr[1][1] = true;
//	gr[3][3]=true;
//	Vector<int> v;
//	v.add(1);
//	v.add(2);
//	//v.add(3);
//	cout << gr.toString() << endl;
//	cout << izqliq(gr, v) << endl;
//	cout << exists(gr, 1) << endl;
//	cout << maxqliqW(gr) << endl;
//	return 0;
//}
