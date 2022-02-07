#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <string.h>
#include <memory>
#include <vector>
#include <time.h>
#include <cstdlib>

using namespace std; 

enum tokenType {
	LEFT_PAREN,RIGHT_PAREN,
	NUM,
	PLUS,MINUS,MUL,DIV,
	KNOWNYET
};

struct token {
	string lexeme;
	tokenType type;
} ;

string nextL;
vector <token> TokList;

class scanner {
	
	public:
	string NextG;
	 
	bool getLexeme() {
		string stayL = "\0";
		string tok = "\0";
		char stay1 = '\0';
		int i = 0, GLen = 0, lPNum = 0;  
		stay1 = cin.peek();
		
		if ( NextG != "\0" ) {
			NextG = "\0";
		} // if
		
		while ( stay1 != EOF && stay1 != '\n' ) {
			scanf( "%c", & stay1 );
			if ( stay1 == '(' ) { // 括號要特別處理 
				lPNum++;
				NextG = NextG + stay1; 
			} // if
			else if ( stay1 == ')' ) {
				if ( lPNum > 0 ) {
					lPNum--;
					NextG = NextG + stay1; 
				} // if
			} // else
			else {
				NextG = NextG + stay1; 
			} // else
			
			stay1 = cin.peek();
		} // while

		if ( lPNum != 0 ) { // ( )數量還沒有相同 
			while ( stay1 != EOF && lPNum != 0 ) {
				scanf( "%c", &stay1 );
				if ( stay1 == '(' ) { // 括號要特別處理 
					lPNum++;
					NextG = NextG + stay1; 
				} // if
				else if ( stay1 == ')' ) {
					if ( lPNum > 0 ) {
						lPNum--;
						NextG = NextG + stay1; 
					} // if
				} // else
				else {
					NextG = NextG + stay1; 
				} // else
				
				stay1 = cin.peek();
			} // while
		} // if
		
		while ( NextG[0] == ' ' || NextG[0] == '\t' || NextG[0] == '\n' ) {
			if ( NextG[0] == ' ' || NextG[0] == '\t' || NextG[0] == '\n' ) {
				NextG.erase( 0, 1 );
			} // if 
		} // while
		
		GLen = NextG.size();
		i = 0;
		while ( i < GLen ) {
			stay1 = NextG[i];
			
			if ( stay1 != ' ' && stay1 != '\t' && stay1 != '\0' && stay1 != '\n' ) {
				tok = tok + stay1;
			} // if
			
			i++; 
		} // while
		
		if ( tok != "\0" ) {
			NextG = tok;
		} // if
		
		if ( stay1 == EOF ) { 
			return true;
		} // if
		else {
			if ( stay1 == '\n' ) {
				scanf( "%c", &stay1 );
			} // if
			
			return false;
		} // else

	} // getLexeme ()
	
	void whatToken() {
		char stay2 = '\0';
		string stayL = "\0";
		token nT;
		int i = 0, GLen = 0, lPNum = 0;
		
		GLen = NextG.size();
		while ( i < GLen ) {
			stay2 = NextG[i];
			
			if ( stay2 == '(' ) {
				if ( stayL != "\0" ) {
					nT.lexeme = stayL;
					nT.type = NUM;
					TokList.push_back(nT);
					
					stayL = "\0";
					stayL = stayL + stay2;
					nT.lexeme = stay2;
					nT.type = LEFT_PAREN;
					TokList.push_back(nT);
				} // if
				else {
					stayL = stayL + stay2;
					nT.lexeme = stay2;
					nT.type = LEFT_PAREN;
					TokList.push_back(nT);
				} // else
				
				stayL = "\0";
			} // if
			else if ( stay2 == ')' ) {
				if ( stayL != "\0" ) {
					nT.lexeme = stayL;
					nT.type = NUM;
					TokList.push_back(nT);
					
					stayL = "\0";
					stayL = stayL + stay2;
					nT.lexeme = stay2;
					nT.type = RIGHT_PAREN;
					TokList.push_back(nT);
				} // if
				else {
					stayL = stayL + stay2;
					nT.lexeme = stay2;
					nT.type = RIGHT_PAREN;
					TokList.push_back(nT);
				} // else
				
				stayL = "\0";
			} // else if 
			else if ( stay2 == '+' || stay2 == '-' || stay2 == '*' || stay2 == '/' ) {
				if ( stayL != "\0" ) {
					nT.lexeme = stayL;
					nT.type = NUM;
					TokList.push_back(nT);
					
					stayL = "\0";
					stayL = stayL + stay2;
					nT.lexeme = stay2;
					if ( stay2 == '+' ) 
						nT.type = PLUS;
					else if ( stay2 == '-' )
						nT.type = MINUS;
					else if ( stay2 == '*' )
						nT.type = MUL;
					else
						nT.type = DIV;
					
					TokList.push_back(nT);
				} // if
				else {
					stayL = stayL + stay2;
					nT.lexeme = stay2;
					if ( stay2 == '+' ) 
						nT.type = PLUS;
					else if ( stay2 == '-' )
						nT.type = MINUS;
					else if ( stay2 == '*' )
						nT.type = MUL;
					else
						nT.type = DIV;
					
					TokList.push_back(nT);
				} // else
				
				stayL = "\0";
			} // else if
			else { // 剩數字 
				stayL = stayL + stay2;
			} // else if
			
			i++;
		} // while
		
		if ( stayL != "\0" ) {
			nT.lexeme = stayL;
			nT.type = NUM;
			TokList.push_back(nT);
		} // if
		
		i = 0;
		while ( i < TokList.size() ) {
			if ( TokList[i].type == LEFT_PAREN ) {
				cout << "LPR\n";
			} // if
			else if ( TokList[i].type == RIGHT_PAREN ) {
				cout << "PPR\n";
			} // else if 
			else if ( TokList[i].type == PLUS ) {
				cout << "PLUS\n";
			} // else if
			else if ( TokList[i].type == MINUS ) {
				cout << "MINUS\n";
			} // else if
			else if ( TokList[i].type == MUL ) {
				cout << "MUL\n";
			} // else if
			else if ( TokList[i].type == DIV ) {
				cout << "DIV\n";
			} // else if
			else { // 剩數字 
				cout << "NUM "<< TokList[i].lexeme << "\n";
			} // else if
			
			i++;
		} // while
		
		TokList.clear();
	} // whatToken()
	
};

int main() {
	
	char getIn = '0';
	bool toStop = false;
	scanner a;
  
	while ( !toStop ) {
		toStop = a.getLexeme();
		a.whatToken();
    }  // while
	
	return 0;
} // main()
