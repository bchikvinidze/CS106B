/**********************************************************
 * File: HuffmanEncoding.cpp
 *
 * Implementation of the functions from HuffmanEncoding.h.
 * Most (if not all) of the code that you write for this
 * assignment will go into this file.
 */

#include "HuffmanEncoding.h"

/* Function: getFrequencyTable
 * Usage: Map<ext_char, int> freq = getFrequencyTable(file);
 * --------------------------------------------------------
 * Given an input stream containing text, calculates the
 * frequencies of each character within that text and stores
 * the result as a Map from ext_chars to the number of times
 * that the character appears.
 *
 * This function will also set the frequency of the PSEUDO_EOF
 * character to be 1, which ensures that any future encoding
 * tree built from these frequencies will have an encoding for
 * the PSEUDO_EOF character.
 */
Map<ext_char, int> getFrequencyTable(istream& file) {
	Map<ext_char, int> result;
	char nextCh;
	while(file.get(nextCh)){
		if(result.containsKey(nextCh))
			result.put(nextCh, result.get(nextCh) + 1);
		else
			result.put(nextCh, 1);
	}
	result.put(PSEUDO_EOF, 1);
	return result;	
}

/* Merges two pqueues of nodes as a part of creating an
 * encoding tree of Huffman. 
 */
void mergeQueues(Node* &pq1, Node* &pq2,
				 PriorityQueue<Node*> &singletonTrees){
	PriorityQueue<Node*> comboNodes;
	Node * newNode = new Node;
	newNode->weight = pq1->weight + pq2->weight;
	newNode->character = NOT_A_CHAR;
	newNode->one = pq2;
	newNode->zero = pq1;
	singletonTrees.enqueue(newNode, newNode->weight);
}

/* Creates an encoding tree using the Huffman algorithm. It assumes
 * to have a size of at least one, considering there is always a
 * pseudo EOF character at the end of a file. 
 */
Node* createTree(PriorityQueue<Node*> &singletonTrees){
	if(singletonTrees.size() == 1)
		return singletonTrees.dequeue();
	Node* pq1 = singletonTrees.dequeue();
	Node* pq2 = singletonTrees.dequeue();
	mergeQueues(pq1, pq2, singletonTrees);
	return createTree(singletonTrees);
}

/* Function: buildEncodingTree
 * Usage: Node* tree = buildEncodingTree(frequency);
 * --------------------------------------------------------
 * Given a map from extended characters to frequencies,
 * constructs a Huffman encoding tree from those frequencies
 * and returns a pointer to the root.
 *
 * This function can assume that there is always at least one
 * entry in the map, since the PSEUDO_EOF character will always
 * be present.
 */
Node* buildEncodingTree(Map<ext_char, int>& frequencies) {
	PriorityQueue<Node*> singletonTrees;
	foreach(ext_char ch in frequencies){
		Node * newNode = new Node;
		newNode->character = ch;
		newNode->weight = frequencies.get(ch);
		newNode->zero = NULL;
		newNode->one = NULL;
		singletonTrees.enqueue(newNode, newNode->weight);
	}
	return createTree(singletonTrees);
}

/* Function: freeTree
 * Usage: freeTree(encodingTree);
 * --------------------------------------------------------
 * Deallocates all memory allocated for a given encoding
 * tree.
 */
void freeTree(Node* root) {
	if(root != NULL){
		freeTree(root->zero);
		freeTree(root->one);
		delete root;
	}
}

/* Shows if this is the correct path towards finding the letter in the tree. */
bool pathFound(Node* encodingTree, ext_char ch){
	if(encodingTree == NULL)
		return false;
	if(encodingTree->character == ch || pathFound(encodingTree->zero, ch) 
		|| pathFound(encodingTree->one, ch))
		return true;
	return false;
}

/* Returns the code generated from a file using a Huffman algorithm. */
string getCode(Node* encodingTree, string result, ext_char ch){
	if(encodingTree == NULL)
		return "";
	if(encodingTree->character == ch)
		return result;
	if(pathFound(encodingTree->zero, ch))
		return getCode(encodingTree->zero, result + '0', ch);
	else 
		return getCode(encodingTree->one, result + '1', ch);
}

/* Function: encodeFile
 * Usage: encodeFile(source, encodingTree, output);
 * --------------------------------------------------------
 * Encodes the given file using the encoding specified by the
 * given encoding tree, then writes the result one bit at a
 * time to the specified output file.
 *
 * This function can assume the following:
 *
 *   - The encoding tree was constructed from the given file,
 *     so every character appears somewhere in the encoding
 *     tree.
 *
 *   - The output file already has the encoding table written
 *     to it, and the file cursor is at the end of the file.
 *     This means that you should just start writing the bits
 *     without seeking the file anywhere.
 */ 
void encodeFile(istream& infile, Node* encodingTree, obstream& outfile) {
	char ch;
	string code;
	while(infile.get(ch)){
		string result;
		code += getCode(encodingTree, result, ext_char(ch));
	}
	code += getCode(encodingTree, "", PSEUDO_EOF);
	for(int i = 0; i < code.size(); i++)
		outfile.writeBit(code[i]-'0');
}

