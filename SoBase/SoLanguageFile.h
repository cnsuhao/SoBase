//------------------------------------------------------------
#ifndef _SoLanguageFile_h_
#define _SoLanguageFile_h_
//------------------------------------------------------------
class SoLanguageFile
{
public:
	SoLanguageFile();
	~SoLanguageFile();

	bool InitLanguageFile(const char* pszFileName);

	const char* GetValue(const char* pszKey);

private:
	void ClearAll();
	bool LoadFile(const char* pszFileName);
	//��ȡ�ļ���һ���ж�����
	int GetLineCount();
	bool ParseFile();
	char* GetNextLine();
	bool ParseFileLine(char* pFileLine);
	void SlimString(char* pBuff, int nValidSize, int& nAdjustStartIndex);
	bool MakeLanguageItem(char* pszKey, char* pszValue);

private:
	struct stLanguageItem
	{
		unsigned int uiHashKeyA;
		unsigned int uiHashKeyB;
		const char* pszKey;
		const char* pszValue;
	};

private:
	//������ڴ�飬���ڴ洢����Language�ļ���
	char* m_pFileBuff;
	int m_nFileBuffSize;
	//����
	stLanguageItem* m_pItemList;
	//����Ԫ�صĸ���
	int m_nItemCount;
	//�����ļ�������ʹ�õı�����
	int m_nReadPos;
};
//------------------------------------------------------------
#endif //_SoLanguageFile_h_
//------------------------------------------------------------
