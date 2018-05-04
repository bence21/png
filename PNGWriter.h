#pragma once

void write4B(unsigned int x, ofstream &stream);

class PNGWriter
{
public:
	void write(char* filename, vector<vector <RGB>> data);
};