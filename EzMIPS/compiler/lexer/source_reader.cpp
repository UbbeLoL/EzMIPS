#include "source_reader.h"

using namespace std;

SourceReader::SourceReader(std::wistream &input):
m_input(&input),
m_current_col(0),
m_current_row(0){
}

SourceReader::~SourceReader(){

}

bool SourceReader::is_eof(){
	return m_input->eof() || m_input->fail();
	wchar_t l = read();
	bool flag = m_input->eof();
	if(!flag){
		m_input->seekg(-1, ios::cur);
	}
	return flag;
}

void SourceReader::eat_whitespace(){
	int curChar;
	while(iswspace(curChar = read())){
		if(curChar == '\n'){
			advance_row();
			reset_col();
		}
	};
	decrement_col();
	m_input->seekg(-1, ios::cur);
}

int SourceReader::read(){
	advance_col();
	return m_input->get();
}

int SourceReader::peek(){
	return m_input->peek();
}

int SourceReader::peek(int forward_count){
	for(int i = 0;i < forward_count;i++){
		read();
	}
	int tmpChar = peek();
	m_input->seekg(-(forward_count+1), ios::cur);
	return tmpChar;
}

void SourceReader::advance(int forward_count){
	for(int i = 0;i < forward_count;i++){
		read();
	}
}

bool SourceReader::is_integer(wint_t val){
	return iswdigit(val);
}

bool SourceReader::is_legal_identifier_start(wint_t val){
	return iswalpha(val);
}

bool SourceReader::matches(wstring str){
	for(int i = 0;i < str.length();i++){
		if(peek(i) != str.at(i)){
			return false;
		}
	}
	return true;
}

// TODO: fixa med peek() ist�llet...
bool SourceReader::matches_unique(wstring str){
	for(int i = 0;i < str.length();i++){
		if(peek(i) != str.at(i)){
			return false;
		}
	}
	return iswspace(peek(str.length()));
}


void SourceReader::reset(){
	m_current_col = 0;
	m_current_row = 0;
	m_input->clear();
	m_input->seekg((wstreampos)0);
}

void SourceReader::advance_row(){
	m_current_row++;
}

void SourceReader::reset_col(){
	m_current_col = 0;
}

void SourceReader::advance_col(){
	m_current_col++;
}

void SourceReader::decrement_col(){
	m_current_col--;
}

void SourceReader::decrement_col(unsigned int count){
	m_current_col -= count;
}

unsigned int SourceReader::get_current_row(){
	return m_current_row;
}

unsigned int SourceReader::get_current_col(){
	return m_current_col;
}