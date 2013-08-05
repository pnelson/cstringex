#include "StringExA.h"


////////////////////////////////////
// Constructors and Destructor
////////////////////////////////////

CStringEx::CStringEx()
{
  m_szString = NULL;
  m_nLength = 0;
  m_nSize = 0;

  Resize(0);
}

CStringEx::CStringEx(const CStringEx& obj)
{
  m_szString = NULL;
  m_nLength = 0;
  m_nSize = 0;

  Assign(obj);
}

CStringEx::CStringEx(const char* str)
{
  m_szString = NULL;
  m_nLength = 0;
  m_nSize = 0;

  Assign(str);
}

CStringEx::CStringEx(char ch)
{
  m_szString = NULL;
  m_nLength = 0;
  m_nSize = 0;

  Assign(ch);
}

CStringEx::~CStringEx()
{
  if (m_szString)
    delete [] m_szString;
}


////////////////////////////////////
// Accessors
////////////////////////////////////

const char* CStringEx::GetString() const
{
  return m_szString;
}

int CStringEx::GetLength() const
{
  return m_nLength;
}

CStringEx::operator char*() const
{
  return m_szString;
}

CStringEx::operator const char*() const
{
  return m_szString;
}

char& CStringEx::operator[](int nIndex) const
{
  assert(nIndex < m_nLength);

  return m_szString[nIndex];
}


////////////////////////////////////
// Assignment
////////////////////////////////////

const CStringEx& CStringEx::Assign(const CStringEx& obj)
{
  Resize(obj.GetLength());

  ::strcpy(m_szString, obj);
  m_nLength = obj.GetLength();

  return *this;
}

const CStringEx& CStringEx::Assign(const char* str)
{
  Resize(::strlen(str));

  ::strcpy(m_szString, str);
  m_nLength = ::strlen(str);

  return *this;
}

const CStringEx& CStringEx::Assign(char ch)
{
  Resize(1);

  m_szString[0] = ch;
  m_nLength = 1;

  return *this;
}

const CStringEx& CStringEx::operator=(const CStringEx& obj) { return Assign(obj); }
const CStringEx& CStringEx::operator=(const char* str) { return Assign(str); }
const CStringEx& CStringEx::operator=(char ch) { return Assign(ch); }


////////////////////////////////////
// Concatenation
////////////////////////////////////

const CStringEx& CStringEx::Append(const CStringEx& obj)
{
  int nLength = obj.GetLength();

  Resize(m_nLength + nLength);

  ::strcpy(&m_szString[m_nLength], obj);
  m_nLength += nLength;

  return *this;
}

const CStringEx& CStringEx::Append(const char* str)
{
  int nLength = ::strlen(str);

  Resize(m_nLength + nLength);

  ::strcpy(&m_szString[m_nLength], str);
  m_nLength += nLength;

  return *this;
}

const CStringEx& CStringEx::Append(char ch)
{
  Resize(m_nLength + 1);

  m_szString[m_nLength] = ch;
  m_nLength++;

  return *this;
}

const CStringEx& CStringEx::operator+=(const CStringEx& obj) { return Append(obj); }
const CStringEx& CStringEx::operator+=(const char* str) { return Append(str); }
const CStringEx& CStringEx::operator+=(char ch) { return Append(ch); }

CStringEx operator+(const CStringEx& lhs, const CStringEx& rhs) { return CStringEx(lhs).Append(rhs); }
CStringEx operator+(const CStringEx& lhs, const char* rhs) { return CStringEx(lhs).Append(rhs); }
CStringEx operator+(const CStringEx& lhs, char rhs) { return CStringEx(lhs).Append(rhs); }
CStringEx operator+(const char* lhs, const CStringEx& rhs) { return CStringEx(lhs).Append(rhs); }
CStringEx operator+(char lhs, const CStringEx& rhs) { return CStringEx(lhs).Append(rhs); }


////////////////////////////////////
// Removal
////////////////////////////////////

const CStringEx& CStringEx::Remove(char chTarget)
{
  for (int i = 0; i < m_nLength; i++)
  {
    if (m_szString[i] != chTarget)
      continue;

    ::strcpy(&m_szString[i], &m_szString[i + 1]);
    m_nLength--;
  }

  return *this;
}

const CStringEx& CStringEx::Remove(const char* szTarget)
{
  int nIndex = 0;
  int nLength = ::strlen(szTarget);

  while ((nIndex = Find(szTarget, nIndex)) != -1)
  {
    ::strcpy(&m_szString[nIndex], &m_szString[nIndex + nLength]);
    m_nLength -= nLength;
  }

  return *this;
}

const CStringEx& CStringEx::operator-=(const CStringEx& obj) { return Remove(obj); }
const CStringEx& CStringEx::operator-=(const char* str) { return Remove(str); }
const CStringEx& CStringEx::operator-=(char ch) { return Remove(ch); }

