// Dictionary.h -- declaration of Dictionary,			//
// what based on AVL-Tree structure 					//
// -----------------------------------------------------//
// @author Yurii Krasniuk,								//
// Igor Sykorsky KPI									//
//------------------------------------------------------//


#ifndef DICTIONARY_DICTIONARY_H_
#define DICTIONARY_DICTIONARY_H_
#include "AVL/AVL.h"	// for most efficient structure for Dictionary
#include <string>		// for key and data we will use strings

typedef std::string Word;
typedef std::string Meaning;

// Dictionary Declaration:
// Dictionary - it is specification of AVL Tree,
// what used strings
typedef AVL<Word, Meaning > Dictionary;


#endif // !DICTIONARY_DICTIONARY_H_
