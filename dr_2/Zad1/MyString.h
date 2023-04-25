#pragma once
#include <iostream>
#include <cstring>

class MyString
{
    union String{
        struct BigString{
            char* data = nullptr;
            size_t length = 0;
            size_t capacity = 0;
        } big;
        struct SmallString{
            char data[sizeof(BigString) - 1]{};
        } small;
    } string{};

	void copyFrom(const MyString& data);
	void free();

	explicit MyString(size_t capacity); //for memory allocation. How much bytes to allocate

    bool isSmall() const;
public:

	MyString();
	MyString(const char* data);
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	~MyString();

	//move semantics on the next lecture
	MyString(MyString&& other);
	MyString& operator=(MyString&& other);

	size_t length() const;
	MyString& operator+=(const MyString& other);

	MyString substr(size_t begin, size_t howMany) const;

	char& operator[](size_t index);
	char operator[](size_t index) const;
	
	const char* c_str() const;

	friend MyString operator+(const MyString& lhs, const MyString& rhs);
	friend std::istream& operator>>(std::istream&, MyString& str);
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