CStringEx operator-(const CStringEx& lhs, const CStringEx& rhs) { return CStringEx(lhs).Remove(rhs); }
CStringEx operator-(const CStringEx& lhs, const char* rhs) { return CStringEx(lhs).Remove(rhs); }
CStringEx operator-(const CStringEx& lhs, char rhs) { return CStringEx(lhs).Remove(rhs); }
CStringEx operator-(const char* lhs, const CStringEx& rhs) { return CStringEx(lhs).Remove(rhs); }
CStringEx operator-(char lhs, const CStringEx& rhs) { return CStringEx(lhs).Remove(rhs); }


////////////////////////////////////
// Comparison
////////////////////////////////////

bool operator==(const CStringEx& lhs, const CStringEx& rhs) { return ::strcmp(lhs, rhs) == 0; }
bool operator!=(const CStringEx& lhs, const CStringEx& rhs) { return ::strcmp(lhs, rhs) != 0; }
bool operator<(const CStringEx& lhs, const CStringEx& rhs) { return ::strcmp(lhs, rhs) < 0; }
bool operator<=(const CStringEx& lhs, const CStringEx& rhs) { return ::strcmp(lhs, rhs) <= 0; }
bool operator>(const CStringEx& lhs, const CStringEx& rhs) { return ::strcmp(lhs, rhs) > 0; }
bool operator>=(const CStringEx& lhs, const CStringEx& rhs) { return ::strcmp(lhs, rhs) >= 0; }

bool operator==(const CStringEx& lhs, const char* rhs) { return ::strcmp(lhs, rhs) == 0; }
bool operator!=(const CStringEx& lhs, const char* rhs) { return ::strcmp(lhs, rhs) != 0; }
bool operator<(const CStringEx& lhs, const char* rhs) { return ::strcmp(lhs, rhs) < 0; }
bool operator<=(const CStringEx& lhs, const char* rhs) { return ::strcmp(lhs, rhs) <= 0; }
bool operator>(const CStringEx& lhs, const char* rhs){ return ::strcmp(lhs, rhs) > 0; }
bool operator>=(const CStringEx& lhs, const char* rhs) { return ::strcmp(lhs, rhs) >= 0; }

bool operator==(const char* lhs, const CStringEx& rhs) { return ::strcmp(lhs, rhs) == 0; }
bool operator!=(const char* lhs, const CStringEx& rhs) { return ::strcmp(lhs, rhs) != 0; }
bool operator<(const char* lhs, const CStringEx& rhs) { return ::strcmp(lhs, rhs) < 0; }
bool operator<=(const char* lhs, const CStringEx& rhs) { return ::strcmp(lhs, rhs) <= 0; }
bool operator>(const char* lhs, const CStringEx& rhs) { return ::strcmp(lhs, rhs) > 0; }
bool operator>=(const char* lhs, const CStringEx& rhs) { return ::strcmp(lhs, rhs) >= 0; }


////////////////////////////////////
// Formatting
////////////////////////////////////

const CStringEx& CStringEx::Format(const char* szFormat, ...)
{
  // TODO: Not implemented.
  return *this;
}

const CStringEx& CStringEx::FormatV(const char* szFormat, va_list szArguments)
{
  // TODO: Not implemented.
  return *this;
}


////////////////////////////////////
// Extraction
////////////////////////////////////

CStringEx CStringEx::Mid(int nFirst, int nCount) const
{
  CStringEx obj;

  if (m_nLength < nFirst + nCount)
    return obj;

  for (int i = nFirst; i < nFirst + nCount; i++)
    obj += m_szString[i];

  return obj;
}

CStringEx CStringEx::Mid(int nFirst) const
{
  return Mid(nFirst, m_nLength - nFirst);
}

CStringEx CStringEx::Left(int nCount) const
{
  return Mid(0, nCount);
}

CStringEx CStringEx::Right(int nCount) const
{
  return Mid(m_nLength - nCount, nCount);
}


////////////////////////////////////
// Conversions
////////////////////////////////////

void CStringEx::MakeLower()
{
  for (int i = 0; i < m_nLength; i++)
    m_szString[i] = ::tolower(m_szString[i]);
}

void CStringEx::MakeUpper()
{
  for (int i = 0; i < m_nLength; i++)
    m_szString[i] = ::toupper(m_szString[i]);
}

void CStringEx::MakeReverse()
{
  char chCurrent;

  char* szLeft = m_szString;
  char* szRight = &m_szString[m_nLength - 1];

  while (szLeft < szRight)
  {
    chCurrent = *szLeft;
    *szLeft++ = *szRight;
    *szRight-- = chCurrent;
  }
}

int CStringEx::Replace(char chOld, char chNew)
{
  int nCount = 0;

  for (int i = 0; i < m_nLength; i++)
  {
    if (m_szString[i] != chOld)
      continue;

    m_szString[i] = chNew;
    nCount++;
  }

  return nCount;
}

