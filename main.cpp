#include<iostream>
#include"BMPReader.cpp"
#include"PNGWriter.h"
#include "main.h"
using namespace std;
int main()
{
	BMPReader bMPReader=BMPReader();
	char* path = "sample.bmp";
	vector<vector <RGB>> v = bMPReader.read(path);
	PNGWriter pNGWriter = PNGWriter();
	pNGWriter.write("out.png", v);
}