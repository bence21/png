#pragma once
#include<fstream>
#include<vector>
using namespace std;
struct RGB
{
	int red;
	int green;
	int blue;
};
class BMPReader
{
public:
	BMPReader() {}
	~BMPReader() {}
	vector<vector <RGB>> read(char* filename)
	{
		vector<vector <RGB>> array;
		FILE* img = fopen(filename, "rb");

		unsigned char header[54];
		fread(header, sizeof(unsigned char), 54, img);
		int width = *(int*)&header[18];
		int height = *(int*)&header[22];

		unsigned char* data = new unsigned char[3];
		array.resize(height);
		for(int i = 0; i<height; ++i)
		{
			array[i].resize(width);
			for(int j = 0; j<width; ++j)
			{
				fread(data, sizeof(unsigned char), 3, img);
				array[i][j].red = data[2];
				array[i][j].green = data[1];
				array[i][j].blue = data[0];
			}
			fread(data, sizeof(unsigned char), 2, img); // padding
		}
		fclose(img);
		return array;
	}
};
