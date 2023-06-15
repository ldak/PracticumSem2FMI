#pragma once
#include <iostream>
#include <cstring>

class MyString
{
	char* _data;
	size_t _length;

	void copyFrom(const MyString& data);
	void free();

	explicit MyString(size_t capacity); //for memory allocation. How much bytes to allocate
public:

	MyString();
	MyString(const char* data);
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	~MyString();

    MyString(MyString&& other);
    MyString& operator=(MyString&& other);

    size_t length() const;
	MyString& operator+=(const MyString& other);

	MyString substr(size_t begin, size_t howMany) const;

    MyString clearStartWhitespaces() const;
    MyString clearEndWhitespaces() const;

	char& operator[](size_t index);
	char operator[](size_t index) const;
	
	const char* c_str() const;

	friend MyString operator+(const MyString& lhs, const MyString& rhs);
	friend std::istream& operator>>(std::istream&, MyString& str);

    bool isInt() const;

    int toInt() const;

    bool isDouble() const;

    double toDouble() const;
};
MyString operator+(const MyString& lhs, const MyString& rhs);

std::ostream& operator<<(std::ostream& os, const MyString& str);

std::istream& operator>>(std::istream& os, MyString& str);

bool operator<(const MyString& lhs, const MyString& rhs);
bool operator<=(const MyString& lhs, const MyString& rhs);
bool operator>=(const MyString& lhs, const MyString& rhs);
bool operator>(const MyString& lhs, const MyString& rhs);
bool operator==(const MyString& lhs, const MyString& rhs);
bool operator!=(const MyString& lhs, const MyString& rhs);