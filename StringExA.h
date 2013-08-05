#ifndef _STRINGEX_H
#define _STRINGEX_H

#include <assert.h>
#include <ctype.h>
#include <string.h>

class CStringEx
{
public:
  ////////////////////////////////////
  // Constructors and Destructor
  ////////////////////////////////////

  CStringEx();
  CStringEx(const CStringEx& obj);
  CStringEx(const char* str);
  CStringEx(char ch);

  virtual ~CStringEx();


  ////////////////////////////////////
  // Accessors
  ////////////////////////////////////

  const char* GetString() const;
  int GetLength() const;

  operator char*() const;
  operator const char*() const;
  char& operator[](int nIndex) const;


  ////////////////////////////////////
  // Assignment
  ////////////////////////////////////

  const CStringEx& Assign(const CStringEx& obj);
  const CStringEx& Assign(const char* str);
  const CStringEx& Assign(char ch);

  const CStringEx& operator=(const CStringEx& obj);
  const CStringEx& operator=(const char* str);
  const CStringEx& operator=(char ch);


  ////////////////////////////////////
  // Concatenation
  ////////////////////////////////////

  const CStringEx& Append(const CStringEx& obj);
  const CStringEx& Append(const char* str);
  const CStringEx& Append(char ch);

  const CStringEx& operator+=(const CStringEx& obj);
  const CStringEx& operator+=(const char* str);
  const CStringEx& operator+=(char ch);

  friend CStringEx operator+(const CStringEx& lhs, const CStringEx& rhs);
  friend CStringEx operator+(const CStringEx& lhs, const char* rhs);
  friend CStringEx operator+(const CStringEx& lhs, char rhs);
  friend CStringEx operator+(const char* lhs, const CStringEx& rhs);
  friend CStringEx operator+(char lhs, const CStringEx& rhs);


  ////////////////////////////////////
  // Removal
  ////////////////////////////////////

  const CStringEx& Remove(char chTarget);
  const CStringEx& Remove(const char* szTarget);

  const CStringEx& operator-=(const CStringEx& obj);
  const CStringEx& operator-=(const char* str);
  const CStringEx& operator-=(char ch);

  friend CStringEx operator-(const CStringEx& lhs, const CStringEx& rhs);
  friend CStringEx operator-(const CStringEx& lhs, const char* rhs);
  friend CStringEx operator-(const CStringEx& lhs, char rhs);
  friend CStringEx operator-(const char* lhs, const CStringEx& rhs);
  friend CStringEx operator-(char lhs, const CStringEx& rhs);


  ////////////////////////////////////
  // Comparison
  ////////////////////////////////////

  friend bool operator==(const CStringEx& lhs, const CStringEx& rhs);
  friend bool operator!=(const CStringEx& lhs, const CStringEx& rhs);
  friend bool operator<(const CStringEx& lhs, const CStringEx& rhs);
  friend bool operator<=(const CStringEx& lhs, const CStringEx& rhs);
  friend bool operator>(const CStringEx& lhs, const CStringEx& rhs);
  friend bool operator>=(const CStringEx& lhs, const CStringEx& rhs);

  friend bool operator==(const CStringEx& lhs, const char* rhs);
  friend bool operator!=(const CStringEx& lhs, const char* rhs);
  friend bool operator<(const CStringEx& lhs, const char* rhs);
  friend bool operator<=(const CStringEx& lhs, const char* rhs);
  friend bool operator>(const CStringEx& lhs, const char* rhs);
  friend bool operator>=(const CStringEx& lhs, const char* rhs);

  friend bool operator==(const char* lhs, const CStringEx& rhs);
  friend bool operator!=(const char* lhs, const CStringEx& rhs);
  friend bool operator<(const char* lhs, const CStringEx& rhs);
  friend bool operator<=(const char* lhs, const CStringEx& rhs);
  friend bool operator>(const char* lhs, const CStringEx& rhs);
  friend bool operator>=(const char* lhs, const CStringEx& rhs);


  ////////////////////////////////////
  // Formatting
  ////////////////////////////////////

  const CStringEx& Format(const char* szFormat, ...);
  const CStringEx& FormatV(const char* szFormat, va_list szArguments);


  ////////////////////////////////////
  // Extraction
  ////////////////////////////////////

  CStringEx Mid(int nFirst, int nCount) const;

  CStringEx Mid(int nFirst) const;
  CStringEx Left(int nCount) const;
  CStringEx Right(int nCount) const;


  ////////////////////////////////////
  // Conversions
  ////////////////////////////////////

  void MakeLower();
  void MakeUpper();
  void MakeReverse();

  int Replace(char chOld, char chNew);
  int Replace(const char* szOld, const char* szNew);

  int TrimLeft();
  int TrimLeft(char chTarget);
  int TrimLeft(const char* szTarget);

  int TrimRight();
  int TrimRight(char chTarget);
  int TrimRight(const char* szTarget);

  int Trim();
  int Trim(char chTarget);
  int Trim(const char* szTarget);


  ////////////////////////////////////
  // Searching
  ////////////////////////////////////

  int Find(char chTarget, int nStart = 0) const;
  int Find(const char* szString, int nStart = 0) const;
  int ReverseFind(char chTarget) const;


  ////////////////////////////////////
  // Miscellaneous
  ////////////////////////////////////

  bool FreeExtra();

protected:
  void Resize(int nLength);

private:
  char* m_szString;
  int m_nLength;
  int m_nSize;
};

#endif
