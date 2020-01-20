#pragma once



using namespace std;

class GridItem
{
public:
	GridItem();
	~GridItem();
   char get_symbol() const;
protected:
	char symbol;
};