int CStringEx::Replace(const char* szOld, const char* szNew)
{
  int nCount = 0;
  int nIndex = 0;

  int nOldLength = ::strlen(szOld);
  int nNewLength = ::strlen(szNew);

  while ((nIndex = Find(szOld, nIndex)) != -1)
  {
    Resize(m_nLength - nOldLength + nNewLength);

    ::memmove(&m_szString[nIndex + nNewLength], &m_szString[nIndex + nOldLength], nOldLength);
    ::memmove(&m_szString[nIndex], szNew, nNewLength);

    m_nLength = m_nLength - nOldLength + nNewLength;
    nCount++;
  }

  return nCount;
}

int CStringEx::TrimLeft()
{
  int nCount = 0;

  for (int i = 0; i < m_nLength && ::isspace(m_szString[i]); i++)
    nCount++;

  ::strcpy(m_szString, &m_szString[nCount]);
  m_nLength -= nCount;

  return nCount;
}

int CStringEx::TrimLeft(char chTarget)
{
  int nCount = 0;

  for (int i = 0; i < m_nLength && m_szString[i] == chTarget; i++)
    nCount++;

  ::strcpy(m_szString, &m_szString[nCount]);
  m_nLength -= nCount;

  return nCount;
}

int CStringEx::TrimLeft(const char* szTarget)
{
  int nCount = 0;

  for (int i = 0; i < m_nLength; i++)
  {
    bool bFound = false;

    for (int j = 0; j < (int)::strlen(szTarget); j++)
    {
      if (m_szString[i] != szTarget[j])
        continue;

      nCount++;
      bFound = true;

      break;
    }

    if (!bFound)
      break;
  }

  ::strcpy(m_szString, &m_szString[nCount]);
  m_nLength -= nCount;

  return nCount;
}

int CStringEx::TrimRight()
{
  int nCount = 0;

  for (int i = m_nLength - 1; i >= 0 && ::isspace(m_szString[i]); i--)
  {
    m_szString[i] = '\0';
    nCount++;
  }

  m_nLength -= nCount;

  return nCount;
}

int CStringEx::TrimRight(char chTarget)
{
  int nCount = 0;

  for (int i = m_nLength - 1; i >= 0 && m_szString[i] == chTarget; i--)
  {
    m_szString[i] = '\0';
    nCount++;
  }

  m_nLength -= nCount;

  return nCount;
}

int CStringEx::TrimRight(const char* szTarget)
{
  int nCount = 0;

  for (int i = m_nLength - 1; i >= 0; i--)
  {
    bool bFound = false;

    for (int j = 0; j < (int)::strlen(szTarget); j++)
    {
      if (m_szString[i] != szTarget[j])
        continue;

      m_szString[i] = '\0';

      nCount++;
      bFound = true;

      break;
    }

    if (!bFound)
      break;
  }

  m_nLength -= nCount;

  return nCount;
}

int CStringEx::Trim()
{
  return TrimLeft() + TrimRight();
}

int CStringEx::Trim(char chTarget)
{
  return TrimLeft(chTarget) + TrimRight(chTarget);
}

int CStringEx::Trim(const char* szTarget)
{
  return TrimLeft(szTarget) + TrimRight(szTarget);
}


////////////////////////////////////
// Searching
////////////////////////////////////

int CStringEx::Find(char chTarget, int nStart) const
{
  const char* szResult = ::strchr(&m_szString[nStart], chTarget);

  if (!szResult)
    return -1;

  return (int)(szResult - m_szString);
}

int CStringEx::Find(const char* szString, int nStart) const
{
  const char* szResult = ::strstr(&m_szString[nStart], szString);

  if (!szResult)
    return -1;

  return (int)(szResult - m_szString);
}

int CStringEx::ReverseFind(char chTarget) const
{
  const char* szResult = ::strrchr(m_szString, chTarget);

  if (!szResult)
    return -1;

  return (int)(szResult - m_szString);
}


////////////////////////////////////
// Miscellaneous
////////////////////////////////////

bool CStringEx::FreeExtra()
{
  if (m_nSize == m_nLength + 1)
    return true;

  char* szString = new char[m_nLength + 1];

  if (!szString)
    return false;

  ::strcpy(szString, m_szString);

  delete [] m_szString;

  m_szString = szString;
  m_nSize = m_nLength + 1;

  return true;
}

void CStringEx::Resize(int nLength)
{
  if (m_nSize > nLength)
    return;

  if (m_nSize < 32 || m_nSize % 32 != 0)
    m_nSize = 32;

  while (m_nSize <= nLength)
    m_nSize *= 2;

  char* szString = new char[m_nSize];

  assert(szString);

  ::memset(szString, NULL, m_nSize * sizeof(char));

  if (m_szString)
  {
    ::strcpy(szString, m_szString);
    delete [] m_szString;
  }

  m_szString = szString;
}
