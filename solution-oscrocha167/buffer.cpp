/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Oscar Rocha <oscar.k.rocha09@gmail.com>
* team: Ying Wen <ywen1306@csu.fullerton.edu>, Edgar Banos <ebanos14@csu.fullerton.edu>, 
* Errict Cantu <errictcantu@csu.fullerton.edu>, Anthony Rodriguez <A.rodriguez525@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

/**
* Implements `buffer.h`.
*/

// TODO: `#include`s for system headers, if necessary

#include "buffer.h"
#include <iostream>

// TODO: `#include`s for other local headers, if necessary

// ----------------------------------------------------------------------------

// TODO: implementations for all functions in `class Buffer`
Buffer::Buffer(unsigned int size_x, unsigned int size_y)
	: size_x(size_x), size_y(size_y)
{
	data_ = new char[size_x * size_y];
	for (unsigned int i = 0; i < size_x * size_y; i++)
		data_[i] = ' ';
}
Buffer::~Buffer()
{
	delete[] data_;
}
char Buffer::get(unsigned int x, unsigned int y) const
{
	if (x >= size_x || y >= size_y)
	{
		std::cerr << "ERROR: `Buffer::get`: index out of bounds\n";
		exit(1);
	}
	else
	{
		char answer = data_[y * size_x + x];
		return answer;
	}

}
void Buffer::set(unsigned int x, unsigned int y, char c)
{
	if (x >= size_x || y >= size_y)
	{
		std::cerr << "ERROR: `Buffer::get`: index out of bounds\n";
		exit(1);
	}
	else
	{
		data_[y * size_x + x] = c;

	}
}
void Buffer::set(unsigned int pos_x, unsigned int pos_y, std::string s)
{
	for (int i = 0, x = pos_x, y = pos_y; i < s.length(); i++) {
		if (s[i] == '\n') {
			y++;
			x = pos_x;
		}
		else {
			set(x++, y, s[i]);
		}
	}
}


void Buffer::draw() const
{

	for (unsigned int y = 0; y < size_y; y++)
	{

		for (unsigned int x = 0; x < size_x; x++)
		{
			std::cout << get(x, y);
		}
		std::cout << std::endl;
	}




}
void Buffer::clear()
{
	for (int i = 0; i < size_x * size_y; i++)
		data_[i] = ' ';
}
