#include<iostream>
#include<cstring>

class CMyString
{
	public:
		CMyString(const char* pData = NULL);
		CMyString(const CMyString& str);
		CMyString& operator=(const CMyString& rhs);
		~CMyString();
		void print();
	private:
		char* m_pData;
};

//no instance's member m_pData is NULL
CMyString:: CMyString(const char* pData)
{
	if(pData == NULL)
	{
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else
	{
		int length = strlen(pData);
		m_pData = new char[length + 1];
		strcpy(m_pData, pData);
	}
}

CMyString:: CMyString(const CMyString& other)
{
	int length = strlen(other.m_pData);
	m_pData = new char[length + 1];
	strcpy(m_pData, other.m_pData);
} 

CMyString& CMyString::operator=(const CMyString& rhs)
{
	if(this == &rhs)
		return *this;
		
	delete [] m_pData;
	m_pData = NULL;
	
	m_pData = new char[strlen(rhs.m_pData) + 1];
	strcpy(m_pData, rhs.m_pData);
	
	return *this;
}

//safe way
/*
CMyString& CMyString::operator=(const CMyString& rhs)
{
	if(this == &rhs)
		return *this;
	
	CMyString tempStr(rhs);
	
	char *pTemp = tempStr.m_pData;
	tempStr.m_pData = m_pData;
	m_pData = pTemp;
} 
*/

CMyString::~CMyString()
{
	delete [] m_pData;
}

void CMyString::print()
{
	std::cout<<m_pData<<std::endl;
}

 
int main(int argc, char* argv[])
{
	CMyString str1;
	str1.print();
	CMyString str2("good boy");
	CMyString str3("programming is interesting");
	CMyString str4 = str2;
	str4.print();
	str4 = str3;
	str4.print();
	
	return 0;
}