/* Function: decodeFile
 * Usage: decodeFile(encodedFile, encodingTree, resultFile);
 * --------------------------------------------------------
 * Decodes a file that has previously been encoded using the
 * encodeFile function.  You can assume the following:
 *
 *   - The encoding table has already been read from the input
 *     file, and the encoding tree parameter was constructed from
 *     this encoding table.
 *
 *   - The output file is open and ready for writing.
 */
void decodeFile(ibstream& infile, Node* encodingTree, ostream& file) {
	string result = "";
	Node* current = encodingTree;
	while(true){
		int next = infile.readBit();
		if(next == 0)
			current = current->zero;
		else
			current = current->one;
		if(current->character == PSEUDO_EOF)
			break;
		if(current->character != NOT_A_CHAR){
			result += char(current->character);
			current = encodingTree;
		}
	}
	for(int i = 0; i < result.size(); i++)
		file.put(result[i]);
}

/* Function: writeFileHeader
 * Usage: writeFileHeader(output, frequencies);
 * --------------------------------------------------------
 * Writes a table to the front of the specified output file
 * that contains information about the frequencies of all of
 * the letters in the input text.  This information can then
 * be used to decompress input files once they've been
 * compressed.
 *
 * This function is provided for you.  You are free to modify
 * it if you see fit, but if you do you must also update the
 * readFileHeader function defined below this one so that it
 * can properly read the data back.
 */
void writeFileHeader(obstream& outfile, Map<ext_char, int>& frequencies) {
	/* The format we will use is the following:
	 *
	 * First number: Total number of characters whose frequency is being
	 *               encoded.
	 * An appropriate number of pairs of the form [char][frequency][space],
	 * encoding the number of occurrences.
	 *
	 * No information about PSEUDO_EOF is written, since the frequency is
	 * always 1.
	 */
	 
	/* Verify that we have PSEUDO_EOF somewhere in this mapping. */
	if (!frequencies.containsKey(PSEUDO_EOF)) {
		error("No PSEUDO_EOF defined.");
	}
	
	/* Write how many encodings we're going to have.  Note the space after
	 * this number to ensure that we can read it back correctly.
	 */
	outfile << frequencies.size() - 1 << ' ';
	
	/* Now, write the letter/frequency pairs. */
	foreach (ext_char ch in frequencies) {
		/* Skip PSEUDO_EOF if we see it. */
		if (ch == PSEUDO_EOF) continue;
		
		/* Write out the letter and its frequency. */
		outfile << char(ch) << frequencies[ch] << ' ';
	}
}

/* Function: readFileHeader
 * Usage: Map<ext_char, int> freq = writeFileHeader(input);
 * --------------------------------------------------------
 * Reads a table to the front of the specified input file
 * that contains information about the frequencies of all of
 * the letters in the input text.  This information can then
 * be used to reconstruct the encoding tree for that file.
 *
 * This function is provided for you.  You are free to modify
 * it if you see fit, but if you do you must also update the
 * writeFileHeader function defined before this one so that it
 * can properly write the data.
 */
Map<ext_char, int> readFileHeader(ibstream& infile) {
	/* This function inverts the mapping we wrote out in the
	 * writeFileHeader function before.  If you make any
	 * changes to that function, be sure to change this one
	 * too!
	 */
	Map<ext_char, int> result;
	
	/* Read how many values we're going to read in. */
	int numValues;
	infile >> numValues;
	
	/* Skip trailing whitespace. */
	infile.get();
	
	/* Read those values in. */
	for (int i = 0; i < numValues; i++) {
		/* Get the character we're going to read. */
		ext_char ch = infile.get();
		
		/* Get the frequency. */
		int frequency;
		infile >> frequency;
		
		/* Skip the space character. */
		infile.get();
		
		/* Add this to the encoding table. */
		result[ch] = frequency;
	}
	
	/* Add in 1 for PSEUDO_EOF. */
	result[PSEUDO_EOF] = 1;
	return result;
}

/* Function: compress
 * Usage: compress(infile, outfile);
 * --------------------------------------------------------
 * Main entry point for the Huffman compressor.  Compresses
 * the file whose contents are specified by the input
 * ibstream, then writes the result to outfile.  Your final
 * task in this assignment will be to combine all of the
 * previous functions together to implement this function,
 * which should not require much logic of its own and should
 * primarily be glue code.
 */
void compress(ibstream& infile, obstream& outfile) {
	Map<ext_char, int> frequencyTable = getFrequencyTable(infile);
	writeFileHeader(outfile, frequencyTable);
	Node* huffmanTree = buildEncodingTree(frequencyTable);
	infile.rewind();
	encodeFile(infile, huffmanTree, outfile);
	freeTree(huffmanTree);
}

/* Function: decompress
 * Usage: decompress(infile, outfile);
 * --------------------------------------------------------
 * Main entry point for the Huffman decompressor.
 * Decompresses the file whose contents are specified by the
 * input ibstream, then writes the decompressed version of
 * the file to the stream specified by outfile.  Your final
 * task in this assignment will be to combine all of the
 * previous functions together to implement this function,
 * which should not require much logic of its own and should
 * primarily be glue code.
 */
void decompress(ibstream& infile, ostream& outfile) {
	Map<ext_char, int> frequencyTable = readFileHeader(infile);
	Node* huffmanTree = buildEncodingTree(frequencyTable);
	decodeFile(infile, huffmanTree, outfile);
	freeTree(huffmanTree);
}

