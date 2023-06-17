#include "MyString.h"

MyString::MyString(size_t capacity)
{
	_length = capacity - 1;
	_data = new char[capacity];
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
	MyString result(lhs._length + rhs._length + 1);

	result[0] = '\0';
	strcat(result._data, lhs._data);
	strcat(result._data, rhs._data);

	return result;
}

MyString& MyString::operator+=(const MyString& other)
{
	char* result = new char[(_length += other._length) + 1];
	result[0] = '\0'; 
	strcat(result, _data);
	strcat(result, other._data);

	delete[] _data;
	_data = result;

	return *this;
}

MyString::MyString() : MyString(1)
{
	_data[0] = '\0';
}

MyString::MyString(MyString&& other)
{
    _data = other._data;
    other._data = nullptr;
    _length = other._length;
}

MyString& MyString::operator=(MyString&& other)
{
    if (this != &other)
    {
        free();
        _data = other._data;
        other._data = nullptr;
        _length = other._length;
    }
    return *this;
}


MyString::MyString(const char* data) : MyString(strlen(data) + 1)
{
	strcpy(_data, data);	
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
	delete[] _data;
	_data = nullptr;
}

MyString::~MyString()
{
	free();
}

size_t MyString::length() const
{
	return _length;
}

void MyString::copyFrom(const MyString& other)
{
	_length = other._length;
	_data = new char[_length + 1];
	strcpy(_data, other._data);
}

char& MyString::operator[](size_t index) //Неконстантен достъп
{
	return _data[index];
}

char MyString::operator[](size_t index) const //Константен достъп 
{
	return _data[index];
}

MyString MyString::substr(size_t begin, size_t howMany) const
{
	if (begin + howMany > _length)
		throw std::length_error("Error, Substr out of range");
	

	MyString res(howMany + 1);
	for (int i = 0; i < howMany; i++)
		res._data[i] = _data[begin + i];
	res[howMany] = '\0';
	return res;
}

const char* MyString::c_str() const
{
	return _data;
}

std::ostream& operator<<(std::ostream& os, const MyString& str)
{
	return os << str.c_str();
}

std::istream& operator>>(std::istream& is, MyString& str)
{
	char buff[1024];
	is >> buff; // is.getLine(buff, 1024);

	delete[] str._data;
	str._length = strlen(buff);
	str._data = new char[str._length + 1];
	strcpy(str._data, buff);
	return is;
}

MyString MyString::clearStartWhitespaces() const {
    int i = 0;
    while (_data[i] == ' ' || _data[i] == '\t' && i < _length) {
        i++;
    }
    return this->substr(i, _length - i);
}

MyString MyString::clearEndWhitespaces() const {
    int i = _length - 1;
    while (_data[i] == ' ' || _data[i] == '\t' && i > 0) {
        i--;
    }
    return this->substr(0, i + 1);
}

bool MyString::isInt() const{
    if ((_data[0] > '9' || _data[0] < '0') && _data[0] != '-' && _data[0] != '+')
        return false;
    for (int i = 1; i < _length; i++) {
        if (_data[i] > '9' || _data[i] < '0')
            return false;
    }
    return true;
}

int MyString::toInt() const{
    if (!isInt())
        throw std::invalid_argument("Error, string is not int");
    int res = 0;
    int i = 0;
    if (_data[0] == '-' || _data[0] == '+')
        i++;
    for (; i < _length; i++) {
        res *= 10;
        res += _data[i] - '0';
    }
    if (_data[0] == '-')
        res *= -1;
    return res;
}

bool MyString::isDouble() const {
    if ((_data[0] > '9' || _data[0] < '0') && _data[0] != '-' && _data[0] != '+')
        return false;
    int i = 1;
    for (; i < _length; i++) {
        if (_data[i] > '9' || _data[i] < '0')
            break;
    }
    if (_data[i] != '.' && _data[i] != '\0')
        return false;
    i++;
    for (; i < _length; i++) {
        if (_data[i] > '9' || _data[i] < '0')
            return false;
    }
    return true;
}

double MyString::toDouble() const{
    if (!isDouble())
        throw std::invalid_argument("Error, string is not double");
    double res = 0;
    int i = 0;
    if (_data[0] == '-' || _data[0] == '+')
        i++;
    for (; _data[i] != '.'&& _data[i] != ',' && _data[i]!= '\0'; i++) {
        res *= 10;
        res += _data[i] - '0';
    }
    i++;
    double dec = 0.1;
    for (; i < _length; i++) {
        res += (_data[i] - '0') * dec;
        dec /= 10;
    }
    if (_data[0] == '-')
        res *= -1;
    return res;
}

bool MyString::isStringLiteral() const {
    return _data[0] == '"' && _data[_length - 1] == '"' && _length > 1;
}

MyString MyString::fromStringLiteral() const {
    char buff[1024]{'\0'};
    int index = 0;
    for (int i = 1; i < _length - 1; ++i) {
        if (_data[i] == '\\' && (_data[i + 1] == '\\' || _data[i + 1] == '"')) {
            buff[index++] = _data[i + 1];
            i++;
        }
        else
            buff[index++] = _data[i];
    }
    return buff;
}

MyString MyString::toStringLiteral() const {
    char buffer[1024]{'\0'};
    buffer[0] = '"';
    int index = 1;
    for (int i = 0; i < _length ; ++i) {
        if (_data[i] == '\\' || _data[i] == '"') {
            buffer[index++] = '\\';
            buffer[index++] = _data[i];
        }
        else
            buffer[index++] = _data[i];
    }
    buffer[index++] = '"';
    return buffer;
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