#include "MyString.h"

MyString::MyString(size_t capacity)
{
    if (capacity <= sizeof(this->string)){
        return;
    }
	this->string.big.capacity = capacity;
    this->string.big.length = capacity - 1;
	this->string.big.data = new char[capacity];
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
	MyString result(lhs.length() + rhs.length() + 1);

    if (result.isSmall()){
        result.string.small.data[0] = '\0';
        strcat(result.string.small.data, lhs.string.small.data);
        strcat(result.string.small.data, rhs.string.small.data);
        return result;
    }
    result.string.big.data[0] = '\0';
    strcat(result.string.big.data, lhs.string.big.data);
    strcat(result.string.big.data, rhs.string.big.data);

	return result;
}

MyString& MyString::operator+=(const MyString& other)
{
    size_t newLength = this->length() + other.length();
    if (newLength < sizeof(this->string)){
        strcat(this->string.small.data, other.string.small.data);
        return *this;
    }

	char* result = new char[this->length() + other.length() + 1];
	result[0] = '\0'; 
	strcat(result, this->string.big.data);
	strcat(result, other.string.big.data);

	delete[] this->string.big.data;
	this->string.big.data = result;

	return *this;
}

MyString::MyString() : MyString(1)
{
	this->operator[](0) = '\0';
}

MyString::MyString(const char* data) : MyString(strlen(data) + 1)
{
    if (isSmall()){
        strcpy(this->string.small.data, data);
        return;
    }
	strcpy(this->string.big.data, data);
}

MyString::MyString(const MyString& other)
{
	copyFrom(other);
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}


void MyString::free()
{
    if (this->isSmall()){
        return;
    }
	delete[] this->string.big.data;
	this->string.big.data = nullptr;
}

MyString::~MyString()
{
	free();
}

size_t MyString::length() const
{
    if (this->isSmall()){
// strlen is a loop, but it has constant time complexity because small strings have max length of sizeof(this->string) - 1
        return strlen(this->string.small.data);
    }
	return this->string.big.length;
}

void MyString::copyFrom(const MyString& other)
{
    if (other.isSmall()){
        this->string = other.string;
        return;
    }
    this->string.big.length = other.string.big.length;
    this->string.big.capacity = other.string.big.capacity;
    this->string.big.data = new char[this->string.big.capacity + 1];
    strcpy(this->string.big.data, other.string.big.data);
}

char& MyString::operator[](size_t index) //Неконстантен достъп
{
    if (this->isSmall()){
        return this->string.small.data[index];
    }
	return this->string.big.data[index];
}

char MyString::operator[](size_t index) const //Константен достъп 
{
    if (this->isSmall()){
        return this->string.small.data[index];
    }
    return this->string.big.data[index];
}

MyString MyString::substr(size_t begin, size_t howMany) const
{
	if (begin + howMany > this->length())
		throw std::length_error("Error, Substr out of range");
	

	MyString res(howMany + 1);
	for (int i = 0; i < howMany; i++)
		res[i] = this->operator[](begin + i);
	res[howMany] = '\0';
	return res;
}

const char* MyString::c_str() const
{
    if (this->isSmall()){
        return this->string.small.data;
    }
    return this->string.big.data;
}

std::ostream& operator<<(std::ostream& os, const MyString& str)
{
	return os << str.c_str();
}

std::istream& operator>>(std::istream& is, MyString& str)
{
	char buff[1024];
	is >> buff; // is.getLine(buff, 1024);

    str.free();
    size_t length = strlen(buff);
    if (length < sizeof(str.string)){
        strcpy(str.string.small.data, buff);
        return is;
    }

	str.string.big.capacity = length + 1;
    str.string.big.length = length;
    str.string.big.data = new char[str.string.big.capacity];
    strcpy(str.string.big.data, buff);
	return is;
}

bool MyString::isSmall() const {
    return this->string.big.length > this->string.big.capacity || this->string.big.capacity == 0;
}

MyString::MyString(MyString &&other) {
    this->string = other.string;
    other.string.big.data = nullptr;

}

MyString &MyString::operator=(MyString &&other) {
    if (this != &other){
        this->free();
        this->string = other.string;
        other.string.big.data = nullptr;
    }
    return *this;
}


bool operator<(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator<=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}
bool operator>=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}
bool operator>(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}
bool operator==(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}
bool operator!=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) != 0;
}